#include <at89c5131.h>
long unsigned int x = 14571;
long unsigned int y = 8636;
long unsigned int x1 = 0;
long unsigned int x0 = 0;
long unsigned int y1 = 0;
long unsigned int y0 = 0;
long unsigned int z0 = 0;
long unsigned int z1 = 0;
long unsigned int z2 = 0;
long unsigned int z = 0;

long unsigned int thomas(unsigned int x , unsigned int y){
long	unsigned int x1 = x/10;
long	unsigned int x0 = x%10;
long	unsigned int y1 = y/10;
long	unsigned int y0 = y%10;
long	unsigned int z0 = x0*y0;
long	unsigned int z1 = (x0+x1)*(y0+y1);
long	unsigned int z2 = x1*y1;
long	unsigned int z = z0 + (z1 - z0 - z2)*10 + z2*100;
return z;
}


//Thomas Algo
void main(){
	
	// Timer Mode
	TMOD = 0x01;
	
	TH0 = 0;
	TL0 = 0;
  
	// Start timer 0

	
	// thomas(14571, 8636);
	TR0 = 1;
   x1 = x/10;
	x0 = x%10;
	y1 = y/10;
	y0 = y%10;
	z0 = x0*y0;
	z1 = (x0+x1)*(y0+y1);
	z2 = x1*y1;
	z = z0 + (z1 - z0 - z2)*10 + z2*100;
	TR0 = 0;
	while(1);
}