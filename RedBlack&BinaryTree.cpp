// Counts every call that a insert takes on a a Red Black tree or an Binary tree

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define N 0
#define R 1

int contador=0;
typedef struct arn{
    int chave;
    struct arn *esq;
    struct arn *dir;
    int cor;
}arn;
typedef struct abb{
    int chave;
    struct abb *esq;
    struct abb *dir;

}abb;

struct abb* insereAbb(abb *ptraiz, int x){
    contador++;
    if(ptraiz==NULL){
        ptraiz=(abb *) malloc(sizeof(abb));
        ptraiz->chave=x;
        ptraiz->esq=ptraiz->dir=NULL;
        return ptraiz;
    }else{
         if(x<ptraiz->chave){
            ptraiz->esq = insereAbb(ptraiz->esq,x);
        }else{
           ptraiz->dir = insereAbb(ptraiz->dir,x);
        }

    }
    return ptraiz;
}

//rotarions
 int COR(arn* n){
    if(n==NULL)
        return N;
    else
        return n->cor;
 }

void recolore(arn* ptraiz){
    contador++;
    ptraiz->cor=R;
    if(ptraiz->esq != NULL)
        ptraiz->esq->cor=N;
    if(ptraiz->dir != NULL)
        ptraiz->dir->cor=N;
}

struct arn* rotaesq(arn* n){
    contador++;
    arn* x = n->dir;
    n->dir=x->esq;
    x->esq=n;
    x->cor=n->cor;
    n->cor=R;
  return x;
}

struct arn* rotadir(arn* n){
    contador++;
    arn* x = n->esq;
    n->esq=x->dir;
    x->dir=n;
    x->cor=n->cor;
    n->cor=R;
  return x;
}

struct arn* insereLeftLeaning(arn *ptraiz, int x){
    contador++;
    if(ptraiz==NULL){
        ptraiz=(arn *)malloc(sizeof(arn));
        ptraiz->chave=x;
        ptraiz->esq=ptraiz->dir=NULL;
        ptraiz->cor=R;
        return ptraiz;
    }
    else{
        if(COR(ptraiz->esq)==R && COR(ptraiz->dir)==R){
            recolore(ptraiz);
        }
        if(x<ptraiz->chave){
            ptraiz->esq = insereLeftLeaning(ptraiz->esq,x);
        }
        else{
             ptraiz->dir = insereLeftLeaning(ptraiz->dir,x);
         }
        if(COR(ptraiz->esq)==N && COR(ptraiz->dir)==R){
                ptraiz = rotaesq(ptraiz);
            }
        }

        if(COR(ptraiz->esq)==R && COR(ptraiz->esq->esq)==R){
            ptraiz = rotadir(ptraiz);
        }
         return ptraiz;
    }

int main (int argc, char *argv[2]) {
    int num;
    if(strcmp(argv[1],"-rn")==0){
        arn* ptraiz=NULL;
        while(scanf("%d", &num)== 1){
           ptraiz = insereLeftLeaning(ptraiz,num);
           ptraiz->cor = N;
            }
    }else{
       abb* ptraiz=NULL;
        while(scanf("%d", &num) == 1){
            ptraiz = insereAbb(ptraiz,num);
            }
    }
    printf("contador = %d\n",contador);
}

