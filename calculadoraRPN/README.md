# Ponderada Semana 10

## Calculadora RPN (Notação Polonesa Reversa)

Esta aplicação implementa uma calculadora baseada na **notação polonesa reversa (RPN - Reverse Polish Notation)**, utilizando a linguagem C e o conceito de **pilha (stack)**.

### O que é RPN?

A notação polonesa reversa é uma forma de escrever expressões matemáticas **sem o uso de parênteses**, onde os **operadores vêm depois dos operandos**.

Por exemplo:

* Expressão infixa tradicional: `2 + 3`
* Em RPN: `2 3 +`

Essa notação é bastante usada em linguagens de máquina, compiladores e calculadoras científicas (como as da HP), pois **simplifica a avaliação de expressões**, especialmente em sistemas com recursos limitados.


### Como funciona a calculadora?

1. A expressão RPN é digitada pelo usuário como uma sequência de números e operadores, separados por espaço.
   * Exemplo: `1 2 + 4 * 3 -` → resultado: `9`

2. O programa **quebra a string em pedaços** usando espaço como separador (`strtok`), e processa item a item:

   * Se o item for um número: ele é **empilhado**.
   * Se for um operador (`+`, `-`, `*`, `/`): o programa **retira os dois últimos números da pilha**, aplica a operação, e **empilha o resultado**.

3. Ao final da expressão, o valor que restar no topo da pilha é o **resultado da operação**.

### Estrutura da pilha

A pilha é implementada com:

* Um vetor de inteiros `dados[100]`
* Um índice `topo` que marca a posição atual do topo da pilha.

```c
typedef struct {
    int dados[100];
    int topo;
} Pilha;
```

As funções `PushFila` e `popFila` servem para empilhar e desempilhar valores conforme as regras da RPN.



### Como usar

1. Compile o programa:

```bash
gcc calcRPN.c -o calcRPN
```

2. Execute:

```bash
./calcRPN
```

3. Digite uma expressão:

```
Informe a expressão: 1 2 + 4 * 3 -
O resultado da expressão é: 9
```


