////////////////////////////////////////////////////////////////////////////////
// Spine Runtimes Software License
// Version 2.4
//
// Copyright (c) 2013-2016, Esoteric Software
// Copyright (c) 2016, Chobolabs
// All rights reserved.
//
// You are granted a perpetual, non-exclusive, non-sublicensable and
// non-transferable license to use, install, execute and perform the Spine
// Runtimes Software (the "Software") and derivative works solely for personal
// or internal use. Without the written permission of Esoteric Software (see
// Section 2 of the Spine Software License Agreement), you may not (a) modify,
// translate, adapt or otherwise create derivative works, improvements of
// the Software or develop new applications using the Software or (b) remove,
// delete, alter or obscure any trademarks or any copyright, trademark, patent
// or other intellectual property or proprietary rights notices on or in the
// Software, including any copy thereof. Redistributions in binary or source
// form must include this license and terms.
//
// THIS SOFTWARE IS PROVIDED BY ESOTERIC SOFTWARE AND CHOBOLABS "AS IS" AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL ESOTERIC SOFTWARE OR CHOBOLABS BE LIABLE FOR
// ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
////////////////////////////////////////////////////////////////////////////////
#pragma once

#include <cmath>

namespace spine
{

struct Vector
{
    Vector() {}
    Vector(float _x, float _y)
        : x(_x)
        , y(_y)
    {}

    Vector& operator=(const Vector& v)
    {
        x = v.x;
        y = v.y;
        return *this;
    }

    Vector& operator+=(const Vector& v)
    {
        x += v.x;
        y += v.y;
        return *this;
    }

    Vector& operator-=(const Vector& v)
    {
        x -= v.x;
        y -= v.y;
        return *this;
    }

    Vector& operator*=(float f)
    {
        x *= f;
        y *= f;
        return *this;
    }

    Vector& operator/=(float f)
    {
        x /= f;
        y /= f;
        return *this;
    }

    float length() const
    {
        return std::sqrt(x*x + y*y);
    }

    float angle() const
    {
        return std::atan2(y, x);
    }

    float x, y;
};

inline Vector operator+(const Vector& a, const Vector& b)
{
    return Vector(a.x + b.x, a.y + b.y);
}

inline Vector operator-(const Vector& a, const Vector& b)
{
    return Vector(a.x - b.x, a.y - b.y);
}

inline Vector operator*(float a, const Vector& v)
{
    return Vector(a * v.x, a * v.y);
}

inline Vector operator*(const Vector& v, float a)
{
    return Vector(a * v.x, a * v.y);
}

inline Vector operator*(const Vector& a, const Vector& b)
{
    return Vector(a.x * b.x, a.y * b.y);
}

inline bool operator==(const Vector& a, const Vector& b)
{
    return a.x == b.x && a.y == b.y;
}

inline bool operator!=(const Vector& a, const Vector& b)
{
    return a.x != b.x || a.y != b.y;
}

}
