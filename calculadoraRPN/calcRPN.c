#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TamanhoMax 100

// Defino a estrtura da minha Pilha
typedef struct
{
    int dados[TamanhoMax]; // O meu vetor de dados
    int topo;              // O indice meu que é considerado o topo da pilha
} Pilha;

// Função para iniciar a lista
void instanciarLista(Pilha *p)
{
    p->topo = -1; // inicio com -1 para quando ter um push o indice 0 virar o topo da função
}

// Função para adicionar no topo da pilha
int PushFila(Pilha *p, int valor)
{
    if (p->topo == 99)
        return -1; // Verifica se esta cheia a fila

    p->topo++;                 // Soma mais um para subi o indice que é considerado topo
    p->dados[p->topo] = valor; // adiciona no indice que foi considerado topo o valor
    return 0;
}

// Função qual pega o primeiro item da pilha
int popFila(Pilha *p)
{
    int topo = p->dados[p->topo]; // variavel intermediaria com o valor que esta no topo
    p->topo--;                    //  diminuo um na variavel que define o topo da pilha
    return topo;
}

int ProcessarString(char str[], Pilha *p)
{
    char *valor = strtok(str, " "); // divide a string em pedaços usando espaço " " como separador
    // Loop enquanto os pedaços gerados acima ainda são valores diferente de nulo
    while (valor != NULL)
    {
        // if que identifica que o pedaço que ele ta lendo agora é de um operador
        if (strlen(valor) == 1 && (valor[0] == '+' || valor[0] == '-' || valor[0] == '*' || valor[0] == '/'))
        {
            int a = popFila(p); // puxa o ultimo item do topo da pilha
            int b = popFila(p); // puxa o ultimo item do topo da pilha
            int resultado;
            switch (valor[0])
            {
            case '+':
                resultado = b + a;
                break;
            case '-':
                resultado = b - a;
                break;
            case '*':
                resultado = b * a;
                break;
            case '/':
                resultado = b / a;
                break;
            }
            PushFila(p, resultado); // coloca na fila o resultado da operação acima
        }
        else
        {
            int num = atoi(valor); // transforma o valor do pedaço em numero e coloca na pilha
            PushFila(p, num);
        }

        valor = strtok(NULL, " "); // passa para o proximo pedaço da string
    }

    return popFila(p); // retorna o valor que ficou no topo da pilha
}
int main()
{
    char expressao[TamanhoMax];
    Pilha p;
    instanciarLista(&p);

    printf("Informe a expressão: ");
    fgets(expressao, sizeof(expressao), stdin);
    expressao[strcspn(expressao, "\n")] = '\0';

    int resultado = ProcessarString(expressao, &p);
    printf("O resultado da expressão é: %d \n", resultado);

    return 0;
}
