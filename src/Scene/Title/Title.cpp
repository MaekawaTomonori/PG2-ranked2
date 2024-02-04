#include "Title.h"

#include "Novice.h"
#include "src/Scene/SceneManager.h"
#include "src/Util/Color.h"
#include "src/Util/InputManager.h"

Title::Title()
    :IScene(STAGE){
    Init();
}

void Title::Init() {
    nextScene_ = STAGE;
}

void Title::Update() {
    if (InputManager::getInstance().isTrigger(DIK_SPACE)){
        SceneManager::GetInstance().SceneSwitch();
    }
}

void Title::Draw() {
    Novice::DrawBox(
        0, 0, 1280, 720,
        0, kWHITE, kFillModeSolid
    );
    Novice::DrawEllipse(
        640, 360,
        40, 40, 0, kAQUA - 0x00000088,
        kFillModeSolid
    );

    Novice::DrawBox(0, 0, 160, 20, 0, kBLACK, kFillModeSolid);
    Novice::ScreenPrintf(0, 0, "[SPACE] : START");
}
