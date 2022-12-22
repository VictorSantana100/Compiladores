#include <stdio.h>
#include <stdlib.h>
#include "analisador.h"
#include "buscasEmArvore.h"
#include "ordenaVetor.h"
#define true 1
#define false 0

int flag = 0;
int cont_vetor = 0;
PONT vet[1000];

PONT criaNovoNo(TIPOcaractere ch){
    PONT novo = (PONT)malloc(sizeof(NO));
    novo->primFilho = NULL;
    novo->proxIrmao = NULL;
    novo->caractere = ch;
    novo->id = indice;
    return(novo);
}

PONT inicializa(TIPOcaractere ch) {
    return(criaNovoNo(ch));
}

PONT buscaid(int id, PONT raiz){
    if (raiz == NULL) return NULL;
    if (raiz->id == id) return raiz;
    PONT p = raiz->primFilho;
    while(p) {
        PONT resp = buscaid(id, p);
        if (resp) return(resp);
        p = p->proxIrmao;
    }
    return(NULL);
    }

void insere(PONT raiz, TIPOcaractere novacaractere, int id){
    PONT pai = buscaid(id,raiz);
    if (!pai) return(false);
        PONT filho = criaNovoNo(novacaractere);
        PONT p = pai->primFilho;
        
    if (!p) pai->primFilho = filho;
    else {
        while (p->proxIrmao)
        p = p->proxIrmao;
        p->proxIrmao = filho;
    }
}

void exibirArvore(PONT raiz){
    if (raiz == NULL) return;
    printf("[%c",raiz->caractere, raiz->id);
    PONT p = raiz->primFilho;
    while (p) {
        if(flag == 0){
            vet[cont_vetor] = p;
            cont_vetor++;
        }
        exibirArvore(p);
        p = p->proxIrmao;
    }
    printf("]");
}

void compacta(PONT* vet, int cont_vetor){
    bublesort(vet, cont_vetor);
    printf("S-0\n");
    for(int i=0; i<cont_vetor; i++){
        printf("%c-%d\n", vet[i]->caractere, vet[i]->id);
    }
}

void criaArvoreAbstrata(PONT raiz, PONT r_abstrata){
    PONT p = raiz->primFilho;
    int indice_pai;
    PONT aux;
    PONT teste;
    
    if (raiz == NULL) return;
    
    switch(raiz->caractere){
        case 'M':
            p = raiz->primFilho;
            insere(r_abstrata, p->caractere, indice-1);
            indice++;
        break;
        
        case 'C':
            
            if(raiz->primFilho->caractere != 'f' && raiz->primFilho->caractere != 'w' && raiz->primFilho->caractere != 'o'){
                    if(raiz->primFilho->proxIrmao){
                    p = raiz->primFilho->proxIrmao;
                    if(p->caractere == '='){
                        insere(r_abstrata, p->caractere,indice-1);
                        indice++;
                       
                        p = raiz->primFilho;
                        insere(r_abstrata, p->caractere, indice-1);
                        indice++;
                       
                        p = raiz->primFilho->proxIrmao->proxIrmao->primFilho;
                        insere(r_abstrata, p->caractere,indice - 2);
                        indice++;
                    }
                }
               
             
                if(raiz->primFilho->proxIrmao->proxIrmao){
                    p = raiz->primFilho->proxIrmao->proxIrmao;
                    aux = raiz->primFilho->proxIrmao;
                   
                    if(p->caractere == 'X'){
                        insere(r_abstrata, p->primFilho->caractere, indice-1);
                        indice++;
                       
                        p = p->proxIrmao->primFilho;
                        insere(r_abstrata, p->caractere, indice-1);
                       
                        insere(r_abstrata, aux->primFilho->caractere, indice-1);
                        indice++;
                    }
                }
            }
            
            
            if(raiz->primFilho->caractere == 'f' || raiz->primFilho->caractere == 'w'){
                //Adiciona o f
                p = raiz->primFilho;
                insere(r_abstrata, p->caractere, indice-1);
                int indiceF = indice;
                indice++;
                
                //Adiciona o +
                p = raiz->primFilho;
                p = p->primFilho->proxIrmao->primFilho->proxIrmao->proxIrmao->primFilho;
                insere(r_abstrata, p->caractere, indiceF);
                int indiceMais = indice;
                indice++;
                
                //Adiciona o =
                p = raiz->primFilho;
                p = p->primFilho->proxIrmao->proxIrmao->proxIrmao->proxIrmao->primFilho->proxIrmao;
                insere(r_abstrata, p->caractere, indiceF);
                int indiceIgual = indice;
                indice++;
                
                //Adiciona 1
                p = raiz->primFilho;
                p = p->primFilho->proxIrmao->primFilho->proxIrmao->primFilho;
                insere(r_abstrata, p->caractere, indiceMais);
                indice++;
                
                 //Adiciona o  1
                p = raiz->primFilho;
                p = p->primFilho->proxIrmao->primFilho->proxIrmao->proxIrmao->proxIrmao->primFilho;
                insere(r_abstrata, p->caractere, indiceMais);
                indice++;
                
                // insere o h
                p = raiz->primFilho;
                p = p->primFilho->proxIrmao->proxIrmao->proxIrmao->proxIrmao->primFilho;
                insere(r_abstrata, p->caractere,indiceIgual);
                indice++;
                
                //insere o 0
                p = raiz->primFilho;
                p = p->primFilho->proxIrmao->proxIrmao->proxIrmao->proxIrmao->primFilho->proxIrmao->proxIrmao;
                if(p->caractere == 'g'){
                    insere(r_abstrata, p->caractere,indiceIgual);
                    indice++;
                }else{
                    p = raiz->primFilho;
                    p = p->primFilho->proxIrmao->proxIrmao->proxIrmao->proxIrmao->primFilho->proxIrmao->proxIrmao->primFilho;
                    insere(r_abstrata, p->caractere,indiceIgual);
                    indice++;
                }
                
            }else if(raiz->primFilho->caractere == 'o'){
                //insere o 'o'
                p = raiz->primFilho;
                insere(r_abstrata, p->caractere, indice-1);
                int indiceF = indice;
                indice++;
                
                //insere primeiro 0
                p = p->primFilho->proxIrmao->primFilho;
                insere(r_abstrata, p->caractere, indice-1);
                indice++;
                
                //insere segundo 1
                p = raiz->primFilho;
                p = p->primFilho->proxIrmao->proxIrmao->proxIrmao->primFilho;
                insere(r_abstrata, p->caractere, indice-2);
                indice++;
                
                //insere +
                p = raiz->primFilho;
                p = p->primFilho->proxIrmao->proxIrmao->proxIrmao->proxIrmao->proxIrmao->primFilho->proxIrmao->proxIrmao->primFilho;
                insere(r_abstrata, p->caractere, indice-1);
                indice++;
                
                //insere 1
                p = raiz->primFilho;
                p = p->primFilho->proxIrmao->proxIrmao->proxIrmao->proxIrmao->proxIrmao->primFilho->proxIrmao->primFilho;
                insere(r_abstrata, p->caractere, indice-1);
                indice++;
                
                //insere 1
                p = raiz->primFilho;
                p = p->primFilho->proxIrmao->proxIrmao->proxIrmao->proxIrmao->proxIrmao->primFilho->proxIrmao->proxIrmao->proxIrmao->primFilho;
                insere(r_abstrata, p->caractere, indice-2);
                indice++;
                
                //insere =
                p = raiz->primFilho;
                p = p->primFilho->proxIrmao->proxIrmao->proxIrmao->proxIrmao->proxIrmao->proxIrmao->proxIrmao->proxIrmao->primFilho->proxIrmao;
                insere(r_abstrata, p->caractere, indice-1);
                indice++;
                
                //insere h
                p = raiz->primFilho;
                p = p->primFilho->proxIrmao->proxIrmao->proxIrmao->proxIrmao->proxIrmao->proxIrmao->proxIrmao->proxIrmao->primFilho;
                insere(r_abstrata, p->caractere, indice-1);
                indice++;
                
                //insere h
                p = raiz->primFilho;
                p = p->primFilho->proxIrmao->proxIrmao->proxIrmao->proxIrmao->proxIrmao->proxIrmao->proxIrmao->proxIrmao->primFilho->proxIrmao->proxIrmao;
                if(p->caractere == 'g'){
                    insere(r_abstrata, p->caractere, indice-2);
                    indice++;
                }else{
                    insere(r_abstrata, p->primFilho->caractere, indice-2);
                    indice++;
                }
                
            }
            
            
        break;
         
        case 'r':
            indice_pai = 0 ;
            insere(r_abstrata, raiz->caractere,indice_pai);
            indice++;
            
            p = raiz->proxIrmao->proxIrmao->primFilho;
            insere(r_abstrata, p->caractere, indice-1);
            indice_pai++;
        break;
    }
    
    while (p) {
        criaArvoreAbstrata(p, r_abstrata);
        p = p->proxIrmao;
    }
}


int main()
{
    PONT r = inicializa('S');
    printf("\n\nInforme a expressão que será analizada com $ no final\n\n");
    lex(); // Precisa por $ no término da expressão
    S(r);
    printf("\nÁrvore de análise sintática com hash. Use o site: https://mshang.ca/syntree/ para visualizar de forma gráfica\n");
    exibirArvore(r);
    flag++;
    printf("\n\nÁrvore de análise abstrata\n");
    indice = 0;
    PONT r_abstrata = inicializa('m');
    criaArvoreAbstrata(r, r_abstrata);
    exibirArvore(r_abstrata);
    /*printf("\n\nNotação polonesa\n");
    mostrarEmPreOrdem(r_abstrata);
    printf("\n\nNotação polonesa reversa\n");
    mostrarEmPosOrdem(r_abstrata);
    printf("\n");
    printf("\nÁrvore em Vetor compactado\n");
    compacta(vet, cont_vetor);*/
    return 0;
}
