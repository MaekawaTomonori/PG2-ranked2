#pragma once
#include "Vector2.h"
#include "src/Util/Color.h"

class Entity {
protected:
    Entity()
        :pos_(0,0), velocity_(0,0), radius_(8),color_(kWHITE) {
    }

    Vector2 pos_;
    Vector2 velocity_;
    float radius_;
    Color color_;

    virtual void Init() = 0;

public:
    virtual ~Entity() = default;
    virtual Entity* Update() = 0;
    virtual void Draw() = 0;

    Vector2 getPos() const {
        return pos_;
    }
    float getRadius() const {
        return radius_;
    }
};

