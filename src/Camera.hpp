// Amy Lewis
// Assignment #1

#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <string>
#include <sstream>

#include "SceneObject.hpp"

class Camera
{

public:
	glm::vec3 location;
	glm::vec3 up;
	glm::vec3 right;
	glm::vec3 look_at;

	std::string to_string() const;
};

#endif