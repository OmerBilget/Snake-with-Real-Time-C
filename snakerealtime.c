#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define size 100

void screen(int dimx,int dimy,int SIZE, int a[SIZE][SIZE]);
void increase(int snake_size,int dimx,int dimy,int SIZE, int a[SIZE][SIZE]);
void food(int dimx,int dimy,int SIZE,int a[SIZE][SIZE]);
int foodcheck(int dimx,int dimy,int SIZE,int a[SIZE][SIZE]);
int main(){
	srand(time(0));
	int a[size][size];
	int i,j;
	int SIZE=size;
	int dimx=15;
	int dimy=15;
	for(i=0;i<dimx;i++){
		for(j=0;j<dimy;j++){
			if(i==0 || i==dimx-1 || j==0 || j==dimy-1){
				a[i][j]=-1;
			}else{
				a[i][j]=0;
			}
		}
	}
	int dirx=0;
	int diry=1;
	int hx=dimx/2;
	int hy=dimy/2;
	int snake_size=2;
	a[hx][hy]=-2;
	a[hx][hy-1]=1;
	a[hx][hy-2]=2;
	food(dimx,dimy,SIZE,a);
	screen(dimx,dimy,SIZE,a);
	int end=0;
	int timer=-1;
	char way;
	while(end==0){
		if(kbhit()){
			way=getch();
			if(way=='w' && a[hx-1][hy]<=0){
				dirx=-1;
				diry=0;
			}
			if(way=='a' && a[hx][hy-1]<=0){
				dirx=0;
				diry=-1;
			}
			if(way=='s' && a[hx+1][hy]<=0){
				dirx=1;
				diry=0;
			}
			if(way=='d' && a[hx][hy+1]<=0){
				dirx=0;
				diry=1;
			}
		}
		if(a[hx+dirx][hy+diry]==0 || a[hx+dirx][hy+diry]==-3){
			if(a[hx+dirx][hy+diry]==-3){
				food(dimx,dimy,SIZE,a);
				snake_size+=1;
			}
			increase(snake_size,dimx,dimy,SIZE,a);
			a[hx][hy]=1;
			hx+=dirx;
			hy+=diry;
			a[hx][hy]=-2;
			timer=-1;
		}else if(a[hx+dirx][hy+diry]!=0 && a[hx+dirx][hy+diry]!=-3 && timer==-1){
			timer=7;
		}
		if(timer>0){
			timer-=1;
		}
		if(timer==0){
			end=1;
		}
		if(foodcheck(dimx,dimy,SIZE,a)==0){
			food(dimx,dimy,SIZE,a);
		}
		screen(dimx,dimy,SIZE,a);
	}
	printf("GAME OVER\n");
	printf("YOU HAVE %d SNAKE PARTS\n",snake_size+1);
	printf("DO YOU WANT TO PLAY AGAIN?\n");
	printf("y    n\n");
	int check=0;
	char replay;
	while(check==0){
		replay=getch();
		if(replay=='y' || replay=='n'){
			check=1;
		}
	}
	if(replay=='y'){
	   main();
	}else{
		return 0;
	}
	
}












void screen(int dimx,int dimy,int SIZE, int a[SIZE][SIZE]){
	system("cls");
	int i,j;
	for(i=0;i<dimx;i++){
		for(j=0;j<dimy;j++){
			if(a[i][j]==0){
				printf("  ");
			}
			else if(a[i][j]==-1){
				printf("[]");
			}
			else if(a[i][j]==-2){
				printf(" S");
			}
			else if(a[i][j]==-3){
				printf(" F");
			}else{
				printf("()");
			}
			
		}
		printf("\n");
	}
}



void increase(int snake_size,int dimx,int dimy,int SIZE, int a[SIZE][SIZE]){
	int i,j;
	for(i=0;i<dimx;i++){
		for(j=0;j<dimy;j++){
			if(a[i][j]>0 && a[i][j]<=snake_size){
				a[i][j]+=1;
			}
			else if(a[i][j]>snake_size){
				a[i][j]=0;
			}
		}		
	}
}

void food(int dimx,int dimy,int SIZE,int a[SIZE][SIZE]){
	int rx,ry;
	int r_check=0;
	while(r_check==0){
		rx=rand() % dimx;
		ry=rand() % dimy;
		if(a[rx][ry]==0){
			a[rx][ry]=-3;
			r_check=1;
		}
	}
}

int foodcheck(int dimx,int dimy,int SIZE,int a[SIZE][SIZE]){
	int i,j;
	for(i=0;i<dimx;i++){
		for(j=0;j<dimy;j++){
	    	if(a[i][j]==-3){
			return 1;
	    	}
		}		
	}
	return 0;
}





