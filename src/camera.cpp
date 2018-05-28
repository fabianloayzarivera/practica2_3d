#include "camera.h"

Camera::Camera(const float width, const float height) 
{
	projection = glm::perspective(glm::radians(60.0f), (width / height), 0.1f, 1000.0f);

}

void Camera::prepare() 
{
	State::projectionMatrix = this->getProjection();
	glm::mat4 view = glm::mat4();
	view = glm::lookAt(glm::vec3(0, 0, 6), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0)); //NEED TO CHANGE THIS
	State::viewMatrix = view;

	glViewport(viewport.x, viewport.y, viewport.z, viewport.w);
	glScissor(viewport.x, viewport.y, viewport.z, viewport.w);


	glClearColor(color.x, color.y, color.z, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}