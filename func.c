
#include "Header.h"



//int login() {
//system("cls");

//	char username[15];
//	char password[12];
//	printf("Unesite korisnicko ime: \n");
//	scanf("%14s", username);
//	printf("Unesite lozinku: \n");
//	scanf("%11s", password);
//	if (strcmp(username, "admin") == 0) {
//		if (strcmp(password, "lozinka") == 0) {
//			return 1;
//		}
//	}
//	return 0;
//
//}

void fileCheck(char* file, unsigned int* pBrojDevelopera) {
	system("cls");

	FILE* fp = fopen(file, "rb");

	if (fp == NULL) {

		perror("Datoteka ne postoji prilikom pokretanja");

		fp = fopen(file, "wb");

		if (fp == NULL) {

			perror("Datoteka se ne moze kreirati");
			exit(EXIT_FAILURE);
		}
		else {

			fwrite(pBrojDevelopera, sizeof(unsigned int), 1, fp);
			fclose(fp);
			printf("Datoteka kreirana\n");
		}
	}
	else {

		fread(pBrojDevelopera, sizeof(unsigned int), 1, fp);
		fclose(fp);

	}
}

void addDeveloper(char* file, unsigned int* pBrojDevelopera) {
	system("cls");

	FILE* fp = NULL;
	
	fp = fopen(file, "rb+");

	if (fp == NULL) {
		perror("Dodavanje novog developera");
		return;
		
	}
	else {

		PROGRAMERI pDeveloper = { 0 };
		printf("Unesite ime programera\n");
		scanf("%30s", pDeveloper.ime);
		printf("Unesite prezime programera\n");
		scanf("%30s", pDeveloper.prezime);
		printf("Unesite vrstu developera\n");
		scanf(" %50s", pDeveloper.vrstaDevelopera);
		printf("Unesite placu programera\n");
		scanf("%13s", pDeveloper.placa);
		
		pDeveloper.id = (*pBrojDevelopera)++;

		fseek(fp, sizeof(unsigned int) + ((*pBrojDevelopera - 1) * sizeof(PROGRAMERI)), SEEK_SET);
		fwrite(&pDeveloper, sizeof(PROGRAMERI), 1, fp);
		rewind(fp);
		fwrite(pBrojDevelopera, sizeof(unsigned int), 1, fp);
		fclose(fp);
	}
}

void readDevelopersName(char* file, unsigned int* pBrojDevelopera) {
	system("cls");
	FILE* fp = NULL;
	fp = fopen(file, "rb");

	if (fp == NULL) {

		perror("Izbor 2");
		return;
	
	}
	else {

		PROGRAMERI* Developeri = NULL;

		fread(pBrojDevelopera, sizeof(unsigned int), 1, fp);

		if (*pBrojDevelopera == 0) {

			printf("Nema developera\n");
			fclose(fp);
			return;
		}
		else {

			Developeri = (PROGRAMERI*)calloc(*pBrojDevelopera, sizeof(PROGRAMERI));

			if (Developeri == NULL) {

				perror("citanje developera");
				exit(EXIT_FAILURE);
			}
			else {

				fread(Developeri, sizeof(PROGRAMERI), *pBrojDevelopera, fp);
				fclose(fp);

				unsigned int i;

				printf("Unesite ime korisnika\n");
				char pName[31] = { '\0' };
				scanf("%30s", pName);
				unsigned int statusPronalaska = 0;
				unsigned int indeksPronalaska = -1;

				for (i = 0; i < *pBrojDevelopera; i++)
				{
					if (!strcmp((Developeri + i)->ime, pName)) {
						statusPronalaska = 1;
						indeksPronalaska = i;
					}
				}

				if (statusPronalaska) {
					printf("Korisnik pronadjen\n");
					printf("%u\t", (Developeri + indeksPronalaska)->id);
					printf("%s ", (Developeri + indeksPronalaska)->ime);
					printf("%s ", (Developeri + indeksPronalaska)->prezime);
					printf("%s ", (Developeri + indeksPronalaska)->vrstaDevelopera);
					printf("%s ", (Developeri + indeksPronalaska)->placa);
					
				}
				else {

					printf("Nepostojeci korisnik\n");
				}

				free(Developeri);
			}
		}
	}
}

void readDevelopersJob(char* file, unsigned int* pBrojDevelopera) {
	system("cls");
	FILE* pDatotekaProcitaj = NULL;
	pDatotekaProcitaj = fopen(file, "rb");

	if (pDatotekaProcitaj == NULL) {

		perror("Izbor 2");
		return;
		//exit(EXIT_FAILURE);
	}
	else {

		PROGRAMERI* sviKorisnici = NULL;

		fread(pBrojDevelopera, sizeof(unsigned int), 1, pDatotekaProcitaj);

		if (*pBrojDevelopera == 0) {

			printf("Nema lanova\n");
			fclose(pDatotekaProcitaj);
			return;
		}
		else {

			sviKorisnici = (PROGRAMERI*)calloc(*pBrojDevelopera, sizeof(PROGRAMERI));

			if (sviKorisnici == NULL) {

				perror("Citanje korisnika");
				exit(EXIT_FAILURE);
			}
			else {

				fread(sviKorisnici, sizeof(PROGRAMERI), *pBrojDevelopera, pDatotekaProcitaj);
				fclose(pDatotekaProcitaj);

				unsigned int i;

				printf("Unesite vrstu developera\n");
				char vrstaDevelopera[51] = { '\0' };
				scanf("%50s", vrstaDevelopera);
				unsigned int statusPronalaska = 0;
				unsigned int indeksPronalaska = -1;

				for (i = 0; i < *pBrojDevelopera; i++)
				{
					if (!strcmp((sviKorisnici + i)->vrstaDevelopera, vrstaDevelopera)) {
						indeksPronalaska = i;
						printf("Developer pronadjen\n");
						printf("%u\t", (sviKorisnici + indeksPronalaska)->id);
						printf("%s ", (sviKorisnici + indeksPronalaska)->ime);
						printf("%s ", (sviKorisnici + indeksPronalaska)->prezime);
						printf("%s ", (sviKorisnici + indeksPronalaska)->vrstaDevelopera);
						printf("%s ", (sviKorisnici + indeksPronalaska)->placa);
					}
				}

				free(sviKorisnici);
			}
		}
	}
}

void fileExit(void) {
	system("cls");

	printf("Da li ste sigurni kako zelite zavrsiti program?\n");
	char izbor[3] = { '\0' };
	scanf(" %2s", izbor);
	if (!strcmp("da", izbor)) {
		exit(EXIT_FAILURE);
	}

	return;
}

void ispisKorisnika(char* file, unsigned int* pBrojDevelopera) {
	system("cls");

	FILE* pDatotekaProcitaj = NULL;
	pDatotekaProcitaj = fopen(file, "rb");

	if (pDatotekaProcitaj == NULL) {

		perror("Izbor2");
		return;
		//exit(EXIT_FAILURE);
	}
	else {

		PROGRAMERI* Developeri = NULL;

		fread(pBrojDevelopera, sizeof(unsigned int), 1, pDatotekaProcitaj);

		if (*pBrojDevelopera == 0) {

			printf("Nema clanova\n");
			fclose(pDatotekaProcitaj);
			return;
		}
		else {

			Developeri = (PROGRAMERI*)calloc(*pBrojDevelopera, sizeof(PROGRAMERI));

			if (Developeri == NULL) {

				perror("Citanje korisnika");
				exit(EXIT_FAILURE);
			}
			else {

				fread(Developeri, sizeof(PROGRAMERI), *pBrojDevelopera, pDatotekaProcitaj);
				fclose(pDatotekaProcitaj);

				unsigned int i;



				for (i = 0; i < *pBrojDevelopera; i++)
				{
					printf("%u\t", (Developeri + i)->id);
					printf("%s ", (Developeri + i)->ime);
					printf("%s ", (Developeri + i)->prezime);
					printf("%s ", (Developeri + i)->vrstaDevelopera);
					printf("%s ", (Developeri + i)->placa);
					printf("\n");

				}

			}
		}
	}
}



void izbornik(char* file, unsigned int* pBrojDevelopera) {
	

	unsigned int izbornik = -1;

	while (1) {
		
		printf("\
				\n1. Dodavanje novih developera\
				\n2. Trazenje developera po imenu\
				\n3. Trazenje developera po vrsti\
				\n4. ispis developera\
			    \n5.Zavrsetak programa");

		scanf("%u", &izbornik);

		switch (izbornik) {
		case 1:
			addDeveloper(file, pBrojDevelopera);
			break;
		case 2:
			readDevelopersName(file, pBrojDevelopera);
			break;
		case 3:
			readDevelopersJob(file, pBrojDevelopera);
			break;
		case 4:
			ispisKorisnika(file, pBrojDevelopera);
			break;
		case 5:
			fileExit();
			break;
		default:
			printf("Krivi odabir\n");
		}
	}
}
