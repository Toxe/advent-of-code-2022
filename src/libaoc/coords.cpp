#include "coords.hpp"

void Coords::move(const int dx, const int dy)
{
    x += dx;
    y += dy;
}

void Coords::move(const Coords& delta)
{
    x += delta.x;
    y += delta.y;
}

void Coords::move_horizontally(int distance) { move(distance, 0); }
void Coords::move_vertically(int distance) { move(0, distance); }

void Coords::move_up(const int distance) { move(0, -distance); }
void Coords::move_down(const int distance) { move(0, distance); }
void Coords::move_left(const int distance) { move(-distance, 0); }
void Coords::move_right(const int distance) { move(distance, 0); }

void Coords::move_north(const int distance) { move(0, -distance); }
void Coords::move_south(const int distance) { move(0, distance); }
void Coords::move_west(const int distance) { move(-distance, 0); }
void Coords::move_east(const int distance) { move(distance, 0); }
