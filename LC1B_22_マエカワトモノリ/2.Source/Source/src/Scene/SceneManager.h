#pragma once
#include "src/Scene/IScene.h"

class SceneManager{
private:
    SceneManager() = default;
    ~SceneManager() = default;

    IScene* currentScene_;

public:
    SceneManager(const SceneManager&) = delete;
    SceneManager(const SceneManager&&) = delete;
    SceneManager& operator = (const SceneManager&) = delete;
    SceneManager& operator = (const SceneManager&&) = delete;
    static auto& GetInstance() {
        static SceneManager instance;
        return instance;
    }

    void Init();
    void Update() const;
    void SceneSwitch();
};