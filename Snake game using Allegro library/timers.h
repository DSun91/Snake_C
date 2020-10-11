volatile int counter=0;
void timer(){
	 counter++;

}END_OF_FUNCTION(timer)



int secondi=0;
void timer_count()
{
	secondi++;
   
}
END_OF_FUNCTION(timer_count)


volatile int counter2=0;
void timer2(){
	 counter2++;

}END_OF_FUNCTION(timer2)



volatile int counter3;
void timer3(){
	 counter3++;

}END_OF_FUNCTION(timer3)

volatile int *veloc;
void set_timers()
{

        LOCK_VARIABLE(counter);
		LOCK_FUNCTION(timer);
        install_int_ex(timer,BPS_TO_TIMER(speed));
        
       
        LOCK_VARIABLE(counter2);
		LOCK_FUNCTION(timer2);
		
		switch(speed)
		{
			case 20:
			counter3=60;
			break;
			case 40:
			counter3=160;
			break;
			case 60:
			counter3=280;
			break;
		} 
		LOCK_VARIABLE(counter3);
		LOCK_FUNCTION(timer3);
       
        
	LOCK_FUNCTION(timer_count);
    install_int_ex(timer_count,SECS_TO_TIMER(1));
	 
	 counter2=speed;
     veloc=&counter2;
	
	 install_int_ex(timer2,BPS_TO_TIMER((*veloc)));
	 
	 install_int_ex(timer3,BPS_TO_TIMER(counter3));
}
