#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

/*Program Name*/
//Maximum Name is 3 //
//change the value of 'NUM' if your program name is less than 3 //
#define FIRST "Awesome"
#define SECOND "Title"
#define THIRD "Generator"
#define NUM 3 	//number of program name


/* Magic Code Define */
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define CLEAN "\033[37m"
#define CURSAVE "\033[s"
#define CURBACK "\033[u"
#define CLEAR "\033[2J"

#define CURSOR_OFF "\e[?25l"
#define CURSOR_ON  "\e[?25h"

#define MAX 500

/*Prototype Declaration */
void wait(float timer,int on);
void fastwait(float timer,int limit);
void title();
void close();


void cursor_off(){
		printf(CURSOR_OFF);
}

void cursor_on(){
		printf(CURSOR_ON);
}

/*Global Variable*/
char color[10][10] = {RED,GREEN,YELLOW,BLUE,MAGENTA,CYAN,CLEAN};
char programe_name[3][25];
int numtitle=0;

void close(){
		int i=0;
		int x=0;
		while(i<26){
				for(x=0;x<6;x++){
						printf("%s*",color[x]);
				}

				i++;
		}
		printf("\n");
}

void name(int numb,char *p1,char *p2,char *p3){
	numtitle = numb;
	int i ;
	strcpy(programe_name[0],p1);
	strcpy(programe_name[1],p2);
	strcpy(programe_name[2],p3);
}

void title(){
		int x=0;
		int i=0;
		int lineCount =10;
		int startPoint = lineCount;
		printf(CLEAR"\033[3;0f");
		printf(CURSOR_OFF);
		printf("\033[%dC",lineCount);
		while(i<25){
				for(x=0;x<6;x++){
						printf("%s*\n",color[x]);
						fastwait(0.00001,40);
						printf("\033[1A\033[%dC",lineCount);
						lineCount++;
				}
				i++;
		}
		for(x=0;x<5;x++){
				printf("\n\033[%dC",startPoint);
				fastwait(0.00001,40);
				printf("%s*\033[%dC%s*",color[x],lineCount-startPoint-3,color[x]);
		}
		printf("\033[1B\033[1D"); //Down Back Cursor

		while(i>0){
				for(x=0;x<6;x++){
						printf("%s*\n",color[x]);
						fastwait(0.00001,40);
						printf("\033[1A\033[%dC",lineCount-2);
						lineCount--;
				}
				i--;
		}
		printf("\n%s",CURSAVE);

		//Write Title (Header can use while write(Include Number and Array stings input) 
	
		
		if(numtitle==1){
		printf("\033[4A\033[73C");
		printf("%s%s",programe_name[0],CURBACK);
		}
		if(numtitle==2){
		printf("\033[4A\033[62C");
		printf("%s\n",programe_name[0]);
		wait(1.0,0);
		printf("\033[1A\033[85C");
		printf("%s%s",programe_name[1],CURBACK);
		}
		if(numtitle==3){
		printf("\033[4A\033[62C");
		printf("%s\n",programe_name[0]);
		wait(1.0,0);
		printf("\033[1A\033[73C");
		printf("%s\n",programe_name[1]);
		wait(1.0,0);
		printf("\033[1A\033[85C");
		printf("%s%s",programe_name[2],CURBACK);
		}
		printf("\033[65C%s...Program Generating...\n",CLEAN);
		wait(1.0,0);
		printf(CURSOR_ON);
		return ;
}



void fastwait(float timer,int limit){
		float x =0.0;
		for(x=0.0;x<limit;x+=timer){}
		return;
}


void wait(float timer,int on){
		time_t now,then;
		float delay =0.0f;
		time(&then);
		cursor_off();
		while(delay < timer){
				time(&now);
				delay = difftime(now,then);
				if(on == 1){
						printf("\033[60C...PLease Wait For %.2f Second...\r",timer-delay);
				}
		}
		cursor_on();
		return;

}
