#pragma once
#include "src/Scene/IScene.h"

class Title final :
    public IScene{
public:
    Title();
    void Init() override;
    void Update() override;
    void Draw() override;
};