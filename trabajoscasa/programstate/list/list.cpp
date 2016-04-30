#include <stdio.h>
#include <stdlib.h>

int main(){

     const char *list[] = {
       "bread", 
       "toast",
       "bacon"
     };

     printf("%s %s %s \n", list[2],list[1], list[0]);



    return EXIT_SUCCESS;
}
