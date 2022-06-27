// Include standard headers
#include <stdio.h>
#include <stdlib.h>
#include <time.h>  

#include <iostream>


// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <GLFW/glfw3.h>
GLFWwindow* window;

// Include GLM
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
using namespace glm;

#include <common/shader.hpp>
#include <common/texture.hpp>
#include <vector>

#include <common/objloader.hpp>
#include <common/controls.hpp>
#include <common/vboindexer.hpp>


GLuint vertexbuffer1;
GLuint uvbuffer1;
GLuint normalbuffer1;
GLuint elementbuffer1;
GLuint vertexbuffer2;
GLuint uvbuffer2;
GLuint normalbuffer2;
GLuint elementbuffer2;
float sizing = 0.0;
float sizing2 = 0.0;
const char* filepath;
int countspaces;
int old_countspaces;

void readsphere() {


	std::vector<glm::vec3> indexed_vertices1;
	std::vector<glm::vec2> indexed_uvs1;
	std::vector<glm::vec3> indexed_normals1;
	bool res1 = loadOBJ("redsphere.obj", indexed_vertices1, indexed_uvs1, indexed_normals1);

	std::vector<unsigned short> indices;
	std::vector<glm::vec3> indexed_vertices;
	std::vector<glm::vec2> indexed_uvs;
	std::vector<glm::vec3> indexed_normals;
	indexVBO(indexed_vertices1, indexed_uvs1, indexed_normals1, indices, indexed_vertices, indexed_uvs, indexed_normals);


	glGenBuffers(1, &vertexbuffer1);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer1);
	glBufferData(GL_ARRAY_BUFFER, indexed_vertices.size() * sizeof(glm::vec3), &indexed_vertices[0], GL_STATIC_DRAW);


	glGenBuffers(1, &uvbuffer1);
	glBindBuffer(GL_ARRAY_BUFFER, uvbuffer1);
	glBufferData(GL_ARRAY_BUFFER, indexed_uvs.size() * sizeof(glm::vec2), &indexed_uvs[0], GL_STATIC_DRAW);


	glGenBuffers(1, &normalbuffer1);
	glBindBuffer(GL_ARRAY_BUFFER, normalbuffer1);
	glBufferData(GL_ARRAY_BUFFER, indexed_normals.size() * sizeof(glm::vec3), &indexed_normals[0], GL_STATIC_DRAW);


	// Generate a buffer for the indices as well

	glGenBuffers(1, &elementbuffer1);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementbuffer1);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned short), &indices[0], GL_STATIC_DRAW);


	sizing = indices.size();
}

void readobj(int i) {


	switch (i) {
	case 1: filepath = "cube1.obj";
		break;
	case 2: filepath = "cube2.obj";
		break;
	case 3: filepath = "cube3.obj";
		break;
	case 4: filepath = "cube4.obj";
		break;
	case 5: filepath = "cube5.obj";
		break;
	case 6: filepath = "cube6.obj";
		break;
	case 7: filepath = "cube7.obj";
		break;
	case 8: filepath = "cube8.obj";
		break;
	case 9: filepath = "cube9.obj";
		break;
	case 10: filepath = "cube10.obj";
		break;
	case 11: filepath = "sphere1.obj";
		break;
	case 12: filepath = "sphere2.obj";
		break;
	case 13: filepath = "sphere3.obj";
		break;
	case 14: filepath = "sphere4.obj";
		break;
	case 15: filepath = "sphere5.obj";
		break;
	case 16: filepath = "sphere6.obj";
		break;
	case 17: filepath = "sphere7.obj";
		break;
	case 18: filepath = "sphere8.obj";
		break;
	case 19: filepath = "sphere9.obj";
		break;
	case 20: filepath = "sphere10.obj";
		break;;
	case 21: filepath = "cylinder1.obj";
		break;
	case 22: filepath = "cylinder2.obj";
		break;
	case 23: filepath = "cylinder3.obj";
		break;
	case 24: filepath = "cylinder4.obj";
		break;
	case 25: filepath = "cylinder5.obj";
		break;
	case 26: filepath = "cylinder6.obj";
		break;
	case 27: filepath = "cylinder7.obj";
		break;
	case 28: filepath = "cylinder8.obj";
		break;
	case 29: filepath = "cylinder9.obj";
		break;
	case 30: filepath = "cylinder10.obj";
		break;
	}

	std::vector<glm::vec3> indexed_vertices2;
	std::vector<glm::vec2> indexed_uvs2;
	std::vector<glm::vec3> indexed_normals2;
	bool res1 = loadOBJ(filepath, indexed_vertices2, indexed_uvs2, indexed_normals2);

	std::vector<unsigned short> indices3;
	std::vector<glm::vec3> indexed_vertices3;
	std::vector<glm::vec2> indexed_uvs3;
	std::vector<glm::vec3> indexed_normals3;
	indexVBO(indexed_vertices2, indexed_uvs2, indexed_normals2, indices3, indexed_vertices3, indexed_uvs3, indexed_normals3);


	glGenBuffers(1, &vertexbuffer2);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer2);
	glBufferData(GL_ARRAY_BUFFER, indexed_vertices3.size() * sizeof(glm::vec3), &indexed_vertices3[0], GL_STATIC_DRAW);


	glGenBuffers(1, &uvbuffer2);
	glBindBuffer(GL_ARRAY_BUFFER, uvbuffer2);
	glBufferData(GL_ARRAY_BUFFER, indexed_uvs3.size() * sizeof(glm::vec2), &indexed_uvs3[0], GL_STATIC_DRAW);


	glGenBuffers(1, &normalbuffer2);
	glBindBuffer(GL_ARRAY_BUFFER, normalbuffer2);
	glBufferData(GL_ARRAY_BUFFER, indexed_normals3.size() * sizeof(glm::vec3), &indexed_normals3[0], GL_STATIC_DRAW);


	// Generate a buffer for the indices as well

	glGenBuffers(1, &elementbuffer2);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementbuffer2);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices3.size() * sizeof(unsigned short), &indices3[0], GL_STATIC_DRAW);


	sizing2 = indices3.size();


}

int main(void)
{
	// Initialise GLFW
	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		getchar();
		return -1;
	}

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);



	// OPEN A WIDNOW ##########################################################################
	window = glfwCreateWindow(600, 600, u8"Συγκρουόμενα", NULL, NULL);
	if (window == NULL) {
		fprintf(stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n");
		getchar();
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	// Initialize GLEW
	glewExperimental = true; // Needed for core profile
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		getchar();
		glfwTerminate();
		return -1;
	}

	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	// Hide the mouse and enable unlimited mouvement
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	// Set the mouse at the center of the screen
	glfwPollEvents();
	glfwSetCursorPos(window, 600 / 2, 600 / 2);

	// Black background
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);


	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	// Accept fragment if it closer to the camera than the former one
	glDepthFunc(GL_LESS);

	// Cull triangles which normal is not towards the camera
	glEnable(GL_CULL_FACE);

	//####################################### SCENE CUBE ########################################################
	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	// Create and compile our GLSL program from the shaders
	GLuint programID = LoadShaders("TransformVertexShader.vertexshader", "ColorFragmentShader.fragmentshader");

	// Get a handle for our "MVP" uniform
	GLuint MatrixID = glGetUniformLocation(programID, "MVP");
	GLuint ViewMatrixID = glGetUniformLocation(programID, "V");
	GLuint ModelMatrixID = glGetUniformLocation(programID, "M");

	// Load the texture for scene cube
	GLuint Texture = loadDDS("uvmap.DDS");

	// Get a handle for our "myTextureSampler" uniform
	GLuint TextureID = glGetUniformLocation(programID, "myTextureSampler");

	// Load the texture for small objects
	GLuint Texture1 = loadDDS("uvmap.DDS");

	// Get a handle for our "myTextureSampler" uniform
	GLuint TextureID1 = glGetUniformLocation(programID, "myTextureSampler");

	// Load the texture for sphere
	GLuint Texture2 = loadDDS("uvmap.DDS");

	// Get a handle for our "myTextureSampler" uniform
	GLuint TextureID2 = glGetUniformLocation(programID, "myTextureSampler");

	// Read our .obj file
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> uvs;
	std::vector<glm::vec3> normals; // Won't be used at the moment.
	bool res = loadOBJ("trcube.obj", vertices, uvs, normals);

	GLuint vertexbuffer;
	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);

	GLuint uvbuffer;
	glGenBuffers(1, &uvbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
	glBufferData(GL_ARRAY_BUFFER, uvs.size() * sizeof(glm::vec2), &uvs[0], GL_STATIC_DRAW);

	GLuint normalbuffer;
	glGenBuffers(1, &normalbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, normalbuffer);
	glBufferData(GL_ARRAY_BUFFER, normals.size() * sizeof(glm::vec3), &normals[0], GL_STATIC_DRAW);



	//###################################################################################### SMALLCUBE ####################################
	/* initialize random seed: */
	srand(time(NULL));

	/* generate secret number between 1 and 10: */
	int i = rand() % 30 + 1;
	readobj(i);

	//REDSPHERE----------------------------------------------------------------------------------------------------------------------------------------
	readsphere();
	


	// Get a handle for our "LightPosition" uniform
	glUseProgram(programID);
	GLuint LightID = glGetUniformLocation(programID, "LightPosition_worldspace");



	// For speed computation
	double lastTime = glfwGetTime();//xronos kathe stigmi
	int nbFrames = 0;

	do {


		// Measure speed
		double currentTime = glfwGetTime();
		float deltaTime = float(currentTime - lastTime);
		nbFrames++;
		if (currentTime - lastTime >= 1.0) { // If last prinf() was more than 1sec ago
			// printf and reset
			printf("%f ms/frame\n", 1000.0 / double(nbFrames));
			nbFrames = 0;
			lastTime += 1.0;
		}

		glDisable(GL_LIGHTING);
		// Clear the screen
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glDisable(GL_DEPTH_TEST);
		glDepthMask(GL_FALSE);
		glEnable(GL_BLEND);
		glBlendFunc(GL_ONE_MINUS_SRC_COLOR, GL_ONE_MINUS_SRC_ALPHA);

		// Use our shader
		glUseProgram(programID);


		// Compute the MVP matrix from keyboard and mouse input
		computeMatricesFromInputs();
		glm::mat4 ProjectionMatrix = getProjectionMatrix();
		glm::mat4 ViewMatrix = getViewMatrix();
		glm::mat4 ModelMatrix = glm::mat4(1.0);
		glm::mat4 MVP = ProjectionMatrix * ViewMatrix * ModelMatrix;

		// Send our transformation to the currently bound shader, 
		// in the "MVP" uniform
		glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
		glUniformMatrix4fv(ModelMatrixID, 1, GL_FALSE, &ModelMatrix[0][0]);
		glUniformMatrix4fv(ViewMatrixID, 1, GL_FALSE, &ViewMatrix[0][0]);


		// Bind our texture in Texture Unit 0
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, Texture);
		// Set our "myTextureSampler" sampler to use Texture Unit 0
		glUniform1i(TextureID, 0);



		// 1rst attribute buffer : vertices
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
		glVertexAttribPointer(
			0,                  // attribute
			3,                  // size
			GL_FLOAT,           // type
			GL_FALSE,           // normalized?
			0,                  // stride
			(void*)0            // array buffer offset
		);

		// 2nd attribute buffer : UVs
		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
		glVertexAttribPointer(
			1,                                // attribute
			2,                                // size
			GL_FLOAT,                         // type
			GL_FALSE,                         // normalized?
			0,                                // stride
			(void*)0                          // array buffer offset
		);

		// 3rd attribute buffer : normals
		glEnableVertexAttribArray(2);
		glBindBuffer(GL_ARRAY_BUFFER, normalbuffer);
		glVertexAttribPointer(
			2,                                // attribute
			3,                                // size
			GL_FLOAT,                         // type
			GL_FALSE,                         // normalized?
			0,                                // stride
			(void*)0                          // array buffer offset
		);


		// Draw the triangle !
		glDrawArrays(GL_TRIANGLES, 0, vertices.size());

		glEnable(GL_DEPTH_TEST);
		glDisable(GL_BLEND);
		glDepthMask(GL_TRUE);
		glEnable(GL_LIGHTING);

		glm::vec3 lightPos = glm::vec3(4, 4, 4);
		glUniform3f(LightID, lightPos.x, lightPos.y, lightPos.z);



		//####################### LITTLE OBJECTS############################

		if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
			old_countspaces = countspaces;
			countspaces++;
		}

		if (countspaces == old_countspaces + 1) {

			// Bind our texture in Texture Unit 0
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, Texture1);
			// Set our "myTextureSampler" sampler to use Texture Unit 0
			glUniform1i(TextureID1, 0);

			//################# MOVE########################
			glm::vec3 position = glm::vec3(0, 0, 0);
			float speed = 3.0f;

			//random direction in [0.1,0.9]
			float vx = 0.1 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (0.9 - 0.1)));
			float vy = 0.1 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (0.9 - 0.1)));
			float vz = 0.1 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (0.9 - 0.1)));

		glm:vec3 direction(vx, vy, vz);

			//move around
			glm::mat4 ModelMatrix2 = glm::mat4(1.0);

			for (int i = 0; i < 10; i++) {
				position += direction * speed * deltaTime;

				if (0 < position.x < 100 && 0 < position.y < 100 && 0 < position.z < 100) {
					ModelMatrix2 = glm::translate(ModelMatrix2, (position));
					glm::mat4 MVP2 = ProjectionMatrix * ViewMatrix * ModelMatrix2;
					// Send our transformation to the currently bound shader, 
					// in the "MVP" uniform
					glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP2[0][0]);
					glUniformMatrix4fv(ModelMatrixID, 1, GL_FALSE, &ModelMatrix2[0][0]);
				}
			}



			//################################################################################# END OF MOVEMENT ######


			// The rest is exactly the same as the first object

			// 1rst attribute buffer : vertices
			glEnableVertexAttribArray(0);
			glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer2);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

			// 2nd attribute buffer : UVs
			glEnableVertexAttribArray(1);
			glBindBuffer(GL_ARRAY_BUFFER, uvbuffer2);
			glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);

			// 3rd attribute buffer : normals
			glEnableVertexAttribArray(2);
			glBindBuffer(GL_ARRAY_BUFFER, normalbuffer2);
			glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

			/// Index buffer
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementbuffer2);

			// Draw the triangles !
			glDrawElements(
				GL_TRIANGLES,      // mode
				sizing2,    // count
				GL_UNSIGNED_SHORT, // type
				(void*)0           // element array buffer offset
			);


		}





		
		//################################################ FOR THE RED SPHERE #########################################
		
		// Bind our texture in Texture Unit 0
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, Texture2);
		// Set our "myTextureSampler" sampler to use Texture Unit 0
		glUniform1i(TextureID2, 0);

		//####################### MOVE SPHERE ###################
	   // Initial position : on +Z
		glm::vec3 position1 = glm::vec3(0, 0, 0);
		// Initial horizontal angle : toward -Z
		float horizontalAngle1 = 3.14f;
		// Initial vertical angle : none
		float verticalAngle1 = 0.0f;
		static double lastTime1 = glfwGetTime();

		// Compute time difference between current and last frame
		double currentTime1 = glfwGetTime();
		float deltaTime1 = float(currentTime1 - lastTime1);

		glm::vec3 direction1(
			cos(verticalAngle1) * sin(horizontalAngle1),
			sin(verticalAngle1),
			cos(verticalAngle1) * cos(horizontalAngle1)
		);
		// Right vector
		glm::vec3 right1 = glm::vec3(
			sin(horizontalAngle1 - 3.14f / 2.0f),
			0,
			cos(horizontalAngle1 - 3.14f / 2.0f)
		);

		// Up vector
		glm::vec3 up1 = glm::cross(right1, direction1);
		

		// Move forward(for z)
		if (glfwGetKey(window, GLFW_KEY_EQUAL) == GLFW_PRESS) {
			position1 += position1 + (direction1 * deltaTime1);
		}
		// Move backward(for z)
		if (glfwGetKey(window, GLFW_KEY_MINUS) == GLFW_PRESS) {
			position1 -= direction1 * deltaTime1;
		}
		// Strafe right(for x)
		if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
			position1 += right1 * deltaTime1;
		}
		// Strafe left(for x)
		if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
			position1 -= right1 * deltaTime1;
		}
		//Move up(for y)
		if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
			position1 += up1 * deltaTime1;
		}
		//Move down(for y)
		if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
			position1 -= up1 * deltaTime1;
		}

		glm::mat4 ModelMatrix3 = glm::mat4(1.0);

		ModelMatrix3 = glm::translate(ModelMatrix3, (position1));
		glm::mat4 MVP2 = ProjectionMatrix * ViewMatrix * ModelMatrix3;



		// Send our transformation to the currently bound shader, 
		// in the "MVP" uniform
		glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP2[0][0]);
		glUniformMatrix4fv(ModelMatrixID, 1, GL_FALSE, &ModelMatrix3[0][0]);
		//####################################################################### 

		// The rest is exactly the same as the first object

		// 1rst attribute buffer : vertices
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer1);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

		// 2nd attribute buffer : UVs
		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, uvbuffer1);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);

		// 3rd attribute buffer : normals
		glEnableVertexAttribArray(2);
		glBindBuffer(GL_ARRAY_BUFFER, normalbuffer1);
		glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

		/// Index buffer
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementbuffer1);

		// Draw the triangles !
		glDrawElements(
			GL_TRIANGLES,      // mode
			sizing,    // count
			GL_UNSIGNED_SHORT, // type
			(void*)0           // element array buffer offset
		);
		//################ END FOR RED SPHERE ##############################


		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
		glDisableVertexAttribArray(2);

		// Swap buffers
		glfwSwapBuffers(window);
		glfwPollEvents();
	}// Check if the ESC key was pressed or the window was closed
	while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		glfwWindowShouldClose(window) == 0);

	// Cleanup VBO and shader
	glDeleteBuffers(1, &vertexbuffer);
	glDeleteBuffers(1, &uvbuffer);
	glDeleteBuffers(1, &normalbuffer);

	glDeleteBuffers(1, &vertexbuffer1);
	glDeleteBuffers(1, &uvbuffer1);
	glDeleteBuffers(1, &normalbuffer1);

	glDeleteBuffers(1, &vertexbuffer2);
	glDeleteBuffers(1, &uvbuffer2);
	glDeleteBuffers(1, &normalbuffer2);

	glDeleteBuffers(1, &vertexbuffer2);
	glDeleteBuffers(1, &uvbuffer2);
	glDeleteBuffers(1, &normalbuffer2);

	glDeleteProgram(programID);
	glDeleteTextures(1, &Texture);
	glDeleteTextures(1, &Texture1);
	glDeleteTextures(1, &Texture2);
	glDeleteVertexArrays(1, &VertexArrayID);

	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	return 0;
}