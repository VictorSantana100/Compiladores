char token;
typedef int bool;
typedef char TIPOcaractere;
typedef int id;
int indice = 0;
//int indiceW;
//int cont;
int vetcomp[100];

typedef struct no {
    TIPOcaractere caractere;
    id id;
    id comp;
    /*Aqui vão outros dados*/
    struct no *primFilho;
    struct no *proxIrmao;
} NO;
typedef NO* PONT;

char lex(){
  token = getchar();
}

void erro(int x)
{
  printf("\nError %d", x);
}

void S(PONT* r)
{
  int indiceS = indice;
  int cont = 1;
  if (token == 'm')
  {
    lex();
    indice = indiceS * 12 + cont;
    insere(r, 'M', indiceS);
    cont++;
    M(r);
    
  }
  else if (token == 'g')
  {
    indice = indiceS * 12 + cont;
    insere(r, 'G', indiceS);
    cont++;
    lex();
    G(r);
    indice = indiceS * 12 + cont;
    insere(r, 'M', indiceS);
    cont++;
    lex();
    M(r);
  }
  else if (token == 'n')
  {
    indice = indiceS * 12 + cont;
    insere(r, 'N', indiceS);
    cont++;
    lex();
    N(r);
    indice = indiceS * 12 + cont;
    insere(r, 'G', indiceS);
    cont++;
    lex();
    G(r);
    indice = indiceS * 12 + cont;
    insere(r, 'M', indiceS);
    cont++;
    lex();
    M(r);
    
  }
  else
  {
    erro(60);
  }
}


void M(PONT* r)
{
  int indiceM = indice;
  int cont = 1;
  indice = indiceM * 12 + cont;
  insere(r,'m',indiceM);
  cont++;
  if (token == '(')
  {
    lex();
    indice = indiceM * 12 + cont;
    insere(r,'(',indiceM);
    cont++;
    if (token == ')')
    {
      indice = indiceM * 12 + cont;
      insere(r,')',indiceM);
      cont++;
      lex();
      if (token == '{')
      {
        indice = indiceM * 12 + cont;
        insere(r,'{',indiceM);
        cont++;
        lex();
        indice = indiceM * 12 + cont;
        insere(r,'A',indiceM);
        cont++;
        A(r);
        if (token == ';')
        {
          indice = indiceM * 12 + cont;
          insere(r,';',indiceM);
          cont++;
          lex();
          if (token == 'r')
          {
            indice = indiceM * 12 + cont;
            insere(r,'r',indiceM);
            cont++;
            lex();
            if (token == '(')
            {
              indice = indiceM * 12 + cont;
              insere(r,'(',indiceM);
              cont++;
              lex();
              indice = indiceM * 12 + cont;
              insere(r, 'E', indiceM);
              cont++;
              E(r);
              if (token == ')')
              {
                indice = indiceM * 12 + cont;
                insere(r,')',indiceM);
                cont++;
                lex();
                if (token == ';')
                {
                  indice = indiceM * 12 + cont;
                  insere(r,';',indiceM);
                  cont++;
                  lex();
                  if (token == '}')
                  {
                    indice = indiceM * 12 + cont;
                    insere(r,'}',indiceM);
                    cont++;
                    lex();
                  }
                  else
                  {
                    erro(1);
                  }
                }
                else
                {
                  erro(61);
                }
              }
              else
              {
                erro(2);
              }
            } // if-(
            else
            {
              erro(3);
            }
          } // if-r
          else
          {
            erro(4);
          }
        } // if-;
        else
        {
          erro(5);
        }
      } // if-{
      else
      {
        erro(6);
      } // não veio {

    } // if-)
    else
    {
      erro(7);
    } // não veio )
  }   // if-(
  else
  {
    erro(8);
  }
  // não veio (
} // if-m

void A(PONT* r)
{
    int indiceA = indice;
    int cont = 1;
    indice = indiceA * 12 + cont;
    insere(r, 'C', indiceA);
    cont++;
    C(r);
    indice = indiceA * 12 + cont;
    insere(r, 'B', indiceA);
    cont++;
    B(r);
}

void B(PONT* r)
{
   int cont = 1;
   int indiceB = indice;
   if(token == '.'){
       indice = indiceB * 12 + cont;
       insere(r, token, indiceB);
       cont++;
       lex();
   }
   else if(token == ';'){
       indice = indiceB * 12 + cont;
       insere(r, token, indiceB);
       cont++;
       lex();
       indice = indiceB * 12 + cont;
       insere(r, 'C', indiceB);
       cont++;
       C(r);
       indice = indiceB * 12 + cont;
       insere(r, 'B', indiceB);
       cont++;
       B(r);
   }
   else erro(100);
}

void E(PONT* r)
{
  int cont = 1;
  int indiceE = indice;
  if (token == '0' || token == '1'|| token == '2' || token == '3' || token == '4' || token == '5' || token == '6' || token == '7' || token == '8' || token == '9' || token == 'x' || token == 'y')
  {
    indice = indiceE * 12 + cont;
    insere(r, token, indiceE);
    cont++;
    lex();
  }
  else if (token == '(')
  {
    indice = indiceE * 12 + cont;
    insere(r, token, indiceE);
    cont++;
    lex();
    indice = indiceE * 12 + cont;
    insere(r, 'E', indiceE);
    cont++;
    E(r);
    indice = indiceE * 12 + cont;
    insere(r, 'X', indiceE);
    cont++;
    X(r);
    indice = indiceE * 12 + cont;
    insere(r, 'E', indiceE);
    cont++;
    E(r);

    if (token == ')')
    {
      indice = indiceE * 12 + cont;
      insere(r, token, indiceE);
      cont++;
      lex();
    }
    else
    {

      erro(10);
    }
  }
  else
  {
    erro(11);
  }
}

void X(PONT* r)
{
  int indiceX = indice;
  if (token == '+' || token == '-' || token == '*' || token == '/')
  {
    indice = indice * 12 + 1;
    insere(r, token, indiceX);
    lex();
  }
  else
  {
    erro(12);
  }
}

void C(PONT* r)
{
  int cont = 1;
  int indiceC = indice;
  if (token == 'h')
  {
    indice = indiceC * 12 + cont;
    insere(r,'h',indiceC);
    cont++;
    lex();
    if (token == '=')
    {
      indice = indiceC * 12 + cont;
      insere(r,'=',indiceC);
      cont++;
      lex();
      if(token == 'g')
      {
        indice = indiceC * 12 + cont;
        insere(r,token,indiceC);
        cont++;
        lex();
        if(token == '(')
        {
          indice = indiceC * 12 + cont;
          insere(r,token,indiceC);
          cont++;
          lex();
          if(token == ')')
          {
            indice = indiceC * 12 + cont;
            insere(r,token,indiceC);
            cont++;
            lex();
          }
          else
          {
            erro(103);
          }
        }
        else
        {
          erro(102);
        }
      }
      else
      {
        erro(101);
      }
    }
    else
    {
      erro(13);
    }
  }
  else if (token == 'i')
  {
    indice = indiceC * 12 + cont;
    insere(r,token,indiceC);
    cont++;
    lex();
    if (token == '=')
    {
      indice = indiceC * 12 + cont;
      insere(r,token,indiceC);
      cont++;
      lex();
      if(token == 'n')
      {
        indice = indiceC * 12 + cont;
        insere(r,token,indiceC);
        cont++;
        lex();
        if(token == '(')
        {
          indice = indiceC * 12 + cont;
          insere(r,token,indiceC);
          cont++;
          lex();
          if(token == ')')
          {
            indice = indiceC * 12 + cont;
            insere(r,token,indiceC);
            cont++;
            lex();
          }
          else
          {
            erro(106);
          }
        }
        else
        {
          erro(105);
        }
      }
      else
      {
        erro(104);
      }
    }
    else
    {
      erro(14);
    }
  }
  else if (token == 'j')
  {
    indice = indiceC * 12 + cont;
    insere(r,token,indiceC);
    cont++;
    lex();
    if (token == '=')
    {
      indice = indiceC * 12 + cont;
      insere(r,token,indiceC);
      cont++;
      lex();
      indice = indiceC * 12 + cont;
      insere(r,'E',indiceC);
      cont++;
      E(r);
    }
    else
    {

      erro(15);
    }
  }
  else if (token == 'k')
  {
    indice = indiceC * 12 + cont;
    insere(r,token,indiceC);
    cont++;
    lex();
    if (token == '=')
    {
      indice = indiceC * 12 + cont;
      insere(r,token,indiceC);
      cont++;
      lex();
      indice = indiceC * 12 + cont;
      insere(r,'E',indiceC);
      cont++;
      E(r);
    }
    else
    {
      erro(16);
    }
  }
  else if (token == 'z')
  {
    indice = indiceC * 12 + cont;
    insere(r,token,indiceC);
    cont++;
    lex();
    if (token == '=')
    {
      indice = indiceC * 12 + cont;
      insere(r,token,indiceC);
      cont++;
      lex();
      indice = indiceC * 12 + cont;
      insere(r,'E',indiceC);
      cont++;
      E(r);
    }
    else
    {
      erro(17);
    }
  }

  else if (token == '(')
  {
    indice = indiceC * 12 + cont;
    insere(r,token,indiceC);
    cont++;
    lex();
    indice = indiceC * 12 + cont;
    insere(r,'E',indiceC);
    cont++;
    E(r);
    indice = indiceC * 12 + cont;
    insere(r,'X',indiceC);
    cont++;
    X(r);
    indice = indiceC * 12 + cont;
    insere(r,'E',indiceC);
    cont++;
    E(r);
    if (token == ')')
    {
      indice = indiceC * 12 + cont;
      insere(r,token,indiceC);
      cont++;
      lex();
    }
    else
    {
      erro(19);
    }
  }
  else if (token == 'w')
  {
    indice = indiceC * 12 + cont;
    insere(r,'w',indiceC);
    cont++;
    lex();
    W(r);
  }
  else if (token == 'f')
  {
    indice = indiceC * 12 + cont;
    insere(r,'f',indiceC);
    cont++;
    lex();
    F(r);
  }
  else if (token == 'o')
  {
    indice = indiceC * 12 + cont;
    insere(r,'o',indiceC);
    cont++;
    lex();
    O(r);
  }
  else
  {
    erro(20);
  }
}

void D(PONT* r)
{
  int cont = 1;
  int indiceD = indice;
  if(token == '}')
  {
    indice = indiceD * 12 + cont;
    insere(r,token,indiceD);
    cont++;
    lex();  
  }
  else if(token == ';')
  {
    indice = indiceD * 12 + cont;
    insere(r,token,indiceD);
    cont++;
    lex();
    indice = indiceD * 12 + cont;
    insere(r,'C',indiceD);
    cont++;
    C(r);
    indice = indiceD * 12 + cont;
    insere(r,'D',indiceD);
    cont++;
    D(r);
  }
  else erro(107);
}

void W(PONT* r)
{
  int cont = 1;
  int indiceW = indice;
  if (token == '(')
  {
    indice = indiceW * 12 + cont;
    insere(r,'(',indiceW);
    cont++;
    lex();
    indice = indiceW * 12 + cont;
    insere(r,'E',indiceW);
    cont++;
    E(r);
    if (token == ')')
    {
      indice = indiceW * 12 + cont;
      insere(r,token,indiceW);
      cont++;
      lex();
      if (token == '{')
      {
        indice = indiceW * 12 + cont;
        insere(r,token,indiceW);
        cont++;
        lex();
        indice = indiceW * 12 + cont;
        insere(r, 'C', indiceW);
        cont++;
        C(r);
        indice = indiceW * 12 + cont;
        insere(r, 'D', indiceW);
        cont++;
        D(r);
      }
      else
      {
        erro(23);
      }
    }
    else
    {
      erro(24);
    }
  }
  else
  {
    erro(25);
  }
}

void F(PONT* r)
{
  int cont = 1;
  int indiceF = indice;
  if (token == '(')
  {
    indice = indiceF * 12 + cont;
    insere(r, token, indiceF);
    cont++;
    lex();
    indice = indiceF * 12 + cont;
    insere(r, 'E', indiceF);
    cont++;
    E(r);
    if (token == ')')
    {
      indice = indiceF * 12 + cont;
      insere(r, token, indiceF);
      cont++;
      lex();
      if (token == '{')
      {
        indice = indiceF * 12 + cont;
        insere(r, token, indiceF);
        cont++;
        lex();
        indice = indiceF * 12 + cont;
        insere(r, 'C', indiceF);
        cont++;
        C(r);
        indice = indiceF * 12 + cont;
        insere(r, 'D', indiceF);
        cont++;
        D(r);
      }
      else
      {
        erro(28);
      }
    }
    else
    {
      erro(29);
    }
  }
  else
  {
    erro(30);
  }
}

void O(PONT* r)
{
  int cont = 1;
  int indiceO = indice;
  if (token == '(')
  {
    indice = indiceO * 12 + cont;
    insere(r, token, indiceO);
    cont++;
    lex();
    indice = indiceO * 12 + cont;
    insere(r, 'E', indiceO);
    cont++;
    E(r);
    if (token == ';')
    {
      indice = indiceO * 12 + cont;
      insere(r, token, indiceO);
      cont++;
      lex();
      indice = indiceO * 12 + cont;
      insere(r, 'E', indiceO);
      cont++;
      E(r);
      if (token == ';')
      {
        indice = indiceO * 12 + cont;
        insere(r, token, indiceO);
        cont++;
        lex();
        indice = indiceO * 12 + cont;
        insere(r, 'E', indiceO);
        cont++;
        E(r);
        if (token == ')')
        {
          indice = indiceO * 12 + cont;
          insere(r, token, indiceO);
          cont++;
          lex();
          if (token == '{')
          {
            indice = indiceO * 12 + cont;
            insere(r, token, indiceO);
            cont++;
            lex();
            indice = indiceO * 12 + cont;
            insere(r, 'C', indiceO);
            cont++;
            C(r);
            indice = indiceO * 12 + cont;
            insere(r, 'D', indiceO);
            cont++;
            D(r);
          }
          else
          {
            erro(33);
          }
        }
        else
        {
          erro(34);
        }
      }
      else
      {
        erro(35);
      }
    }
    else
    {
      erro(36);
    }
  }
  else
  {
    erro(37);
  }
}

void N(PONT* r)
{
  int cont = 1;
  int indiceN = indice;
  indice = indiceN * 12 + cont;
  insere(r, 'n', indiceN);
  cont++;
  if (token == '(')
  {
    indice = indiceN * 12 + cont;
    insere(r, token, indiceN);
    cont++;
    lex();
    if (token == ')')
    {
      indice = indiceN * 12 + cont;
      insere(r, token, indiceN);
      cont++;
      lex();
      if (token == '{')
      {
        indice = indiceN * 12 + cont;
        insere(r, token, indiceN);
        cont++;
        lex();
        indice = indiceN * 12 + cont;
        insere(r, 'A', indiceN);
        cont++;
        A(r);
        if (token == ';')
        {
          indice = indiceN * 12 + cont;
          insere(r, token, indiceN);
          cont++;
          lex();
          if (token == 'r')
          {
            indice = indiceN * 12 + cont;
            insere(r, token, indiceN);
            cont++;  
            lex();
            if (token == '(')
            {
              indice = indiceN * 12 + cont;
              insere(r, token, indiceN);
              cont++;
              lex();
              indice = indiceN * 12 + cont;
              insere(r, 'E', indiceN);
              cont++;
              E(r);
              if (token == ')')
              {
                indice = indiceN * 12 + cont;
                insere(r, token, indiceN);
                cont++;
                lex();
                if (token == ';')
                {
                  indice = indiceN * 12 + cont;
                  insere(r, token, indiceN);
                  cont++;    
                  lex();
                  if (token == '}')
                  {
                    indice = indiceN * 12 + cont;
                    insere(r, token, indiceN);
                    cont++;  
                    lex();
                  }
                  else
                  {
                    erro(38);
                  }
                }
                else
                {
                  erro(70);
                }
              }
              else
              {
                erro(39);
              }
            }
            else
            {
              erro(40);
            }
          }
          else
          {
            erro(41);
          }
        }
        else
        {
          erro(42);
        }
      }
      else
      {
        erro(43);
      }
    }
    else
    {
      erro(44);
    }
  }
  else
  {
    erro(45);
  }
}

void G(PONT* r)
{
  int cont = 1;
  int indiceG = indice;
  indice = indiceG * 12 + cont;
  insere(r, 'g', indiceG);
  cont++;
  if (token == '(')
  {
    indice = indiceG * 12 + cont;
    insere(r, token, indiceG);
    cont++;
    lex();
    if (token == ')')
    {
      indice = indiceG * 12 + cont;
      insere(r, token, indiceG);
      cont++;
      lex();
      if (token == '{')
      {
        indice = indiceG * 12 + cont;
        insere(r, token, indiceG);
        cont++;
        lex();
        indice = indiceG * 12 + cont;
        insere(r, 'A', indiceG);
        cont++;
        A(r);
        if (token == ';')
        {
          indice = indiceG * 12 + cont;
          insere(r, token, indiceG);
          cont++;
          lex();
          if (token == 'r')
          {
            indice = indiceG * 12 + cont;
            insere(r, token, indiceG);
            cont++;  
            lex();
            if (token == '(')
            {
              indice = indiceG * 12 + cont;
              insere(r, token, indiceG);
              cont++;
              lex();
              indice = indiceG * 12 + cont;
              insere(r, 'E', indiceG);
              cont++;
              E(r);
              if (token == ')')
              {
                indice = indiceG * 12 + cont;
                insere(r, token, indiceG);
                cont++;
                lex();
                if (token == ';')
                {
                  indice = indiceG * 12 + cont;
                  insere(r, token, indiceG);
                  cont++;
                  lex();
                  if (token == '}')
                  {
                    indice = indiceG * 12 + cont;
                    insere(r, token, indiceG);
                    cont++;
                    lex();
                  }
                  else
                  {
                    erro(46);
                  }
                }
                else
                {
                  erro(80);
                }
              }
              else
              {
                erro(47);
              }
            }
            else
            {
              erro(48);
            }
          }
          else
          {
            erro(49);
          }
        }
        else
        {
          erro(50);
        }
      }
      else
      {
        erro(51);
      }
    }
    else
    {
      erro(52);
    }
  }
  else
  {
    erro(53);
  }
}