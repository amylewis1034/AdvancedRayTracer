// Amy Lewis
// Assignment #1

#ifndef CAMERA_H
#define CAMERA_H

#include <string>
#include <sstream>

#include "SceneObject.hpp"

class Camera : public SceneObject
{

public:
	vec3 location;
	vec3 up;
	vec3 right;
	vec3 look_at;
};

#endif