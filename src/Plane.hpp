// Amy Lewis
// Assignment #1

#ifndef PLANE_H
#define PLANE_H

#include <string>
#include <sstream>

#include "Geometry.hpp"

class Plane : public Geometry
{

public:
	glm::vec3 normal;
	float distance;

	virtual std::string to_string() const override
	{
		std::string dist = std::to_string(distance);

		std::string normalX = std::to_string(normal.x);
		std::string normalY = std::to_string(normal.y);
		std::string normalZ = std::to_string(normal.z);

		std::string pigR = std::to_string(pigment.colorRGB.r);
		std::string pigG = std::to_string(pigment.colorRGB.g);
		std::string pigB = std::to_string(pigment.colorRGB.b);

		std::string ambient = std::to_string(finish.ambient);
		std::string diffuse = std::to_string(finish.diffuse);

		return "- Normal: {" + normalX + " " + normalY + " " + normalZ + "}\n"
			 + "- Distance: " + dist + "\n"
		 	 + "- Color: {" + pigR + " " + pigG + " " + pigB + "}\n"
			 + "- Material:\n"
			 + "  - Ambient: " + ambient + "\n"
			 + "  - Diffuse: " + diffuse + "\n";
	}
};

#endif