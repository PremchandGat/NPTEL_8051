#include <at89c5131.h>

sbit p5 = P1^5;
sbit p6 = P1^6;
sbit p7 = P1^7;
sbit p4 = P1^4;

sbit i0 = P1^0;
sbit i1 = P1^1;
sbit i2 = P1^2;
sbit i3 = P1^3;


void msdelay(unsigned int time)
{
	int i,j;
	for(i=0;i<time;i++);
	{
		for(j=0;j<382;j++);
	}
}


void main()
{
	i0 = i2 = i3 = i1 =  1;
    while(1)
    {
			if(i0 == 1){
			p4 = 1;
			}
			if(i1 == 1){
			p5 = 1;
			}
			if(i2 == 1){
			p6 = 1;
			}
			if(i3 == 1){
			p7 = 1;
			}
        msdelay(500);
			  p4 = p5 = p6 = p7 =  0 ;
        msdelay(500);
    }
}