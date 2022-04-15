#include <stdlib.h>
#include <stdio.h>

char* ordinal(int number){
	int digit = number%10;
	char* retVal = number > 20 ? 
					digit==1 ? "st" 
					: digit==2 ? "nd" 
					: digit==3 ? "rd"
					: "th"
				 : number < 10 ?
				 	digit==1 ? "st"
				  : digit == 2 ? "nd"
				  : digit == 3 ? "rd"
				  : "th"
				 : "th";
	return retVal;	
}

int main()
{
	/* task 1 */
	int c;
	
	for(c = 1;c<=20;c++){
		printf("%3d%s\t%3d%s\t%3d%s\t%3d%s\t%3d%s\t%3d%s\n",c,ordinal(c),c+20,ordinal(c+20),
		c+30,ordinal(c+30),c+40,ordinal(c+40),
		c+60,ordinal(c+60),c+80,ordinal(c+80));
	}
	

}
