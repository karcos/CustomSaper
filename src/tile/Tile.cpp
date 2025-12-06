#include <iomanip>

#include "../../include/tile/Tile.h"


TileType TileBase::type() const noexcept {
	return TileType::TileBase;
}

bool TileBase::is_open() const noexcept {
	return is_open_;
}

bool TileBase::is_flagged() const noexcept {
	return is_flagged_;
}

void TileBase::open() {
	if (not is_flagged_ and not is_open_) is_open_ = true;
}

void TileBase::toggle_flagged() {
	if (not is_open_) is_flagged_ = not is_flagged_;
}

void TileBase::print(std::ostream& os) const noexcept {
	if (is_open_) os << '[' << TileConstants::TileBase::opened_mark << ']';
	else os << '[' << TileConstants::closed_mark << ']';
}

TileType TileBomb::type() const noexcept {
	return TileType::TileBomb;
}

int TileBomb::bombs() const noexcept {
	return bombs_;
}

void TileBomb::open() {
	if (not is_flagged_ and not is_open_) {
		is_open_ = true;
		explode_ = true;
	}
}

void TileBomb::print(std::ostream& os) const noexcept {
	if (is_open_ and explode_) os << '[' << bombs_ << TileConstants::TileBomb::opened_mark_wh_explosion << ']';
	else if (is_open_ and not explode_) os << '[' << bombs_ << TileConstants::TileBomb::opened_mark_no_explosion << ']';
	else os << '[' << TileConstants::closed_mark << ']';

}

void TileNumber::increase_bombs(const int to_add) {
	if (to_add < 0) throw std::invalid_argument("Value must be greater than zero");
	bombs_ += to_add;
}

TileType TileNumber::type() const noexcept {
	return TileType::TileNumber;
}

int TileNumber::bombs() const noexcept {
	return bombs_;
}

void TileNumber::print(std::ostream& os) const noexcept {
	if (is_open_) os << '[' << bombs_ << ']';
	else os << '[' << TileConstants::closed_mark << ']';
}