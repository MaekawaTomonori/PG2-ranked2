#pragma once
#include "src/Entity/Enemy/Enemy.h"
#include "src/Entity/Player/Player.h"
#include "src/Scene/IScene.h"

class Stage final :
    public IScene{
protected:
    Player* player_;
    Enemy* enemy_;

    bool collision();
public:
    Stage();
    ~Stage() override;
    void Init() override;
    void Update() override;
    void Draw() override;
};

