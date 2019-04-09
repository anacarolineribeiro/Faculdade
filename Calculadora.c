    #include <stdio.h>
    #include <locale.h>
    #include <math.h>
    #include <string.h>

typedef struct
{
    char bin[32];
    int dec;
    char hexa[8];
}Binario;


void Converte2_10(Binario *B)
{
    int i, Resultado= 0, t, p=0;
    t = strlen(B[0].bin)-1;
    for (i=t;i>=0;i--)
    {
        int pot = pow(2,p);
        Resultado += ((B[0].bin[i]-'0')*pot);
        p++;
    }
    B[0].dec = Resultado;
    printf("Conversão de Base 2 para 10 = %d\n", B[0].dec);
}

void Converte10_x(int valor, int E, int S)
{
    Binario EsteBin[1];
    char hexa[7] = {'A','B','C','D','E','F'};
    int i, r=1, q = valor;
    for (i=0;i<=32; i++)
    {
        EsteBin[0].bin[i] = NULL;
    }
    i = 0;
    while (q>=S-1)
    {
        r = q%S;
        q/=S;
        if (r>9&&S==16) EsteBin[0].bin[i] = hexa[r-10];
        else EsteBin[0].bin[i] = r+'0';
        i++;
    }
    if (q>9&&S==16) EsteBin[0].bin[i] = hexa[q-10];
    else EsteBin[0].bin[i] = q + '0';

    int t = strlen(EsteBin[0].bin);
    printf("Conversão de Base %d para %d = ",E, S);
    for (i=t-1;i>=0;i--)
    {
        printf("%c", EsteBin[0].bin[i]);
    }
    printf("\n");
}

void ConverteX_10(Binario *B, int E)
{
    char Letrahexa[7] = {'A','B','C','D','E','F'};
    int i, Resultado= 0, v=0, t, p=0, y;
    t = strlen(B[0].hexa)-1;
    for (i=t;i>=0;i--)
    {
        int pot = pow(E,p);
        if (E==16)
        {
            if (B[0].hexa[i]-'0'<=9){ v = B[0].hexa[i]-'0';
            printf("Teste <9 v = %d, B = %c\n", v, B[0].hexa[i]);}
            else
            {
                for (y=0;y<=5;y++)
                {
                    if (B[0].hexa[i] == Letrahexa[y]){
                    v = y+10;
                    break;}
                }
                printf("Teste >9 v = %d, B = %c\n", v, B[0].hexa[i]);
            }
        }
        else v = B[0].hexa[i]-'0';
        Resultado += (v*pot);
        p++;
    }
    B[0].dec = Resultado;
    printf("Conversão de Base %d para 10 = %d\n", E, B[0].dec);
}

int TestaEntrada(Binario *B, int valor, int E)
{
    int i;
    if (E==16)
    {
        for (i = 0;i<=strlen(B[0].hexa)-1;i++)
        {
            if (B[0].hexa[i]-'0'<=9||B[0].hexa[i]=='A'||B[0].hexa[i]=='B'||
                B[0].hexa[i]=='C'||B[0].hexa[i]=='D'||B[0].hexa[i]=='E'||
                B[0].hexa[i]=='F') return 1;
            else
            {
                printf("Valor Inválido para base %d. Informe outro valor.", E);
                return 0;
            }
        }
    }
    else if (E==2)
    {
        for (i = 0;i<=strlen(B[0].bin)-1;i++)
        {
            if (B[0].bin[i]=='0'||B[0].bin[i]=='1') return 1;
            else
            {
                printf("Valor Inválido para base %d. Informe outro valor.", E);
                return 0;
            }

        }
    }
    else if (E==5||E==8)
    {
        for (i = 0;i<=strlen(B[0].hexa)-1;i++)
        {
            if (B[0].hexa[i]-'0'>=0) return 1;
            else
            {
                printf("Valor Inválido para base %d. Informe outro valor:", E);
                return 0;
            }

        }
    }
    else if (E==10)
    {
        if (valor>=0) return 1;
        else
        {
            printf("Valor Inválido para base %d. Informe outro valor:", E);
            return 0;
        }
    }
}

int main()
{
    do
    {
        setlocale(LC_ALL, "Portuguese");
        int valor, E, Teste;

        printf("\n************************Conversor de bases numéricas************************\n");
        printf("Informe sua base (2, 5, 8, 10 ou 16): ");
        do{
            scanf("%d",&E);
            if (E==2||E==5||E==8|E==10||E==16) Teste = 0;
            else
            {
                printf("Valor de entrada %d inválido. Informe outro valor: ", E);
                Teste = 1;
            }
        } while(Teste!=0);

        if (E == 2)
        {
            Binario EsteBin[1];
            printf("Informe o valor para conversão: ");
            do{
            scanf("%s", &EsteBin[0].bin);
            Teste = TestaEntrada (EsteBin[0].bin, 0, E);
            }while (Teste != 1);
            Converte2_10(EsteBin[0].bin);
            Converte10_x(EsteBin[0].dec, E, 5);
            Converte10_x(EsteBin[0].dec, E, 8);
            Converte10_x(EsteBin[0].dec, E, 16);
        }
        if (E==5)
        {
            Binario EsteBin[1];
            printf("Informe o valor para conversão: ");
            do{
            scanf("%s", &EsteBin[0].hexa);
            Teste = TestaEntrada (EsteBin[0].bin, 0, E);
            }while (Teste != 1);
            ConverteX_10(EsteBin[0].bin, E);
            Converte10_x(EsteBin[0].dec, E, 2);
            Converte10_x(EsteBin[0].dec, E, 8);
            Converte10_x(EsteBin[0].dec, E, 16);
        }
        if (E==8)
        {
            Binario EsteBin[1];
            printf("Informe o valor para conversão: ");
            do{
            scanf("%s", &EsteBin[0].hexa);
            Teste = TestaEntrada (EsteBin[0].bin, 0, E);
            }while (Teste != 1);
            ConverteX_10(EsteBin[0].bin, E);
            Converte10_x(EsteBin[0].dec, E, 2);
            Converte10_x(EsteBin[0].dec, E, 5);
            Converte10_x(EsteBin[0].dec, E, 16);
        }
        if (E==10)
        {
            printf("Informe o valor para conversão: ");
            do{
            scanf("%d", &valor);
            Teste = TestaEntrada (0, valor, E);
            }while (Teste != 1);
            Converte10_x(valor, E, 2);
            Converte10_x(valor, E, 5);
            Converte10_x(valor, E, 8);
            Converte10_x(valor, E, 16);
        }
        if (E==16)
        {
            Binario EsteBin[1];
            printf("Informe o valor para conversão: ");
            do{
            scanf("%s", &EsteBin[0].hexa);
            Teste = TestaEntrada (EsteBin[0].bin, 0, E);
            }while (Teste != 1);
            ConverteX_10(EsteBin[0].bin, E);
            Converte10_x(EsteBin[0].dec, E, 2);
            Converte10_x(EsteBin[0].dec, E, 5);
            Converte10_x(EsteBin[0].dec, E, 8);
        }
    }while (getchar() == '\n');
}
