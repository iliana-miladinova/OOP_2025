#pragma once
#include <iostream>
#pragma warning (disable: 4996)

class Secret {
private:
	char* task;
	char* password;
	unsigned invalidEntrences;

public:
	Secret();
	Secret(const char* task, const char* password);
	~Secret();

	void freePassword();
	void freeTask();

	void setPassword(const char* password);
	void setTask(const char* task);
	void setInvalidEntrences(unsigned invalidEntrences);

	unsigned getInvalidEntrences() const;
	const char* getPassword() const;
	const char* getTask() const;

	const char* getTask(const char* pwd);
	void setPassword(const char* newPassword, const char* oldPassword);
	void setTask(const char* newTask, const char* password);
	unsigned getLoginFails();
};