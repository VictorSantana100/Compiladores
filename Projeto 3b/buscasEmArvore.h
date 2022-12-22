// percurso em ordem  esq-raiz-dir
void mostrarEmOrdem(PONT a){
    if(a!=NULL){
        mostrarEmOrdem(a->primFilho);
        printf("%c",a->caractere);
        mostrarEmOrdem(a->proxIrmao);
    }
}

// percuso em preordem raiz-esq-dir POLONESA
void mostrarEmPreOrdem(PONT a){
    if(a!=NULL){
      
        printf("%c",a->caractere);
        mostrarEmPreOrdem(a->primFilho);
        mostrarEmPreOrdem(a->proxIrmao);
    }
}

// percuso em pos ordem esq-dir-raiz POLONESA REVERSA
void mostrarEmPosOrdem(PONT a){
    if(a!=NULL){
      
        mostrarEmOrdem(a->primFilho);
        mostrarEmOrdem(a->proxIrmao);
        printf("%c",a->caractere);
    }
}