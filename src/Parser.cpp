// Amy Lewis
// Assignment #1

#include <iostream>
#include <limits>

#include "Parser.hpp"
#include "Camera.hpp"

using namespace std;

void Parse::parseComment(std::stringstream & Stream)
{
	string curLine;
	getline(Stream, curLine);
}

SceneObject* Parse::parseCamera(std::stringstream & Stream)
{
	Camera* camera = new Camera();

	string curWord;
	Stream >> curWord;

	while (curWord != "}")
	{
		if (curWord == "location") 
		{
			camera->location = parseVector(Stream);
		}
		else if (curWord == "up")
		{
			camera->up = parseVector(Stream);
		}
		else if (curWord == "right")
		{
			camera->right = parseVector(Stream);
			cout << camera->right.x << endl;
		}
		else if (curWord == "look_at")
		{
			camera->look_at = parseVector(Stream);
		}
		Stream >> curWord;
	}

	return camera;
}

vec3 Parse::parseVector(std::stringstream & Stream)
{
	vec3 v;
	v.x = v.y = v.z = 0.f;
	std::stringbuf buf;
	string curWord;

	Stream >> curWord;
	curWord = curWord.substr(1);

	for (int i = curWord.size() -1; i >= 0; i--)
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