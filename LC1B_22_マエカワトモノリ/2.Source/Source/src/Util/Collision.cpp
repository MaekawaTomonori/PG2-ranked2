#include "Collision.h"
#include <src/Util/MathUtil.h>

bool Collision::isHitSphere(Entity* e, const Entity* other) {
	float y = e->getPos().y - other->getPos().y,
		x = e->getPos().x - other->getPos().x,
		d = sqrtf(x * x + y * y);

	if (d <= (e->getRadius() + other->getRadius())){
		return true;
	}

    return false;
}
