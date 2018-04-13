// Amy Lewis
// Assignment #1

#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <sstream>

#include "SceneObject.hpp"
#include "Geometry.hpp"
#include "Camera.hpp"
#include "Light_Source.hpp"
#include "Sphere.hpp"
#include "Plane.hpp"

class Parse
{

public:

	Parse() {}

	static void parseComment(std::stringstream & Stream);

	static Camera* parseCamera(std::stringstream & Stream);

	static Light_Source* parseLightSource(std::stringstream & Stream);

	static Sphere* parseSphere(std::stringstream & Stream);

	static Plane* parsePlane(std::stringstream & Stream);

	static glm::vec3 parseVector3(std::stringstream & Stream);

	static glm::vec4 parseVector4(std::stringstream & Stream);

    static Pigment parsePigment(std::stringstream & Stream);

	static Finish parseFinish(std::stringstream & Stream);

};

#endif