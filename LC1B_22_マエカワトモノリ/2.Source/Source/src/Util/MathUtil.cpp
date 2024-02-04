#include "MathUtil.h"

int MathUtil::Clamp(const int& min, const int& max, int& value) {
    if (value < min){value = min;}
    else if (max < value){value = max;}

    return value;
}

unsigned MathUtil::Clamp(const unsigned min, const unsigned max, unsigned value) {
    if (value < min){value = min;}
    if (max < value){value = max;}

    return value;
}

float MathUtil::Clamp(const float& min, const float& max, float& value) {
    if (value < min){value = min;}
    else if (max < value){value = max;}

    return value;
}

Vector2 MathUtil::Clamp(const Vector2& min, const Vector2& max, Vector2& value) {
    if (value.x < min.x){value.x = min.x;}
    if (value.y < min.y){value.y = min.y;}
    if (max.x < value.x){value.x = max.x;}
    if (max.y < value.y){value.y = max.y;}

    return value;
}

float MathUtil::Length(Vector2 vector) {
    return sqrtf(vector.x * vector.x + vector.y * vector.y);
}

Vector2 MathUtil::Normalize(Vector2& vector) {
    const float len= Length(vector);
    return len >= 0.001f ? vector / len : vector;
}
