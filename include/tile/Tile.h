#pragma once

#include "TileConstants.h"


class TileBase {
protected:
	bool is_open_{ TileConstants::TileBase::is_open };
	bool is_flagged_{ TileConstants::TileBase::is_flagged };

public:
	explicit TileBase(const bool is_open = TileConstants::TileBase::is_open,
		const bool is_flagged = TileConstants::TileBase::is_flagged) noexcept :
	is_open_(is_open), is_flagged_(is_flagged) {}

	virtual ~TileBase() = default;

	virtual TileType type() const noexcept;
	[[nodiscard]] bool is_open() const noexcept;
	[[nodiscard]] bool is_flagged() const noexcept;

	virtual void open();
	void toggle_flagged();
	virtual void print(std::ostream& os) const noexcept;
};

inline std::ostream& operator<<(std::ostream& os, const TileBase& tile) {
	tile.print(os);
	return os;
}

class TileBomb final : public TileBase {
protected:
	const int bombs_{ TileConstants::TileBomb::bombs };
	bool explode_{ TileConstants::TileBomb::explode };

public:
	explicit TileBomb(const int bombs,
		const bool is_open = TileConstants::TileBomb::is_open,
		const bool is_flagged = TileConstants::TileBomb::is_flagged) noexcept :
	TileBase(is_open, is_flagged), bombs_(bombs) {}

	~TileBomb() override = default;

	TileType type() const noexcept override;
	[[nodiscard]] int bombs() const noexcept;
	void open() override;
	void print(std::ostream& os) const noexcept override;
};

class TileNumber final : public TileBase {
	int bombs_{ TileConstants::TileNumber::bombs };

public:
	explicit TileNumber(const int bombs,
		const bool is_open = TileConstants::TileNumber::is_open,
		const bool is_flagged = TileConstants::TileNumber::is_flagged) noexcept :
	TileBase(is_open, is_flagged), bombs_(bombs) {}

	~TileNumber() override = default;

	void increase_bombs(int to_add = TileConstants::TileNumber::to_add_default);
	TileType type() const noexcept override;
	[[nodiscard]] int bombs() const noexcept;
	void print(std::ostream& os) const noexcept override;
};

