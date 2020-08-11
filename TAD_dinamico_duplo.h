#ifndef TAD_DINAMICO_DUPLO_H_INCLUDED
#define TAD_DINAMICO_DUPLO_H_INCLUDED

///Alunos: Eduardo Caldeira Vicente e Julia Disner
///Lista Dinâmica Duplamente Encadeada

template<typename tipo>
struct Dado{
    tipo dado;
};

template<typename tipo>
struct TElemento{
    tipo elemento;
    TElemento *next;
    TElemento *previus;
};

template<typename tipo>
struct TLista{
    TElemento<tipo> *primeiro;
    TElemento<tipo> *ultimo;
};

template<typename tipo>
bool inicializa_lista_enc_dupla(TLista<tipo> *Lista){
    Lista->primeiro = NULL;
    Lista->ultimo = NULL;
    return true;
}

template<typename tipo>
bool insere_fim_lista_enc_dupla(TLista<tipo> *Lista, tipo dado){
    TElemento<tipo> *var = new TElemento<tipo>;
    var->elemento = dado;
    if(Lista->primeiro != NULL){
        var->next=NULL;
        var->previus=Lista->ultimo;
        Lista->ultimo->next=var;
        Lista->ultimo=var;
        return true;
    }else{
        var->next = NULL;
        var->previus = NULL;
        Lista->ultimo = var;
        Lista->primeiro = var;
        return true;
    }
}

template<typename tipo>
bool remove_fim_lista_enc_dupla(TLista<tipo> *Lista){
    if(Lista->primeiro==NULL){
        return false;
    }else{
        TElemento<tipo> *escravo = Lista->ultimo;
        Lista->ultimo=escravo->previus;
        Lista->ultimo->next = NULL;
        delete escravo;
        return true;
    }
}

template<typename tipo>
bool insere_inicio_lista_enc_dupla(TLista<tipo> *Lista, tipo dado){
    TElemento<tipo> *var;
    var = new TElemento<tipo>;
    var->elemento = dado;
    if(Lista->primeiro==NULL){
        var->next=NULL;
        var->previus=NULL;
        Lista->primeiro=var;
        Lista->ultimo=var;
        return true;
    }else{
        Lista->primeiro->previus=var;
        var->next = Lista->primeiro;
        var->previus = NULL;
        Lista->primeiro= var;
        return true;
    }
}

template<typename tipo>
bool remove_inicio_lista_enc_dupla(TLista<tipo> *Lista){
    TElemento<tipo> *escravo=Lista->primeiro;
    if(Lista->primeiro==NULL){
        return false;
    }else{
        Lista->primeiro = Lista->primeiro->next;
        Lista->primeiro->previus = NULL;
        delete escravo;
        return true;
    }
}

template<typename tipo>
bool remove_posicao_lista_enc_dupla(TLista<tipo> *Lista, int posi){
    TElemento<tipo> *escravo;
    if(Lista->primeiro==NULL){
        return false;
    }else if(posi==0){///Remove início
        escravo=Lista->primeiro;
        Lista->primeiro = Lista->primeiro->next;
        Lista->primeiro->previus = NULL;
        delete escravo;
        return true;
    }else if(posi==quantidade_enc_dupla(Lista)-1){///Remove fim
        escravo = Lista->ultimo;
        Lista->ultimo=escravo->previus;
        Lista->ultimo->next = NULL;
        delete escravo;
        return 0;
    }else if(posi<(quantidade_enc_dupla(Lista)/2)){///Vai de frente para trás
        escravo = Lista->primeiro;
        for(int i=0; i<posi; i++){
            escravo = escravo->next;
        }
        escravo->previus->next=escravo->next;
        delete escravo;
        return true;
    }else{///Vai de trás para frente
        escravo=Lista->ultimo;
        for(int i=quantidade_enc_dupla(Lista); i>posi+1; i--){
            escravo = escravo->previus;
        }
        escravo->previus->next=escravo->next;
        delete escravo;
        return true;
    }
}

template <typename tipo>
void bubblesort(TLista<tipo> *Lista){
    int i,j;
    for(i=0;i<quantidade_enc_dupla(Lista);i++){
        TElemento<tipo> *escravo = Lista->primeiro;
        for(j=0;j<quantidade_enc_dupla(Lista)-1;j++){
            if(escravo->elemento > escravo->next->elemento){
                tipo aux;
                aux = escravo->elemento;
                escravo->elemento = escravo->next->elemento;
                escravo->next->elemento = aux;
            }
            escravo = escravo->next;
        }
    }
}

template<typename tipo>
bool insere_posicao_lista_enc_dupla(TLista<tipo> *Lista, int posi, tipo dado){
    TElemento<tipo> *var;
    var= new TElemento<tipo>;
    var->elemento = dado;
    if(posi==0){///Incere no Início
        Lista->primeiro->previus=var;
        var->next = Lista->primeiro;
        var->previus = NULL;
        Lista->primeiro= var;
        return true;
    }else if(posi<(quantidade_enc_dupla(Lista)/2)){///Vai de frente para trás
        TElemento<tipo> *escravo=Lista->primeiro;
        for(int i=0; i<posi-1; i++){
            escravo = escravo->next;
        }
        var->next = escravo->next;
        var->previus = escravo;
        escravo->next = var;
        return true;
    }else{///Vai de trás para frente
        TElemento<tipo> *escravo=Lista->ultimo;
        for(int i=quantidade_enc_dupla(Lista); i>posi; i--){
            escravo = escravo->previus;
        }
        var->next = escravo->next;
        var->previus = escravo;
        escravo->next = var;
        return true;
    }
}

template<typename tipo>
int quantidade_enc_dupla(TLista<tipo> *Lista){
    TElemento<tipo> *escravo= Lista->primeiro;
    int cont=1;
    if(Lista->primeiro == NULL){
        return 0;
    }else{
        while(escravo->next!= NULL){
            escravo=escravo->next;
            cont++;
        }
        return cont;
    }
}

template<typename tipo>
TElemento<tipo>* cata_elemento(TLista<tipo> *Lista, int posi){
    TElemento<tipo> *escravo= Lista->primeiro;
    for(int i=0; i<posi;i++){
        escravo = escravo->next;
    }
    return escravo;
}

template<typename tipo>
int part(TLista<tipo> *Lista,int inicio,int fim){
    TElemento<tipo> *pivo=cata_elemento(Lista, fim);
    TElemento<tipo> *escravo = cata_elemento(Lista, inicio);
    int indice=inicio;
    TElemento<tipo> *escravo_2 = cata_elemento(Lista, indice);
    int i;
    tipo aux;

    for(i=inicio;i<fim;i++)
    {
        if(escravo->elemento<=pivo->elemento)
        {
            aux=escravo->elemento;
            escravo->elemento=escravo_2->elemento;
            escravo_2->elemento=aux;
            indice++;
            escravo_2=cata_elemento(Lista, indice);
        }
        escravo= escravo->next;
     }
      aux=pivo->elemento;
      pivo->elemento=escravo_2->elemento;
      escravo_2->elemento=aux;

     return indice;
 }

template<typename tipo>
void quicksort(TLista<tipo> *Lista,int inicio,int fim){
    if(inicio<fim)
    {
         int indice=part(Lista,inicio,fim);
             quicksort(Lista,inicio,indice-1);
             quicksort(Lista,indice+1,fim);
    }
}

#endif // TAD_DINAMICO_DUPLO_H_INCLUDED
