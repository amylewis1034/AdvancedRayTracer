// Amy Lewis
// Assignment #1

#ifndef SCENEOBJECT_H
#define SCENEOBJECT_H

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <string>
#include <sstream>

class SceneObject
{

public:
	virtual std::string to_string() const = 0;
	virtual ~SceneObject() { }
};
#endif