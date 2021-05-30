#include <stdio.h>

int main()
{
int Nhoras,Nminutos,Nsegundos;
printf("Edward Brito Diaz\n");
printf("2019-0823\n");
printf("\nMuestra la hora 1 segundo despues \n");

printf("\nIntroduzca la hora: ");
scanf("%d",&Nhoras);
printf("Introduzca los minutos: ");
scanf("%d",&Nminutos);
printf("Introduzca los segundos: ");
scanf("%d",&Nsegundos);
if (Nsegundos == 59 ){
	Nminutos=Nminutos+1;
	Nsegundos=0;
	printf("Si le sumas un segundo seran las %d:%d:%d  ",Nhoras,Nminutos,Nsegundos);
}
else{
		Nsegundos=Nsegundos+1;
	printf("Si le sumas un segundo seran las %d:%d:%d  ",Nhoras,Nminutos,Nsegundos);
}




}
