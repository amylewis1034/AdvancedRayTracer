// Amy Lewis
// Assignment #1

#ifndef SPHERE_H
#define SPHERE_H

#include <string>
#include <sstream>

#include "Geometry.hpp"

class Sphere : public Geometry
{

public:
	float radius;
	glm::vec3 center;

	virtual std::string to_string() const override
	{
		std::string rad = std::to_string(radius);

		std::string centerX = std::to_string(center.x);
		std::string centerY = std::to_string(center.y);
		std::string centerZ = std::to_string(center.z);

		std::string pigR = std::to_string(pigment.colorRGB.r);
		std::string pigG = std::to_string(pigment.colorRGB.g);
		std::string pigB = std::to_string(pigment.colorRGB.b);

		std::string ambient = std::to_string(finish.ambient);
		std::string diffuse = std::to_string(finish.diffuse);

		return "- Center: {" + centerX + " " + centerY + " " + centerZ + "}\n"
			 + "- Radius: " + rad + "\n"
			 + "- Color: {" + pigR + " " + pigG + " " + pigB + "}\n"
			 + "- Material:\n"
			 + "  - Ambient: " + ambient + "\n"
			 + "  - Diffuse: " + diffuse + "\n";
	}
};

#endif