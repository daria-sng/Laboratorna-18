#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N1 4
#define N2 6

void input(double array[], int N);
void calculation(double array[], int N, double function1(double), double function2(double), double function3(double), double *p1, double *p2, double *p3);

int main(){
    system("chcp 65001");
    double x[N1], y[N2], A, B, C, D, E, F, gamma;
    input(x, N1);
    input(y, N2);

    calculation(x,N1,sin,cos,tan,&A,&B,&C);
    calculation(y,N2,tan,exp,cos,&D,&E,&F);

    printf("A = %lf\n", A);
    printf("B = %lf\n", B);
    printf("C = %lf\n", C); 
    printf("D = %lf\n", D);
    printf("E = %lf\n", E);
    printf("F = %lf\n", F);

    if( D+E*sin(F) > 0 ){
        gamma = (A+B*(cos(C))) / (D+E*sin(F));
        printf("Результат гамми: %lf", gamma);
    }
    else{
        printf("Увага! Ділення на нуль, спробуйте ще раз!");
    }
    return 0;
}

void input(double array[], int N){
    printf("Введіть значення елементів для масиву (Розміри - 4, 6) ");
    int i;
    for(i=0; i<N; i+=1){
        scanf("%lf", &array[i]);
    };
}

void calculation(double array[], int N, double function1(double), double function2(double), double function3(double), double *p1, double *p2, double *p3){
    double s = 0;
    double p = 1;
    *p1 = 0;
    *p2 = 0; 
    *p3 = 0;
    int i;
    for(i=0; i<N; i+=1){
        s+=array[i];
        p*=array[i];
    }
    for(i=0; i<N; i+=1){
        *p1 += array[i]*function1(array[i]);
        *p2 += array[i]*function2(array[i]);
        *p3 += array[i]*function3(array[i]);
    }
    *p1 *= s;
    *p2 *= p;
    *p3 *= (s+p);
}