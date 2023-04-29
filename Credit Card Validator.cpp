#include<iostream>
#include<conio.h>
#include<ctype.h>
#include<time.h>
#include<cstring>
#include<stdlib.h>
#include<math.h>
#include "windows.h"

using namespace std;


void setCursor(int row, int col)
{

  COORD coord = {col, row};

  SetConsoleCursorPosition(GetStdHandle((DWORD)-11), coord);

}
void setTextColor(int color)
{

  SetConsoleTextAttribute(GetStdHandle((DWORD)-11), color);

}


void knowyourcard(int a)
{
	cout<<endl<<"Your card type is ";
	if(a==4) 
		   cout<<"Visa Card"<<endl;
	    else if (a==5) 
			cout<<"Master Card"<<endl;
	    
	    else if (a==6) cout<<"Discover Card"<<endl;
	
	
	
}


void captcha()
{
    int ch, i;
    char capt[5], ver[5], c;
    srand(time(NULL));
    for (i=0; i<4;)
    {
        c = rand()%127;
        if(isalnum(c))
        {
            capt[i] = c;
            i++;
        }
    }
    capt[i]='\0';
		setCursor(0,70);
        cout<<"ATM CARD VALIDATOR"<<endl;
		cout<<"CAPTCHA: "<<capt<<endl;
        cout<<"Captcha verification: "; cin>>ver;
        if (strcmp(ver, capt)==0)
        {
            cout<<"Captcha verified!!!";
        }
        else
        {
            setCursor(5,40);
			cout<<endl<<"Captcha mismatch!!!"<<endl<<"1. Try again! "<<endl<<"2. Exit"<<endl;
            cout<<"Input: ";cin>>ch;
        }
        switch(ch)
        {
            case 1:
            {
                system("cls");
                captcha();
                break;
            }
            case 2:
            {
                system("cls");
                break;
            }
        }

}



void knowyourbank(int a)
{
	cout<<"BANK NAME: ";
	if(a==406750|| a==409072 || a==413545 || a==458701|| a==457987|| a==451132|| a==439371 || a==422627 || a==418902)
		cout<<endl<<"NABIL BANK"<<endl;

	else if(a==481367||  a==481364)
		cout<<endl<<"EVEREST BANK"<<endl;

	else if(a==	403110 || a==461006 || a==461005 || a==461004|| a==403729|| a==450052|| a==403735|| a==461003)
		cout<<endl<<"SANIMA BANK";
	
	else if(a==403019 || a==408910 || a==408911 || a==470946 || a==483751 || a==483752)
		cout<<"NMB BANK"<<endl;
	
	else if(a==420611 || a==420622 || a==439128 || a==439129 || a==492469)
		cout<<"KUMARI BANK"<<endl;
	
	else if(a==402487 || a==416211 || a==416212 || a==416213 || a==437369 || a==437370  || a==437370)
	    cout<<"SUNRISE BANK"<<endl;

	else if(a==418119 || a==418120 || a==418121 ||a==457709)
		cout<<"RASTRIYA BANIJYA BANK"<<endl;

	else if(a==462416 || a==468959)
	    cout<<"NCC BANK"<<endl;
	
	else if(a==436895 || a==468950 )
	
		cout<<endl<<"GLOBAL IME BANK"<<endl;
	
	else if(a==423559)
	cout<<endl<<"NIC ASIA BANK"<<endl;
	
	else if(a==443830||a==443832||a==443834)
	cout<<endl<<"NEPAL INVESTMENT BANK"<<endl;
	
	

}

int count(long long n)
{
	
	int c;
	
	while(n!=0)
	{
		n=n/10;
		c++;
		
	}
	return c;
	
}




int main()
{
	
	captcha();
	
	system ("cls");
	
	long long n;
	long long nn;
	int ch,s,t;
	int carray[20]	,sumo=0,sume=0,digit,sum=0;
	
	cout<<"CHECK THE CARD VALIDITY"<<endl;
	
	cout<<endl<<"Please enter the card number:"<<endl;
	cin>>n;
	nn=n;
	digit=count(n);
	//converting long to array
	for(int i=digit-1; i>=0; i--)
	{
		
		
		int a=n%10;
		carray[i]=a;
		n=n/10;
    }
    
    
    
    //sum of odd positioned digits
    	for(int i=1; i<digit; i=i+2)
	{
		sumo=sumo+carray[i];
		
	}
	
	//sum of even positioned digits
	for(int i=0; i<digit; i=i+2)
	{
		int p=carray[i]*2;
		if (p>9)
		{
			sume=(p/10) +(p%10)+sume;
		}
		else
		sume=sume+p;
	}
	sum=sumo+sume;
	
	if (sum%10==0)
	{
		cout<<"The card is valid"<<endl;
		getch();
		system("cls");
		setCursor(0,40);
		cout<<"PICK A MENU"<<endl;
		setCursor(1,10);
    	cout<<"1.KNOW YOUR CARD"<<endl;
    	setCursor(2,10);
		cout<<"2.KNOW YOUR BANK"<<endl;
		setCursor(3,10);
		cout<<"3.EXIT"<<endl;
		while(1)
		{
	    	cout<<endl<<"Enter your choice:";
			cin>>ch;
	    
	
			switch(ch)
			{
			
				case 1:
					s=nn/(pow(10,15));
					knowyourcard(s);
					break;
				case 2:
					t=nn/(pow(10,10));	
	         		knowyourbank(t);
			    	break;
				case 3:
					exit(0);	
			}
		}
    }
	else
	cout<<"The card is not valid!!";
}

