#include "Secret.h"

void Secret::freePassword() {
    delete[] password;
}

void Secret::freeTask() {
    delete[] task;
}

void Secret::setPassword(const char* password) {
    if (!password) {
        return;
    }
    freePassword();
    this->password = new char[strlen(password) + 1];
    strcpy(this->password, password);
}

void Secret::setTask(const char* task) {
    if (!task) {
        return;
    }
    freeTask();
    this->task = new char[strlen(task) + 1];
    strcpy(this->task, task);
}

//void Secret::setInvalidEntrences(unsigned invalidEnrences) {
//    this->invalidEntrences = invalidEnrences;
//}

unsigned Secret::getInvalidEntrences() const {
    return this->invalidEntrences;
}

const char* Secret::getPassword() const {
    return this->password;
}

const char* Secret::getTask() const {
    return this->task;
}

Secret::Secret() {
    setTask("");
    setPassword("");
    invalidEntrences = 0;
}

Secret::Secret(const char* task, const char* password) {
    setTask(task);

    setPassword(password);

    invalidEntrences = 0;
}

Secret::~Secret() {
    freePassword();
    freeTask();
}

const char* Secret::getTask(const char* pwd) {
    if (!pwd) {
        return nullptr;
    }
    if (strcmp(pwd, this->getPassword()) == 0) {
        return getTask();
    }
    invalidEntrences++;
    std::cout << "Incorrect password" << std::endl;

    return nullptr;
}

void Secret::setPassword(const char* newPassword, const char* oldPassword) {
    if (!newPassword || !oldPassword) {
        return;
    }
    if (strcmp(oldPassword, this->getPassword()) == 0) {
        setPassword(newPassword);
        std::cout << "Password updated to: " << this->password << std::endl;
        return;
    }
    invalidEntrences++;
    std::cout << "Incorrect password" << std::endl;

    return;
}

void Secret::setTask(const char* newTask, const char* password) {
    if (!password) {
        return;
    }
    if (strcmp(password, this->getPassword()) == 0) {
        setTask(newTask);
        std::cout << "Task updated to: " << this->task << std::endl;
        return;
    }
    invalidEntrences++;
    std::cout << "Incorrect password" << std::endl;

    return;
}

unsigned Secret::getLoginFails() {
    return this->getInvalidEntrences();
}