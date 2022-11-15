#pragma once

struct People
{
	char* surname;
	char* name;
	char* patronymic;
	int age;
};
void read(char*);
int write(struct People*, FILE*);
int printStruct(struct People*);
int readStr(char*, FILE*);


