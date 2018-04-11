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

SceneObject Parse::parseCamera(std::stringstream & Stream)
{
	Camera camera;

	string curWord;
	Stream >> curWord;

	while (curWord != "}")
	{
		if (curWord == "location") 
		{
			//Stream >> curWord;
			camera.location = parseVector(Stream);
			cout << camera.location.x << endl;
			cout << camera.location.y << endl;
			cout << camera.location.z << endl;
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