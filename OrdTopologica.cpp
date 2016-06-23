#include <stdio.h>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct celulaLista{
   int chave;
   struct celulaLista *proximo;
}celula;

int main(int argc, char** argv) {
	celula *ptLista[101];
	celula *resposta;
	int gentrada[101];
	int  n,m,i,j,mark[102],tam[101],gsaida[102],tam2=0,comeco=0,vetorVerdices[200], u = 0;;//pra saber quantos elementos tem a i'esima lista

	scanf("%d %d", &n, &m);

    while(n || m ){
        for(int h=1;h<=n;h++){
            gentrada[h]=0;
            tam[h]=0;
            mark[h]=0;
            gsaida[h]=0;
        }
        comeco = 0;
		for(int k=0;k<m;k++){
			scanf("%d %d", &i,&j);
			gentrada[j]++;
			gsaida[i]++;
		//inserindo itens na lista
			if(tam[i]==0){ 
				ptLista[i] = (celula *)malloc(sizeof(celula));
				ptLista[i]->chave = j;  
				tam[i]++;
									
			}else{
				tam[i]++;
				celula *temporario;
				temporario = (celula *)malloc(sizeof(celula));
				temporario->chave = j;
				temporario->proximo = ptLista[i];
				ptLista[i] = temporario;
				temporario = (celula *)NULL;
                free(temporario);
			}

		}
		while(comeco < n){
			for(int k =1; k<=n ; k++){
				if(gentrada[k]==0 and mark[k]==0){
				comeco++;
				mark[k]=1;
					if(tam2==0){
						resposta = (celula *)malloc(sizeof(celula));
						resposta->chave = k;
						tam2++;
					}else{
						tam2++;
						celula *temporario;
						temporario = (celula *)malloc(sizeof(celula));
						temporario->chave = k;
						temporario->proximo = resposta;
						resposta = temporario;
						temporario = (celula *)NULL;
						free(temporario);
					}
					vetorVerdices[u]=k;//base de onde printa as respostas
					u++;
                }

			}


		// Removendo
		while(tam2>0){ 
            celula *aux;
            aux=resposta->proximo;
            int v = resposta->chave;
            tam2--;
            resposta->proximo=(celula*)NULL;
            resposta=aux;
			celula *percorredor;
			for(percorredor = ptLista[v]; percorredor!=(celula*)NULL and gsaida[v]!=0; percorredor=percorredor->proximo){
                gentrada[percorredor->chave]--;
                gsaida[v]--;
			}
		}
	}
	for(int i = 0 ; i < u ; i++)
        if(i==(u-1))
            printf("%d\n",vetorVerdices[i]);
        else
            printf("%d ",vetorVerdices[i]);
	scanf("%d %d", &n, &m);
	}//fim do while principal

	
		return 0;
	}








