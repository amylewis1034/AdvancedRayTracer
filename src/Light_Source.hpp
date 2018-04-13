// Amy Lewis
// Assignment #1

#ifndef LIGHT_SOURCE_H
#define LIGHT_SOURCE_H

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <string>
#include <sstream>

class Light_Source
{

public:
	glm::vec3 pos;
	glm::vec3 color;

	virtual std::string to_string() const
	{
		std::string posX = std::to_string(pos.x);
		std::string posY = std::to_string(pos.y);
		std::string posZ = std::to_string(pos.z);

		std::string colorX = std::to_string(color.x);
		std::string colorY = std::to_string(color.y);
		std::string colorZ = std::to_string(color.z);

		return "- Location: {" + posX + " " + posY + " " + posZ + "}\n" 
			 + "- Color: {" + colorX + " " + colorY + " " + colorZ + "}\n";
	}
};

#endif