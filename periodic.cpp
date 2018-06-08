/*//Program Name: PERIODIC TABLE                         //*/
/*//Description : MENU DRIVEN INTERACTIVE PERIODIC TABLE //*/
//---------------------------------------------------------//

#include<iostream.h>
#include<fstream.h>
#include<process.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>

//CLASS ELEMENT TO ENTER ELEMENT DATA AND DISPLAY IT


class group
{
	public:
	unsigned long pos;
	int groupno;
	char elements[20];                  //elements present
	char block;                         //s,p,d,f
	//char nm[10];                        //general name of group
	char config[20];                    //general electronic configuration
	//char itrends[100];                  //Properties increasing down the group
	//char dtrends[100];                  //Properties decreasing down the group
	char info[300];

	group()
	{
		pos = 0;
		groupno = 0;
		strcpy(elements, "\0");
		block = '\0';
		//strcpy(nm, "\0");
		strcpy(config, "\0");
		strcpy(info, "\0");
	}

	void getdata()
	{ cout<<"\nGroup No:";
	  cin>>groupno;
	  cout<<"\nBlock: ";
	  cin>>block;
	  cout<<"\nGeneral EC :";
	  gets(config);
	  cout<<"\nElments:";
	  gets(elements);
	  cout<<"\nInfo:";


	}
	void showdata()
	{
	 cout<<"\nGroup :"<<groupno;
	 cout<<"\nBlock: "<<block;
	 cout<<"\nElectronic configuration  :"<<config;
	 cout<<"\nElements:"<<elements;
	 cout<<"\nInformation:"<<info;
	}

};

void disptable(void);
void menu(void);
void colour(void);
void main()
{  /*     int i=0;
	char ch='a';

	group x;
	fstream file;


	file.open("D:\\pt\\group.txt",ios::app);

	while(i<2)
	{

		x.getdata();
		file.write((char *)&x, sizeof(group));
		i++;
	}
	file.close();


	file.open("D:\\pt\\group.txt", ios::in);
	i = 0;
	while (i<2)
	{
		file.read((char *)&x, sizeof(group));
		x.showdata();
		cout<<endl;
		i++;
	}
	file.close();
	*/
	char c='a';
	char ele[120][4]={" ","H","He","Li","Be","B","C","N","O","F","Ne","Na","Mg","Al","Si","P","S","Cl","Ar","K","Ca","Sc","Ti","V","Cr","Mn","Fe","Co","Ni","Cu","Zn","Ga","Ge","As","Se","Br","Kr","Rb","Sr","Y","Zr","Nb","Mo","Tc","Ru","Rh","Pd","Ag","Cd","In","Sn","Sb","Te","I","Xe","Cs","Ba","La*","Hf","Ta","W","Re","Os","Ir","Pt","Au","Hg","Tl","Pb","Bi","Po","At","Rn","Fr","Ra","Ac*","Rf","Db","Sg","Bh","Hs","Mt","Ds","Rg","Cn","Uut","Fl","Uup","Lv","Uus","Uuo"};
	char f4[15][4]={" ","Ce","Pr","Nd","Pm","Sm","Eu","Gd","Tb","Dy","Ho","Er","Tm","Yb","Lu"};
	char f5[15][4]={" ","Th","Pa","U","Np","Pu","Am","Cm","Bk","Cf","Es","Fm","Md","No","Lr"} ;
	int atmno;
	clrscr();
	menu();

    while(c!='e')

  {

	   c=getch();
	   if(c=='h')
	   {
		clrscr();
	   }
	   else if(c=='m')
	   {
		menu();
	   }
	   else if(c=='g')
	   {
		clrscr();
		cout<<"\n\n\n\n\n\n\n\n\t\t\t     Enter atomic no: ";
		cin>>atmno;
		gotoxy(37,11);
		if(atmno>57 && atmno<72)
		{

		 cout<<atmno<<":"<<f4[atmno-57];

		}
		else if(atmno>89 && atmno<104)
		{
		  cout<<atmno<<":"<<f5[atmno-89];
		}
		else
		cout<<atmno<<":"<<ele[atmno];

	   }
	   else if(c=='s')
		   {
		clrscr();
		disptable();

	   }

	   else
	   {
		c=getch();
	   }
   }


   getch();
}

//Gets input, press Ctrl+Z+enter for stopping input
int getline(char *s)
{
	int c;
	char *start = s;
	while ((c=getche()) != '\r')
	{
		*s = c;
		s++;
	}
	*s = '\0';
	return s-start;
}
void disptable()
{
  int i;

  char ele[120][4]={" ","H","He","Li","Be","B","C","N","O","F","Ne","Na","Mg","Al","Si","P","S","Cl","Ar","K","Ca","Sc","Ti","V","Cr","Mn","Fe","Co","Ni","Cu","Zn","Ga","Ge","As","Se","Br","Kr","Rb","Sr","Y","Zr","Nb","Mo","Tc","Ru","Rh","Pd","Ag","Cd","In","Sn","Sb","Te","I","Xe","Cs","Ba","La*","Hf","Ta","W","Re","Os","Ir","Pt","Au","Hg","Tl","Pb","Bi","Po","At","Rn","Fr","Ra","Ac*","Rf","Db","Sg","Bh","Hs","Mt","Ds","Rg","Cn","Uut","Fl","Uup","Lv","Uus","Uuo"};

  char f4[15][4]={" ","Ce","Pr","Nd","Pm","Sm","Eu","Gd","Tb","Dy","Ho","Er","Tm","Yb","Lu"};

  char f5[15][4]={" ","Th","Pa","U","Np","Pu","Am","Cm","Bk","Cf","Es","Fm","Md","No","Lr"} ;
  //TABLE LAYOUT
	cout<< endl<<"    ";
	for(i=1;i<=18;i++)
	{
		if(i/10==0)
			cout<<" "<<i<<"  ";
		  else
		  cout<<" "<<i<<" ";
	}
	cout<<endl<<endl;
	for(int j=1;j<=7;j++)
	{
		cout<<"   " ;
		for( i=1;i<=18;i++)
		{
			if((j==1 && i>=2 && i<18)||(j==2 && i>=3 && i<13)||(j==3 & i>=3 && i<13))
			cout<< "    ";
			else
			cout<<" ÍÍÍ" ;
		}
		cout<<endl;
		cout<<"   "  ;
		for( i=1;i<=18;i++)
		{
			if(i==18)
				cout<<"º   º";
			else if((j==1 && i>2 && i<18)||(j==2 && i>3 && i<13)||(j==3 & i>3 && i<13))
				cout<<"    ";

		    else
		    cout<<"º   ";

		}
		cout<<endl;
	}
	cout<<"   ";
	for(i=1;i<=18;i++)
	cout<<" ÍÍÍ";
	  //=======================================================================//
	gotoxy(5,5);cout<<"H" ;
	gotoxy(73,5);cout<<"He";
	int y=7,x=5;
	//Element filling for period 1,2 and 3
	for(int p=1;p<=16;p++)
	{
		gotoxy(x,y);
		cout<<ele[p+2];
		if(x==9)
		{
			 x=53;
		}
		else if(p==8)
		{
			x=5;
			y=y+2;
		}
		else if(strlen(ele[p+2])==2)
		{
			x=x+4;
		}
		else
			    x=x+4;

	}

     //Period 3 ends

   //Filling rest of the table
   x=5 ;
   y=11  ;


   for(p=19;p<=118;p++)
   {
       gotoxy(x,y);
       x=x+4;
       cout<<ele[p];
      if(x==77)
     {
       y=y+2;
       x=5;
       gotoxy(x,y);
     }


   }
    //REST OF TABLE ENDS


    //PERIOD NUMBER

     int init=5;
     for(i=1;i<=7;i++)
     {
      gotoxy(2,init);
      cout<<i;
      init=init+2;
     }
    //PERIOD NUMBER ENDS



   // LANTHANOID AND ACTINOIDS SERIES
	gotoxy(12,20);

	for(i=1;i<=14;i++)
	{ cout<< " ÍÍÍ";

	}  cout<<endl;
	gotoxy(12,21);
	x=12;y=21;
	for(j=0;j<=1;j++)
	{
		gotoxy(12,y++);
		for(i=1;i<=14;i++)
		{
			  cout<<"º   " ;
		}
		cout<<"º";
		gotoxy(12,y++);
		for(i=1;i<=14;i++)
		{
			cout<<" ÍÍÍ";
		}

	}
	gotoxy(13,21);
	x=13;
	y=21;                        //initial
	for(i=1;i<=14;i++)
	{ gotoxy(x,y);
	  cout<<f4[i];
	  if(strlen(f4[i])==2)
	  x=x+4;
	  else
	  x=x+5;
	}
	x=13;y=23;
	for(i=1;i<=14;i++)
	{ gotoxy(x,y);
	  cout<<f5[i];
	  if(strlen(f5[i])==1)
	  x=x+4;
	  else if(strlen(f5[i])==2)
	  x=x+4;
	  else
	  x=x+5;
	}
}
void menu()
{
	clrscr();
	int i=1;
	textattr(WHITE);
	textbackground(BLUE);
	for(i=1;i<=80;i++)
	cprintf(" ");
	cprintf("                            ");
	textattr(YELLOW);
	textbackground(BLUE);

	cprintf("...<PERIODIC TABLE>...");
	textattr(WHITE);
	textbackground(BLUE);
	cprintf("                              ");
	for(i=1;i<=80;i++)
	cprintf(" ");
	i=1;
	while(i<81)
	{textattr(25);
	 textbackground(BLUE);
	 cprintf("=");
	 i++;
	}
	textattr(WHITE);
	textbackground(BLUE);

	cprintf("                                  MAIN MENU:                                    ");
	colour();
	cprintf("                     =>    Press 'm' to show menu                           ");
	colour();
	cprintf("                         =>    Press 's' to show table");
	colour();
	cprintf("                                                   =>    Press 'h' to hide table");
	colour();
	cprintf("                                                   =>    Press 'e' to exit program");
	colour();
	cprintf("                                         =>    Press 'g' to know Element (input atm no).                    ");
	for(i=1;i<=8;i++)
	colour();
	i=1;
	while(i<81)
	{textattr(25);
	 textbackground(BLUE);
	 cprintf("=");
	 i++;
	}
	 textattr(151);
}
void colour()     //function to insert a blue coloured blank line
{
  textbackground(BLUE);
  for(int i=1;i<=80;i++)
  cprintf(" ");
  textbackground(BLUE);
}
