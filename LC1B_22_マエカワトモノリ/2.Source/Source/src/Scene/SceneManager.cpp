#include "SceneManager.h"

#include "src/Util/InputManager.h"
#include "Stage/Stage.h"
#include "Title/Title.h"

void SceneManager::Init() {
    currentScene_ = new Title();
}

void SceneManager::Update() const {
    currentScene_->Update();
    currentScene_->Draw();
}

void SceneManager::SceneSwitch() {
    const SceneType next = currentScene_->getNextScene();

    delete currentScene_;

    switch (next){
    case TITLE:
        currentScene_ = new Title();
        break;
    case STAGE:
        currentScene_ = new Stage();
        break;
    }
}
