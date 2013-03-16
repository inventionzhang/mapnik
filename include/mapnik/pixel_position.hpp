/*****************************************************************************
 *
 * This file is part of Mapnik (c++ mapping toolkit)
 *
 * Copyright (C) 2012 Artem Pavlenko
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 *****************************************************************************/
#ifndef MAPNIK_PIXEL_POSITION_HPP
#define MAPNIK_PIXEL_POSITION_HPP

// stl
#include <iomanip>

namespace mapnik
{

struct rotation;
struct pixel_position
{
    double x;
    double y;
    pixel_position(double x_, double y_) : x(x_), y(y_) { }
    pixel_position() : x(0), y(0) { }
    pixel_position operator+ (pixel_position const& other) const
    {
        return pixel_position(x + other.x, y + other.y);
    }

    pixel_position operator- (pixel_position const& other) const
    {
        return pixel_position(x - other.x, y - other.y);
    }

    pixel_position operator* (double other) const
    {
        return pixel_position(x * other, y * other);
    }

    void set(double x_, double y_)
    {
        x = x_;
        y = y_;
    }

    void clear()
    {
        x = 0;
        y = 0;
    }

    pixel_position rotate(rotation const& rot) const;
    pixel_position operator~()
    {
        return pixel_position(x, -y);
    }
};

inline pixel_position operator* (double factor, pixel_position const& pos)
{
    return pixel_position(factor * pos.x, factor * pos.y);
}

template <class charT, class traits>
inline std::basic_ostream<charT,traits>&
operator << (std::basic_ostream<charT,traits>& out,
             const pixel_position& e)
{
    std::basic_ostringstream<charT,traits> s;
    s.copyfmt(out);
    s.width(0);
    s << '(' << std::fixed << std::setprecision(16)
      << e.x << ", " << e.y << ')';
    out << s.str();
    return out;
}

}


#endif // MAPNIK_PIXEL_POSITION_HPP
