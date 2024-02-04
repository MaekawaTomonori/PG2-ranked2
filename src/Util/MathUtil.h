#pragma once
#define _USE_MATH_DEFINES
#include <cmath>

#include "Vector2.h"

namespace MathUtil{
    int Clamp(const int& min, const int& max, int& value);
    unsigned Clamp(const unsigned min, const unsigned max, unsigned value);
    float Clamp(const float& min, const float& max, float& value);
    Vector2 Clamp(const Vector2& min, const Vector2& max, Vector2& value);

    float Length(Vector2 vector);
    Vector2 Normalize(Vector2& vector);
};

