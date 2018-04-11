// Amy Lewis
// Assignment #1

#ifndef SPHERE_H
#define SPHERE_H

#include <string>
#include <sstream>

#include "SceneObject.hpp"

class Sphere : public SceneObject
{

public:
	float radius;
	vec3 center;
};

#endif