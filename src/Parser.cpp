// Amy Lewis
// Assignment #1

#include <iostream>
#include <limits>

#include "Parser.hpp"
#include "Camera.hpp"
#include "Light_Source.hpp"
#include "Sphere.hpp"
#include "Plane.hpp"

using namespace std;
using namespace glm;

void Parse::parseComment(std::stringstream & Stream)
{
	string curLine;
	getline(Stream, curLine);
}

Camera* Parse::parseCamera(std::stringstream & Stream)
{
	Camera* camera = new Camera();

	string curWord;
	Stream >> curWord;

	while (curWord != "}")
	{
		if (curWord == "location") 
		{
			camera->location = parseVector3(Stream);
		}
		else if (curWord == "up")
		{
			camera->up = parseVector3(Stream);
		}
		else if (curWord == "right")
		{
			camera->right = parseVector3(Stream);
		}
		else if (curWord == "look_at")
		{
			camera->look_at = parseVector3(Stream);
		}
		Stream >> curWord;
	}

	return camera;
}

Light_Source* Parse::parseLightSource(std::stringstream & Stream)
{
	Light_Source* light = new Light_Source();

	light->pos = parseVector3(Stream);

	string curWord;
	Stream >> curWord;

	while (curWord != "}")
	{
		if (curWord == "rgb")
		{
			light->color = parseVector3(Stream);
		}
		Stream >> curWord;
	}

	return light;
}

Sphere* Parse::parseSphere(std::stringstream & Stream)
{
	Sphere* sphere = new Sphere();

	sphere->center = parseVector3(Stream);

	string curWord;
	Stream >> curWord >> curWord;
	std::string::size_type sz;

	sphere->radius = stof(curWord, &sz);
	Stream >> curWord;

	while (curWord != "}")
	{
		if (curWord == "rotate")
		{
			sphere->rotate = parseVector3(Stream);
		}
		else if (curWord == "scale")
		{
			sphere->scale = parseVector3(Stream);
		}
		else if (curWord == "translate")
		{
			sphere->translate = parseVector3(Stream);
		}
		else if (curWord == "pigment")
		{
			sphere->pigment = parsePigment(Stream);
		}
		else if (curWord == "finish")
		{
			sphere->finish = parseFinish(Stream);
		}
		Stream >> curWord;
	}

	return sphere;
}

Plane* Parse::parsePlane(std::stringstream & Stream)
{
	Plane* plane = new Plane();

	plane->normal = parseVector3(Stream);

	string curWord;
	Stream >> curWord >> curWord;

	std::string::size_type sz;
	plane->distance = stof(curWord, &sz);

	Stream >> curWord;

	while (curWord != "}")
	{
		if (curWord == "pigment")
		{
			plane->pigment = parsePigment(Stream);
		}
		else if (curWord == "finish")
		{
			plane->finish = parseFinish(Stream);
		}
		Stream >> curWord;
	}

	return plane;
}

vec3 Parse::parseVector3(std::stringstream & Stream)
{
	vec3 v;
	v.x = v.y = v.z = 0.f;
	std::stringbuf buf;
	string curWord;

	Stream >> curWord;
	
	if (curWord[0] == '{')
	{
		curWord = curWord.substr(2);
	}
	else
	{
		curWord = curWord.substr(1);
	}

	for (int i = curWord.size() - 1; i >= 0; i--)
	{
		Stream.putback(curWord[i]);
	}

	Stream.get(buf, '>');
	Stream.ignore(numeric_limits<streamsize>::max(), '>');

	string line = buf.str(); // be careful...
	int read = sscanf(line.c_str(), "%f, %f, %f", &v.x, &v.y, &v.z);

	if (read != 3)
	{
		cerr << "Expected to read 3 vector elements but found '" << line << "'" << endl;
	}

	return v;
}

vec4 Parse::parseVector4(std::stringstream & Stream)
{
	vec4 v;
	v.x = v.y = v.z = v.a = 0.f;
	std::stringbuf buf;
	string curWord;

	Stream >> curWord;

	if (curWord[0] == '{')
	{
		curWord = curWord.substr(2);
	}
	else
	{
		curWord = curWord.substr(1);
	}

	for (int i = curWord.size() - 1; i >= 0; i--)
	{
		Stream.putback(curWord[i]);
	}

	Stream.get(buf, '>');
	Stream.ignore(numeric_limits<streamsize>::max(), '>');

	string line = buf.str(); // be careful...
	int read = sscanf(line.c_str(), "%f, %f, %f, %f", &v.x, &v.y, &v.z, &v.a);

	if (read != 4)
	{
		cerr << "Expected to read 4 vector elements but found '" << line << "'" << endl;
	}

	return v;
}

Pigment Parse::parsePigment(std::stringstream & Stream)
{
	Pigment* pigment = new Pigment();

	string curWord;
	Stream >> curWord;

	if (curWord == "{") 
	{
		Stream >> curWord;
	}
	else
	{
		curWord = curWord.substr(1);
	}

	if (curWord == "color")
	{
		Stream >> curWord;
		while (curWord != "}")
		{
			if (curWord == "rgb")
			{
				pigment->colorRGB = parseVector3(Stream);
			}
			else if (curWord == "rgbf")
			{
				pigment->colorRGBF = parseVector4(Stream);
			}
			Stream >> curWord;
		}
	}

	return *pigment;
}


Finish Parse::parseFinish(std::stringstream & Stream)
{
	Finish* finish = new Finish();

	Stream.ignore(1, '{');
	char buf[512];
	Stream.get(buf, 512, '}');

	stringstream properties(buf);
	std::string::size_type sz;

	string curWord;
	while (properties >> curWord) {
		if (curWord[0] == '{')
		{
			curWord = curWord.substr(1);
		}
		
		if (curWord == "ambient")
		{
			properties >> curWord;
			finish->ambient = stof(curWord, &sz);
		}
		else if (curWord == "diffuse")
		{
			properties >> curWord;
			finish->diffuse = stof(curWord, &sz);
		}
		else if (curWord == "reflection")
		{
			properties >> curWord;
			finish->reflection = stof(curWord, &sz);
		}
		else if (curWord == "specular")
		{
			properties >> curWord;
			finish->specular = stof(curWord, &sz);
		}
		else if (curWord == "roughness")
		{
			properties >> curWord;
			finish->roughness = stof(curWord, &sz);
		}
		else if (curWord == "refraction")
		{
			properties >> curWord;
			finish->refraction = stof(curWord, &sz);
		}
		else if (curWord == "ior")
		{
			properties >> curWord;
			finish->ior = stof(curWord, &sz);
		}
	}
	Stream.ignore(1, '}');

	return *finish;
}