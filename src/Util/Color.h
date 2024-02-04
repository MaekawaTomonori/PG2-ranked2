#pragma once

#define kWHITE 0xFFFFFFFF
#define kRED 0xFF0000FF
#define kGREEN 0x00FF00FF
#define kBLUE 0x0000FFFF
#define kGRAY 0x555555FF
#define kAQUA 0x00FFFFFF
#define kBLACK 0x000000FF

enum PrimaryColors{
    RED,
    GREEN,
    BLUE,
    ALPHA,
};

class Color{
private:
    unsigned red_;
    unsigned green_;
    unsigned blue_;
    unsigned alpha_;

public:
    Color()
        :red_(255),
        green_(255),
        blue_(255),
        alpha_(255) {
    }
    Color(unsigned color);
    Color(unsigned r, unsigned g, unsigned b, unsigned a);

    int to_int() const;

    void set(PrimaryColors type, unsigned value);
};

