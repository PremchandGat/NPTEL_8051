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
long unsigned int z3 = 0;
long unsigned int z =  0;

long unsigned int stevenAlgo(unsigned int x , unsigned int y){
long unsigned int x1 = x/10;
long unsigned int x0 = x%10;
long unsigned int y1 = y/10;
long unsigned int y0 = y%10;
long unsigned int z0 = x0*y0;
long unsigned int z1 = x0*y1;
long unsigned int z2 = x1*y0;
long unsigned int z3 = x1*y1;
long unsigned int z = z0 + (z1 + z2)*10 + z3*100;
return z;
}

/// Steve Algorithm
void main(){
	
	// Timer Mode
	TMOD = 0x01;
	
	TH0 = 0;
	TL0 = 0;
  
	// Start timer 0
	TR0 = 1;
	//stevenAlgo(14571, 8636);
	x1 = x/10;
	x0 = x%10;
	y1 = y/10;
	y0 = y%10;
	z0 = x0*y0;
	z1 = x0*y1;
	z2 = x1*y0;
	z3 = x1*y1;
	z = z0 + (z1 + z2)*10 + z3*100;
	TR0 = 0;
	while(1);
}