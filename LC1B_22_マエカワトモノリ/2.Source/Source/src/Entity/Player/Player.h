#pragma once
#include <vector>

#include "src/Entity/Entity.h"

class Bullet;
class Player final :
    public Entity{
protected:
    void Init() override;

    void Shoot();
    void Movement();

    std::vector<Bullet*> bullets_;
    unsigned cooldown_;
public:
    Player();
    ~Player() override;
    Entity* Update() override;
    void Draw() override;

    std::vector<Bullet*> getBullets() const;
};

