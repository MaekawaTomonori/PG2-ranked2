#pragma once
#include "Vector2.h"
#include "Novice.h"

class InputManager{
private:
    InputManager() = default;
	~InputManager() = default;

	// キー入力結果を受け取る箱
	char keys_[256] = {0};
	char preKeys_[256] = {0};

	Vector2Int mousePos_;

public:
    InputManager(const InputManager&) = delete;
	InputManager(const InputManager&&) = delete;
	InputManager& operator=(const InputManager&) = delete;
	InputManager& operator=(const InputManager&&) = delete;

	static  auto& getInstance() {
		static InputManager instance;
		return instance;
	}

	void Update();
	bool isTrigger(int key) const;
	bool isPress(int key) const;
	bool isRelease(int key) const;
};

