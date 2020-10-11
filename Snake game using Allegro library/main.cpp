#include <allegro.h>
#include<stdio.h>

#include<string.h>
#include<time.h>
#include<stdlib.h>
#include "GUI.h"
#include "timers.h"
#include "allegrobbd.h"
#define not_done true
#define done false
SAMPLE *a;

void draw(int* Vx , int* Vy,int dimensions,int cancel_x,int cancel_y,BITMAP* sfondo,int x_cord,BITMAP* &d_buf,bool item_taken,int *item,bool& gameplay,MP3FILE* audio )
{
    int i,colore,g,r;
	for(i=0;i<dimensions;i++)
	                         {   
		                       
		                         if (i!=dimensions-1)  circlefill(d_buf,Vx[i],Vy[i],5,makecol(220,224,0));//corpo
		                       else 
		                        circlefill(d_buf,Vx[i],Vy[i],5,makecol(220,234,220));
		                      
		                      
		                      circlefill(d_buf,cancel_x,cancel_y,4,makecol(0,0,0));
							  
		                    
		                       if(item_taken==false)
		                      {
		                      	circlefill(d_buf,item[1],item[0],5,makecol(222,34,56));
			                   
		                     
		                      }
		                   
		       
		                     colore=getpixel(sfondo,Vx[i]-x_cord,Vy[i]);
		                     if( (g=getg(colore))==255 && (r=getr(colore))==0 ) {gameplay=false;
		                     play_sample(a,255,128,1000,false);
		                                                close_mp3_file(audio);
		                                                 alert("Game Over",NULL,NULL,"ESC",NULL,0,0);
		                                                 
														 // exit(0);
														 }
      
	                         }
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




int main() {


	int depth, res;
	allegro_init();
	depth = desktop_color_depth();
	if (depth == 0) depth = 32;
	set_color_depth(depth);
	res = set_gfx_mode(schermo_int, 640, 400, 0, 0);
	if (res != 0) {
		allegro_message(allegro_error);
		exit(-1);
	}

	install_timer();
	install_keyboard();
	install_mouse();
  
a=load_wav("coll.wav");
    srand(time(NULL));

int random=rand()%2;

install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, "A");

MP3FILE *merda;
merda=open_mp3_file("chon.mp3");

/*switch(random)
{
	case 0:nenno=open_mp3_file("asd.mp3");
	
	break;
	
	case 1:nenno=open_mp3_file("rum.mp3");

	break;
}
//sound=load_sample("art.wav");
 //int bau =play_sample(sound,255, 128, 1000, 1);*/
 play_mp3_file(merda, BUFSZ, 205, 128);


	  font=load_font("f1.pcx",NULL,NULL);
	  gui_fg_color = makecol(0, 255, 0);
	  gui_mg_color = makecol(255, 0, 0);
	  gui_bg_color = makecol(0, 0, 0);
	  set_dialog_color (the_dialog, gui_fg_color, gui_bg_color);
	  do_dialog(the_dialog, -1);
      set_gfx_mode(schermo_int, 640, 400, 0, 0);

	int *Vx,*Vy,*temp_x,*temp_y;
	int i;
	int cancel_x,cancel_y;
	int dimensions=strtod(stringa,NULL);
	if(dimensions==0) dimensions=1;
	int head_x,head_y;
	int direction=0;
	int item[2];
   
    int x_cord=0;
    bool update_item=true;
    bool moved=false;
   	bool gameplay=true;
	bool item_taken=false;
	
	
	Vx=(int*)malloc(dimensions*sizeof(int));
	Vy=(int*)malloc(dimensions*sizeof(int));
    temp_x=(int*)malloc(dimensions*sizeof(int));
	temp_y=(int*)malloc(dimensions*sizeof(int));
	item[0]=20;
	item[1]=20;
	for(i=0;i<dimensions;i++)
	{
		Vx[i]=26+i;
		Vy[i]=184;
	}
	
	head_x=Vx[dimensions-1];
	head_y=Vy[dimensions-1];

    set_timers();
   
     
    BITMAP* d_buf=d_buf=create_bitmap(640,400);
	
	BITMAP* sfondo=load_bitmap("map.bmp",NULL);;
	


	BITMAP* final=create_bitmap(640,400);

   
	
   srand(time(NULL));
int lunghez;

int t1,t2,scarto=0;
bool agg_t1=false;
int vd;
	while (!key[KEY_ESC] && gameplay==true ) {
	
		
		
		if(  ( vd= almp3_poll_mp3stream(merda->s))==ALMP3_POLL_NOTPLAYING)
		{
			
              merda=open_mp3_file("chon.mp3");
              play_mp3_file(merda, BUFSZ, 205, 128);
		}
		//t1=lunghez;
		
			poll_mp3_file(merda);
        
        if((secondi%5)==0 && agg_t1==false ) 
		{
		t1=lunghez;
		agg_t1=true;
		}
       
         if((secondi%5)!=0  ) 
		{
		
		agg_t1=false;
		}
        lunghez=almp3_get_pos_bytes_mp3stream(merda->s);
        
        scarto=lunghez-t1;
        //printf("t1=%d\n",scarto);
		 while(counter>0 && gameplay==true)
							
							 {	
						 	
		
			    
				                       x_cord-=1;
			                        if (x_cord==-3000)  x_cord=690;
			                       clear(d_buf);
			                       draw_sprite(d_buf,sfondo,x_cord, 0);
			   
			   
		   if(key[KEY_UP] /*&& direction!=2*/ )    direction=4;
   	 else  if(key[KEY_RIGHT] /*&& direction!=3*/) direction=1;
   	 else  if(key[KEY_LEFT]  /*&& direction!=1*/)  direction=3;
   	 else  if(key[KEY_DOWN]  /*&& direction!=4*/)  direction=2;
   	    
	                    
	 
	draw(Vx , Vy, dimensions, cancel_x, cancel_y, sfondo, x_cord,d_buf, item_taken,item,gameplay,merda);						 	
	
		 					 	
		
	
		
		textprintf_ex(d_buf,font,0,0,makecol(200,110,30),-1,"time: %d:%d:%d",(secondi/3600),(secondi/60),secondi%60);
		textprintf_ex(d_buf,font,170,380,makecol(200,110,30),-1,"PREMERE SPAZIO PER IL TURBO");	
		textprintf_ex(d_buf,font,440,0,makecol(200,110,30),-1,"lunghezza :%d ",dimensions);	
							 	
       if(key[KEY_SPACE]){
       	counter3=0;
       	veloc=&counter3;
	   }
   	 else if(veloc!=&counter2){
   	 	counter2=0;
			veloc=&counter2;
		}

	counter--;
}
	

while(*veloc>0 && gameplay==true)
	       {
	   
	        if(key[KEY_UP] /*&& direction!=2*/ )    direction=4;
   	 else  if(key[KEY_RIGHT] /*&& direction!=3*/) direction=1;
   	 else  if(key[KEY_LEFT]  /*&& direction!=1*/)  direction=3;
   	 else  if(key[KEY_DOWN]  /*&& direction!=4*/)  direction=2;
   	    
	                    
	 
		switch(direction){
   		                case 1: head_x+=10;
   		                        break;
   		                case 2: head_y+=10;
   		                        break;
   		                case 3: head_x-=10;
   		                        break;
   		                case 4: head_y-=10;
   		                        break;
	   }
	       	
   	 draw(Vx , Vy, dimensions, cancel_x, cancel_y, sfondo, x_cord,d_buf, item_taken,item,gameplay,merda);
	
	                               
	
   	 
   	 
   	 
   	 if(direction!=0) moved=true;
   	 
  
 
 	scroll(Vx,Vy,head_x,head_y,dimensions,cancel_x,cancel_y);
 	
 if((secondi%5)==0 && update_item==not_done )
	                                                 {    
												        // circlefill(d_buf,item[1],item[0],5,makecol(0,0,0));
                                                       
														  item[0]=4+rand()%400;
                                                          item[1]=1+rand()%400;
                                                         
														
												/*		   while(l[item[0]][item[1]]=='x')
														                            {
														                              item[0]=4+rand()%19;
                                                                                      item[1]=1+rand()%37;
																					 }
														 
	                                                      */
                                                          update_item=done;
                                                          item_taken=false;
	                                                  }
	

	if((secondi%5)!=0)  update_item=not_done;
	if(head_x>screen->w) head_x=0;
	if(head_x<0) head_x=screen->w;
	if(head_y>screen->h) head_y=0;
	if(head_y<0) head_y=screen->h;
	


	if(head_x>item[1]-10 && head_x<item[1]+10 &&head_y>item[0]-10 && head_y<item[0]+10 && item_taken==false)
	{
		item_taken=true;
	    
	
        
		
	    for(i=0;i<dimensions;i++)
		{
		    temp_x[i]=Vx[i];
			temp_y[i]=Vy[i];
		}
		
		dimensions+=1;
		
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
	
        counter2--;	
        counter3--;
		   }
	       
		  
	
	draw_sprite(final,d_buf,0,0);

		draw_sprite(screen,final,0,0);
	}

	clear_keybuf();	
	free(Vx);
	free(Vy);
	free(temp_x);
	free(temp_y);

	
	return 0;
}
END_OF_MAIN()



