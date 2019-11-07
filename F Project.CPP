
// Header Files & Macros Included

#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<iostream.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#define bca 4450
#define bcj 5550
#define bda 3425
#define bdj 4487
#define bka 6900
#define bkj 7120
#define bma 3925
#define bmj 4940
#define cda 7350
#define cdj 8350
#define cka 6200
#define ckj 7000
#define cma 4900
#define cmj 5850
#define dka 4000
#define dkj 4700
#define dma 6500
#define dmj 7550
#define dka 4000
#define dkj 4700
#define kma 8000
#define kmj 8720

// Structures Declared

struct oneway
{
  int from,to;
  int dd,mm,yyyy;
  char clas;
  int adult,child;
};
struct round
{
  int from,to,retun;
  int dd,mm,yyyy,DD,MM,YYYY;
  char clas;
  int adult,child;
};
struct cargo
{
  int from,to;
  int dd,mm,yyyy;
  float par;
};
struct nad
{
  char ad[40];
}name[100];
struct nch
{
  char ch[40];
}nme[100];

// Main Program

void main()
{
  clrscr ();

  // Graphics

  int a,b=DETECT;
  detectgraph(&a,&b);
  initgraph(&a,&b," ");
  settextstyle(SANS_SERIF_FONT,HORIZ_DIR,7);
  setcolor(RED);
  for(int q=0;q<650;q+=3)
  {
    for(int w=100;w<200;w+=3)
    {
      setcolor(RED);
      line(0,100,q,w);
      setcolor(BLUE);
      outtextxy(200,100,"Loading...");
    }
  }
  setcolor(RED);
  for(float y=0;y<300;y+=0.3)
  {
    cleardevice();
    outtextxy(190,y,"RESERVAIR");
  }
  settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
  outtextxy(210,380," DOMESTIC AIR SERVICE");
  for(int e=0;e<200;e+=10)
  {
    for(int r=0;r<200;r+=10)
    {
      line(0,0,e,r);
    }
  }
  setcolor(RED+GREEN);
  line(240,230,340,130);
  line(340,130,440,230);
  line(250,170,430,170);
  line(340,170,340,270);
  for (int r=100 ; r<=110;r++)
    circle(340,205,r);
  settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
  outtextxy(500,400,"MADE BY;");
  outtextxy(500,410,"ARPIT GUPTA");
  outtextxy(500,420,"TUSHAR SHARMA");
  sleep(5);
  closegraph();

  // Main Menu

  main:
  clrscr();
  int t,i;
  char ext;
  cout<<" MAIN MENU"<<endl<<endl;
  cout<<"1. ONE WAY"<<endl;
  cout<<"2. ROUND TRIP"<<endl;
  cout<<"3. CARGO"<<endl;
  cout<<"4. EXIT"<<endl<<endl;
  cout<<"Note: For cancelation of Ticket or Customer Care contact 011-9988776655.";
  cout<<"\n\n\n";
  cout<<"Your choice:";
  cin>>t;
  if(t<1||t>4)
  {
    cout<<"\a ERROR: ENTER CORRECT CHOICE";
    getch();
    clrscr();
    goto main;
  }
  switch (t)
  {
    case 1:

    // 1. One Way

    one:
    clrscr();
    oneway f;
    cout<<"\t\t\t\tONE WAY"<<endl<<endl;
    cout<<"BOOKING DETAILS"<<endl;
    cout<<"Codes\t\t   City";
    cout<<endl<<"1\t\t   Bhopal";
    cout<<endl<<"2\t\t   Chennai";
    cout<<endl<<"3\t\t   Delhi";
    cout<<endl<<"4\t\t   Kolkata";
    cout<<endl<<"5\t\t   Mumbai"<<endl<<endl;
    cout<<"From (enter nos. from above codes):";
    cin>>f.from;
    if(f.from<=0 || f.from>=6)
    {
      cout<<"\a ERROR: TOO MANY PARAMETERS!!!!!!!!!";
      getch();
      goto one;
    }
    cout<<"To (enter nos. from above code):";
    cin>>f.to;
    if(f.to<=0 || f.to>=6)
    {
      cout<<"\a ERROR: TOO MANY PARAMETERS!!!!!!!!!";
      getch();
      goto one;
    }
    if(f.from==f.to)
    {
      cout<<"\a ERROR: TO & FROM CANNOT BE SAME";
      getch();
      goto one;
    }
    cout<<"Departuring date(dd mm yyyy):";
    cin>>f.dd>>f.mm>>f.yyyy;
    cout<<"Class (B/E):";
    cin>>f.clas;
    if(f.clas!='b'&& f.clas!='B' && f.clas!='E' && f.clas!='e')
    {
      cout<<"\a ERROR: TOO MANY PARAMETERS!!!!!";
      getch();
      goto one;
    }
    cout<<endl<<"PASSENGER DETAILS";
    cout<<endl<<"Adults:";
    cin>>f.adult;
    for(i=0;i<f.adult;i++)
    {
      cout<<"NAME: ";
      cin>>name[i].ad;
    }
    cout<<"Children (0-11):";
    cin>>f.child;
    for(i=0;i<f.child;i++)
    {
      cout<<"NAME: ";
      cin>>nme[i].ch;
    }
    cout<<endl;
    cout<<"Press ENTER";
    getch();
    clrscr();

    // Calculating The Data For One Way

    char c[20],v[20];
    switch (f.from)
    {
      case 1:
      strcpy(c,"BHOPAL");
      break;

      case 2:
      strcpy(c,"CHENNAI");
      break;

      case 3:
      strcpy(c,"DELHI");
      break;

      case 4:
      strcpy(c,"KOLKATA");
      break;

      case 5:
      strcpy(c,"MUMBAI");
      break;
    }
    switch (f.to)
    {
      case 1:
      strcpy(v,"BHOPAL");
      break;

      case 2:
      strcpy(v,"CHENNAI");
      break;

      case 3:
      strcpy(v,"DELHI");
      break;

      case 4:
      strcpy(v,"KOLKATA");
      break;

      case 5:
      strcpy(v,"MUMBAI");
      break;
    }
    char cl[20];
    if(f.clas=='b'||f.clas=='B')
      strcpy(cl,"BUSINESS CLASS");
    else
      strcpy(cl,"ECONOMIC CLASS");
    int farea,farej;
    if((f.from==1 && f.to==2) || (f.from==2 && f.to==1))
    {
      farea=bca;
      farej=bcj;
    }
    if((f.from==1 && f.to==3) || (f.from==3 && f.to==1))
    {
      farea=bda;
      farej=bdj;
    }
    if((f.from==1 && f.to==4) || (f.from==4 && f.to==1))
    {
      farea=bka;
      farej=bkj;
    }
    if((f.from==1 && f.to==5) || (f.from==5 && f.to==1))
    {
      farea=bma;
      farej=bmj;
    }
    if((f.from==2 && f.to==3) || (f.from==3 && f.to==2))
    {
      farea=cda;
      farej=cdj;
    }
    if((f.from==2 && f.to==4) || (f.from==4 && f.to==2))
    {
      farea=cka;
      farej=ckj;
    }
    if((f.from==2 && f.to==5) || (f.from==5 && f.to==2))
    {
      farea=cma;
      farej=cmj;
    }
    if((f.from==3 && f.to==4) || (f.from==4 && f.to==3))
    {
      farea=dka;
      farej=dkj;
    }
    if((f.from==3 && f.to==5) || (f.from==5 && f.to==3))
    {
      farea=dma;
      farej=dmj;
    }
    if((f.from==4 && f.to==5) || (f.from==5 && f.to==4))
    {
      farea=kma;
      farej=kmj;
    }
    float d,neta,netj,net;
    if(f.clas=='e'||f.clas=='E')
      d=0;
    else
      d=0.4;
    int choice;
    neta=((farea+(d*farea))*f.adult)+((0.75*(farea+(d*farea)))*f.child);
    netj=((farej+(d*farej))*f.adult)+((0.75*(farej+(d*farej)))*f.child);

    // Flight Details of One Way

    fare:
    int dot;
    cout<<"\t\t\t\tFlight Details"<<endl<<endl;
    for (dot=0 ; dot<80;dot++)
      cout<<".";
    cout<<" AIR INDIA"<<endl;
    cout<<"From: "<<c<<"\tTo: "<<v<<endl;
    cout<<"Departuring date: "<<f.dd<<"/"<<f.mm<<"/"<<f.yyyy<<endl;
    cout<<"Time of Departure: 10:00 am"<<endl;
    cout<<"Class: "<<cl<<endl;
    cout<<"Adult(s): "<<f.adult<<endl;
    cout<<"Children: "<<f.child<<endl;
    cout<<"NET FARE: Rs."<<neta<<"/-"<<endl;
    for (dot=0 ; dot<80;dot++)
      cout<<".";
    cout<<endl<<" JET AIRWAYS"<<endl;
    cout<<"From: "<<c<<"\tTo: "<<v<<endl;
    cout<<"Departuring date: "<<f.dd<<"/"<<f.mm<<"/"<<f.yyyy<<endl;
    cout<<"Time of Departure: 10:00 am"<<endl;
    cout<<"Class: "<<cl<<endl;
    cout<<"Adult(s): "<<f.adult<<endl;
    cout<<"Children: "<<f.child<<endl;
    cout<<"NET FARE: RS."<<netj<<"/-"<<endl;
    for (dot=0 ; dot<80;dot++)
      cout<<".";
    cout<<endl<<"ENTER 1 IF AIR INDIA & 2 IF JET AIRWAYS: ";
    cin>>choice;
    if(choice<1 || choice>2)
    {
      cout<<"\a ERROR: TOO MANY PARAMETERS!!!!!!";
      getch();
      clrscr();
      goto fare;
    }
    switch (choice)
    {
      case 1:

      // AIR INDIA Ticket For One Way

      net=neta;
      clrscr();
      cout<<endl;
      for (dot=0 ; dot<80;dot++)
	cout<<"~";
      cout<<"\t\t\t\t  AIR INDIA"<<endl<<endl;
      cout<<" From "<<c<<" to "<<v<<endl;
      cout<<" < "<<f.dd<<"/"<<f.mm<<"/"<<f.yyyy;
      cout<<" >  < AI-109 >";
      cout<<"  < "<<cl;
      cout<<" >  <  Departs "<<c<<" at 10:00 am >"<<endl<<endl;
      cout<<" PASSENGER INFORMATION:"<<endl;
      cout<<" "<<f.adult + f.child<<" Passenger(s)"<<endl;
      cout<<" ADULT:"<<endl;
      for(i=0;i<f.adult;i++)
	cout<<" "<<name[i].ad<<" ;";
      cout<<endl<<endl<<" CHILDREN:"<<endl;
      for(i=0;i<f.child;i++)
	cout<<" "<<nme[i].ch<<" ;";
      cout<<"\n\n Net Amount: Rs."<<net<<"/-"<<endl<<endl;
      for (dot=0 ; dot<80;dot++)
	cout<<"~";
      cout<<"  Here is your TICKET. \n";
      cout<<"  Get it`s Print Out & make the cash payment at the Booking Counter at the \n  airport.";
      getch();
      clrscr();
      cout<<"DO YOU WANT TO CONTINUE(y/n):";
      cin>>ext;
      if(ext=='y'||ext=='Y')
	goto main;
      else if(ext=='n'||ext=='N')
	cout<<"THANKING YOU...............";
      getch();
      exit(1);
      getch();
      break;

      case 2:

      // JET AIRWAYS Ticket For One Way

      net=netj;
      clrscr();
      cout<<endl;
      for (dot=0 ; dot<80;dot++)
	cout<<"~";
      cout<<"\t\t\t\t  JET AIRWAYS"<<endl<<endl;
      cout<<" From "<<c<<" to "<<v<<endl;
      cout<<" < "<<f.dd<<"/"<<f.mm<<"/"<<f.yyyy;
      cout<<" >  < JA-109 >";
      cout<<"  < "<<cl;
      cout<<" >  <  Departs "<<c<<" at 10:00 am >"<<endl<<endl;
      cout<<" PASSENGER INFORMATION:"<<endl;
      cout<<" "<<f.adult + f.child<<" Passenger(s)"<<endl;
      cout<<" ADULT:"<<endl;
      for(i=0;i<f.adult;i++)
	cout<<" "<<name[i].ad<<" ;";
      cout<<endl<<endl<<" CHILDREN:"<<endl;
      for(i=0;i<f.child;i++)
	cout<<" "<<nme[i].ch<<" ;";
      cout<<"\n\n Net Amount: Rs."<<net<<"/-"<<endl<<endl;
      for (dot=0 ; dot<80;dot++)
	cout<<"~";
      cout<<"  Here is your TICKET. \n";
      cout<<"  Get it`s Print Out & make the cash payment at the Booking Counter at the \n  airport.";
      getch();
      clrscr();
      cout<<"DO YOU WANT TO CONTINUE(y/n):";
      cin>>ext;
      if(ext=='y'||ext=='Y')
	goto main;
      else if(ext=='n'||ext=='N')
	cout<<"THANKING YOU...............";
      getch();
      exit(1);
      getch();
      break;
    }
    break;

    case 2:

    // 2. Round Trip

    round:
    clrscr();
    round g;
    cout<<"\t\t\t\tROUND TRIP"<<endl<<endl;
    cout<<"BOOKING DETAILS"<<endl;
    cout<<"Codes\t\t   City";
    cout<<endl<<"1\t\t   Bhopal";
    cout<<endl<<"2\t\t   Chennai";
    cout<<endl<<"3\t\t   Delhi";
    cout<<endl<<"4\t\t   Kolkata";
    cout<<endl<<"5\t\t   Mumbai"<<endl<<endl;
    cout<<"From (enter nos. from above codes):";
    cin>>g.from;
    if(g.from<=0 || g.from>=6)
    {
      cout<<"\a ERROR: TOO MANY PARAMETERS!!!!!!!!!";
      getch();
      goto round;
    }
    cout<<"To (enter nos. from above code):";
    cin>>g.to;
    if(g.to<=0 || g.to>=6)
    {
      cout<<"\a ERROR: TOO MANY PARAMETERS!!!!!!!!!";
      getch();
      goto round;
    }
    if(g.from==g.to)
    {
      cout<<"\a ERROR: TO & FROM CANNOT BE SAME";
      getch();
      goto round;
    }
    cout<<"Departuring date (dd mm yyyy):";
    cin>>g.dd>>g.mm>>g.yyyy;
    cout<<"Returning Date (dd mm yyyy):";
    cin>>g.DD>>g.MM>>g.YYYY;
    if((g.YYYY<g.yyyy) || (g.YYYY==g.yyyy && g.MM<g.mm) || (g.DD<g.dd && g.MM==g.mm && g.YYYY==g.yyyy))
    {
      cout<<"\a ERROR: RETURNING DATE MUST COME AFTER DEPARTURING DATE";
      getch();
      goto round;
    }
    cout<<"Class (B/E):";
    cin>>g.clas;
    if(g.clas!='b'&& g.clas!='B' && g.clas!='E' && g.clas!='e')
    {
      cout<<"\a ERROR: TOO MANY PARAMETERS!!!!!";
      getch();
      goto round;
    }
    cout<<endl<<"PASSENGER DETAILS";
    cout<<endl<<"Adults:";
    cin>>g.adult;
    for(i=0;i<g.adult;i++)
    {
      cout<<"NAME: ";
      cin>>name[i].ad;
    }
    cout<<"Children (0-11):";
    cin>>g.child;
    for(i=0;i<g.child;i++)
    {
      cout<<"NAME: ";
      cin>>nme[i].ch;
    }
    cout<<endl;
    cout<<"Press ENTER";
    getch();
    clrscr();

    // Calculating The Data For Round Trip

    char cb[20],vb[20];
    switch (g.from)
    {
      case 1:
      strcpy(cb,"BHOPAL");
      break;

      case 2:
      strcpy(cb,"CHENNAI");
      break;

      case 3:
      strcpy(cb,"DELHI");
      break;

      case 4:
      strcpy(cb,"KOLKATA");
      break;

      case 5:
      strcpy(cb,"MUMBAI");
      break;
    }
    switch (g.to)
    {
      case 1:
      strcpy(vb,"BHOPAL");
      break;

      case 2:
      strcpy(vb,"CHENNAI");
      break;

      case 3:
      strcpy(vb,"DELHI");
      break;

      case 4:
      strcpy(vb,"KOLKATA");
      break;

      case 5:
      strcpy(vb,"MUMBAI");
      break;
    }
    char clr[20];
    if(g.clas=='b' && g.clas=='B')
      strcpy(clr,"BUSINESS CLASS");
    else
      strcpy(clr,"ECONOMIC CLASS");
    int farear,farejr;
    if((g.from==1 && g.to==2) || (g.from==2 && g.to==1))
    {
      farear=bca;
      farejr=bcj;
    }
    if((g.from==1 && g.to==3) || (g.from==3 && g.to==1))
    {
      farea=bda;
      farejr=bdj;
    }
    if((g.from==1 && g.to==4) || (g.from==4 && g.to==1))
    {
      farear=bka;
      farejr=bkj;
    }
    if((g.from==1 && g.to==5) || (g.from==5 && g.to==1))
    {
      farear=bma;
      farejr=bmj;
    }
    if((g.from==2 && g.to==3) || (g.from==3 && g.to==2))
    {
      farear=cda;
      farejr=cdj;
    }
    if((g.from==2 && g.to==4) || (g.from==4 && g.to==2))
    {
      farear=cka;
      farejr=ckj;
    }
    if((g.from==2 && g.to==5) || (g.from==5 && g.to==2))
    {
      farear=cma;
      farejr=cmj;
    }
    if((g.from==3 && g.to==4) || (g.from==4 && g.to==3))
    {
      farear=dka;
      farejr=dkj;
    }
    if((g.from==3 && g.to==5) || (g.from==5 && g.to==3))
    {
      farear=dma;
      farejr=dmj;
    }
    if((g.from==4 && g.to==5) || (g.from==5 && g.to==4))
    {
      farear=kma;
      farejr=kmj;
    }
    float dr,netar,netjr,netr;
    if(g.clas=='e'||g.clas=='E')
      dr=0;
    else
      dr=0.4;
    int choicer;
    netar=1.7*(((farear+(dr*farear))*g.adult)+((0.75*(farear+(dr*farear)))*g.child));
    netjr=1.7*(((farejr+(dr*farejr))*g.adult)+((0.75*(farejr+(dr*farejr)))*g.child));

    // Flight Details of Round Trip

    farer:
    cout<<"\t\t\t\tFlight Details"<<endl;
    cout<<" AIR INDIA"<<endl;
    cout<<"From: "<<cb<<"\tTo: "<<vb<<endl;
    cout<<"Departuring date: "<<g.dd<<"/"<<g.mm<<"/"<<g.yyyy<<endl;
    cout<<"Returning date: "<<g.DD<<"/"<<g.MM<<"/"<<g.YYYY<<endl;
    cout<<"Time of Departure: 10:00 am"<<endl;
    cout<<"Time of Return: 10:00 am"<<endl;
    cout<<"Class: "<<clr<<endl;
    cout<<"Adult(s): "<<g.adult<<endl;
    cout<<"Children: "<<g.child<<endl;
    cout<<"NET FARE: Rs."<<netar<<"/-"<<endl;
    int dotr;
    for (dotr=0 ; dotr<80;dotr++)
      cout<<".";
    cout<<endl<<" JET AIRWAYS"<<endl;
    cout<<"From: "<<cb<<"\tTo: "<<vb<<endl;
    cout<<"Departuring date: "<<g.dd<<"/"<<g.mm<<"/"<<g.yyyy<<endl;
    cout<<"Returning date: "<<g.DD<<"/"<<g.MM<<"/"<<g.YYYY<<endl;
    cout<<"Time of Departure: 10:00 am"<<endl;
    cout<<"Time of Return: 10:00 am"<<endl;
    cout<<"Class: "<<clr<<endl;
    cout<<"Adult(s): "<<g.adult<<endl;
    cout<<"Children: "<<g.child<<endl;
    cout<<"NET FARE: RS."<<netjr<<"/-"<<endl;
    for (dotr=0 ; dotr<80;dotr++)
      cout<<".";
    cout<<"ENTER 1 IF AIR INDIA & 2 IF JET AIRWAYS: ";
    cin>>choicer;
    if(choicer<1 || choicer>2)
    {
      cout<<"\a ERROR: TOO MANY PARAMETERS!!!!!!";
      getch();
      clrscr();
      goto farer;
    }
    switch (choicer)
    {
      case 1:

      // AIR INDIA Ticket For Round Trip

      netr=netar;
      clrscr();
      cout<<endl;
      for (dotr=0 ; dotr<80;dotr++)
	cout<<"~";
      cout<<"\t\t\t\t  AIR INDIA"<<endl<<endl;
      cout<<" From "<<cb<<" to "<<vb<<endl;
      cout<<" < "<<g.dd<<"/"<<g.mm<<"/"<<g.yyyy;
      cout<<" >  < AI-109 >";
      cout<<"  < "<<clr;
      cout<<" >  <  Departs "<<cb<<" at 10:00 am >"<<endl;
      cout<<" From "<<vb<<" to "<<cb<<endl;
      cout<<" < "<<g.DD<<"/"<<g.MM<<"/"<<g.YYYY;
      cout<<" >  < AI-110 >";
      cout<<"  < "<<clr;
      cout<<" >  <  Departs "<<vb<<" at 10:00 am >"<<endl<<endl;
      cout<<" PASSENGER INFORMATION:"<<endl;
      cout<<" "<<g.adult + g.child<<" Passenger(s)"<<endl;
      cout<<" ADULT:"<<endl;
      for(i=0;i<g.adult;i++)
	cout<<" "<<name[i].ad<<" ;";
      cout<<endl<<endl<<" CHILDREN:"<<endl;
      for(i=0;i<g.child;i++)
	cout<<" "<<nme[i].ch<<" ;";
      cout<<"\n\n Net Amount: Rs."<<netr<<"/-"<<endl<<endl;
      for (dotr=0 ; dotr<80;dotr++)
	cout<<"~";
      cout<<"  Here is your TICKET. \n";
      cout<<"  Get it`s Print Out & make the cash payment at the Booking Counter at the \n  airport.";
      getch();
      clrscr();
      cout<<"DO YOU WANT TO CONTINUE(y/n):";
      cin>>ext;
      if(ext=='y'||ext=='Y')
	goto main;
      else if(ext=='n'||ext=='N')
	cout<<"THANKING YOU...............";
      getch();
      exit(1);
      getch();
      break;

      case 2:

      // JET AIRWAYS Ticket For Round Trip

      netr=netjr;
      clrscr();
      cout<<endl;
      for (dotr=0 ; dotr<80;dotr++)
	cout<<"~";
      cout<<"\t\t\t\t  JET AIRWAYS"<<endl<<endl;
      cout<<" From "<<cb<<" to "<<vb<<endl;
      cout<<" < "<<g.dd<<"/"<<g.mm<<"/"<<g.yyyy;
      cout<<" >  < JA-109 >";
      cout<<"  < "<<clr;
      cout<<" >  <  Departs "<<cb<<" at 10:00 am >"<<endl;
      cout<<" From "<<vb<<" to "<<cb<<endl;
      cout<<" < "<<g.DD<<"/"<<g.MM<<"/"<<g.YYYY;
      cout<<" >  < JA-110 >";
      cout<<"  < "<<clr;
      cout<<" >  <  Departs "<<vb<<" at 10:00 am >"<<endl<<endl;
      cout<<" PASSENGER INFORMATION:"<<endl;
      cout<<" "<<g.adult + g.child<<" Passenger(s)"<<endl;
      cout<<" ADULT:"<<endl;
      for(i=0;i<g.adult;i++)
	cout<<" "<<name[i].ad<<" ;";
      cout<<endl<<endl<<" CHILDREN:"<<endl;
      for(i=0;i<g.child;i++)
	cout<<" "<<nme[i].ch<<" ;";
      cout<<"\n\n Net Amount: Rs."<<netr<<"/-"<<endl<<endl;
      for (dotr=0 ; dotr<80;dotr++)
	cout<<"~";
      cout<<"  Here is your TICKET. \n";
      cout<<"  Get it`s Print Out & make the cash payment at the Booking Counter at the \n  airport.";
      getch();
      clrscr();
      cout<<"DO YOU WANT TO CONTINUE(y/n):";
      cin>>ext;
      if(ext=='y'||ext=='Y')
	goto main;
      else if(ext=='n'||ext=='N')
	cout<<"THANKING YOU...............";
      getch();
      exit(1);
      getch();
      break;
    }
    break;

    case 3:

    // 3. Cargo

    cargo:
    clrscr();
    cargo h;
    cout<<"\t\t\t\tCARGO"<<endl<<endl;
    cout<<"Codes\t\t   City";
    cout<<endl<<"1\t\t   Bhopal";
    cout<<endl<<"2\t\t   Chennai";
    cout<<endl<<"3\t\t   Delhi";
    cout<<endl<<"4\t\t   Kolkata";
    cout<<endl<<"5\t\t   Mumbai"<<endl<<endl;
    cout<<"From (enter nos. from above codes):";
    cin>>h.from;
    if(h.from<=0 || h.from>=6)
    {
      cout<<"\a ERROR: TOO MANY PARAMETERS!!!!!!!!!";
      getch();
      goto cargo;
    }
    cout<<"To (enter nos. from above code):";
    cin>>h.to;
    if(h.to<=0 || h.to>=6)
    {
      cout<<"\a ERROR: TOO MANY PARAMETERS!!!!!!!!!";
      getch();
      goto cargo;
    }
    if(h.from==h.to)
    {
      cout<<"\a ERROR: TO & FROM CANNOT BE SAME";
      getch();
      goto cargo;
    }
    cout<<"Departuring date (dd mm yyyy):";
    cin>>h.dd>>h.mm>>h.yyyy;
    cout<<"Weight of Parcel (in kgs): ";
    cin>>h.par;
    cout<<"Rate : Rs. 100/- per kg"<<endl<<endl;
    cout<<"Press ENTER";
    getch();
    clrscr();

    // Calculating The Data For Cargo

    char cc[20],vc[20];
    switch (h.from)
    {
      case 1:
      strcpy(cc,"BHOPAL");
      break;

      case 2:
      strcpy(cc,"CHENNAI");
      break;

      case 3:
      strcpy(cc,"DELHI");
      break;

      case 4:
      strcpy(cc,"KOLKATA");
      break;

      case 5:
      strcpy(cc,"MUMBAI");
      break;
    }
    switch (h.to)
    {
      case 1:
      strcpy(vc,"BHOPAL");
      break;
      case 2:
      strcpy(vc,"CHENNAI");
      break;
      case 3:
      strcpy(vc,"DELHI");
      break;
      case 4:
      strcpy(vc,"KOLKATA");
      break;
      case 5:
      strcpy(vc,"MUMBAI");
      break;
    }

    // Receipt of Cargo

    int dotc;
    float na;
    na= h.par * 100;
    cout<<endl;
    for (dotc=0 ; dotc<80;dotc++)
      cout<<"~";
    cout<<"\t\t\t\t  RECEIPT"<<endl<<endl;
    cout<<" From "<<cc<<" to "<<vc<<endl;
    cout<<" Departuring date: "<<h.dd<<"/"<<h.mm<<"/"<<h.yyyy<<endl;
    cout<<" Time of Departure: 11:00 am"<<endl;
    cout<<" Weight of Parcel (in kgs): "<<h.par;
    cout<<"\n\n Net Amount: Rs."<<na<<"/-"<<endl<<endl;
    for (dotc=0 ; dotc<80;dotc++)
      cout<<"~";
    cout<<"  Here is your RECEIPT. \n";
    cout<<"  Get it`s Print Out & make the cash payment at the Parcel Counter at the \n  airport.";
    getch();
    clrscr();
    cout<<"DO YOU WANT TO CONTINUE(y/n):";
    cin>>ext;
    if(ext=='y'||ext=='Y')
      goto main;
    else if(ext=='n'||ext=='N')
      cout<<"THANKING YOU...............";
    getch();
    exit(1);
    getch();
    break;

    case 4:
    cout<<"THANKING YOU.................";
    getch();
    exit(1);
    break;
  }
}