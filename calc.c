//Leonardo Oneda Galvani    RA: 20.00196-7
//Renan Germano                    RA: 20.01879-7
//Ubiratan da Motta Filho      RA:20.00928-3
//Breno Yukio Harazaki           RA: 20.01303-5

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "pilha.c"

void ExibirPilha(TPilha);

int main(){

    char cmd[MAX_STRING] = "a";
    TPilha p;
    Dados ent, arg1, arg2, result;

    CriarPilha(&p);

    while (strcmpi(cmd, "FIM") != 0){
        
        read_string(cmd);

       if (strcmpi(cmd, "+") == 0){
            if (QuantidadeNaPilha(p) >= 2){
                RetirarDaPilha(&p, &arg1);
                RetirarDaPilha(&p, &arg2);
                result.valor = arg1.valor + arg2.valor;
                InserirNaPilha(&p, result);
            }
            else{
                printf("Impossivel realizar a soma, digitar mais argumentos...\n");
            }

        }

        else if (strcmpi(cmd, "-") == 0){
            if (QuantidadeNaPilha(p) >= 2){
                RetirarDaPilha(&p, &arg1);
                RetirarDaPilha(&p, &arg2);
                result.valor = arg2.valor - arg1.valor;
                InserirNaPilha(&p, result);
            }
            else{
                printf("Impossivel realizar a subtracao, digitar mais argumentos...\n");
            }

        }

        else if (strcmpi(cmd, "*") == 0){
            if (QuantidadeNaPilha(p) >= 2){
                RetirarDaPilha(&p, &arg1);
                RetirarDaPilha(&p, &arg2);
                result.valor = arg2.valor * arg1.valor;
                InserirNaPilha(&p, result);
            }
            else{
                printf("Impossivel realizar a multiplicacao, digitar mais argumentos...\n");
            }

        }

        else if (strcmpi(cmd, "/") == 0){
            if (QuantidadeNaPilha(p) >= 2){
                RetirarDaPilha(&p, &arg1);
                RetirarDaPilha(&p, &arg2);
                if (arg1.valor == 0){
                    printf("Vc eh um lesado, impossivel dividir por 0.");
                    InserirNaPilha(&p, arg2);
                }
                else{
                    result.valor = arg2.valor / arg1.valor;
                    InserirNaPilha(&p, result);
                }
                
            }
            else{
                printf("Impossivel realizar a divisao, digitar mais argumentos...\n");
            }

        }

        else if (strcmpi(cmd, "SIN") == 0){
            if (QuantidadeNaPilha(p) >= 1){
                RetirarDaPilha(&p, &arg1);

                result.valor = sin(arg1.valor);
                InserirNaPilha(&p, result);
            }
            else{
                printf("Vc nao tem argumentos na pilha...\n");
            }

        }

        else if (strcmpi(cmd, "COS") == 0){
            if (QuantidadeNaPilha(p) >= 1){
                RetirarDaPilha(&p, &arg1);

                result.valor = cos(arg1.valor);
                InserirNaPilha(&p, result);
            }
            else{
                printf("Vc nao tem argumentos na pilha...\n");
            }

        }

        else if (strcmpi(cmd, "RAIZ") == 0){
            if (QuantidadeNaPilha(p) >= 1){
                RetirarDaPilha(&p, &arg1);
                if (arg1.valor < 0){
                    printf("Vc eh lesado, digite um valor maior ou igual a 0.");
                }
                else{
                    result.valor = sqrt(arg1.valor);
                    InserirNaPilha(&p, result);
                }
                
            }
            else{
                printf("Vc nao tem argumentos na pilha...\n");
            }

        }

        else if (strcmpi(cmd, "PI") == 0){
            result.valor = M_PI;
            InserirNaPilha(&p, result);
        }

        else{ 
            ent.valor = atof(cmd);
            InserirNaPilha(&p, ent);
        }
        
    ExibirPilha(p);
    }


    return 0;
}

void ExibirPilha(TPilha p){
    printf("\nPilha:\n\n");

    for (int i=0; i<=p.topo; i++){
        printf("%i:\t\t%.2f\n", i, p.elemento[i].valor);
    }
    
    printf("\n");
}