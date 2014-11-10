#include <iostream>
#include <stdio.h>
#include <stdlib.h>
/** Trabalho de Estruturas de Dados 01 */

struct Nodapilha
{
    int dados;
    struct Nodapilha *proximo;
    Nodapilha(int d, Nodapilha* p)
    {
        dados = d;
        proximo = p;
    }
    Nodapilha() {}
};

void pilha_push(struct Nodapilha **i)
{
    int dados;
    std::cout << "Digite o valor :"<<std::endl;
    std::cin >> dados;
    Nodapilha* novoNodapilha = new Nodapilha(dados, NULL), aux;
    if(*i!=NULL)
    {
        novoNodapilha->proximo = *i;
        aux = **i;
        **i = aux;
        *i = novoNodapilha;
    };

    if(*i==NULL)
    {
        *i = novoNodapilha;
        novoNodapilha->proximo = NULL;
    };
}

void move_pilha_to_fila(struct Nodapilha **i, int *fila,int *iniciofila,int *fimfila)
{
    struct Nodapilha* aux = *i;

    if(*i!=NULL)
    {
        if((*fimfila == *iniciofila - 1 )|| (*iniciofila == 0 && *fimfila == 5))
        {
            std::cout << "Fila Cheia.\n";
        }

        if(*fimfila == 0 && *iniciofila==0)
        {
            std::cout << "Movendo Dados >> " << (**i).dados << " << da pilha para a Fila.\n";
            fila[*fimfila] = (**i).dados;
            (**i).dados = 0;
            *i = aux->proximo;
            delete (aux);
            *fimfila = *fimfila + 1;
            std::cout << "Fim e Inicio = 0 ";
        }

        else if(*fimfila!=5)
        {
                std::cout << "Movendo Dados >> " << (**i).dados << " << da pilha para a Fila.\n";
                fila[*fimfila] = (**i).dados;
                (**i).dados = 0;
                *i = aux->proximo;
                delete (aux);
                *fimfila = *fimfila + 1;
                std::cout << "Fim fila != 5 e outra condição ";
        }
        if(*fimfila==5)
        {
            if(fila[0]!=0)
            {
                std::cout << "Movendo Dados >> " << (**i).dados << " << da pilha para a Fila.\n";
                fila[0] = (**i).dados;
                (**i).dados = 0;
                *i = aux->proximo;
                delete (aux);
                std::cout << "Fim fila == 5 e outra condição ";
            }
        }
        if(aux->proximo == NULL)
        {
            *i = NULL;
        }
    }
    else
    {
        std::cout << "Pilha Vazia.\n";
    }

};

void print_top_pilha_and_fila(Nodapilha **i,int *fila,int *iniciofila, int *fimfila)
{
    if(*i==NULL && fila[*fimfila]==NULL)
    {
        std::cout << "Pilha Vazia.";
        std::cout << "\nFila Vazia.";

    }
     if(*i==NULL)
    {
        std::cout << "Pilha Vazia.";
        std::cout << "\nValor Topo da Fila:" << fila[*iniciofila];
    }
     if(fila[*iniciofila]==NULL)
    {
        std::cout << "Valor Topo da Pilha:" << (**i).dados;
        std::cout << "\nFila Vazia.";
    }
     if((*i!=NULL) && (fila[*iniciofila]!=NULL))
    {
        std::cout << "Valor Topo da Pilha:" << (**i).dados;
        std::cout << "\nValor Topo da Fila:" << fila[*iniciofila];
    }

};

void dequeue_fila(int *fila, int *iniciofila, int *fimfila)
{
    if((*fimfila == 0) && (*iniciofila==0))
    {
        std::cout << "Fila Vazia.";
    }
    if(*iniciofila!=5)
    {
        fila[*iniciofila] = 0;
        *iniciofila++;
    }
    if(*iniciofila==5 && *fimfila != 0)
    {
        fila[*iniciofila] = 0;
        *iniciofila = 0;
    }
    /*else
        {
        fila[*iniciofila] = 0;
        *iniciofila++;
        }
*/
};

int main(int argc, char * argv[])
{
    struct Nodapilha *iniciopilha = NULL;
    int op, fila[5] = {0}, fi=0, ff=0;
    std::cout << "OPCOES: \n" << "1 - Inserir na Pilha; \n" << "2 - Mover da pilha para a Matriz; \n" << "3 - Consultar Valor da Pilha e da Fila; \n" << "4 - Remover valor da fila; \n" << "0 - Encerrar o Programa.\n";
    std::cin >> op;

    while(op!=0)
    {
        switch (tolower(op))
        {
        case 1:
            std::cout << "Inserir na Pilha: \n";
            pilha_push(&iniciopilha);
            break;
        case 2:
            std::cout << "Mover da pilha para a Fila Sequencial: \n";
            move_pilha_to_fila(&iniciopilha,fila, &fi, &ff);
            break;
        case 3:
            std::cout << "Consultar Valor do topo da Pilha e da Fila: \n";
            print_top_pilha_and_fila(&iniciopilha, fila, &fi, &ff);
            std::cout << "Valor Ini " << fi << " Valor f " << ff;
            break;
        case 4:
            std::cout << "Remover valor da FILA: \n";
            dequeue_fila(fila, &fi, &ff);
            break;
        default:
            std::cout << "Opcao Invalida!\n";
            break;
        }
        std::cout << "\nOPCOES: \n" << "1 - Inserir na Pilha; \n" << "2 - Mover da pilha para a Matriz; \n" << "3 - Consultar Valor da Pilha e da Fila; \n" << "4 - Remover valor da fila; \n" << "0 - Encerrar o Programa.\n";
        std::cin >> op;

    }
    return 0;
}
