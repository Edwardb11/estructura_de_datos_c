#include <stdio.h>

int main()
{
	int h,m,s,cal;
	printf("Introduzca horas: ");
	scanf("%d",&h);
	printf("Introduzca minutos: ");
	scanf("%d",&m);
	printf("Introduzca segundos: ");
	scanf("%d",&s);
	
	cal=(h*3600)+(m*60)+s;
	printf("Han pasado %d segundos.",cal);
}
