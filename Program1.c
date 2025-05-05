#include <stdio.h>
#include <stdlib.h>
#define N 5

double function1(double x, double y);
double function2(double x, double y);
double function3(double x, double y);
double function4(double x, double y);
double function5(double x, double y);

int main(){
    system("chcp 65001");
    printf("Введіть x та y для обчислень: ");
    double x, y;
    scanf("%lf%lf", &x, &y);

    double array[N];
    double (*p[])(double x, double y) = {function1, function2, function3, function4, function5};
    int i;
    printf("x = %.3lf\ny = %.3lf\n", x, y);
    for(i=0; i<N; i+=1){
        array[i] = p[i](x,y);
        printf("%d.Результат = %.4lf\n", i+1, array[i]);
    }
    return 0;
}

double function1(double x, double y){
    return x*y + y*10;
}

double function2(double x, double y){
    return x - y;
}

double function3(double x, double y){
    return 3*x/4;
}

double function4(double x, double y){
    return x + 2*y;
}

double function5(double x, double y){
    return (x - y)/4;
}