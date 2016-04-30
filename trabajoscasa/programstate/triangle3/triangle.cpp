#include <stdio.h>
 #include <stdlib.h>
    
      int main(){
                int h;
		printf("cual es h? \n");
		scanf("%i",&h);
        
        
                for (int l1=0; l1<h; l1++){
	         for (int l2=0; l2<h; l2++)

		     if(l2>l1)
			 printf(" ");
		     else
	            
	            printf("*");
	  
	 
	         printf("\n");}
  return EXIT_SUCCESS;

      }

