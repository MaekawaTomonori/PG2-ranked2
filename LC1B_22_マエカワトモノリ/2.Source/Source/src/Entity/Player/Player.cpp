#include "Player.h"

#include "Novice.h"
#include "src/Entity/Bullet/Bullet.h"
#include "src/Util/MathUtil.h"

#include "src/Util/InputManager.h"
#define inp InputManager::getInstance()

void Player::Init() {
    pos_ = {640, 360};
    velocity_ = {0, 0};
    cooldown_ = 0;
    radius_ = 16;
    bullets_.clear();
}

void Player::Shoot() {
    if (cooldown_ > 0){
        --cooldown_;
        return;
    }
    if (inp.isPress(DIK_SPACE)){
        bullets_.push_back(new Bullet(OwnerType::PLAYER, pos_));
        cooldown_ = 15;
    }
}

void Player::Movement() {
    velocity_ = {
        float(inp.isPress(DIK_D) - inp.isPress(DIK_A)),
        float(inp.isPress(DIK_S) - inp.isPress(DIK_W)),
    };
    velocity_ = MathUtil::Normalize(velocity_);
    velocity_ = velocity_ * 6;

    pos_ += velocity_;

    MathUtil::Clamp({radius_,radius_}, {1280 - radius_, 720 - radius_}, pos_);
}

Player::Player(){
    Init();
}

Player::~Player() {
    bullets_.clear();
}

Entity* Player::Update() {
    Shoot();
    Movement();

    auto itr = bullets_.begin();
    while (itr != bullets_.end()){
        (*itr)->Update();

        if ((*itr)->getPos().y < -radius_ || (*itr)->getPos().y > 720 + radius_){
            itr = bullets_.erase(itr);
            continue;
        }
        ++itr;
    }

    return this;
}

void Player::Draw() {
    for (auto itr = bullets_.begin(); itr != bullets_.end(); ++itr){
        (*itr)->Draw();
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

std::vector<Bullet*> Player::getBullets() const {
    return bullets_;
}
