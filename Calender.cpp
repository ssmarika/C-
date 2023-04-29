#include "windows.h"

#include <iostream>

#include <string>

#include <ctime>

#include<conio.h>

#include<fstream>

using namespace std;


#define GREEN   10

#define CYAN    11

#define RED     12

#define MAGENTA 13

#define WHITE   7



//CONSOLE_SCREEN_BUFFER_INFO csbiInfo;



void setCursor(int row, int col)
{

  COORD coord = {col, row};

  SetConsoleCursorPosition(GetStdHandle((DWORD)-11), coord);

}
void setTextColor(int color)
{

  SetConsoleTextAttribute(GetStdHandle((DWORD)-11), color);

}
void showAppName()
{

  system("cls");

  
  
  	setTextColor(CYAN);
  	setCursor(1, 2);

  cout << "SASA CALENDAR APP"<<endl;
  cout<<endl;
  cout<<endl;
  cout<<endl;
  
  setTextColor(MAGENTA);



  int n=10, i, j;
   
   for(i = 1; i<=n; i++) {
      for(j = 1; j<=(n-i); j++) 
	  {
	  
         cout << " ";
      }
      if(i == 1 || i == n)
	   { 
         for(j = 1; j<=i; j++) 
		 {
            cout << "* ";
         }
      }
	  else
	  {
         cout << "*"; 
         for(j = 1; j<=2*i-3; j++) 
		 { 
            cout << " ";
         }
         cout << "*";
      }
      cout << endl;
   }

  
  
}






int day, month, year;


int getNumber();


void getInput();


void printcal(int);

bool checkleap(int year);

void appoint();


int first_year(int);

class date{
	private:
	    int d,m,y,n;
	    char event[50],detail[100];
	public:
		
		
		void getdata(){
			system("cls");
			int x;
			 setTextColor(WHITE);
			cout<<"ENTER THE DATE (YYYY|MM|DD)";
			cout<<"YEAR: ";
			cin>>y;
			cout<<endl<<"MONTH: ";
			cin>>m;
			cout<<endl<<"DAY: ";
			cin>>d;
			while(1)
		    {
			
			if(m>12 || d>31)
			{
				cout<<"INVALID DATE"<<endl;
				cout<<"ENTER THE DTAE (YYYY|MM|DD)"<<endl;
				cout<<endl<<"YEAR: ";
			    cin>>y;
			    cout<<endl<<"MONTH: ";
			    cin>>m;
			    cout<<endl<<"DAY: ";
			    cin>>d;
		        
				
			}
			else if(m==2 && d>29)
			{
				cout<<"INVALID DATE"<<endl;
				cout<<"ENTER THAE DATE (YYYY|MM|DD)"<<endl;
				cout<<endl<<"YEAR: ";
			    cin>>y;
			    cout<<endl<<"MONTH: ";
			    cin>>m;
			    cout<<endl<<"DAY: ";
			    cin>>d;}
			else
			break;
		        
		}
					
				
			
			
			
				
			 setTextColor(RED);
	
			cout<<"EVENT LIST"<<endl;
			 setTextColor(CYAN);
	        cout<<"1. BIRTHDAY\n2. BUSINESS MEETING\n3. FAMILY GATHERING\n4. RECREATION\n5.OTHERS" ;
	         setTextColor(WHITE);
	        cout<<"\nEnter your choice";
	        cin>>x;
	            	if (x==1)
			{
				strcpy(event,"BIRTHDAY");
				
			}
			else if(x==2)
			{
				strcpy(event,"BUSINESS MEETING");
				
			}
			else if(x==3)
			{
				strcpy(event,"FAMILY GATHERING");
				
			}
			else if(x==4)
			{
				strcpy(event,"RECREATION");
			}
			else if (x==5)
			{
				 setTextColor(CYAN);
				cout<<"ENTER EVENT NAME:\n";
					fflush(stdin);
			        gets(event);
			}
			 setTextColor(WHITE);
			cout<<"Enter short description:\n";
			fflush(stdin);
			gets(detail);
	    }
		
			
			
	
		void display(){
			      setTextColor(WHITE);
				cout<<"DATE: "<<endl;
				cout<<"DAY: "<<d<<"   MONTH: "<<m<<"   YEAR:"<<y<<endl;
				cout<<"EVENT: "<<event<<endl;
				cout<<"DETAIL: "<<detail<<endl;
				cout<<endl;
		}
		void writetofile()
		{
			system("cls");
			char check;
		    while(1)
		    {
			getdata();
			ofstream outfile("date.dat",ios::app);
			outfile.write(reinterpret_cast<char*>(this),sizeof(*this));
			cout<<"do you have next data(Y?N)";
			cin>>check;
			if(check=='N'||check =='n') break;
		    }
		}
		void readfromfile()
		{
			system("cls");
			ifstream infile("date.dat");
			while(!infile.eof())
			{	
			if(infile.read(reinterpret_cast<char*>(this),sizeof(*this))>0)
		         display();
			}
		}
		
		void searchbydate()
		{
			int sd,sm,sy;
		
			int flag=0;
			ifstream infile("date.dat");//ios::in mode ma automatic
			 setTextColor(WHITE);
			cout<<"enter date you want to search (YYYY|MM|DD)"<<endl;
			
			cout<<"YEAR: ";
			cin>>sy;
			cout<<endl<<"MONTH: ";
			cin>>sm;
			cout<<endl<<"DAY: ";
			cin>>sd;
			
				while(1)
		{
			
				if(sm>12 || sd>31)
				{
				
				
			
				cout<<"/nINVALID DATE"<<endl;
				cout<<"enter the date (YYYY|MM|DD)"<<endl;
				cout<<"YEAR: ";
			    cin>>sy;
			    cout<<endl<<"MONTH: ";
			    cin>>sm;
			    cout<<endl<<"DAY: ";
			    cin>>sd;
		        
				
			}
				else if(sm==2 && sd>29)
				{
				cout<<"/nINVALID DATE"<<endl;
				cout<<"enter the date (YYYY|MM|DD)"<<endl;
				cout<<"YEAR: ";
			cin>>sy;
			cout<<endl<<"MONTH: ";
			cin>>sm;
			cout<<endl<<"DAY: ";
			cin>>sd;}
			else
			break;
		        
		}
			
			
			while(!infile.eof())
			{	
			if(infile.read(reinterpret_cast<char*>(this),sizeof(*this))>0)
			  {
				    if(sd==d && sm==m &&sy==y)
		               {display();
		               getch();
					   flag=1;}
				}

			}
			if(flag==0)  {
				 setTextColor(RED);
				cout<<"data is not there in file"<<endl;
				getch();
			}
			cout<<"Press enter to continue";
		}
		void searchbyevent()
	
		{
				system("cls");
			char sevent[50];
			
			 setTextColor(MAGENTA);
		
			cout<<"EVENT LIST";
				int x;
				 setTextColor(CYAN);
				
				cout<<"\n1. BIRTHDAY\n2. BUSINESS MEETING\n3. FAMILY GATHERING\n4. RECREATION " ;
				setTextColor(WHITE);
	            cout<<"\nEnter your choice: ";
	            cin>>x;
	            	if (x==1)
			{
				strcpy(sevent,"BIRTHDAY");
				
			}
			else if(x==2)
			{
				strcpy(sevent,"BUSINESS MEETING");
				
			}
			else if(x==3)
			{
				strcpy(sevent,"FAMILY GATHERING");
				
			}
			else if(x=4)
			{
				strcpy(sevent,"RECREATION");
			
				
				
			}
		
			int flag=0;
			ifstream infile("date.dat");
			
			while(!infile.eof())
			{	
			if(infile.read(reinterpret_cast<char*>(this),sizeof(*this))>0)
			  {
			  	system("cls");
				    if(strcmp(event,sevent)==0)
				    
		               {
					   
					   display();
		               getch();
					   flag=1;}
				}

			}
			if(flag==0)  {
				 setTextColor(RED);
				cout<<"data is not there in file"<<endl;
				getch();
			}
			cout<<"Press enter to continue";
		}
		
		void deletefromfile_date()
		{
			system("cls");
			int ay,am,ad;
			int flag1=0;
			cout<<"ENTER THE DATE YOU WISH TO DELETE(YYYY/MM/DD)";
			cout<<endl<<"YEAR: ";
			cin>>ay;
			cout<<endl<<"MONTH: ";
			cin>>am;
			cout<<endl<<"DAY: ";
			cin>>ad;
			
				while(1)
		{
			
				if(am>12 || ad>31)
				{
				
				
			
				cout<<"/nINVALID DATE"<<endl;
				cout<<"enter the date (YYYY|MM|DD)"<<endl;
				cout<<"YEAR: ";
			    cin>>ay;
			    cout<<endl<<"MONTH: ";
			    cin>>am;
			    cout<<endl<<"DAY: ";
			    cin>>ad;
			}
			
				else if(am==2 && ad>29)
				{
				cout<<"/nINVALID DATE"<<endl;
				cout<<"enter the date (YYYY|MM|DD)"<<endl;
				cout<<"YEAR: ";
			    cin>>ay;
			    cout<<endl<<"MONTH: ";
			    cin>>am;
			    cout<<endl<<"DAY: ";
			    cin>>ad;}
			else
			break;
		}
			    
			ofstream ofile("date1.dat");
			ifstream ifile("date.dat");
			while(!ifile.eof())
			{	
			if(ifile.read(reinterpret_cast<char*>(this),sizeof(*this))>0)
		         if(ay!=y && am!=m && ad!=d)
		         {
		         	ofile.write(reinterpret_cast<char*>(this),sizeof(*this));
		         	
				 }
			}
			
			ofile.close();
			ifile.close();
			
			
			int q=remove("date.dat");
		   if (q==0)
		   {
		   	cout<<"ENTRY DELETED";
		   	getch();
		   }
		
			rename("date1.dat","date.dat");
		        
				
			
		        
		}
		
		void deletefromfile_event()
		{
			int ch1;
			char ssevent[50];
				cout<<"\n1. BIRTHDAY\n2. BUSINESS MEETING\n3. FAMILY GATHERING\n4. RECREATION " ;
				setTextColor(WHITE);
	            cout<<"\nEnter your choice: ";
	            cin>>ch1;
	            	if (ch1==1)
			{
				strcpy(ssevent,"BIRTHDAY");
				
			}
			else if(ch1==2)
			{
				strcpy(ssevent,"BUSINESS MEETING");
				
			}
			else if(ch1==3)
			{
				strcpy(ssevent,"FAMILY GATHERING");
				
			}
			else if(ch1=4)
			{
				strcpy(ssevent,"RECREATION");
			
				
				
			}
			ofstream ofile("date1.dat");
			ifstream ifile("date.dat");
			while(!ifile.eof())
			{	
			if(ifile.read(reinterpret_cast<char*>(this),sizeof(*this))>0)
		         if((strcmp(event,ssevent))!=0)
		         {
		         	ofile.write(reinterpret_cast<char*>(this),sizeof(*this));
		         	
				 }
			}
			
			ofile.close();
			ifile.close();
			
			
			int q=remove("date.dat");
		   if (q==0)
		   {
		   	cout<<"ENTRY DELETED";
		   	getch();
		   }
		
			rename("date1.dat","date.dat");
		        
				
			
	            
			
		}
			
		
	
};


int main()
{



menu:
  
  showAppName();


  setCursor(3, 30);

 
   setTextColor(WHITE);
   cout << "PICK A MENU";

   setCursor(5, 30);
   setTextColor(MAGENTA);

  cout << "1. CHECK LEAP YEAR";

  setCursor(7, 30);

  cout << "2. PRINT CALENDAR";

  setCursor(9, 30);

  cout << "3. SCHEDULE APPOINTMENT";

  setCursor(11, 30);
  setTextColor(RED);

  cout << "4. QUIT";

  setCursor(13, 30);
   setTextColor(WHITE);

  cout << "Choice [1, 2, 3, 4]? ";

  int choice = getNumber();

  switch (choice)
  {

    // leap year check 
  case 1:
    {
      
      getInput();
      if (checkleap(year) == 1)
     {
     	setCursor(7, 30);
     	 setTextColor(CYAN);
        cout<<year<<" is a LEAP YEAR";
     	getch();
	  } 
	

	else
	
	{
		setCursor(7, 30);
		 setTextColor(CYAN);
		cout<<year<<" is NOT LEAP YEAR";
	
		
		}	
		setCursor(10, 30);
		setTextColor(WHITE);
		cout<<"Press enter to go back to menu";
		getch();
		goto menu;

    
    }

    // show calendar 
  case 2:
    {
    	
    	system("cls");

      getInput();
	  printcal(year);
	   setTextColor(WHITE);
	  cout<<"\nPress enter to go back to menu";
	  getch();
	  goto menu;



    }

    // schedule an appointment 
    case 3:
    {
    	menu1:
        system("cls");
        setCursor(3, 20);
         setTextColor(WHITE);
        cout << "PICK A MENU";
        setCursor(5, 20);
         setTextColor(MAGENTA);
        cout << "1. ADD APPOINTMENT";
		setCursor(7, 20);
		cout << "2. PRINT APPOINTMENT";
		setCursor(9, 20);
		cout << "3. SEARCH APPOINTMENT";
		setCursor(11, 20);
		cout<<"4. DELETE APPOINTMENT";
		setCursor(13, 20);
		 setTextColor(RED);
		cout << "5. GO BACK TO MAIN MENU";
		setCursor(15, 20);
		 setTextColor(WHITE);
		cout << "Choice [1, 2, 3, 4, 5]? ";
		int choice = getNumber();
		date s;
	    switch(choice)
	{
		case 1:
			{
			s.writetofile();
			goto menu1;
		}
             
              
        case 2:
        {
	     	s.readfromfile();
        	getch();
        	goto menu1;
        }
        case 3:
        {
			menu2:
            system("cls");
            setCursor(3, 20);
            setTextColor(WHITE);
            cout << "Pick a option";
            setCursor(5, 20);
             setTextColor(MAGENTA);
            cout << "1. SEARCH APPOINTMENT BY DATE";
		    setCursor(7, 20);
            cout << "2. SEARCH APPOINTMENT BY EVENT";
		    setCursor(9, 20);
		     setTextColor(RED);
		    cout << "3. GO BACK TO SCHEDULE MENU";
            setCursor(11, 20);
             setTextColor(WHITE);
			cout << "Choice [1, 2, 3]? ";
            int choice1 = getNumber();
			switch(choice1)
	    {
		    case 1:
			s.searchbydate();
			goto menu2;
             
              
            case 2:
        	s.searchbyevent();
        	getch();
        	goto menu2;
        
        
            case 3:
        	goto menu1;
        	
        	default:
        		break;
        }
    }
        case 4:
        
        {
			menu3:
            system("cls");
            setCursor(3, 20);
            setTextColor(WHITE);
            cout << "Pick a option";
            setCursor(5, 20);
             setTextColor(MAGENTA);
            cout << "1. DELETE APPOINTMENT BY DATE";
		    setCursor(7, 20);
            cout << "2. DELETE APPOINTMENT BY EVENT";
		    setCursor(9, 20);
		     setTextColor(RED);
		    cout << "3. GO BACK TO SCHEDULE MENU";
            setCursor(11, 20);
             setTextColor(WHITE);
			cout << "Choice [1, 2, 3]? ";
            int choice2 = getNumber();
			switch(choice2)
	    {
		    case 1:
			s.deletefromfile_date();
			cout<<endl<<"Press any key to continue";
			getch();
			goto menu1;
             
              
            case 2:
        	s.deletefromfile_event();
        	cout<<endl<<"Press any key to continue";
        	getch();
        	goto menu1;
        
        
            case 3:
        	goto menu1;
        	
        	default:
        	break;
        }
        }
        
        case 5:
        	goto menu;
        
        
        }


    
    }
    
}
}
  
  
  //FUNCTION DEFINATIONS

void getInput()
{
	system("cls");

  showAppName();

  

setCursor(5, 30);



 setTextColor(WHITE);

  cout << "Year?";

  year = getNumber();

 

}

int getNumber()
{

  int s;
  cin>>s;

  return s;

}



void printcal(int year)

{


	
	int day,week;
	int days_month[12]={31,28,31,30,31,30,31,30,31,30,31,30};
	string month[12]={"Janauary", "February", "March", "April", "May","June", "July","August","September","October","November","December"};

	if (year%4==0)
	
	if (year%4==0)
	days_month[1]=29;
	day=first_year(year);
	system("cls");
	setCursor(2, 10);
	cout<<"CALENDAR OF THE YEAR "<<year;

	
	for (int i=0; i<=11; i++)
	
	{
		 setTextColor(GREEN);
		cout<<endl<<endl<<month[i]<<"  "<<year<<endl;
		 setTextColor(CYAN);
		cout<<endl<<"   SUN   MON   TUE   WED   THU   FRI   SAT"<<endl;
		for(int j=0; j<day; j++)
		
		{
			cout<<"      ";
		}
		
		week=day;
		for(int m=1; m <=days_month[i]; m++)
		{
			
			if(m<=10)
			
			cout<<"     "; 
			
			else
			
			cout<<"    ";
			
			if(week>6)
			{
				cout<<"\n    "<<m;
				
				week=0;
			}
			
			else 
			cout<<m;
			week ++;
		}
		day=week;
	}
	
}




int first_year(int year) 
{
	
	int day;
	day=(((year-1)*365)+((year-1)/4)-((year-1)/100)+((year)/400)+1)%7;
	return day;
}

bool checkleap(int year)
{
	
	if (year % 400 == 0)
		return true;

	else if (year % 100 == 0)
		return false;


	else if (year % 4 == 0)
		return true;
	else
		return false;
	
}




