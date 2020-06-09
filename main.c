
#include "Header.h"




int main(void) {
	/*int n = login();
	if (n == 0) {
		printf("Neuspjesan login");
		return 0;
	}*/
	char* programeri = "programeri.bin";
	unsigned int brojKorisnika = 0;

	fileCheck(programeri, &brojKorisnika);
	izbornik(programeri, &brojKorisnika);

	return 0;
}
