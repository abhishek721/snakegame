#include<iostream>
#include<cstdlib>
#include<conio.h>
#include<windows.h>
using namespace std;


bool gameover;
const int width=20;
const int height=20;
int x,y,fruitX, fruitY,score;
enum eDirection { STOP=0, LEFT, RIGHT, UP, DOWN};
eDirection Dir;
int tailX[100],tailY[100];
int nTail;


void setup()
{ 

gameover=false;
Dir=STOP; 
x=width/2;
y=width/2;
fruitX = rand() % width;
fruitY = rand() % height;
score = 0;

}

void draw()
{
system("cls");
Dir=STOP;
for(int i=0; i<width+2; i++)
cout<<"#";
cout<<endl;

for(int i=0;i<height; i++)
{
	for(int j=0;j<width; j++)
	{
		if(j==0)
		cout<<"#";
		
		if(i==y && j==x)
		cout<<"O";
		else if(i==fruitY && j==fruitX)
		cout<<"F";
		else{
			bool print=false;
			for(int k=0;k<nTail;k++){
				if(tailX[k]==j && tailY[k]==i){
				cout<<"o";
				print=true;
			}
			}
			if(!print)
		cout<<" ";
		}
		
		
		if(j==width-1)
		cout<<"#";
	}
	cout<<endl;
}
for(int i=0; i<width+2; i++)
cout<<"#";
cout<<endl;
cout<<"Score :"<<score<<endl;
}

void Input(){
	
if(_kbhit()){
	switch(_getch()){
		case 'a':
			Dir= LEFT;
			break;
		case 'd':
			Dir= RIGHT;
			break;
		case 'w':
			Dir=UP;
			break;
		case 's':
			Dir=DOWN;
			break;
		case 'x':
			gameover=true;
			break;
		
		  
	}
}
}


void Logic(){
	
	int prevX=tailX[0];
	int prevY=tailY[0];
	tailX[0]=x;
	tailY[0]=y;
	int prev2X,prev2Y;
	for(int i=1;i<nTail;i++){
		prev2X=tailX[i];
		prev2Y=tailY[i];
		tailX[i]=prevX;
		tailY[i]=prevY;
		prevX=prev2X;
		prevY=prev2Y;
	}
	switch(Dir){
		case RIGHT:
			x++;
			break;
		case LEFT:
		    x--;
			break;
		case UP:
			y--;
			break;
		case DOWN:
			y++;
			break;
		default:
			break;
		  }
	//if(x>width || x<0 || y>height || y<0)
	//gameover=true;
	if(x>=width) x=0 ;else if(x<0) x=width;
	if(y>=height) y=0 ;else if(y<0) y=height;
	if(x==fruitX && y==fruitY){
		
		score +=10;
	   fruitX = rand() % width;
       fruitY = rand() % height;
       nTail++;
	}
}



int main(){
	setup();
	while(!gameover){
	draw();
	Input();
	Logic();
    Sleep(5);
	}
	
return 0;
}

