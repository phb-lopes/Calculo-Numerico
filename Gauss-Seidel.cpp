#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<locale.h>
#define X 4
int main(){
    double x[X][X+1],chute_inicial[X],chute_inicial2[X],t,aux,e,gauss[X];
    float soma=0,erro=0.001;
    int i,j,mxit=10,cont=0,k=0;
    setlocale(LC_ALL, "Portuguese");

	for(i=1;i<=X;i++) chute_inicial[i]=0;
	for(i=1;i<=X;i++) chute_inicial2[i]=0;
    
	for(i=0;i<X;i++){
	    for(j=0;j<X+1;j++){
    	printf("Insira o valor %d da equação %d\n",j+1,i+1);
		scanf("%lf",&x[i][j]);
    	}
    	system("cls");
    }
    
    printf("\nGauss-Seidel Final:\n\n");
	
	while(cont<mxit){
		printf("Interação [%d]\n",cont+1);
        for(i=0;i<X-1;i++){
            aux=0;
            for(j=0;j<X;j++,k++){
            	if(j!=i){
            		aux+=x[i][j]*chute_inicial[j];
				}
			}
            t=(x[i][X]-aux)/x[i][i];
            chute_inicial[i]=t;
            gauss[i]=chute_inicial[i];
			
			printf("Número[%d]: %f\t",i+1,chute_inicial[i]);		
        }			
		printf("\n");
		
		soma=0.0;
		
		for(i=0;i<X;i++){
			soma = soma +  ( pow((gauss[i]-chute_inicial2[i]),2));
		}
		soma = sqrt(soma);
		
		for(i=0;i<X;i++){
			chute_inicial2[i]=gauss[i];
		}
		
		printf("Margem de erro: %f\n\n",soma);   
        
		if(soma<=erro){
			break;
		}
	    cont++;
	    if(cont==11){
	    	printf("Números não convergem\n");
	    	break;
		}
    }
    
    printf("Critério de parada final: %f\n",soma);
    printf("Números finais calculados\n");
	for(i=0;i<X;i++){
		printf("x[%d]:%f\n",i+1,chute_inicial2[i]);
	}
	
    printf("\n");
	system("PAUSE");
	
	return 0;
}

