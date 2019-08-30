#include<stdio.h>
#include<conio.h>
#include<math.h>

float f(float x){
    //return (1/x);	// Slide
    
    //return exp(x);	// A
    //return (1/x*x);		// B
    //return (1/pow((1+x),x));	// C
    //return (pow(x,2)/pow((x-1),2));		// D
    return (pow(x,3)+pow(x,2)+x+1);		// E
}


int main(){
    int i,n;
    double a,b,h,y[20],so,se,x[20],l;
    
    a=3.0;
	b=3.3;
    n=6;
    
    if(n%2==1){
        n=n+1;
    }
    h=(b-a)/n;
    printf("\nNumeros de Partes:%d\nNumero de H: %.4lf\n",n,h);
    printf("Valores de X/Y:\n");
    
	for(i=0; i<=n; i++){
        x[i]=a+i*h;
        y[i]=f(x[i]);
        printf("X[%d] = %lf\t",i,x[i]);
        printf("Y[%d] = %lf\n",i,y[i]);
        
    }
    so=0;
    se=0;
    for(i=1; i<n; i++){
        
		if(i%2==1){
            so=so+y[i];
        }
        else{
            se=se+y[i];
        }
    }
    
    l=h/3*(y[0]+y[n]+4*so+2*se);
    printf("\nI final %lf",l);   
}
