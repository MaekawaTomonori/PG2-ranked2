#pragma once
#include <vector>

#include "src/Entity/Entity.h"
#include "src/Entity/Bullet/Bullet.h"

class Enemy :
    public Entity{
protected:
    void Init() override;

    std::vector<Bullet*> bullets_;
    unsigned downTimer_;
public:
    Enemy();
    Entity* Update() override;
    void Draw() override;

    void onDamage();
};

