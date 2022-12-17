#pragma once

struct Coords {
    void move(int dx, int dy);
    void move(const Coords& delta);

    void move_up(int distance);
    void move_down(int distance);
    void move_left(int distance);
    void move_right(int distance);

    void move_north(int distance);
    void move_south(int distance);
    void move_west(int distance);
    void move_east(int distance);

    int x = 0;
    int y = 0;
};

inline bool operator==(const Coords& lhs, const Coords& rhs) { return lhs.x == rhs.x && lhs.y == rhs.y; }
inline bool operator!=(const Coords& lhs, const Coords& rhs) { return !(lhs == rhs); }
inline bool operator<(const Coords& lhs, const Coords& rhs) { return (lhs.x < rhs.x) || (lhs.x == rhs.x && lhs.y < rhs.y); }
inline bool operator>(const Coords& lhs, const Coords& rhs) { return (lhs.x > rhs.x) || (lhs.x == rhs.x && lhs.y > rhs.y); }

inline Coords operator+(const Coords& lhs, const Coords& rhs) { return Coords{lhs.x + rhs.x, lhs.y + rhs.y}; }
inline Coords operator-(const Coords& lhs, const Coords& rhs) { return Coords{lhs.x - rhs.x, lhs.y - rhs.y}; }

inline Coords& operator+=(Coords& lhs, const Coords& rhs)
{
    lhs.x += rhs.x;
    lhs.y += rhs.y;
    return lhs;
}

inline Coords& operator-=(Coords& lhs, const Coords& rhs)
{
    lhs.x -= rhs.x;
    lhs.y -= rhs.y;
    return lhs;
}
