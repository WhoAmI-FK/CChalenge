#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#define PSIZE 20
#define RSIZE 15
#define ROWS 8
#define COLS 8
#define MAXL 10
#define W_MAX 100
#define W_MIN 16
#define W_DEFAULT 40
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

int isLeapYear(int year){
	if(year%400 == 0) return 1;
	if(year%100 == 0) return 0;
	if(year%4 == 0) return 1;
	return 0;
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


void printChessBoard(char chessboard[ROWS][COLS]){
	int i,j;
	puts("\n--------");
	for(i = 0;i<ROWS;++i){
		for(j = 0;j<COLS;++j){
			printf("%c",chessboard[i][j]);
		}
		puts("\n");
	}
	puts("--------");
}

double phi(double g, double precision){
	if(precision){
		return g + 1/phi(g,precision-1);
	} 
	return g;
}

int getNumberLength(int64_t num){
	int counter = 0;
	while(num){
		num/=10;
		counter++;
	}
	return counter;
}

void formatOutput(int64_t num){
	int tmp,i,j;
	int num_length;
	num_length = getNumberLength(num);
	if(num_length>MAXL){
		printf("The value apparently is too large to handle\n");
		return;	
	}
	for(i = num_length;i>0;i--){
		if(i%3==0 && i != num_length) printf(",");
		tmp = num;
		for(j=0;j<(i-1);++j){
			tmp/=10;
		}
		printf("%d",tmp%10);
	}
}

struct frame{
	char b1,b2;
	int ball1, ball2, score;
};
 
 int ball_roll(int pins)
 {
 	return (rand()%(pins+1));
 }
 
 void fill_frame(struct frame* f){
 	f->ball1 = ball_roll(10);
 	if(f->ball1==10){
 		f->b1 = ' ';
 		f->b2 = 'X';
 		f->ball2 = 0;
 		f->score=10;
	 }else{
	 	f->b1 = f->ball1 ? f->ball1 + '0' : '-';
	 	f->ball2 = ball_roll(10-f->ball1);
	 	if(f->ball1 + f->ball2 == 10)
	 	{
	 		f->b2 = '/';	
		}else{
			f->b2 = f->ball2 ? f->ball2+'0' : '-';
		}
		f->score = f->ball1 + f->ball2;
	 }
 }
void writeline(char *s, char *e)
{
	do
	{
		if( *s=='\0' )		/* avoid reading beyond the end */
			return;
		putchar(*s);
		s++;
	}
	while(s<=e);
}

char* months[] = {
	{"January"},
	{"February"},
	{"March"},
	{"April"},
	{"May"},
	{"June"},
	{"July"},
	{"August"},
	{"September"},
	{"October"},
	{"November"},
	{"December"}
};

char* weekDays[]={
	{"Monday"},
	{"Tuesday"},
	{"Wednesday"},
	{"Thursday"},
	{"Friday"},
	{"Saturday"},
	{"Sunday"}
};

int daysOfMonthsLeap[12] = {
		31,
		29,
		31, 
		30,
		31,
		30,
		31,
		31,
		30,
		31,
		30,
		31
	};
	int daysOfMonths[12] = {
		31,
		28,
		31, 
		30,
		31,
		30,
		31,
		31,
		30,
		31,
		30,
		31
	};	

void initDaysOfMonths(int* arr, int Year){
	int isLeap,i;
	isLeap = isLeapYear(Year);
	for(i = 0;i<12;i++){
		*(arr+i) = isLeap ? *(daysOfMonthsLeap+i) : *(daysOfMonths+i);
	}
}

void showNextMonday(int extraDays,int Month,int Day,int Year){
	int feb;
	int* monthsDays = (int*)malloc(sizeof(int)*12);
	initDaysOfMonths(monthsDays,Year);
	while(extraDays){
		if(Day==monthsDays[Month-1]){
			Day = 1;
			Month++;
		} else Day++;
		if(Month==13){
			Month = 1;
			Year++;
		}
		extraDays--;
	}
	printf("\nNext Monday will be the %d%s of %s, %d",
		Day,
		(Day%10) == 1 && (Day!=11)? "st"
		: (Day%10) == 2 && (Day!=12)? "nd" 
		: (Day%10) == 3 && (Day!=13)? "rd" 
		: "th",
		months[Month-1],
		Year
	);
	free(months);
}

struct matrix {
	int rows;
	int cols;
	char *cells;
};

void fill_matrix(struct matrix g)
{
	int row,col;

	for( row=0; row<g.rows; row++ )
		for( col=0; col<g.cols; col++ )
			*(g.cells+(row*g.cols)+col) = (rand() % 26) + 'a';
}
void output_matrix(struct matrix g)
{
	int row,col;

	for( row=0; row<g.rows; row++ )
	{
		for( col=0; col<g.cols; col++ )
			printf(" %c",*(g.cells+(row*g.cols)+col));
		putchar('\n');
	}
}

void rotate_matrix(struct matrix *g)
{
	struct matrix *r;
	int rsize,x,y,i;

	/* create the new (temporary) matrix */
	r = (struct matrix *)malloc( sizeof(struct matrix) );
	if( r==NULL )
	{
		fprintf(stderr,"Unable to allocate new matrix\n");
		exit(1);
	}
	/* swap the rows and columns (for output) */
	r->rows = g->cols;
	r->cols = g->rows;
	rsize = r->rows*r->cols;
	r->cells = (char *)malloc( sizeof(char)*rsize );
	if( r->cells==NULL )
	{
		fprintf(stderr,"Unable to allocate cell memory\n");
		exit(1);
	}

	/* fill the new matrix with rotated contents */
	i = 0;
	for( x=0; x<g->cols; x++ )
	{
		for( y=g->rows-1; y>=0; y-- )
		{
			/* The cells are read in a rotated fashion,
			   from the bottom of the first column up
			   row-by-row, to the top of the last column.
			   The rotated cell's contents are filled
			   sequentially using variable 'i' */
			*(r->cells+i) = *(g->cells+(g->cols*y)+x);
			i++;
		}
	}

	/* copy back to the original matrix */
	for( i=0; i<rsize; i++ )
		*(g->cells+i) = *(r->cells+i);
	/* reset original matrix dimensions */
	g->cols = r->cols;
	g->rows = r->rows;

	/* free allocated memory */
	free(r->cells);
	free(r);
}


int main(int argc, char* argv[])
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
	/*
	char string[] = "Once upon a time, there was a string";
	printf("Original string: %s\n",string);
	printf("Left %d characters: %s\n",16, left(string,16));
	printf("Right %d characters: %s\n",18,right(string,18));
	printf("Middle %d characters: %s\n",11,mid(string,13,11));
	*/
	/* task 7 */
	/*
	int i;
	for(i = 1582;i<=2101;++i){
		if(isLeapYear(i)) printf("%d is a leap year\n",i);
	}
	*/
	/* task 8 */
	/*
	char *playlist[PSIZE] = {
		"Like a Rolling Stone", "Satisfaction", "Imagine",
		"What's Going On", "Respect", "Good Vibrations",
		"Johnny B. Goode", "Hey Jude", "What'd I Say",
		"Smells Like Teen Spirit", "My Generation",
		"Yesterday", "Blowin' in the Wind", "Purple Haze",
		"London Calling", "I Want to Hold Your Hand",
		"Maybellene", "Hound Dog", "Let It Be",
		"A Change Is Gonna Come"
	};
	int frequency[PSIZE];
	int recent[RSIZE];
	int x,r,count,found;
	*/
	/* initialize */
	/*
	srand( (unsigned)time(NULL) );
	for(x=0;x<PSIZE;x++)
		frequency[x] = 0;
	for(x=0;x<RSIZE;x++)
		recent[x] = -1;			/* -1 because no element is -1 */ 

	
	/* run through the playlist randomly */
	/*
	puts("Playlist:");
	count = 0;
	while(count<100)
	{
		/* does r appear in recent[]? */
	/*	found = 1;				/* assume it does */
	/*	while(found)
		{
			r = rand() % PSIZE;		/* random value */
	/*		found = 0;				/* not found yet */
	/*		for(x=0;x<RSIZE;x++)
			{
				if( r==recent[x] )
	/*				found=1;		/* found! */
	/*		}
		}
		recent[count%RSIZE] = r;		/* play the song */
	/*	printf("%3d: Now Playing '%s'\n",
				count+1,
				playlist[r]
			  );
		frequency[r]++;
		count++;
	}

	puts("Song frequency:");
	for(x=0;x<PSIZE;x++)
		printf("%s: %d\n",playlist[x],frequency[x]);
	*/
	/* task 9 */
	/*
	int i,j,_x,_y,count,direction,_pos_x,_pos_y;
	char chessboard[ROWS][COLS];
	srand( (unsigned)time(NULL) );
	direction = 0;
	count = 0;
	for(i = 0;i<ROWS;++i){
		for(j = 0;j<COLS;++j)
			chessboard[i][j] = '.';
	}
	_x = 5;
	_y = 4;
	_pos_x = _x;
	_pos_y = _y;
	chessboard[_y][_x] = 'K'; 
	printChessBoard(chessboard);
	while(1){
	while(chessboard[_y][_x]!='.'){
		_x = _pos_x;
		_y = _pos_y;
		direction = rand()%8 + 1;
		switch(direction){
			case 1:
				_y++;
				break;
			case 2:
				_y--;
				break;
			case 3:
				_x++;
				break;
			case 4:
				_x--;
				break;
			case 5:
				_x++;
				_y++;
				break;
			case 6:
				_x--;
				_y++;
				break;
			case 7:
				_x++;
				_y--;
				break;
			case 8:
				_x--;
				_y--;
				break;
		}
	}
	_pos_x = _x;
	_pos_y = _y;
	chessboard[_y][_x]='K';
	puts("\n");
	printChessBoard(chessboard);
	puts("\n");
	count++;
	if((_y+1)==ROWS || (_x+1)==COLS){
		count++;
		printf("\nTHE END\n");
		printf("%d MOVES REQUIRED.",count);
		return;
	}	
	}
	*/
	/* task 10 */
	/*
		struct matrix grid[3] = {
		{ 8, 3, NULL },
		{ 5, 5, NULL },
		{ 4, 6, NULL }
	};
	int x;

	srand( (unsigned)time(NULL) );

	for( x=0; x<3; x++ )
	{
		grid[x].cells = (char *)malloc( sizeof(char)*grid[x].rows*grid[x].cols );
		if( grid[x].cells==NULL )
		{
			fprintf(stderr,"Memory allocation error on grid #%d\n",
					x
				   );
			exit(1);
		}
	}


	for( x=0; x<3; x++ )
	{
		fill_matrix(grid[x]);
		printf("Original matrix %d:\n",x+1);
		output_matrix(grid[x]);
		rotate_matrix(&grid[x]);
		printf("Rotated matrix: %d:\n",x+1);
		output_matrix(grid[x]);
	}
	*/
	/* task 11 */
	/*
	int i,dayOfWeek,Month,Day,Year,count;
	count =0;
	scanf("%d",&dayOfWeek);
	scanf("%d",&Month);
	scanf("%d",&Day);
	scanf("%d",&Year);
	printf("Today is %s, %s %d%s, %d",
		weekDays[dayOfWeek-1],
		months[Month-1],
		Day,
		(Day%10) == 1 && (Day!=11)? "st"
		: (Day%10) == 2 && (Day!=12)? "nd" 
		: (Day%10) == 3 && (Day!=13)? "rd" 
		: "th",
		Year
	);
	if(dayOfWeek==1){
		count = 7;		
	}else{
	while(dayOfWeek!=1){
			dayOfWeek = (dayOfWeek+1)%7;
			count++;
	}
	}
	showNextMonday(count,Month,Day,Year);
	*/
	/* task 12 */
	/*formatOutput(48266);*/
	
	/* task 13 */
	/*
	struct frame* f = (struct frame*)malloc(sizeof(struct frame)*1);
	srand( (unsigned)time(NULL) );
	fill_frame(f);
	printf("\n| %c|%c|\n",f->b1,f->b2);
	printf("| %2d |\n",f->score);
	free(f);
	*/
	/* task 14 */
	/*
	printf("%lf",phi(1.0,30));
	*/
	/*task 15*/
	/* 
	static char *text = "Shall I compare thee to a summer's day? \
Thou art more lovely and more temperate:\n\
Rough winds do shake the darling buds of May, \
And summer's lease hath all too short a date;\n\
Sometime too hot the eye of heaven shines, \
And often is his gold complexion dimm'd;\n\
And every fair from fair sometime declines, \
By chance or nature's changing course untrimm'd;\n\
But thy eternal summer shall not fade, \
Nor lose possession of that fair thou ow'st;\n\
Nor shall death brag thou wander'st in his shade, \
When in eternal lines to time thou grow'st:\n\
So long as men can breathe or eyes can see, \
So long lives this, and this gives life to thee.";
	printf("%s",text);
	char *start,*end;
	int width;

	width = W_DEFAULT;
	if( argc>1 )
	{
		width = strtol(argv[1],NULL,10);
		if( width<W_MIN || width>W_MAX )
			width=W_DEFAULT;	
	}

	start = end = text;				
	while( *end )					
	{
		if( *end=='\n')
		{
			writeline(start,end);	
			end++;					
			start = end;		
		}
		else
		{
			end++;					
			if( end==start+width )
			{
				while( !isspace(*end) )
				{
					end--;
					if( start==end )
					{
						end+=width;		
						break;
					}
				}
				writeline(start,end);
				if( *end != '\n')		
					putchar('\n');		
				end++;					
				start = end;			
			}
		}
	}
	writeline(start,end);			
	if( *end != '\n')				
		putchar('\n');
	*/
	return 0;
}
