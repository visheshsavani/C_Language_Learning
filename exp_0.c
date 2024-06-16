#include <stdio.h>
#include <math.h>
// ln n function
double natural_log(double n){
return log(n);
}
// 2^n function
double power_1(double n){
return (double) pow(2,n);
}
// 2^2^n function
double power_n(double n){
return (double)pow(2,power_1(n));
}
// 2^2^(n+1) function
double power_2(double n){
return (double)pow(2,power_1(n+1));
}
// lnln(n) function
double log_log(double n){
return log(natural_log(n));
}
// lg(n) of base 2 function
double log_base2(double n){
return log(n)/log(2);
}
// n * lg(n) function
double n_multiply(double n){
return n * log_base2(n);
}
// sqaureroot_lg(n) function
double squareroot_lg(double n){
return (double)pow(log_base2(n),0.5);
}
// n function
int linear(int n){
return n;
}
// lg(n) ^ lg(n) function
double lg_power(double n){
return pow(log_base2(n),log_base2(n));
}
// n factorial function
int factorial(int n){
if(n < 1) return 1;
else return factorial(n-1)*n;
}
int main(){
for (int i = 0; i < 100; i++)
{
    /* code */
    printf("Taking the input as %d\n",i);
    printf("%d\n",linear(i));
    printf("%.4f\n",natural_log(i));
    printf("%.4f\n",power_1(i));
    printf("%.4f\n",power_2(i));
    printf("%.4f\n",squareroot_lg(i));
    printf("%.4f\n",log_base2(i));
    printf("%.4f\n",log_log(i));
    printf("%.4f\n",power_n(i));
    printf("%.4f\n",n_multiply(i));
    printf("%.4f\n",lg_power(i));
    printf("\n");
}

for (int i = 0; i < 20; i++)
{
    /* code */
    printf("The factorial of %d is %d\n",i,factorial(i));
}   
return 0;
}
