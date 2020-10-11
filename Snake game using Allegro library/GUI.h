char stringa[6]={NULL};
int speed=0;
int dimensioni=0;
int schermo_int=2;
int my_button_proc(int msg, DIALOG *d, int c);

 int my_edit_proc(int msg, DIALOG *d, int c)
 {
 	int ret=d_edit_proc(msg,d,c);
 	if(speed!=0) {
 	
	
	 return ret;	
	 }
 
 	else return D_O_K;
 }



	DIALOG the_dialog[] =
	{
	   /* (dialog proc)     (x)      (y)      (w)      (h)       (fg)       (bg)      (key)     (flags)     (d1)     (d2)    (dp)                               (dp2)       (dp3) */
	   { d_clear_proc,       0,       0,       0,       0,         0,        0,         0,         0,         0,       0,    NULL,                               NULL,        NULL  },
	   
	   { d_text_proc,        0,      10,     100,      20,         0,        0,         0,         0,         0,       0,  (void*)" Scegli frames al secondo: ",  NULL,        NULL  },
	   
 	   { my_button_proc,   250,      60,      80,      30,         0,        0,         0,     D_EXIT,       20,       0,    (void*)"20",                         NULL,        NULL },
	
	   { my_button_proc,   250,      100,     80,      30,        0,       0,         0,     D_EXIT,       40,       0,      (void*)"40",                         NULL,        NULL },
		
       { my_button_proc,   250,      140,     80,      30,        0,       0,         0,     D_EXIT,       60,       0,      (void*)"60",                         NULL,        NULL },
     	
       { d_text_proc,        0,     250,     100,      20,         0,        0,         0,          0,        0,       0,  (void*)" Dimensione iniziale (maggiore di zero): ",  NULL, NULL  },	
     	
       { my_edit_proc,       390,    250,     80,      30,        0,       0,         0,      D_EXIT,       4,       0,  (void*)stringa,                       NULL,        NULL },
		
	   { my_button_proc,     550,    350,     80,      30,        0,       0,         0,      D_EXIT,       0,       0,  (void*)"Invio",                       NULL,        NULL },
	   
	    { my_button_proc,     350,    350,     180,      30,        0,       0,         0,      D_EXIT,       100,       0,  (void*)"FULLSCREEN",                       NULL,        NULL },
	
 	   { NULL,                0,      0,       0,       0,         0,        0,         0,           0,       0,       0,            NULL,                       NULL,        NULL  }
	};
	 
	 int my_button_proc(int msg, DIALOG *d, int c)
{
   int ret = d_button_proc(msg, d, c);
   int s=d->d1;
   int risposta;
   if (ret == D_CLOSE)
   { d->flags=D_SELECTED;
   	switch(s) 
   	          {
   	          	case 20: 
					     risposta=alert("Velocita frames selezionata 20","Vuoi confermare?",NULL,"OK","NO",0,0);
					     if(risposta==1)
					     speed=20;
					            else{
					     	d->flags=D_EXIT;
						 }
					     break;
					    
				case 40:
					     risposta=alert("Velocita frames selezionata 40","vuoi confermare?",NULL,"OK","NO",0,0);
					     if(risposta==1)
					     speed=40;
					     else{
					     	d->flags=D_EXIT;
						 }
					     break;
					     
				
				case 60:
					     risposta=alert("Velocita frames selezionata 60","vuoi confermare?",NULL,"OK","NO",0,0);
					     if(risposta==1)
					     speed=60;
					     else{
					     	d->flags=D_EXIT;
						 }
					     break;
				case 100: schermo_int=0;
				break;		     
			    
				case 0:  if(speed==0) {
				          alert("Selezionare velocita di gioco prima",NULL,NULL,"OK",NULL,0,0);
			              d->flags=D_EXIT;
					          break;
				
				                        }
				
				                        
				         if(stringa[0]==NULL){
				          alert("Selezionare dimensione",NULL,NULL,"OK",NULL,0,0);
			              d->flags=D_EXIT;
					          break;
				                        }
				        else return D_CLOSE;
					     break;
					     //d->flags=D_EXIT;
					     
						 
				}
   
  
   return D_O_K;	
   }
     
   return ret;
}
