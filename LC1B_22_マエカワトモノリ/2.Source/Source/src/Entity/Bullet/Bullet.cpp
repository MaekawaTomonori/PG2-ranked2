#include "Bullet.h"

#include "Novice.h"

void Bullet::Init() {
    if(owner_ == OwnerType::ENEMY){
        color_ = kRED;
        velocity_ = velocity_ * -1;
    }
}

Bullet::Bullet(OwnerType type, Vector2 pos) {
    Bullet::Init();
    owner_ = type;
    pos_ = pos;
    velocity_ = {0, -7};
    radius_ = 3;
}

Entity* Bullet::Update() {
    pos_ += velocity_;
    return this;
}

void Bullet::Draw() {
    Novice::DrawEllipse(
        int(pos_.x),
        int(pos_.y),
        int(radius_),
        int(radius_),
        0, color_.to_int(),
        kFillModeSolid
    );
}
