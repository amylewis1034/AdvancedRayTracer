// Amy Lewis
// Assignment #1

#include "Parser.hpp"
#include "Camera.hpp"
#include "Light_Source.hpp"
#include "SceneObject.hpp"

#include <fstream>
#include <iostream>
#include <sstream>
#include <exception>
#include <string>
#include <vector>

using namespace std;

void parseScene(Camera* & camera, std::vector<Light_Source*> & lights, std::vector<SceneObject*> & scene, int argc, char **argv)
{
    if (argc > 2)
	{
        ifstream in_file;
		stringstream s_stream;

        in_file.open(argv[2]);

		if (!in_file.is_open()) {
			throw (exception("Could not open file"));
		}

		s_stream << in_file.rdbuf();

		if (s_stream)
		{			
				string curWord;
				while (s_stream >> curWord)
				{
					if (curWord[0] == '/' && curWord[1] == '/')
					{
						Parse::parseComment(s_stream);
					}
					else if (curWord == "camera") 
					{
						camera = Parse::parseCamera(s_stream);
					}
					else if (curWord == "light_source") 
					{
						Light_Source* light_source = Parse::parseLightSource(s_stream);
						lights.push_back(light_source);
					}
					else if (curWord == "sphere") 
					{
						Sphere* sphere = Parse::parseSphere(s_stream);
						scene.push_back(sphere);
					}
					else if (curWord == "plane") 
					{
						Plane* plane = Parse::parsePlane(s_stream);
						scene.push_back(plane);
					}
				}
				
			
		}
    }
    else {
        cout << "Please use the following syntax: raytrace <command> <input_filename> <width> <height>" << endl;
    }
}

int main(int argc, char **argv) {
	Camera* camera = new Camera();
	std::vector<Light_Source*> lights;
	std::vector<SceneObject*> scene;

	parseScene(camera, lights, scene, argc, argv);

	if (strcmp(argv[1], "sceneinfo") == 0)
	{
		cout << "Camera:" << endl;
		cout << camera->to_string() << endl;
		cout << "---\n" << endl;

		cout << lights.size() << " light(s)\n" << endl;
		for (int i = 0; i < lights.size(); i++)
		{
			cout << "Light[" + to_string(i) + "]:" << endl;
			cout << lights[i]->to_string() << endl;
		}
		cout << "---\n" << endl;

		cout << scene.size() << " object(s)\n" << endl;
		for (int j = 0; j < scene.size(); j++)
		{
			cout << "Object[" + to_string(j) + "]:" << endl;
			cout << scene[j]->to_string() << endl;
		}
	}

	return 0;
}