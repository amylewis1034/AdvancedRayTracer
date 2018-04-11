// Amy Lewis
// Assignment #1

#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <sstream>

#include "SceneObject.hpp"

class Parse
{

public:

	Parse() {}

	static void parseComment(std::stringstream & Stream);

	static SceneObject* parseCamera(std::stringstream & Stream);

	static vec3 parseVector(std::stringstream & Stream);

   // static vec3 parsePigment(std::stringstream & Stream);

};

#endif