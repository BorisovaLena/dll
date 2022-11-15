#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Header.h"
#include <malloc.h>

struct People* person;

int main()
{
	system("chcp 1251>nul");
	//read("X:\\4 курс\\сист программ\\dll\\dll\\text1.txt");
	read("X:\\4 курс\\сист программ\\dll\\dll\\111.csv");
	
}

void read(char* filename)
{
	char* str = calloc(100,1);
	int i = 0;
	
	FILE* file = fopen(filename, "r");
	FILE* filerez = fopen("X:\\4 курс\\сист программ\\dll\\dll\\rez.csv", "w");
	FILE* fileIvan = fopen("X:\\4 курс\\сист программ\\dll\\dll\\Ivanovi.csv", "w");
	/*while (fscanf(file, "%s", str) != EOF)
	{
		istr = strtok(str, ";");
		while (istr != NULL)
		{
			printf("%s ", istr);
			istr = strtok(NULL, ";");
		}
		printf("\n");
	}
	fclose(file);*/
	file = fopen(filename, "r");
	while (fscanf(file, "%s", str) != EOF)
	{
		//printf("%s\n", str);
		readStr(str, filerez, fileIvan);
	}
	fclose(filerez);
	fclose(file);
	//printStruct(person);

	return 0;

}

int readStr(char* str, FILE* filerez, FILE* fileIvan)
{
	person = calloc(100, sizeof(char));
	char* istr;
	int i = 0;
	int k = 0;
	int ivan = 0;
	//char* iv= "Иванова";
	istr = strtok(str, ";");
	while (istr != NULL)
	{
		//printf("%s ", istr);
		if (i == 0)
		{
			person->surname = istr;
		}
		if (i == 1)
		{
			if (istr == "Дарья")
			{
				ivan = 1;
			}
			person->name= istr;
		}
		if (i == 2)
		{
			person->patronymic= istr;
		}
		if (i == 3)
		{
			person->age = atoi(istr);
		}
		istr = strtok(NULL, ";");
		i++;
	}
	printStruct(person);
	write(person, filerez);
	search(person);
	printf("\n");
}

int printStruct(struct People* person)
{
	printf("%s ", person->surname);
	printf("%s ", person->name);
	printf("%s ", person->patronymic);
	printf("%d ", person->age);
	person++;
}

int write(struct People* person, FILE* file)
{
	char* str = calloc(100, sizeof(char));
	sprintf(str, "%s;%s;%s;%d", person->surname, person->name, person->patronymic, person->age);
	fprintf(file, str);
	fprintf(file, "\n");
}

int search(struct People* person, FILE* fileIvan)
{
	if (person->surname == "Иванов")
	{
		write(person, fileIvan);
	}
}

