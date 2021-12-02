#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Exercice 1
double PolyLagrange(double* X, double x, int i, int n ){
    double r = 1;
    for(int j = 0 ; j < n ; j++){
        if (i != j){
            r *= ( x - X[j] ) / ( X[i] - X[j] );
        }
    }
    return r;
}

//Exercice 2

double InterpLagrange(double* X, double(*f)(double),double x, int n){
    double r = 0;
    for(int i = 0 ; i < n ; i++){
        r += f(X[i])*PolyLagrange(X,x,i,n);
    }
    return r;
}

//Exercice 3

double f1(double x){
    return sin(x);
}

double f2(double x){
    return exp(x);
}

double f3(double x){
    return 1/(1+x*x);
}

double* xlist(double a, double b, int n){
    double* arr = (double*)malloc(sizeof(double)*n+1);
    double j = a;
    int i = 0;
    while(j <= b){
        arr[i] = j;
        j += (b-a)/n;
        i++; 
    }
    arr[n]=b;
    return arr;
}

double* ylist(double* xlist,double(*f)(double),int n){
    double* arr =(double*)malloc(sizeof(double)*n+1);
    for(int i = 0 ; i < n+1 ; i++){
        arr[i] = f(xlist[i]);
    }
    return arr;
}

double* ylistInterp(double* xlist1,double* xlist2,double(*f)(double*,double(*)(double),double,int),int n,int m){
    double(*functions[])(double)={f1,f2,f3};
    int o = n * 10;
    double* arr =(double*)malloc(sizeof(double)*o+1);
    for(int i = 0 ; i < o+1 ; i++){
        arr[i] = f(xlist1,functions[m],xlist2[i],n);
    }
    return arr;
}

void freelist(double* list){
    free(list);
    return;
}

int main(){
    double(*functions[])(double)={f1,f2,f3};
    double a,b;
    int n,m,o;
    printf("Please enter the points :\n");
    scanf("%lf%lf%d",&a,&b,&n);
    printf("For the sin function type 0, for the exp function type 1:\n");
    scanf("%d",&m);
    FILE* fptr;
    fptr = fopen("Function.txt","w");
    //For the functions
    o = n * 10;
    double* X1 = xlist(a,b,o);
    double* Y1 = ylist(X1,functions[m],o);
    fprintf(fptr,"#xvalues\t\tyvalues\n");
    for (int i = 0; i < o+1; i++)
    {
        fprintf(fptr,"%lf\t\t%lf\n",X1[i],Y1[i]);
    }
    fclose(fptr);
    fptr = fopen("Interp.txt","w");
    //For the interpolation
    double* X2 = xlist(a,b,n);
    double* Y2 = ylistInterp(X2,X1,&InterpLagrange,n,m); 
    fprintf(fptr,"#xvalues\t\tyvalues\n");
    for (int i = 0; i < o+1; i++)
    {
        fprintf(fptr,"%lf\t\t%lf\n",X1[i],Y2[i]);
    }
    fclose(fptr);
    freelist(X1);
    freelist(X2);
    freelist(Y1);
    freelist(Y2);
    return 0;
}