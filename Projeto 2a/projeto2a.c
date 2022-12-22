#include <stdio.h>
#include <stdlib.h>
#define N 100

struct pilha
{
  char n; // quantidade elementos da pilha
  char vet[N];
};
typedef struct pilha Pilha;

Pilha *cria_pilha()
{
  Pilha *p = (Pilha *)malloc(sizeof(Pilha));
  p->n = 0;

  return p;
}

void push(Pilha *p, char v)
{

  if (p->n == N)
  {
    printf("Pilha cheia");
    // exit(1);
  }

  p->vet[p->n] = v;
  p->n++;
}

float pop(Pilha *p)
{
  char v;
  if (p->n == 0)
  {
    printf("Pilha vazia");
    // exit(1);
  }

  v = p->vet[p->n - 1];
  p->n--;
  return v;
}

void mostrar(Pilha *p)
{
  int i;

  for (i = p->n - 1; i >= 0; i--)
    printf("%c", p->vet[i]);
}

char stack(Pilha *p)
{
  return p->vet[p->n - 1];
}

int main()
{
  Pilha *p;
  p = cria_pilha();
  char token;

  printf("Digite a palavra a ser analisada com o caractere $ no final \n");
  goto q0;

q0:                  // estado q0
  push(p, 'S');      // stack[0] = 'S'
  token = getchar(); // pega primeiro char
  goto q1;

q1: // estado q1

  printf("Token: %c ----", token);       // imprime token atual a ser analisado
  printf(" Conteudo da pilha: ");     // Mostrando conteúdo da pilha
  mostrar(p);                        // imprime conteúdo da pilha
  printf("\n\n");

  //------TRANSIÇÕES DE PRODUÇÃO---------
  if ((token == 'm') && (stack(p) == 'S'))
  {
    pop(p);
    push(p, 'M');
    goto q1; // t1
  }
  else if ((token == 'g') && (stack(p) == 'S'))
  {
    pop(p);
    push(p, 'M');
    push(p, 'G');
    goto q1;

  } // t2
  else if ((token == 'f') && (stack(p) == 'S'))
  {
    pop(p);
    push(p, 'M');
    push(p, 'G');
    push(p, 'F');
    goto q1; // t3
  }

  else if ((token == 'm') && (stack(p) == 'M'))
  {
    pop(p);
    push(p, '}');
    push(p, ';');
    push(p, ')');
    push(p, 'E');
    push(p, '(');
    push(p, 'r');
    push(p, ';');
    push(p, 'C');
    push(p, '{');
    push(p, ')');
    push(p, '(');
    push(p, 'm');
    goto q1; // t4
  }

  else if ((token == 'g') && (stack(p) == 'G'))
  {
    pop(p);
    push(p, '}');
    push(p, ';');
    push(p, ')');
    push(p, 'E');
    push(p, '(');
    push(p, 'r');
    push(p, ';');
    push(p, 'C');
    push(p, '{');
    push(p, ')');
    push(p, '(');
    push(p, 'g');
    goto q1; // t4
  }

  else if ((token == 'n') && (stack(p) == 'N'))
  {
    pop(p);
    push(p, '}');
    push(p, ';');
    push(p, ')');
    push(p, 'E');
    push(p, '(');
    push(p, 'r');
    push(p, ';');
    push(p, 'C');
    push(p, '{');
    push(p, ')');
    push(p, '(');
    push(p, 'm');
    goto q1; // t4
  }

  else if ((token == '+') && (stack(p) == 'X'))
  {
    pop(p);
    push(p, '+');
    goto q1; // t5
  }
  else if ((token == '-') && (stack(p) == 'X'))
  {
    pop(p);
    push(p, '-');
    goto q1; // t5
  }
  else if ((token == '*') && (stack(p) == 'X'))
  {
    pop(p);
    push(p, '*');
    goto q1; // t6
  }
  else if ((token == '/') && (stack(p) == 'X'))
  {
    pop(p);
    push(p, '/');
    goto q1; // t7
  }

  else if ((token == '0') && (stack(p) == 'E'))
  {
    pop(p);
    push(p, '0');
    goto q1; // 
  }
  else if ((token == '1') && (stack(p) == 'E'))
  {
    pop(p);
    push(p, '1');
    goto q1; // 
  }
  else if ((token == 'x') && (stack(p) == 'E'))
  {
    pop(p);
    push(p, 'x');
    goto q1; // 
  }
  else if ((token == 'y') && (stack(p) == 'E'))
  {
    pop(p);
    push(p, 'y');
    goto q1; // 
  }
  else if ((token == '(') && (stack(p) == 'E'))
  {
    pop(p);
    push(p, ')');
    push(p, 'E');
    push(p, 'X');
    push(p, 'E');
    push(p, '(');
    goto q1; // 
  }

  else if ((token == 'h') && (stack(p) == 'C'))
  {
    pop(p);
    push(p, 'E');
    push(p, '=');
    push(p, 'h');
    goto q1;
  }
  else if ((token == 'j') && (stack(p) == 'C'))
  {
    pop(p);
    push(p, 'E');
    push(p, '=');
    push(p, 'j');
    goto q1;
  }
  else if ((token == 'i') && (stack(p) == 'C'))
  {
    pop(p);
    push(p, 'E');
    push(p, '=');
    push(p, 'i');
    goto q1;
  }
  else if ((token == 'k') && (stack(p) == 'C'))
  {
    pop(p);
    push(p, 'E');
    push(p, '=');
    push(p, 'k');
    goto q1;
  }
  else if ((token == 'z') && (stack(p) == 'C'))
  {
    pop(p);
    push(p, 'E');
    push(p, '=');
    push(p, 'z');
    goto q1;
  }
  else if ((token == '(') && (stack(p) == 'C'))
  {
    pop(p);
    push(p, ')');
    push(p, 'E');
    push(p, 'X');
    push(p, 'E');
    push(p, '(');
    goto q1; // 
  }
  else if ((token == 'w') && (stack(p) == 'C'))
  {
    pop(p);
		push(p,'}');
		push(p,';');
		push(p,'C');
		push(p,'{');
		push(p,')');
		push(p,'E');
		push(p,'(');
		push(p,'w');
    goto q1; // 
  }
  else if ((token == 'f') && (stack(p) == 'C'))
  {
    pop(p);
		push(p,'}');
		push(p,';');
		push(p,'C');
		push(p,'{');
		push(p,')');
		push(p,'E');
		push(p,'(');
		push(p,'f');
    goto q1; // 
  }
  else if ((token == 'o') && (stack(p) == 'C'))
  {
    pop(p);
		push(p,'}');
		push(p,';');
		push(p,'C');
		push(p,'{');
		push(p,')');
		push(p,'E');
		push(p,';');
		push(p,'E');
		push(p,';');
		push(p,'E');
		push(p,'(');
		push(p,'o');
    goto q1; // 
  }

  //------TRANSIÇÕES DE LEITURA---------
  else if ((token == 'm') && (stack(p) == 'm'))
  {
    pop(p);
    token = getchar();
    goto q1; // t8
  }
  else if ((token == 'g') && (stack(p) == 'g'))
  {
    pop(p);
    token = getchar();
    goto q1; // t8
  }
  else if ((token == 'n') && (stack(p) == 'n'))
  {
    pop(p);
    token = getchar();
    goto q1; // t8
  }
  else if ((token == '(') && (stack(p) == '('))
  {
    pop(p);
    token = getchar();
    goto q1; // t8
  }
  else if ((token == ')') && (stack(p) == ')'))
  {
    pop(p);
    token = getchar();
    goto q1; // t9
  }
  else if ((token == '{') && (stack(p) == '{'))
  {
    pop(p);
    token = getchar();
    goto q1; // t9
  }
  else if ((token == '}') && (stack(p) == '}'))
  {
    pop(p);
    token = getchar();
    goto q1; // t9
  }
  else if ((token == 'r') && (stack(p) == 'r'))
  {
    pop(p);
    token = getchar();
    goto q1; // t9
  }
  else if ((token == ';') && (stack(p) == ';'))
  {
    pop(p);
    token = getchar();
    goto q1; // t9
  }
  else if ((token == '=') && (stack(p) == '='))
  {
    pop(p);
    token = getchar();
    goto q1; // t9
  }
  else if ((token == '+') && (stack(p) == '+'))
  {
    pop(p);
    token = getchar();
    goto q1; // t10
  }
  else if ((token == '-') && (stack(p) == '-'))
  {
    pop(p);
    token = getchar();
    goto q1; // t11 }
  }
  else if ((token == '*') && (stack(p) == '*'))
  {
    pop(p);
    token = getchar();
    goto q1; // t12
  }
  else if ((token == '/') && (stack(p) == '/'))
  {
    pop(p);
    token = getchar();
    goto q1; // t13
  }
  else if ((token == '0') && (stack(p) == '0'))
  {
    pop(p);
    token = getchar();
    goto q1; // t14
  }
  else if ((token == '1') && (stack(p) == '1'))
  {
    pop(p);
    token = getchar();
    goto q1; // t15
  }
  else if ((token == 'w') && (stack(p) == 'w'))
  {
    pop(p);
    token = getchar();
    goto q1; // t15
  }
  else if ((token == 'o') && (stack(p) == 'o'))
  {
    pop(p);
    token = getchar();
    goto q1; // t15
  }
  else if ((token == 'f') && (stack(p) == 'f'))
  {
    pop(p);
    token = getchar();
    goto q1; // t15
  }
  else if ((token == 'h') && (stack(p) == 'h'))
  {
    pop(p);
    token = getchar();
    goto q1; // t15
  }
  else if ((token == 'j') && (stack(p) == 'j'))
  {
    pop(p);
    token = getchar();
    goto q1; // t15
  }
  else if ((token == 'i') && (stack(p) == 'i'))
  {
    pop(p);
    token = getchar();
    goto q1; // t15
  }
  else if ((token == 'k') && (stack(p) == 'k'))
  {
    pop(p);
    token = getchar();
    goto q1; // t15
  }
  else if ((token == 'z') && (stack(p) == 'z'))
  {
    pop(p);
    token = getchar();
    goto q1; // t15
  }
  else if ((token == 'y') && (stack(p) == 'y'))
  {
    pop(p);
    token = getchar();
    goto q1; // t15
  }
  else if ((token == 'x') && (stack(p) == 'x'))
  {
    pop(p);
    token = getchar();
    goto q1; // t15
  }
  else if ((token == '$'))
  { // Não ta funcionando (mas se usar um '$' ele funciona)
    printf("\nAnalisada com sucesso!\n");
  }
  else
  {
    printf("\nError, palavra rejeitada!\n");
  }

  return 0;
}
