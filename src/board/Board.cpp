#include <functional>
#include <iostream>

#include "../../include/board/Board.h"
#include "../../include/random/Random.h"
#include "../../include/console_color/ConsoleColor.h"


TileBase& Board::at(const int x, const int y) {
	return *board_.at(y).at(x);
}

const TileBase& Board::at(const int x, const int y) const {
	return *board_.at(y).at(x);
}

void Board::mv_up() noexcept {
	if (focused_tile_.y > 0 ) { focused_tile_.y--; }
}

void Board::mv_down() noexcept {
	if (focused_tile_.y < height_ - 1) { focused_tile_.y++; }
}

void Board::mv_right() noexcept {
	if (focused_tile_.x < width_ - 1) { focused_tile_.x++; }
}

void Board::mv_left() noexcept {
	if (focused_tile_.x > 0) { focused_tile_.x--; }
}

void Board::generate(const float& chance_to_bomb) {
	for (std::vector<std::unique_ptr<TileBase>>& row : board_) {
		for (std::unique_ptr<TileBase>& tile : row) {
			const float roll = Random::float_in_range(0.0f, 1.0f);

			if (roll < chance_to_bomb) {
				tile = std::make_unique<TileBomb>(Random::int_in_range(BoardConstants::min_bombs, BoardConstants::max_bombs));
			}
		}
	}

	const std::function<void(int, int)> add_bombs_to_neighbors = [this](const int& x, const int& y) {
		const auto* bomb_tile = dynamic_cast<TileBomb*>(board_[y][x].get());
		if (not bomb_tile) { throw std::invalid_argument("add_bombs_to_neighbors called for non-bomb"); }

		const int bombs_here = bomb_tile->bombs();

		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				if (i == 0 and j == 0) { continue; }

				const int new_x = x + i;
				const int new_y = y + j;

				if (new_x >= 0 and new_x < width_ and new_y >= 0 and new_y < height_) {
					auto& new_tile = board_[new_y][new_x];

					if (!new_tile) {
						new_tile = std::make_unique<TileNumber>(bombs_here);
					}
					else if (new_tile->type() == TileType::TileNumber) {
						auto* num = dynamic_cast<TileNumber*>(new_tile.get());
						num->increase_bombs(bombs_here);
					}
				}
			}
		}
	};


	for (int i = 0; i < height_; i++) {
		for (int j = 0; j < width_; j++) {
			if (board_[i][j] and board_[i][j]->type() == TileType::TileBomb) { add_bombs_to_neighbors(j, i); }
		}
	}

	for (std::vector<std::unique_ptr<TileBase>>& row : board_) {
		for (std::unique_ptr<TileBase>& tile : row) {
			if (not tile) { tile = std::make_unique<TileBase>(); }
		}
	}
}

void Board::open() noexcept {
	if (board_[focused_tile_.y][focused_tile_.x]->type() == TileType::TileBomb or
		board_[focused_tile_.y][focused_tile_.x]->type() == TileType::TileNumber) {

		board_[focused_tile_.y][focused_tile_.x]->open();
		return;
	}
	open_req(focused_tile_);
}

void Board::open_req(const Coords &pos) noexcept {
	if (not board_[pos.y][pos.x]->is_open() and board_[pos.y][pos.x]->type() != TileType::TileBomb) {
		board_[pos.y][pos.x]->open();
		if (board_[pos.y][pos.x]->type() == TileType::TileNumber) { return; }

		open_req(Coords{pos.x + 1, pos.y});
		open_req(Coords{pos.x - 1, pos.y});
		open_req(Coords{pos.x, pos.y + 1});
		open_req(Coords{pos.x, pos.y - 1});
	}
}

void Board::toggle_flag() noexcept {
	board_[focused_tile_.y][focused_tile_.x]->toggle_flagged();
}
