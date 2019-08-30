#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>

double f(double x){
    //return x*x-2;
    //return 3*(x*x)-(12*x)+29;
    //return 3*x-cos(x);
	//return x*log10(x) - 1.2;
	//return cos(x)-x;
	//return (x*x*x*x)-(26*x*x)+24*x+21;
	return x-exp(-x);
	//return 10*x+(x*x*x)+2;
}

int main(){
    double a, b, m_ant,m;
    int i = 0,e=0.001,max_it=10;
	setlocale(LC_ALL, "PORTUGUESE");
	
    printf("Entre com o intervalo [A]:\n");
    scanf("%lf",&a);
    printf("Entre com o intervalo [B]:\n");
    scanf("%lf",&b);
    system("cls");
    
    m_ant = b;
    while (i < max_it){
        if(f(a) == 0){
            printf("A raiz é %lf.\n", a);
        }

        if(f(b) == 0){
            printf("A raiz é %lf.\n", b);
        }

        if(f(a)*f(b) < 0){
        	
            m = a-((b-a)*f(a)/(f(b)-f(a))); // Regula Falsi
            
            printf("\nResultado iteração %d: \t%.4f\nValor a:\t%.2f\nValor b:\t%.2f", i+1, m, a, b);
            
			if(f(m) < 0 || fabs(f(m)-f(m_ant)) < e){
                printf("\nA raiz é %lf.\n", m);
                break;
            }

            if(f(a)*f(m) < 0)
                b = m;
            else
                a = m;

            m_ant = m;
        	}
        
		else{
            printf("Intervalo não contém raíz.\n");
            printf("Entre com o intervalo [A]:\n");
    		scanf("%lf",&a);
    		printf("Entre com o intervalo [B]:\n");
    		scanf("%lf",&b);
            m_ant = b;
            i = 0;
        }
        i++;
    }
    printf("\nNúmero máximo de iterações atingido.\n");
}
