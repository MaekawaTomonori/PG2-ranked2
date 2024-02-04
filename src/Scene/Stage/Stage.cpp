#include "Stage.h"

#include "Novice.h"
#include "src/Scene/SceneManager.h"
#include "src/Util/Collision.h"
#include "src/Util/InputManager.h"

bool Stage::collision() {

    if(Collision::isHitSphere(player_, enemy_)){
        return true;
    }

    if(!player_->getBullets().empty()){
        auto bullets = player_->getBullets();
        auto itr = bullets.begin();
        while(itr != bullets.end()){
            if (Collision::isHitSphere(enemy_, (*itr))){
                enemy_->onDamage();
                itr = bullets.erase(itr);
                //1frame / 1hit
                return true;
            }
            ++itr;
        }
    }
    return false;
}

Stage::Stage()
    :IScene(TITLE){
    Init();
}

Stage::~Stage() {
    delete player_;
    delete enemy_;
}

void Stage::Init() {
    player_ = new Player();
    enemy_ = new Enemy();
}

void Stage::Update() {
    enemy_->Update();
    player_->Update();

    if (collision() || InputManager::getInstance().isTrigger(DIK_R)){
        SceneManager::GetInstance().SceneSwitch();
        return;
    }
}

void Stage::Draw() {
    Novice::DrawBox(
        0, 0, 1280, 720,
        0, kGRAY, kFillModeSolid
    );
    enemy_->Draw();
    player_->Draw();

    Novice::ScreenPrintf(0, 0, "[W A S D] : MOVE");
    Novice::ScreenPrintf(0, 20, "[SPACE] : SHOOT");
    Novice::ScreenPrintf(0, 40, "[R] : BACK TO TITLE");
}
