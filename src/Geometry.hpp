// Amy Lewis
// Assignment #1

#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <string>
#include <sstream>

#include "SceneObject.hpp"

struct Pigment
{
	glm::vec3 colorRGB;
	glm::vec4 colorRGBF;
};

struct Finish 
{
	float ambient;
	float diffuse;
	float reflection;
	float specular;
	float roughness;
	float refraction;
	float ior;
};

class Geometry : public SceneObject
{

public:
	Pigment pigment;
	Finish finish;
	
	glm::vec3 rotate;
	glm::vec3 scale;
	glm::vec3 translate;

	virtual std::string to_string() const = 0;
};

#endif