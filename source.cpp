/*==========================================*/
/*	                           HEADER FILES                                */
/*==========================================*/


#include<stdio.h>
#include<time.h>
#include<string.h>
#include<process.h>
#include<fstream.h>
#include<dos.h>
#include<graphics.h>
#include<conio.h>
/*=========================================*/
/*                        FUNCTION PROTOTYPES                       */
/*=========================================*/
void sp3();
void pg4();
void quit();
void instructions();
void pg2();
/* =========================================*/
/*                           GLOBAL VARIABLES                           */
/*=========================================*/
int key=1,flag=0,pal=0;
char u[20];

/* =========================================*/
/*                             CLASS DEFINITION                             */
/*=========================================*/
class login{
	int clas,age;
	char name[20],gender,hobby[20],password[20],username[20];
	int pt;
	public:
	void read();
	void disp();
	char*rtnusernm()
	{
	return username;
	}
	char*rtnname()
	{
	return name;
	}
	char*rtnpass()
	{
	return password;
	}
	int rtnpt()
	{
	return pt;
	}
	void ptstore(int n)
	{
	 pt=n;
	}
	};
	login l;
/*==========================================*/
/*                MEMBER FUNCTION DEFINITION                 */
/*==========================================*/

	int l1(char username1[20])
	{
	 int x=0;
	 ifstream f("detail.dat",ios::binary);
	 while(f.read((char*)&l,sizeof(l)))
	  {
	   if(strcmp(username1,l.rtnusernm())==0)
	     {
	       x++;
	     }
	  }
	 f.close();
	 if(x==0)
	  return 1;
	 else
	      return 0;
	}

	void login::read()
	  {
	    textcolor(6);
	    cprintf("Enter Name     : ");
	    gets(name);
	    cprintf("Enter Age      : ");
	    cin>>age;
	    cprintf("Enter Gender   : ");
	    cin>>gender;
	    cprintf("Enter Class    : ");
	    cin>>clas;
	    cprintf("Enter Hobby    : ");
	    gets(hobby);
	    int b;

	     do{
		cprintf("Enter Username : ");
		cin>>username;
		b=l1(username);
		if(b==1)
		break;
		else if(b==-1)
		 {
		  textcolor(4);
		  cprintf("Wrong Program");
		 }
		else
		 {
		  textcolor(7);
		  cout<<'\n';cprintf("Username already taken");cout<<'\n';
		 }
		}while(1); textcolor(6);
		cprintf("Enter Password : ");
		cin>>password;
		pt=0;
	       }
	    void login::disp()
	      {
	    pal++;
	    textcolor(9);
	    cprintf("Name     : ");
	    cout<<name;
	    cout<<'\n';cprintf("Age      : ");
	    cout<<age;
	    cout<<'\n';cprintf("Gender   : ");
	    cout<<gender;
	    cout<<'\n';cprintf("Class    : ");
	    cout<<clas;
	    cout<<'\n';cprintf("Hobby    : ");
	    cout<<hobby;
	    cout<<'\n';cprintf("Points   : ");
	    cout<<pt;
	    cout<<'\n';
	    }
	void login1()
	  {
	    clrscr();
	    char username1[20],password1[20];
	    ifstream f("detail.dat",ios::binary);
	    f.read((char*)&l,sizeof(l));
	   do{textcolor(6);
	    cprintf("ENTER USERNAME : ");
	    cin>>username1;
	    cprintf("ENTER PASSWORD : ");
	    cin>>password1;
	    do
	    {

	    if(strcmp(username1,l.rtnusernm())==0)
		 {
		  if(strcmp(password1,l.rtnpass())==0)
		  {
		  f.close();
		  strcpy(u,l.rtnusernm());
		  sp3();
		  }
		 }
	    }while(f.read((char*)&l,sizeof(l)));
	    textcolor(4);
	    cout<<"\n\n";cprintf("              RE-ENTER");cout<<"\n\n";
	    f.close();
	    f.open("detail.dat",ios::binary);
	    flag++;
	   }
	   while(flag<=2);
	  }
	void signup()
	  {
	    clrscr();
	    login s;
	    s.read();
	    if(flag!=3)
	    {
	    ofstream f2("detail.dat",ios::binary|ios::app);
	    f2.write((char*)&s,sizeof(s));
	    f2.close();
	     }
	    else
	   { textcolor(4);
	     cout<<'\n';cout<<"NO MORE CHANCES";}
	    delay(2000);
	    instructions();
	   }
void store(int m)
 {
 ifstream f("detail.dat",ios::binary);
 ofstream f1("temp.dat",ios::binary|ios::app);
 login s;
 int z=m;
 while(f.read((char*)&s,sizeof(s)))
  {
    if(strcmp(u,s.rtnusernm())==0)
     {
	s.ptstore(z);
	f1.write((char*)&s,sizeof(s));
     }
 else
    f1.write((char*)&s,sizeof(s));
 }
 f.close();
 f1.close();
 if(remove("detail.dat")==0)
 cout<<'\a';
 if(rename("temp.dat","detail.dat")==0)
 cout<<'\a';
 }
 void logsin()
  {
   int driver=DETECT,mode,key=1;
   initgraph(&driver,&mode,"..\\bgi");
   char ch;
   while(1)
    {
     settextstyle(3,0,7);setcolor(11);
     outtextxy(100,20,"TYPERUNNER");
     if(key==2)
      {
      setcolor(4);
      setlinestyle(1,2,3);
      line(200,207,270,207);
      }
     if(key==1)
      {
	setcolor(4);
       setlinestyle(1,2,3);
       line(200,167,265,167);
       }
      settextstyle(3,0,3);
      setcolor(1);
      outtextxy(200,140,"LOGIN");
       outtextxy(200,180,"SIGNUP");
       {
	ch=getch();
	if(ch==13)
	 {
	  if(key==1) ch='s';
	  if(key==2) ch='d';
	 }
	 if(ch=='s')
	  {
	   cleardevice();
	   closegraph();
	   delay(10);
	   login1();
	   cout<<"LOGIN";
	   getch();
	   exit(0);
	  }
	  if(ch=='d')
	    {
	      cleardevice();
	      closegraph();
	      delay(10);
	      signup();
	      cout<<"SIGNUP";
	      getch();
	      exit(0);
	   }

	  if(ch==80)
	   {
	     key++;
	    if(key>2)
	     key=1;
	  }
	  if(ch==75)
	    {
	     key++;
	     if(key>2)
	     key=1;
	    }
	 if(ch==72)
	  {
	     key--;
	     if(key<=0)
	     key=2;
	  }
	 if(ch==77)
	  {
	   key--;
	   if(key<=0)
	     key=2;
	  }
	 cleardevice();
      }
   }
}

void easy()
 {
 clrscr();
 char wr[20];
 clock_t s,e;
 gotoxy(25,1);
 textbackground(7);
 textcolor(4);
 cprintf("TYPERUNNER");
 char a[70],b[70];
 ifstream f1("EASY.txt");
 float k;
 cout<<"\n";
 int i=0;
 while(f1>>wr)
  {
   i++;
   cout<<wr<<" ";
   if(i==10)
   break;
  }
 f1.close();
 getch();
 s=clock();
 textcolor(3);
 ifstream f2("EASY.txt");
 char word[20],word1[20];
 int f=0,j=0,m=0,n=0;
 cout<<"\n\n";
 for(n=0;n<1;n++)
 {
 cout<<'\n';
 gets(b);
 for(int i=0;i<=strlen(b);i++)
 {
  if(b[i]!=' ' &&b[i]!='\0')
  {
   word[j++]=b[i];
  }
  else
  {word[j]='\0';
  j=0;
   f2>>word1;
   m++;
   if(strcmp(word,word1)==0)
   f++;
  }
 }
 strcpy(b,"\0");
}
 f2.close();
 e=clock();
 getch();
 k=(e-s)/CLK_TCK;
 cout<<int((m/k)*60);cprintf("wpm");
 cout<<'\n';
 if(m==f)
 cprintf("   ALL WORDS ARE CORRECT   ");
 else
 {
 cout<<'\n'<<f;cprintf("  Words are correct ");}
 int x,y;
 x=int((f/k)*60);
 if(x==0)
 x=1;
 store(x);
 textcolor(5);
 getch();
 pg4();
}

void medium()
 {
 clrscr();
 char wr[20];
 clock_t s,e;
 gotoxy(25,1);
 textbackground(7);
 textcolor(4);
 cprintf("TYPERUNNER");
 char a[70],b[70];
 ifstream f1("EASY.txt");
 float k;
 cout<<"\n";
 int i=0;
 while(f1>>wr)
  {
   i++;
   cout<<wr<<" ";
  if(i==10||i==20)
   cout<<'\n';
  if(i==28)
   break;
  }
 f1.close();
 getch();
 s=clock();
 textcolor(3);
 ifstream f2("EASY.txt");
 char word[20],word1[20];
 int f=0,j=0,m=0,n=0;
 cout<<"\n\n";
 for(n=0;n<3;n++)
   {
    cout<<'\n';
    gets(b);
    for(int i=0;i<=strlen(b);i++)
     {
      if(b[i]!=' ' &&b[i]!='\0')
       {
	word[j++]=b[i];
       }
     else
      {
       word[j]='\0';
       j=0;
       f2>>word1;
       m++;
      if(strcmp(word,word1)==0)
      f++;
      }
    }
  strcpy(b,"\0");
 }
 f2.close();
 e=clock();
 getch();
 k=(e-s)/CLK_TCK;
 cout<<int((m/k)*60);cprintf("wpm");
 cout<<'\n';
 if(m==f)
 cprintf("   ALL WORD ARE COORECT   ");
 else
  {
    cout<<'\n'<<f;cprintf("  Words are correct ");
  }
 int x,y;
 x=int((f/k)*60);
 if(x==0)
 x=1;
 store(x);
 textcolor(2);
 getch();
 pg4();
}

void hard()
 {
 clrscr();
 char wr[20];
 clock_t s,e;
 gotoxy(25,1);
 textbackground(7);
 textcolor(4);
 cprintf("TYPERUNNER");
 char a[70],b[70];
 ifstream f1("EASY.txt");
 float k;
 cout<<"\n";
 int i=0;
 while(f1>>wr)
 {
  i ++;
  cout<<wr<<" ";
  if(i==10||i==20||i==28||i==39)
    cout<<'\n';
  if(i==45)
    break;
 }
 f1.close();
 getch();
 s=clock();
 textcolor(3);
 ifstream f2("EASY.txt");
 char word[20],word1[20];
 int f=0,j=0,m=0,n=0;
 cout<<"\n\n";
 for(n=0;n<5;n++)
 {
 cout<<'\n';
 gets(b);
 for(int i=0;i<=strlen(b);i++)
 {
   if(b[i]!=' ' &&b[i]!='\0')
   {
     word[j++]=b[i];
   }
   else
   {
   word[j]='\0';
   j=0;
   f2>>word1;
   m++;
   if(strcmp(word,word1)==0)
   f++;
  }
 }
 strcpy(b,"\0");
}
 f2.close();
 e=clock();
 getch();
 k=(e-s)/CLK_TCK;
 cout<<int((m/k)*60);cprintf("wpm");
 cout<<'\n';
 if(m==f)
 cprintf("   ALL WORDS ARE CORRECT   ");
 else
 {
 cout<<'\n'<<f;cprintf("  Words are correct ");
 }
 int x,y;
 x=int((f/k)*60);
 if(x==0)
 x=1;
 store(x);
 textcolor(4);
 getch();
 pg4();
}
void playerdetails()
 {
  textcolor(5);
  cprintf("                                   PLAYERDETAILS");
  cout<<"\n\n\n";
  char u[20];
  login s;
  ifstream f1("detail.dat",ios::binary);
  f1.read((char*)&s,sizeof(s));
  char ch;
  do{
  textcolor(14);
  cprintf("Enter username : ");
  cin>>u;
    do{
       if(strcmp(u,s.rtnusernm())==0)
	     {
	      s.disp();
	      break;
	      }

    }while(f1.read((char*)&s,sizeof(s)));
     if(pal==0)
    {
      textcolor(4);
      cprintf("INVALID USERID");cout<<'\n';
    }
    f1.close();
    f1.open("detail.dat",ios::binary);
    cout<<'\n';
    textcolor(2);
    cprintf("If you want to continue enter 'y' ");cout<<'\n';
    cprintf("ENTER : ");cin>>ch;
    pal=0;
    }while(ch=='y'||ch=='Y');
  f1.close();
  getch();
  pg4();
}

void leaderboard()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"..\\bgi");
int a[50],i=0,k=0,j=0,temp=0,max=0;
char b[50][20],tempw[20];
login s;
ifstream f1("detail.dat",ios::binary);
while(f1.read((char*)&s,sizeof(s)))
  {
    a[i]=s.rtnpt();
    strcpy(b[i],s.rtnusernm());
    i++;
  }
f1.close();
for(k=0;k<i-1;k++)
   {
    max=k;
    for(j=k+1;j<i;j++)
       if(a[j]>a[max])
	 max=j;
     temp=a[k];strcpy(tempw,b[k]);
     a[k]=a[max];strcpy(b[k],b[max]);
     a[max]=temp;strcpy(b[max],tempw);
    }
setcolor(9);
settextstyle(3,0,7);
outtextxy(100,20,"LEADERBOARD");
settextstyle(3,0,2);
i=0;int x=50,y=2;char q[5];
f1.open("detail.dat",ios::binary);
f1.read((char*)&s,sizeof(s));
do{
do{
   if(strcmp(b[i],s.rtnusernm())==0)
      {
	  settextstyle(3,0,2);
	  i++;
	  setcolor(i+1);
	  sprintf(tempw,"%s",s.rtnname());
	  outtextxy(10,100+x,tempw);
	  settextstyle(2,0,7);
	  gotoxy(45,9+y);cout<<s.rtnpt();outtextxy(373,100+x,"wpm");
	  break;

       }
       }while(f1.read((char*)&s,sizeof(s)));
  x=x+50;
  y=y+3;
  f1.close();
  f1.open("detail.dat",ios::binary);
}while(i<=4);
f1.close();
getch();
closegraph();
pg4();
}
void pg4()
{
  int driver=DETECT,mode;
  initgraph(&driver,&mode,"..\\bgi");
  char ch;
  while(1)
   {
    settextstyle(3,0,7);setcolor(11);
    outtextxy(100,20,"TYPERUNNER");
    settextstyle(3,0,3);
    setcolor(12);
    if(key==1)
     {
      setcolor(6);
      setfillstyle(SOLID_FILL,15);
      rectangle(136,116,215,138);
      floodfill(197,127,6);
     }
    if(key==2)
     {
      setcolor(2);
      setfillstyle(SOLID_FILL,15);
      rectangle(136,146,230,168);
      floodfill(203,157,2);
     }
    if(key==3)
     {
      setcolor(4);
      setfillstyle(SOLID_FILL,15);
      rectangle(136,176,215,198);
      floodfill(213,197,4);
     }
    if(key==4)
     {
      setcolor(1);
      setfillstyle(SOLID_FILL,15);
      rectangle(136,206,206,228);
      floodfill(191,217,1);
     }
    if(key==5)
     {
      setcolor(9);
      setfillstyle(SOLID_FILL,15);
      rectangle(136,236,310,258);
      floodfill(307,255,9);
      }
    if(key==6)
     {
       setcolor(5);
       setfillstyle(SOLID_FILL,15);
       rectangle(136,266,325,288);
       floodfill(323,285,5);
     }
     setcolor(5);
     outtextxy(150,260,"PLAYERDETAILS");
     setcolor(9);
     outtextxy(150,230,"LEADERBOARD");
     setcolor(1);
     outtextxy(150,200,"QUIT");
     setcolor(4);
     outtextxy(150,170,"HARD");
     setcolor(2);
     outtextxy(150,140,"MEDIUM");
     setcolor(6);
     outtextxy(150,110,"EASY");

      {
       ch=getch();
	if(ch==13)
	 {
	  if(key==1) ch='s';
	  if(key==2) ch='d';
	  if(key==3) ch='i';
	  if(key==4) ch='q';
	  if(key==5) ch='l';
	  if(key==6) ch='p';
	 }
	 if(ch=='p')
	   {
	    cleardevice();
	    closegraph();
	    delay(10);
	    playerdetails();
	    getch();
	    exit(0);
	   }
	 if(ch=='l')
	   {
	    cleardevice();
	    closegraph();
	    delay(10);
	    leaderboard();
	    getch();
	    exit(0);
	   }
	 if(ch=='q')
	  {
	   cleardevice();
	   closegraph();
	   delay(10);
	   quit();
	   getch();
	   exit(0);
	  }

	 if(ch=='s')
	  {
	   cleardevice();
	   closegraph();
	   delay(10);
	   easy();
	   getch();
	   exit(0);
	  }
	 if(ch=='d')
	  {
	   cleardevice();
	   closegraph();
	   delay(10);
	   medium();
	   getch();
	   exit(0);
	  }
	 if(ch=='i')
	  {
	   cleardevice();
	   closegraph();
	   delay(10);
	   hard();
	   getch();
	   exit(0);
	  }
	 if(ch==80)
	  {
	   key++;
	   if(key>6)
	    key=1;
	  }
	  if(ch==75)
	  {
	   key++;
	   if(key>6)
	    key=1;
	  }
	  if(ch==72)
	  {
	   key--;
	   if(key<=0)
	    key=6;
	  }
	 if(ch==77)
	  {
	   key--;
	   if(key<=0)
	    key=6;
	  }
	 cleardevice();
      }
   }
}


void sp3()
 {
 int driver=DETECT,mode,y=0;
 initgraph(&driver,&mode,"..\\bgi");
 settextstyle(3,0,7);setcolor(11);
 outtextxy(100,20,"TYPERUNNER");
 getch();
 cleardevice();
 setcolor(11);
 settextstyle(3,0,7);
 char b[20];
 sprintf(b,"%s",l.rtnname());
 for(y=0;y<542;y=y+2)
 {
 cleardevice();
 settextstyle(3,0,7);setcolor(11);
 outtextxy(100+y,20,"TYPERUNNER");
 settextstyle(7,0,5);setcolor(2);
 outtextxy(170,100,"WELCOME");setcolor(13);
 outtextxy(170,170,b);setcolor(y);
 outtextxy(75,240,"LET'S GO TYPE RUNNER");
 delay(1);
}
 pg4();
 cout<<"DONE";
 getch();
 closegraph();
}
void instructions()
 {
 int gd=DETECT,gm;
 initgraph(&gd,&gm,"..\\bgi");
 setcolor(10);
 settextstyle(1,0,5);
 outtextxy(160,40,"INSTRUCTIONS");
 settextstyle(3,0,1);
 setcolor(1);
 outtextxy(10,150,"YOU HAVE TO TYPE WITHIN A PARTICULAR LIMITED TIME.");
 outtextxy(10,175,"YOU CAN TYPE AS FAST AS YOU CAN.");
 outtextxy(10,195,"YOU CAN FINISH BY ENTERING THE TEXT DISPLAYED");
 outtextxy(10,215,"FINISH IN LIMITED TIME WITH CORRECTED WORDS ");
 getch();
 closegraph();
pg2();
}

void about()
{
 int gd=DETECT,gm;
 initgraph(&gd,&gm,"..\\bgi");
 setcolor(2);
 settextstyle(1,0,5);
 outtextxy(260,40,"ABOUT");
 settextstyle(3,0,1);
 setcolor(1);
 outtextxy(10,150,"THIS PROGRAM IS ABOUT IMPROVING THE TYPING SPEED OF PROGRAMMERS.");
 outtextxy(10,175,"PROGRAMMERS ARE OFTEN GIVEN VERY ADVANCED CODES.  ");
 outtextxy(10,195,"MANY COMPANIES WANT VERY FAST CODERS WITH BEST TYPING ABILITY  ");
 outtextxy(10,215,"YOU CAN CHECK YOUR TYPING SPEED USING THIS CODE. ");
 setcolor(8);
 outtextxy(10,245,"DONE BY -");
 setcolor(11);
 outtextxy(10,265,"JAYANTH AND NAVEEN");
 getch();
 closegraph();
 pg2();
}
void quit()
{
 exit(0);
}
void pg2()
{
  int driver=DETECT,mode;
  initgraph(&driver,&mode,"..\\bgi");
  char ch;
  while(1)
   {
    settextstyle(3,0,7);setcolor(11);
    outtextxy(100,20,"TYPERUNNER");
    settextstyle(3,0,3);
    setcolor(12);
    if(key==1)
     {
      setcolor(6);
      setfillstyle(SOLID_FILL,15);
      rectangle(136,116,300,138);
      floodfill(238,127,6);
     }
    if(key==2)
     {
      setcolor(4);
      setfillstyle(SOLID_FILL,15);
      rectangle(136,146,230,168);
      floodfill(203,157,4);
     }
    if(key==3)
     {
      setcolor(2);
      setfillstyle(SOLID_FILL,15);
      rectangle(136,176,310,198);
      floodfill(243,197,2);
     }
    if(key==4)
     {
      setcolor(1);
      setfillstyle(SOLID_FILL,15);
      rectangle(136,206,206,228);
      floodfill(191,217,1);
     }
     setcolor(1);
     outtextxy(150,200,"QUIT");
     setcolor(2);
     outtextxy(150,170,"INSTRUCTIONS");
     setcolor(4);
     outtextxy(150,140,"ABOUT");
     setcolor(6);
     outtextxy(150,110,"START GAME");
      {
       ch=getch();
	if(ch==13)
	 {
	  if(key==1) ch='s';
	  if(key==2) ch='d';
	  if(key==3) ch='i';
	  if(key==4) ch='q';
	 }
	 if(ch=='q')
	  {
	   cleardevice();
	   closegraph();
	   delay(10);
	   quit();
	   getch();
	   exit(0);
	  }
	 if(ch=='s')
	  {
	   cleardevice();
	   closegraph();
	   delay(10);
	   logsin();
	   getch();
	   exit(0);
	  }
	 if(ch=='d')
	  {
	   cleardevice();
	   closegraph();
	   delay(10);
	   about();
	   getch();
	   exit(0);
	  }
	 if(ch=='i')
	  {
	   cleardevice();
	   closegraph();
	   delay(10);
	   instructions();
	   getch();
	   exit(0);
	  }
	 if(ch==80)
	  {
	   key++;
	   if(key>4)
	    key=1;
	  }
	  if(ch==75)
	  {
	   key++;
	   if(key>4)
	    key=1;
	  }
	  if(ch==72)
	  {
	   key--;
	   if(key<=0)
	    key=4;
	  }
	 if(ch==77)
	  {
	   key--;
	   if(key<=0)
	    key=4;
	  }
	 cleardevice();
      }
   }
}
void codepix()
{
 int gd=DETECT, gm;
 initgraph(&gd,&gm, "..\\bgi");
 setcolor(11);
 settextstyle(8,0,8);
 outtextxy(20,110,"TYPE RUNNER");
 setcolor(7);
 settextstyle(3,0,3);
 outtextxy(170,300,"DONE BY : ");
 setcolor(10);
 settextstyle(3,0,2);
 outtextxy(200,330,"JAYANTH AND NAVEEN");
 getch();
 closegraph();
 pg2();
}
void main()
{
 clrscr();
 codepix();
}
