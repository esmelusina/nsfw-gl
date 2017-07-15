#define GLEW_STATIC
#define STB_IMAGE_IMPLEMENTATION


#include "nsfw\test.h"

#include "GL\glew.h"
#include "GLFW\glfw3.h"

#include "stb\stb_image.h"

#include "glm\glm.hpp"
#include "glm\ext.hpp"

#include "assimp\cimport.h"
#include "assimp\scene.h"
#include "assimp\postprocess.h"

/*

*/
void test_linkages()
{
	glfwInit();
	glewInit();
	glfwTerminate();
	glm::mat4 d = glm::translate(glm::vec3(1,1,1));

	stbi_set_flip_vertically_on_load(true);
	
	aiMatrix4x4 mat;
	aiIdentityMatrix4(&mat);
	//aiImportFile(nullptr, 0);
}