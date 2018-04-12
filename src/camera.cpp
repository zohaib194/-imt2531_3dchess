#include "../header/camera.hpp"
#include "../header/globalVar.hpp"
#include "../header/global_function.hpp"


Camera::Camera(glm::vec3 pos, glm::vec3 dir, glm::vec3 up) {
	this->pos = pos;
	this->dir = dir;
	this->up = up;
}

void Camera::setPos(glm::vec3 pos){
	this->pos = pos;
}

void Camera::setDir(glm::vec3 dir){
	this->dir = dir;
}

void Camera::setUp(glm::vec3 up){
	this->up = up;
}

glm::vec3 Camera::getPos(){
	return this->pos;
}

glm::vec3 Camera::getDir(){
	return this->dir;
}

glm::vec3 Camera::getUp(){
	return this->up;
}

glm::mat4 Camera::getViewMatrix(){
	return glm::lookAt(this->pos, this->dir, this->up);
}

glm::mat4 Camera::getPerspectiveMatrix(){
	return glm::perspective(PI / 3.0f, windowSize().x / windowSize().y, 0.1f, -10.0f);	
}