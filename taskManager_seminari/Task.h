#pragma once

class Task {
private:
	char* description;
	int priority;
	bool status;
	int duration;

	void setDescription();
public:
	Task();
	Task(const char* description, int priority, int duration);

	Task(const Task& other);
	Task& operator=(const Task& other);
	~Task();

	const char* getDescription() const;
	int getPriority() const;
	int getDuration() const;


	void setDuration(int duration);
	void setPriority(int priority);
	void makeComplete();
};