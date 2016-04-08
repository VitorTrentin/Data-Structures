
#include <string.h>
#include <stdio.h>
#define ARRAYSTRUCT 10000
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct PalavrasLidas {
    char palavraSalva[50];
    int frequencia=0;
};

int main(int argc, char** argv) {
	char palavra[50];
	PalavrasLidas palavras[ARRAYSTRUCT];
	
	for(int k=0;k<ARRAYSTRUCT;k++) {
		palavras[k].palavraSalva[0] = '\0';	
	}	

	int i;
	int salvo;
	while(!feof(stdin)) {
		if(scanf("%s", palavra) == 1) {
			for(int j=0;j<ARRAYSTRUCT;j++){
				if(strcmp(palavra, palavras[j].palavraSalva)==0){
					palavras[j].frequencia++;
					salvo=1;
				}
			}
				if (salvo==0){
                    strcpy(palavras[i].palavraSalva, palavra);
                    palavras[i].frequencia=1;
                    i++;
                }
            }
            salvo=0;
	}
			
	char auxC[50];
	int auxI;
	for(int j=0;j<ARRAYSTRUCT;j++){
		if(palavras[j].frequencia<palavras[j+1].frequencia){
			strcpy(auxC,palavras[j].palavraSalva);
			strcpy(palavras[j].palavraSalva, palavras[j+1].palavraSalva);
			strcpy(palavras[j+1].palavraSalva, auxC);
			
			auxI=palavras[j].frequencia;
			palavras[j].frequencia=palavras[j+1].frequencia;
			palavras[j+1].frequencia=auxI;
			j=-1;
		}
}
	for(int j=0;j<10;j++){
		if(palavras[j].frequencia!=0) {
			printf("%s",palavras[j].palavraSalva);
			printf(" %i\n",palavras[j].frequencia); 
			
		}
	}
	return 0;
}

