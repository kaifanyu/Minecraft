#pragma once

#include <glad/glad.h> // include glad to get all the required OpenGL headers
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;
class Shader
{
public:
	unsigned int ID;

	//read and builds shader


	//void setBool(const std::string& name, bool value) const; 
	void setInt(const std::string& name, int value) const;
	//void setFloat(const std::string& name, int value) const;


	Shader(const char* vertexPath, const char* fragmentPath);


	void use();


private:
	void checkErrors(unsigned int shader, string type);
};





