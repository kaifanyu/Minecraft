#include "shader.hpp"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

Shader::Shader(const char* vertexPath, const char* fragmentPath)
{
	string vertexCode;
	string fragmentCode;

	ifstream vShaderFile;
	ifstream fShaderFile;

	//exceptions
	vShaderFile.exceptions(ifstream::failbit | std::ifstream::badbit);
	fShaderFile.exceptions(ifstream::failbit | std::ifstream::badbit);

	try
	{
		vShaderFile.open(vertexPath);
		fShaderFile.open(fragmentPath);
		stringstream vShaderStream, fShaderStream;

		vShaderStream << vShaderFile.rdbuf();
		fShaderStream << fShaderFile.rdbuf();

		vShaderFile.close();
		fShaderFile.close();

		vertexCode = vShaderStream.str();
		fragmentCode = fShaderStream.str();
	}
	catch (ifstream::failure* e)
	{
		std::cout << "ERROR::SHADER::FILE_NOT_READ: " << e->what() << endl;
	}


	const char* vertexShaderSource = vertexCode.c_str();
	const char* fragmentShaderSource = fragmentCode.c_str();
	
	//create and compile vertex shader
	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);   //create the shader
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);     //add our shader source code into shader
	glCompileShader(vertexShader);                                  //compile it

	checkErrors(vertexShader, "shader");
	//create and compile fragment shader
	unsigned int fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	checkErrors(fragmentShader, "shader");
	ID = glCreateProgram();
	glAttachShader(ID, vertexShader);
	glAttachShader(ID, fragmentShader);
	glLinkProgram(ID);

	checkErrors(ID, "program");
	glUseProgram(ID);
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}


void Shader::use()
{
	glUseProgram(ID);
}

void Shader::setInt(const std::string &name, int value) const
{ 
	glUniform1i(glGetUniformLocation(ID, name.c_str()), value); 
}

void Shader::setVec3(const std::string &name, const vec3 &vec3) const
{
	glUniform3f(glGetUniformLocation(ID, name.c_str()), vec3[0], vec3[1], vec3[2]);
}

void Shader::setMat4(const std::string &name, const mat4 &mat4 ) const
{
	glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, (const float*)mat4);
}

void Shader::checkErrors(unsigned int shader, string type)
{
	int success;
	char infoLog[1024];

	if (type == "shader")
	{
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(shader, 1024, NULL, infoLog);
			cout << "ERROR::SHADER_COMPILATION_ERROR TYPE: " << type << "\n" << infoLog << endl;
		}
	}
	else
	{
		glGetProgramiv(shader, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(shader, 1024, NULL, infoLog);
			cout << "ERROR::PROGRAM_COMPILATION_ERROR TYPE: " << type << "\n" << infoLog << endl;

		}
	}
}