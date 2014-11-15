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

void move_pilha_to_fila(struct Nodapilha **i, int *fila,int *iniciofila,int *fimfila,int *tamf)
{
    struct Nodapilha* aux = *i;

    if(*i!=NULL)
    {
        if(*tamf<6)
        {
            if(*fimfila == 4)
            {
            *fimfila = -1;
            }

            *fimfila = *fimfila + 1;
            fila[*fimfila] = aux->dados;
            aux->dados = 0;

                if(aux->proximo != NULL)
                {
                    *i = aux->proximo;
                }
                else
                {
                    *i = NULL;
                }

            delete (aux);
            *tamf = *tamf + 1;


        }
        else
            {
                /*
            *fimfila = *fimfila + 1;
            fila[*fimfila] = (**i).dados;
            (**i).dados = 0;

                if(aux->proximo != NULL)
                {
                    *i = aux->proximo;
                }
                else
                {
                    *i = NULL;
                }
            delete (aux);
            *tamf = *tamf + 1;
            */
            std::cout << "Fila Cheia.\n";
            }





        /*
        if(tamf == 4)
        {
            std::cout << "Fila Cheia.\n";
        }

        if(*fimfila == *iniciofila)
        {
            std::cout << "Movendo Dados >> " << (**i).dados << " << da pilha para a Fila.\n";
            fila[*fimfila] = (**i).dados;
            (**i).dados = 0;
            *i = aux->proximo;
            delete (aux);
            *fimfila = *fimfila + 1;
            *tamf = *tamf + 1;
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
                *tamf = *tamf + 1;
                std::cout << "Fim fila != 5 e outra condição ";
        }
       /* if(*fimfila==5)
        {
            if(fila[0]!=0)
            {
                std::cout << "Movendo Dados >> " << (**i).dados << " << da pilha para a Fila.\n";
                fila[0] = (**i).dados;
                (**i).dados = 0;
                *i = aux->proximo;
                *tamf = *tamf + 1;
                delete (aux);
                std::cout << "Fim fila == 5 e outra condição ";
            }
        }*//*
        if(*tamf < 5 && fila[*iniciofila]!=0)
        {
                std::cout << "Movendo Dados >> " << (**i).dados << " << da pilha para a Fila.\n";
                *fimfila = *fimfila - *iniciofila;
               // *iniciofila = *fimfila;
                fila[*fimfila] = (**i).dados;
                (**i).dados = 0;
                *i = aux->proximo;
                *tamf = *tamf + 1;
                delete (aux);


        }
        if(aux->proximo == NULL)
        {
            *i = NULL;
        }*/
    }
    else
    {
        std::cout << "Pilha Vazia.\n";
    }

};

void print_top_pilha_and_fila(Nodapilha **i,int *fila,int *iniciofila, int *fimfila, int *tamf)
{
    if(*i==NULL && *tamf==1)
    {
        std::cout << "Pilha Vazia.";
        std::cout << "\nFila Vazia.";

    }
    else if(*i==NULL)
    {
        std::cout << "Pilha Vazia.";
        std::cout << "\nValor Topo da Fila:" << fila[*iniciofila];
    }
    else if(*tamf==1)
    {
        std::cout << "Valor Topo da Pilha:" << (**i).dados;
        std::cout << "\nFila Vazia.";
    }
     if((*i!=NULL) && (*tamf!=1))
    {
        std::cout << "Valor Topo da Pilha:" << (**i).dados;
        std::cout << "\nValor Topo da Fila:" << fila[*iniciofila];
    }

};

void dequeue_fila(int *fila, int *iniciofila, int *fimfila, int *tamf)
{
    if(*tamf==1)
    {
        std::cout << "Fila Vazia.";
    }
    else
    {
    fila[*iniciofila] = NULL;
    *iniciofila = *iniciofila + 1;
    if(*iniciofila == 5)
        {
                *iniciofila = 0;
        }

        std::cout << "Valor Indice INICIO:" << *iniciofila;
        *tamf = *tamf -1;
    /*
    if(*iniciofila!=5)
    {
        fila[*iniciofila] = 0;
        *iniciofila = *iniciofila + 1;
        *tamf = *tamf - 1;
    }

    if(*iniciofila==5 && *fimfila != 0)
    {
        fila[*iniciofila] = 0;
        *iniciofila = 0;
        *tamf = *tamf - 1;
    }
*/
    }
};

int main(int argc, char * argv[])
{
    struct Nodapilha *iniciopilha = NULL;
    int op, fila[5] = {0}, fi=0, ff=-1, tamf=1;
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
            move_pilha_to_fila(&iniciopilha,fila, &fi, &ff,&tamf);
            break;
        case 3:
            std::cout << "Consultar Valor do topo da Pilha e da Fila: \n";
            print_top_pilha_and_fila(&iniciopilha, fila, &fi, &ff, &tamf);
            std::cout << "Valor Ini " << fi << " Valor f " << ff;
            std::cout << "\n\ntamanho Fila: " << tamf - 1;
            break;
        case 4:
            std::cout << "Remover valor da FILA: \n";
            dequeue_fila(fila, &fi, &ff, &tamf);
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
