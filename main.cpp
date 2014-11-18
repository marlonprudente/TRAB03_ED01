#include <iostream>
#include <stdio.h>
#include <stdlib.h>

/** Trabalho de Estruturas de Dados 01
Marlon Mateus Prudente
Helena Senn Arins
*/

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
/** Função responsável por inserir valores na pilha*/
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
/** Função responsável por mover valores da pilha para a fila*/
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
            std::cout << "\nMovendo Valor => " << aux->dados << " <=da PILHA para a FILA.\n";
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
            std::cout << "\nFila Cheia.\n";
            }
    }
    else
    {
        std::cout << "\nPilha Vazia.\n";
    }

};
/** Função responsável por mostrar valores do inicio da pilha e do topo da fila*/
void print_top_pilha_and_fila(Nodapilha **i,int *fila,int *iniciofila, int *fimfila, int *tamf)
{
    if(*i==NULL && *tamf==1)
    {
        std::cout << "\nPilha Vazia.";
        std::cout << "\nFila Vazia.\n";

    }
    else if(*i==NULL)
    {
        std::cout << "\nPilha Vazia.";
        std::cout << "\nValor Topo da Fila:" << fila[*iniciofila] << "\n";
    }
    else if(*tamf==1)
    {
        std::cout << "\nValor Topo da Pilha:" << (**i).dados;
        std::cout << "\nFila Vazia.\n";
    }
     if((*i!=NULL) && (*tamf!=1))
    {
        std::cout << "\nValor Topo da Pilha:" << (**i).dados;
        std::cout << "\nValor Topo da Fila:" << fila[*iniciofila] << "\n";
    }

};
/** Função responsável por remover falores da fila*/
void dequeue_fila(int *fila, int *iniciofila, int *fimfila, int *tamf)
{
    if(*tamf==1)
    {
        std::cout << "Fila Vazia.\n";
    }
    else
    {
    std::cout << "\nRemovendo Valor => " << fila[*iniciofila] << " <= da FILA.\n";
    fila[*iniciofila] = NULL;
    *iniciofila = *iniciofila + 1;
    if(*iniciofila == 5)
        {
                *iniciofila = 0;
        }
        *tamf = *tamf -1;
    }
};
/** Função principal Main*/
int main(int argc, char * argv[])
{
    struct Nodapilha *iniciopilha = NULL;
    int op, fila[5] = {0}, fi=0, ff=-1, tamf=1;
    std::cout << "OPCOES: \n" << "1 - Inserir na Pilha; \n" << "2 - Mover da pilha para a Matriz; \n" << "3 - Consultar Valor da Pilha e da Fila; \n" << "4 - Remover valor da fila; \n" << "0 - Encerrar o Programa.\n";
    std::cin >> op;

    while(op!=0)
    {
        switch (op)
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
