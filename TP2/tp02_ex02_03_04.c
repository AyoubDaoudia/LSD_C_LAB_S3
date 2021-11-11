#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double f(double);
double fp(double);
double Dichotomie(double(*f)(double),double a, double b, int n);
double Newton(double(*f)(double),double(*fp)(double), double x, int n);

double f(double x){
	return x*x-2;
}

double fp(double x){
	return 2*x;
}

double Dichotomie(double(*f)(double),double a, double b, int n){
	double k = (a+b)/2;
	for(int i =0 ; i < n; i++){
		if(f(a)*f(k)<0){
			b=k;
		}
		else{
			a=k;
		}
		k = (a+b)/2;
	}
	return k;
}

double Newton(double(*f)(double),double(*fp)(double), double x, int n){
	for(int i = 0 ; i< n; i++){
		x=x-(f(x)/fp(x));
	}
	return x;
}


double Dichotomie2(double(*f)(double),double a, double b, int e)
{
	double x0=Dichotomie(*f,a,b,1);
	double x1=Dichotomie(*f,a,b,2);
	int i=0;
	while( abs(x1-x0)>e)
	{
		x0=x1;
		x1=Dichotomie(*f,a,b,i);
		i++;
	}
	return x0;
}

double g(double x){
	return (x*x*x - x -3);
}

double gp(double x){
	return (3*x*x - 1);
}

int main(){
	//Exercice 5
	/*double a = 0;
	double b = 3;
	printf("By Dichotomie:\n");
	double c;
	c = Dichotomie(&f,a,b,3);
	printf("%f\n",c);
	c = Dichotomie(&f,a,b,10);
	printf("%f\n",c);
	c = Dichotomie(&f,a,b,20);
	printf("%f\n",c);
	printf("By Newton :\n");
	double d;
	d = Newton(&f,&fp,2,3);
	printf("%f\n",d);
	d = Newton(&f,&fp,2,10);
	printf("%f\n",d);
	d = Newton(&f,&fp,2,20);
	printf("%f\n",d);
	//double e = Dichotomie2(&f,a,b,pow(10,-9));
	//printf("%f\n",e);
	*/
	//Exercice 6
	int n = 100;
	double Arr[n];
	Arr[0] = 1;
	for(int i = 1 ; i < n ; i++ ){
		Arr[i] = Newton(&g,&gp,Arr[i-1],1);
	}
	/*for(int i = 0 ; i < n ; i++){
		printf("%d %.51lf\n",i,Arr[i]);
	}*/
	for(int i = 1 ; i < n ; i++ ){
		printf("%.10lf\n",1e-10);
		if(abs(Arr[i-1] - Arr[i]) < 1e-10){
			printf("yes\n");
		}
		if(abs(Arr[i-1] - Arr[i]) < 1e-10){
			printf("%.30lf\n",Arr[i-1] - Arr[i]);
			printf("%d\n%.30lf\n%.30lf\n",i,Arr[i],Arr[i-1]);
			break;
		}
	}
	return 0;
}
