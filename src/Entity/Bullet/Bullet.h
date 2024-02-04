#pragma once
#include "src/Entity/Entity.h"

enum class OwnerType{
    PLAYER,
    ENEMY,
};

class Bullet :
    public Entity{
protected:
    void Init() override;

    OwnerType owner_;
public:
    Bullet(OwnerType type, Vector2 pos);
    Entity* Update() override;
    void Draw() override;
};

