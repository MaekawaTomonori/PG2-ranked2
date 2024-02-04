#include "InputManager.h"

#include <Novice.h>

void InputManager::Update() {
    // キー入力を受け取る
    memcpy(preKeys_, keys_, 256);
    Novice::GetHitKeyStateAll(keys_);

    Novice::GetMousePosition(&mousePos_.x, &mousePos_.y);
}

bool InputManager::isTrigger(int key) const {
    return !preKeys_[key] && keys_[key];
}

bool InputManager::isPress(int key) const {
    return keys_[key];
}

bool InputManager::isRelease(int key) const {
    return preKeys_[key] && !keys_[key];
}
