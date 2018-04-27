#ifndef ADD_H
#define ADD_H

typedef struct Data
    {
        int id;
        char surname[100];
	char othername[100];
	int age;
	char position[100];
	char errMessage[1000];
    }MY_STRUCT;

extern MY_STRUCT DataArr[1000];

#endif

