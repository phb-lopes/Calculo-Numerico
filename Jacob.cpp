#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<locale.h>
#define max 4


int main(){
float s[max][max];
float b[max];
float chute_inicial[max],dp[max];
float up=0,erro;
float jacob[max];
float margem=0.0,aux=0,soma;;
int i=0,j=0,cont=0,l=0,op=1;
setlocale(LC_ALL, "Portuguese");

	printf("Equação:\n");
    for(i=0;i<max;i++){
        for(j=0;j<max;j++){
            printf("Insira o valor %d da equação %d\n",j+1,i+1);
            scanf("%f",&s[i][j]);
        }
        system("cls");
    }

	for(i=0;i<max;i++){
        for(j=0;j<max;j++){
			if(i==j){
            	dp[j]=s[i][j];
			}
		}
		jacob[i]=0;
	}

	system("cls");
    printf("Valores de B:\n");

	for(i=0;i<max;i++){
        printf("Insira o valor de B para a equação %d\n",i+1);
        scanf("%f",&b[i]);
    }

	system("cls");
    printf("Equação:\n");

	for(i=0;i<max;i++){
        for(j=0;j<max;j++){
            printf(" %.1fx%d ",s[i][j],j+1);
        }
        printf("= %.1f ",b[i]);
        printf("\n");
    }

	printf("Valores para o chute inicial\n");

    for(i=0;i<max;i++){
        printf("Valor %d:\n",i+1);
        scanf("%f",&chute_inicial[i]);
    }

	printf("Margem de erro?\n");
    scanf("%f",&erro);

    system("cls");

    printf("Critério das Linhas:\n");
    for(i=0;i<max;i++){
        up=0;
        for(j=0;j<max;j++){
			if(i != j){
                up += s[i][j];
            }
        }

        up=up/dp[i];

        if(up<1){
            printf("Sistema Ok : %.2f\n",up);
            cont++;
		}if(up>=1){
			printf("Sistema No-Ok\n");
		}
	}
	printf("\n");


	while((op==1) & (l<10)){
	printf("\nInteração[%d]:\n",l+1);
		for(i=0;i<max;i++){
			aux=0;
	   		for(j=0;j<max;j++){
    			if(i != j){
	   				aux = aux + ( s[i][j] * (chute_inicial[j]) );
				}
			}
		jacob[i] = (b[i] - aux)/dp[i];
		}

		soma=0.0;
		for(i=0;i<max;i++){
			soma = soma +  ( pow((jacob[i]-chute_inicial[i]),2));
		}

		margem = sqrt(soma);


		if(margem<=erro){
			op=0;
		}

		for(i=0;i<max-1;i++){
			chute_inicial[i]=jacob[i];
			printf("Numero[%d]:%f\t",i+1,chute_inicial[i]);		
		}

		l++;
		printf("\n\nMargem %d:%f\n",l,margem);

	} // Fecha while da margem
	printf("\n");
	printf("Jacob Final:\n");

	for(i=0;i<max;i++){
		printf("x%d:%f\n",i+1,jacob[i]);
	}
	printf("\n");
	system("pause");
}

