#include <stdio.h>
int main()
{
    int producto1,producto2,producto3,subTotal,IVA,Total,descuento,pago;
    printf(" Producto 1 ? ");
	scanf("%d",&producto1);
    printf( " Producto 2 ? ");
    scanf("%d",&producto2);
    printf(" Producto 3 ? ");
    scanf("%d",&producto3);
    subTotal=producto1+producto2+producto3;
    printf("\n EL Subtotal de tu compra es: %d ",subTotal);
    IVA=15;
    printf("\n EL itebis es: %d ",IVA);
    Total=subTotal+IVA;
    printf("\n El Total: %d",Total);
    descuento=23;
    printf("\n Descuento: %d ",descuento);
    Total= Total - descuento;
    printf("\n El total final es: %d",Total);
  	printf("\n Con cuanto pagas? ",pago);
  	scanf("%d",&pago);
  	if (pago<Total)//En caso de que el pago sea menor que el total marcara cuanto dinero le falta.
	  {
  		printf("Le faltan %d para completar su pago.",Total-pago);
	}
	else{
		printf("\n Tu cambio es: %d", pago-Total);
	  }
	  return 0;
}
