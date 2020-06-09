

#ifndef HEADER_H
#define HEADER_H
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>


typedef struct programeri {

	unsigned int id;
	char ime[31];
	char prezime[31];
	char vrstaDevelopera[51];
	char placa[14];

}PROGRAMERI;

int login();
void ispisKorisnika(char*, unsigned int*);
void fileCheck(char*, unsigned int*);
void addDeveloper(char*, unsigned int*);
void readDevelopersName(char*, unsigned int*);
void fileExit(void);
void readDevelopersJob(char*, unsigned int*);
void deleteDeveloper(char*, unsigned int*);
void izbornik(char*, unsigned int*);

#endif HEADER_H
