#include "Enemy.h"

#include "Novice.h"
#include "src/Util/MathUtil.h"

void Enemy::Init() {
    pos_ = {640, 250};
    velocity_ = {5, 0};
    radius_ = 14;
    color_ = kRED;
    downTimer_ = 0;
}

Enemy::Enemy() {
    Enemy::Init();
}

Entity* Enemy::Update() {
    if(downTimer_ > 0){
        --downTimer_;

        if(downTimer_ == 0){
            Init();
        }

        return this;
    }
    pos_ += velocity_;

    if(pos_.x <= radius_ || pos_.x >= 1280 - radius_){
        velocity_ = velocity_ * -1;
    }

    MathUtil::Clamp({radius_, radius_}, {1280 - radius_, 720 - radius_}, pos_);

    return this;
}

void Enemy::Draw() {
    if(downTimer_ > 0){
        return;
    }
    Novice::DrawEllipse(
        int(pos_.x),
        int(pos_.y),
        int(radius_),
        int(radius_),
        0, color_.to_int(),
        kFillModeSolid
    );
}

void Enemy::onDamage() {
    downTimer_ = 60;
    color_.set(RED, 120);
}
