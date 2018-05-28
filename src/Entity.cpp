#include "Entity.h"

void Entity::move(const glm::vec3& vec) 
{
	position += rotation * vec;
}