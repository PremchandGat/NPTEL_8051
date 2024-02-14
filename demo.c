#include <at89c5131.h>

sbit pin = P1^6;

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
	P1 = 0x00;
    while(1)
    {
        pin = 1;
        msdelay(500);
        pin = 0;
        msdelay(500);
    }
}