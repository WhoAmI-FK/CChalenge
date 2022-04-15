#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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

void center_text(int width, char* text){
	char* output = (char*)malloc(width*sizeof(char));
	int text_length = (int)strlen(text);
	int spaces, i,j;
	if(text_length>width){
		width+= (text_length-width);
	}
	spaces = (int)((width-text_length)/2);
	for(i = 0;i<spaces;++i){
		*(output+i) = ' ';
	}
	for(j = spaces,i=0;i<text_length;++j,++i){
		output[j] = text[i];
	}
	output[j]='\0';
	printf("%s\n",output);
}

int chall(int n){
	if(n==1) return n;
	
	if(n%2==0) return (n/2);
	
	if(n%2!=0) return (n*3)+1;
}

void Collatz_Conjecture(int number){
	int counter =1;
	while(number!=1){
		printf("%d ",number);
		number = chall(number);
		counter++;
	}
	printf("%d \nSequence length: %d",number,counter);
}


int getLength(char* s){
	int i;
	for(i = 0;(*(s+i))!='\0';++i);
	return i;
}

char* left(char* s, int len){
	static char* buff;
	int i,original_length;
	original_length = getLength(s);
	if(len>original_length) len = original_length;
	buff = (char*)malloc((len+1)*sizeof(char));
	if(buff==NULL) exit(1);
	for(i = 0;i<len;++i){
		*(buff+i) = *(s+i);
	}
	*(buff+i) = '\0';
	return buff;
}

char* right(char* s, int len){
	static char* buff;
	int i, original_length,j;
	original_length = getLength(s);
	if(len>original_length) len = original_length;
	buff = (char*)malloc((len+1)*sizeof(char));
	if(buff==NULL) exit(1);		
	for(i = original_length-len,j=0;j<len;i++,j++)
	*(buff+j) = *(s+i);
	*(buff+j) = '\0';
	return buff;
}


char* mid(char* s, int offset,int len){
	static char* buff;
	int i, original_length,j;
	original_length = getLength(s);
	if(len>original_length) len = original_length;
	buff = (char*)malloc((len+1)*sizeof(char));
	if(buff==NULL) exit(1);
	for(i = 0;i<len;i++)
	{
		*(buff+i) = *(s+offset-1+i);
		if(*(buff+i)=='\0') break;
	}
	*(buff+i)='\0';
	return buff;
}

int main()
{
	/* task 1 */
	/*
	int c;
	
	for(c = 1;c<=20;c++){
		printf("%3d%s\t%3d%s\t%3d%s\t%3d%s\t%3d%s\t%3d%s\n",c,ordinal(c),c+20,ordinal(c+20),
		c+30,ordinal(c+30),c+40,ordinal(c+40),
		c+60,ordinal(c+60),c+80,ordinal(c+80));
	}
	*/
	/* task 2 */
	/*
	char* title[] = {
		"March Sales",
		"My First Project",
		"Centering output is so much fun!",
		"This title is very long, just to see whether the code can handle such a long title"
	};
	int x;
	for(x=0;x<4;x++){
		center_text(80,title[x]);
	}
	*/
	/* task 3 */
	/*
	float amount[] = {
		0.49, 1.27, 0.75, 1.31, 0.83
	};
	int x, coins, quarters, dimes, nickels, pennies;
	for(x = 0;x<5;x++){
		quarters=dimes=nickels=pennies=0;
		printf("Making change for: $%.2f\n",amount[x]);
		coins = amount[x]*100;
		quarters = (int)((coins>0 ? coins : 0)/25);
		coins-=(quarters*25);
		dimes = (int)((coins>0 ? coins : 0)/10);
		coins-=(dimes*10);
		nickels = (int)((coins>0?coins:0)/5);
		coins-=(nickels*5);
		pennies = coins > 0 ? coins : 0;
		printf("\t%d quarters, %d dimes, %d nickels, %d pennies\n",
		quarters,dimes,nickels,pennies);
	}
	*/
	/* task 4 */
	/*
	int n;
	printf("Input positive integer:\t");
	scanf("%d",&n);
	Collatz_Conjecture(n);
	*/
	/* task 5 */
	/*
	char original[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char deck[27],shuffle[27];
	const int shufsize =13;
	int count, s,d;
	
	printf("Original deck: %s\n",original);
	strcpy(deck,original);
	count = 0;
	while(1){
		for(d = 0,s=0;d<shufsize;d++,s+=2){
			shuffle[s] = deck[d];
			shuffle[s+1] = deck[d+shufsize];
		}
		shuffle[s] = '\0';
		count++;
		printf("%2d: %s\n",count, shuffle);
		if(strcmp(original,shuffle)==0)
		break;
		strcpy(deck, shuffle);
	}
	*/
	/* task 6 */
	char string[] = "Once upon a time, there was a string";
	printf("Original string: %s\n",string);
	printf("Left %d characters: %s\n",16, left(string,16));
	printf("Right %d characters: %s\n",18,right(string,18));
	printf("Middle %d characters: %s\n",11,mid(string,13,11));
	return 0;
}
