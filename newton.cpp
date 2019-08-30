#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>

double f(double x){
    //return (x*x*x) - (6*(x*x)) - x + (30*x); // A
	//return (3*x)-cos(x);	// B
	//return x+(2*cos(x));	//C
	//return pow(x,3)-exp(2*x)+3;	// D
	//return 2*(pow(x,3))+(x*x)-2;	// E
	//return exp(cos(x))+(x*x*x)-3;	// F
	//return 0,1*(x*x*x)-exp(2*x)+2;	//G
	//return pow(x,3) - 5*pow(x,2) + x +3;	// H
	//return 2*x - sin(x) + 4; // I
	return pow(10,x)+pow(x,3)+2;	// J
}

double df(double x){
    //return 3*(x*x)-(12*x)-29;		//A
    //return 3+x*sin(x);	// B
	//return 1 - sin(x);	// C
	//return 3*(x*x)-(2*exp(2*x));	//D
	//return 6*(x*x)+2*x;		// E
	//return -sin(x)*exp(cos(x)) + 3*pow(x,2); // F
	//return 0.3*(x*x) - 2*exp(2*x);	//G
	//return 3*(x*x)-10*x+1;	//H
	//return x - cos(x);	// I
	return pow(10,x)*log(10) + 3*pow(x,2);
}


int main(){
    double a, b, xn = 0, m_ant,e=0.001;
    int i = 0;
    int max_it=10;
    setlocale(LC_ALL, "PORTUGUESE");

    printf("Entre com o intervalo [A]:\n");
    scanf("%lf",&a);
    printf("Entre com o intervalo [B]:\n");
    scanf("%lf",&b);
        
    system("cls");
    
    if(df(a) > df(b)){
        xn = a;
    }
    else{
        xn = b;
    }
    
    m_ant = xn;
    while (i < max_it){
        if(f(a) == 0){
            printf("A raiz é %lf.\n", a);
        }

        if(f(b) == 0){
            printf("A raiz é %lf.\n", b);
        }
		
        if(f(a)*f(b) < 0){
            double m = 0;
            double fxn = 0;
            double dfxn = 0;
            fxn = f(xn);
            dfxn = df(xn);
            m = xn-(fxn/dfxn);
            
			printf("\nResultado iteração %d: \t%.4f\nValor x[%d]:\t%.2f", i+1, m,i+1, xn);
            
			if(f(m) == 0 || fabs(f(m)-f(m_ant)) < e){
                printf("\nA raiz é %lf.\n", m);
                break;
            }
            m_ant = m;
            xn = m;
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
    system("PAUSE");
}
