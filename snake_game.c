#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<time.h>

#define not_done true
#define done false

time_t secs;
char l[23][40]={"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx",
                "x                                     x",
                "x                 x                   x",
                "x                                     x",
                "x                                     x",
                "x                                     x",
                "x         x                           x",
                "x                                     x",
                "x         x                           x",
                "x        x                            x",
                "x                                     x",
                "xxxx                                  x",
                "x                                     x",
                "x                                     x",
                "x    x                                x",
                "x                                     x",
                "x    x       x    x                   x",
                "x            x    x                   x",
                "x      x     x    x    xxx            x",
                "x                                     x",
                "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"};
void gotoxy( int column, int line )
  {
  COORD coord;
  coord.X = column;
  coord.Y = line;
  SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ),coord);
  }

void scroll(int* v_x , int* v_y, int h_x, int h_y , int dimension,int& canc_x,int& canc_y)
{   int i;


    canc_x=v_x[0];
    canc_y=v_y[0];
	for(i=0;i<dimension-1;i++)
	{
		v_x[i]=v_x[i+1];
		v_y[i]=v_y[i+1];
	 } 

   
     v_x[dimension-1]=h_x;
     v_y[dimension-1]=h_y;

}



int main(int argc,char* argv[]){
	
	int *Vx,*Vy,*temp_x,*temp_y;
	int i;
	int cancel_x,cancel_y;
	int dimensions=3;
	int head_x,head_y;
	int direction=0;
	int item[2];
	int secondi;
	int speed=150;
    bool update_item=true;
	bool game_play=true;
	bool item_taken=false;
	
	//inizializazione
	system("cls");
	system("color a");
	printf("inserire la lentezza di gioco:\n->10\n->50\n->100\n->150\n");
	scanf("%d",&speed);
	
	system("cls");
    Vx=(int*)malloc(dimensions*sizeof(int));
	Vy=(int*)malloc(dimensions*sizeof(int));
    temp_x=(int*)malloc(dimensions*sizeof(int));
	temp_y=(int*)malloc(dimensions*sizeof(int));
	item[0]=20;
	item[1]=20;
	for(i=0;i<dimensions;i++)
	{
		Vx[i]=6+i;
		Vy[i]=4;
	}
	
	head_x=Vx[dimensions-1];
	head_y=Vy[dimensions-1];
	
	gotoxy(0,3);
	for(i=0;i<21;i++)
	{
		printf("%s\n",l[i]);
		
	}
	for(i=0;i<dimensions;i++)
	{
		gotoxy(Vx[i],Vy[i]);
		printf("%c",1);}
	
	gotoxy(10,30);
	printf("premi un tasto direzionale e poi invio per cominciare....");
	fflush(stdin);
	getchar();
	system("cls");
	
	// fine inizializzazione
	
 while(game_play==true){

       secondi=(clock()/1000.);
       srand(time(NULL));
   	   
	       if(GetAsyncKeyState(VK_UP)!=0)    direction=4;
   	 else  if(GetAsyncKeyState(VK_RIGHT)!=0) direction=1;
   	 else  if(GetAsyncKeyState(VK_LEFT)!=0)  direction=3;
   	 else  if(GetAsyncKeyState(VK_DOWN)!=0)  direction=2;
   	 
   	 
   	switch(direction){
   		                case 1: head_x++;
   		                        break;
   		                case 2: head_y++;
   		                        break;
   		                case 3: head_x--;
   		                        break;
   		                case 4: head_y--;
   		                        break;
	   }
	                    
	 
 
 	scroll(Vx,Vy,head_x,head_y,dimensions,cancel_x,cancel_y);
 	gotoxy(0,3);
	
	for(i=0;i<21;i++)
	                {
		               printf("%s\n",l[i]);
		
	                 }

	
	for(i=0;i<dimensions;i++)
	                         {   
		                       gotoxy(Vx[i],Vy[i]);
		                       if (i!=dimensions-1) printf("%c",1);
		                       else printf("%c",2);
		                       
							   gotoxy(cancel_x,cancel_y);
		                       printf(" ");
		
		                       if(item_taken==false)
		                      {
			                   gotoxy(item[1],item[0]+3);
		                       printf("%c",5);
		                      }
		
		                       gotoxy(0,0);
		                       printf("Score: %d\nSecondi gioco %d l[%d][%d] = %c",dimensions-3,secondi,item[0],item[1],l[item[0]][item[1]]);
		
      
	                         }
	
	 if((secondi%5)==0 && update_item==not_done )
	                                                 {    
												          gotoxy(item[1],item[0]+3);
                                                          printf(" ");
                                                          
														  item[0]=4+rand()%16;
                                                          item[1]=1+rand()%37;
                                                         
														
														   while(l[item[0]][item[1]]=='x')
														                            {
														                              item[0]=4+rand()%19;
                                                                                      item[1]=1+rand()%37;
																					 }
														 
	                                                      
                                                          update_item=done;
                                                          item_taken=false;
	                                                  }
	
	
	if((secondi%5)!=0)  update_item=not_done;
	
	
	if(head_x==item[1] && head_y==item[0]+3 && item_taken==false)
	{
		item_taken=true;
		gotoxy(item[1],item[0]+3);
        printf("%c",2);
		
		
	    for(i=0;i<dimensions;i++)
		{
		    temp_x[i]=Vx[i];
			temp_y[i]=Vy[i];
		}
		
		dimensions++;
		
		Vx=(int*)realloc(Vx,dimensions*sizeof(int));
		Vy=(int*)realloc(Vy,dimensions*sizeof(int));
		
		for(i=0;i<dimensions-1;i++)
		{
			Vx[i]=temp_x[i];
			Vy[i]=temp_y[i];
		}
		
		temp_x=(int*)realloc(temp_x,dimensions*sizeof(int));
		temp_y=(int*)realloc(temp_y,dimensions*sizeof(int));
		
		switch(direction)
		{
		
			case 1:
			      Vx[dimensions-1]=head_x; 
			      Vy[dimensions-1]=head_y;
			      break;
			case 2:
			      Vx[dimensions-1]=head_x; 
			      Vy[dimensions-1]=head_y;
			      break;
			case 3:
			      Vx[dimensions-1]=head_x; 
			      Vy[dimensions-1]=head_y;
			      break;
			case 4:
			      Vx[dimensions-1]=head_x; 
			      Vy[dimensions-1]=head_y;
			      break;
		}
	
	
	}
	
        if(l[head_y-3][head_x]=='x')
		{
   	     game_play=false;
        }	

	

	Sleep(speed);
}
	free(Vx);
	free(Vy);
	free(temp_x);
	free(temp_y);
	fflush(stdin);
	system("cls");
	printf("You loose!!\nYour score is %d\n",dimensions-3);

	return 0;
}
