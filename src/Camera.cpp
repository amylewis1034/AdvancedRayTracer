// Amy Lewis
// Assignment #1

#include <iostream>
#include <limits>

#include "Camera.hpp"

using namespace std;

 std::string Camera::to_string() const
{
	std::string posX = std::to_string(location.x);
	std::string posY = std::to_string(location.y);
	std::string posZ = std::to_string(location.z);

	std::string upX = std::to_string(up.x);
	std::string upY = std::to_string(up.y);
	std::string upZ = std::to_string(up.z);

	std::string rightX = std::to_string(right.x);
	std::string rightY = std::to_string(right.y);
	std::string rightZ = std::to_string(right.z);

	std::string look_atX = std::to_string(look_at.x);
	std::string look_atY = std::to_string(look_at.y);
	std::string look_atZ = std::to_string(look_at.z);

	return "- Location: {" + posX + " " + posY + " " + posZ + "}\n"
	   	+ "- Up: {" + upX + " " + upY + " " + upZ + "}\n"
		+ "- Right: {" + rightX + " " + rightY + " " + rightZ + "}\n"
		+ "- Look at: {" + look_atX + " " + look_atY + " " + look_atZ + "}\n";
}