// Amy Lewis
// Assignment #1

#include "Parser.hpp"
#include "SceneObject.hpp"

#include <fstream>
#include <iostream>
#include <sstream>
#include <exception>
#include <string>
#include <vector>

using namespace std;

void init(std::vector<SceneObject*> scene, int argc, char **argv) {
    if (argc == 5 || argv[1] == "raycast") {
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
						SceneObject* camera = Parse::parseCamera(s_stream);
						scene.push_back(camera);
					}
					else if (curWord == "light_source") 
					{
						//cout << "light" << endl;
					}
					else if (curWord == "sphere") 
					{
						//cout << "sphere" << endl;
					}
					else if (curWord == "plane") 
					{
						//cout << "plane" << endl;
					}
				}
				
			
		}
    }
    else {
        cout << "Please use the following syntax: raytrace raycast <input_filename> <width> <height>" << endl;
    }
}

int main(int argc, char **argv) {
	std::vector<SceneObject*> scene;

	init(scene, argc, argv);

	return 0;
}