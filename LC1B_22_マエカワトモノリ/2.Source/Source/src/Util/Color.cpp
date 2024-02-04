#include "Color.h"

#include "MathUtil.h"

Color::Color(unsigned color) {
    red_ = (color >> 24) & 0xFF;
    green_ = (color >> 16) & 0xFF;
    blue_ = (color >> 8) & 0xFF;
    alpha_ = color & 0xFF;

}

Color::Color(unsigned r, unsigned g, unsigned b, unsigned a) {
    red_ = r;
    green_ = g;
    blue_ = b;
    alpha_ = a;
}

int Color::to_int() const {
    const unsigned min = 0;
    const unsigned max = 255;
    MathUtil::Clamp(min, max, red_);
    MathUtil::Clamp(min, max, green_);
    MathUtil::Clamp(min, max, blue_);
    MathUtil::Clamp(min, max, alpha_);


    return (red_ << 24) + (green_ << 16) + (blue_ << 8) + alpha_;
}

void Color::set(PrimaryColors type, unsigned value) {
    switch (type){
    case RED:
        red_ = value;
        break;
    case GREEN:
        green_ = value;
        break;
    case BLUE:
        blue_ = value;
        break;
    case ALPHA:
        alpha_ = value;
        break;
    }
}
