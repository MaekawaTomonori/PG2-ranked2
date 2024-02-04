#pragma once
enum SceneType{
    TITLE,
    STAGE,
};

class IScene{
protected:
    SceneType nextScene_;
public:
    IScene(SceneType type): nextScene_(type) {
    }

    virtual ~IScene() = default;

    virtual void Init() = 0;
    virtual void Update() = 0;
    virtual void Draw() = 0;

    SceneType getNextScene() const {
        return nextScene_;
    }
};

