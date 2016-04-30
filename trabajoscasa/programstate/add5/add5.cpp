#include <stdio.h>
#include <stdlib.h>

void add(double  num1,double num2){
  	
	
double added = num1 +num2;
printf("\n add = %lf", added);


}
int main(){
    double input1, input2;
    scanf("%lf",&input1);
    scanf("%lf",&input2);

    add(input1,input2);

    return EXIT_SUCCESS;
}
