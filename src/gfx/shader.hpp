#pragma once

#include <glad/glad.h> // include glad to get all the required OpenGL headers
#include <cglm/cglm.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;
class Shader {
	public:
		Shader();
		// Shader(const char* vertexPath, const char* fragmentPath);

		//void setBool(const std::string& name, bool value) const; 
		void setShader(const char* vertexPath, const char* fragmentPath);
		void setInt(const std::string& name, int value) const;
		void setVec3(const std::string& name, const vec3 &vec3) const;
		void setMat4(const std::string &name, const mat4 &mat) const;
		void use();

		unsigned int getID() const;

	private:
		unsigned int ID;
		void checkErrors(unsigned int shader, std::string type);
};





