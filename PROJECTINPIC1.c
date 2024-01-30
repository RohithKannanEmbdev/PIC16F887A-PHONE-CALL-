#include<pic.h>
#define RS RA0
#define RW RA1
#define EN RA2
#define LCD PORTD

int typenumber[10]={0x3F,0X06,0x5B,0x4F,0x66,0x6D,0xFD,0x07,0x7F,0x6F};
int Segnumber[10]={0x40,0x79,0x24,0x30,0x19,0x12,0x02,0x78,0x00,0x10};
int store[10],i=0,l,count=0;

void delay(int count)
{
	while(count--);
}

void pulse()
{
	EN=1;
	delay(1000);
	EN=0;
	delay(1000);
}
	 
void type()
{
	RS=0;
	RW=0;
	LCD=0X38;
	pulse();
}

void on()
{
	RS=0;
	RW=0;
	LCD=0X0E;
	pulse();
}

void address(int place)
{
	RS=0;
	RW=0;
	LCD=place;
	pulse();
}

void data(char value)
{
	RS=1;
	RW=0;
	LCD=value;
	pulse();
}

void idisplay(char *sentence)
{
	while(*sentence)
	{
		RS=1;
		RW=0;
		LCD=*sentence;
		sentence++;
		pulse();
	}
}

void show(char *declined)
{
	while(*declined)
	{
		RS=1;
		RW=0;
		LCD=*declined;
		declined++;
		pulse();
	}
}
void show1(char *Busy)
{
	while(*Busy)
	{
		RS=1;
		RW=0;
		LCD=*Busy;
		Busy++;
		pulse();
	}
}

void error(char *result)
{
	while(*result)
	{
		RS=1;
		RW=0;
		LCD=*result;
		result++;
		pulse();
	}
}

void keypad()
{
	
		RB3=1;
	    RB4=0;
	    RB5=0;
	    RB6=0;
	    if(RB0==1)
	    {
		    PORTD=typenumber[1];
		    store[i]=1;
		    data('1'); 
		    i++;	    
		}while(RB0==1);
		
		if(RB1==1)
	    {
		    PORTD=typenumber[2];
		    store[i]=2;
		    data('2'); 
		    i++;
		}while(RB1==1);
		
		if(RB2==1)
	    {
		    PORTD=typenumber[3];
		    store[i]=3;
		    data('3'); 
		    i++;
		}while(RB2==1);
			
		/////////////////////
		RB3=0;
	    RB4=1;
	    RB5=0;
	    RB6=0;
	    if(RB0==1)
	    {
		    PORTD=typenumber[4];
		    store[i]=4;
		    data('4');
		    i++; 
		}while(RB0==1);
		
		if(RB1==1)
	    {
		    PORTD=typenumber[5];
		    store[i]=5;
		    data('5');
		    i++; 
		}while(RB1==1);
		
		if(RB2==1)
	    {
		    PORTD=typenumber[6];
		    store[i]=6;
		    data('6');
		    i++; 
		}while(RB2==1);	
		////////////////////
		RB3=0;
	    RB4=0;
	    RB5=1;
	    RB6=0;
	    if(RB0==1)
	    {
		    PORTD=typenumber[7];
		    store[i]=7;
		    data('7');
		    i++; 
		}while(RB0==1);
		
		if(RB1==1)
	    {
		    PORTD=typenumber[8];
		    store[i]=8;
		    data('8'); 
		    i++;
		}while(RB1==1);
		
		if(RB2==1)
	    {
		    PORTD=typenumber[9];
		    store[i]=9;
		    data('9');
		    i++; 
		}while(RB2==1);		
}


void main()
{	
	TRISA=0X00;
	PORTA=0X00;
	TRISB=0X07;
	PORTB=0X78;
	TRISC=0X00;
	PORTC=0X00;
	TRISD=0X00;
	PORTD=0X00;
	TRISE=0X00;
	PORTE=0X00;
	ANSEL=0x00;  
    ANSELH=0x00;
    
    type();
    on();
    address(0x80);
    idisplay("TYPE_CALL_NO");
    address(0xC0);
    while(1) 
    {
        keypad();
        RB3=0;
        RB4=0;
        RB5=0;
        RB6=1;
        if(RB0==1)
        {
	        if(i==10)
	        {
	            for(l=30;l>=0;l--)
	            {
	                RE0=1,RE1=0;
	                PORTC=Segnumber[l/10];
	                delay(10000);
	                RE0=0,RE1=1;
	                PORTC=Segnumber[l%10];
	                delay(10000);
	                RB3=0;
	                RB4=0;
	                RB5=0;
	                RB6=1;
	                if(RB2==1) 
	                {   
	                    l=0;
	                    RE0=0,RE1=0;
	                    PORTC=0;
	                    delay(10000);
	                    RE0=0,RE1=0;
	                    PORTC=0; 
	                    delay(10000);
	                    address(0x01);
	                    address(0x80);
	                    show("Declined!");   
	                    break; 
	                }    
	                
	                if(l==0) 
	                {
	                    address(0x01);
	                    address(0x80);
	                    show1("Busy!");
	                }     
	            }
	            i=0;
	        }
	        else
	        {
		        address(0x01);
		        address(0x80);
	            error("Invalid");
		    }   
	    }      
    }                               
}	    

