#include <stdio.h>

int main()
{
	int a=5,b=3, c=-12;
	printf ("A= %i, B=%i, C=%i",a,b,c);
	printf("\n a) a > 3: %i ", a>3);
	printf("\n b) a > c: %i ", a>c);
	printf("\n c) a < c: %i ", a<c);
	printf("\n d) b < c: %i ", b<c);
	printf("\n e) b != c: %i ", b!=c);
	printf("\n f) a == 3: %i ", a==3);
	printf("\n g) a * b == 15: %i ", a*b==15);
	printf("\n h) a * b == -30: %i ", a*b==-30);
	printf("\n i) c / b < a: %i ", c/b<a);
	printf("\n j) c / b == -10: %i ", c/b==-10);
	printf("\n k) c /b == -4: %i ", c/b==-4);
	printf("\n m) (a+b==8) &&(a-b==2) : %i ",(a+b==8) &&(a-b==2));
	printf("\n n) (a+b==8) || (a-b==6) : %i ",(a+b==8) || (a-b==6));
	printf("\n o) a>3 && b>3 && c<3 : %i ",a>3 && b>3 && c<3 );
	printf("\n p) a>3 && b>=3 && c<-3 : %i ",a>3 && b>=3 && c<-3 );

return 0;
	
}



