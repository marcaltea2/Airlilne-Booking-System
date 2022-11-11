#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<conio.h>
#include<time.h>
#include<windows.h>
#define MAX 100

COORD coord={0,0};

void gotoxy(int x, int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

struct passenger
{
    char firstname[50],middlename[50],lastname[50],gender[10],nationality[50];
    char userid[50],password[50];
    int age;
};
struct passenger p[MAX];

char pnr[]={"XXXXXXXXXX"};
char flightdate[]={"XXXXXXXXXX"};
char flighttime[]={"XXXXXXXXXX"};
char departure[]={"XXXXXXXXXX"};
char arrival[]={"XXXXXXXXXX"};
char cabinclass[]={"XXXXXXXXXX"};
int n,price,last,seat;
int p1;
int i;
int j;
int s[10]={};
void mainmenu();
void admin();
void user();
void aboutus();
void adminmenu();
void usermenu();
void searchflight();
void bookinghistory();
void account();
void bookflight();
void ticket();
void ecophilippines();
void ecosingapore();
void ecokorea();
void busiphilippines();
void busisingapore();
void busikorea();
void economyflights();
void businessflights();
void delay();
void logo();
void userlogin();
void userregister();
void userdata();
void seatreserve10();
void seatreserve15();
void insertcard();

int main()
{
    logo();
    mainmenu();
}
void mainmenu()
{
    int choice;
    while(1)
    {
        system("cls");
        gotoxy(0,3);
        printf("=================================================================================\n");
        gotoxy(20,5);
        printf("[1] Admin \n");
        gotoxy(50,5);
        printf("[2] User \n");
        gotoxy(20,7);
        printf("[3] About us \n");
        gotoxy(50,7);
        printf("[4] Exit \n");
        gotoxy(0,9);
        printf("=================================================================================\n");
        gotoxy(20,11);
        printf("Enter Your choice: ");


        switch(choice=(char) getch() - '0')
        {
            case 1: system("cls"); admin(); break;
            case 2: system("cls"); user(); break;
            case 3: system("cls"); aboutus(); break;
            case 4: exit(0);
            default: printf("Invalid Choice."); getch();
        }
    }
}
void admin()//not available
{
    printf("Not available.");
    getch();
}
void user()
{
    int choice;
    while(1)
    {
        system("cls");
        gotoxy(0,3);
        printf("=================================================================================\n");
        gotoxy(20,5);
        printf("[1] Log in \n");
        gotoxy(20,7);
        printf("[2] Sign Up \n");
        gotoxy(20,9);
        printf("[3] Back \n");
        gotoxy(0,11);
        printf("=================================================================================\n");
        gotoxy(20,13);
        printf("Enter Your Choice: ");

        switch(choice=(char) getch() - '0')
        {
            case 1: system("cls"); userlogin(); break;
            case 2: system("cls"); userregister(); break;
            case 3: system("cls"); mainmenu();
            default: printf("Invalid Choice."); getch();
        }
    }
    usermenu();
}
void userlogin()//user log in
{
    FILE *fp;
    char uid[50],pass[50];
    int checku,checkp;
    fp=fopen("user_register.txt","r");
    gotoxy(0,3);
    printf("=================================================================================\n");
    gotoxy(0,9);
    printf("=================================================================================\n");
    gotoxy(20,5);
    printf("Enter your User ID: ");
    scanf("%s",&uid);
    gotoxy(20,7);
    printf("Enter your Password: ");
    scanf("%s",&pass);
     for(int i=0;i<=last;i++)
    {
        fscanf(fp,"%s %s %s %s %s %d %s %s \n",&p[i].firstname,&p[i].middlename,&p[i].lastname,&p[i].gender,p[i].nationality,&p[i].age,&p[i].userid,&p[i].password);
        checku=strcmp(uid,p[i].userid);
        checkp=strcmp(pass,p[i].password);
        if(checku==0&&checkp==0)
        {
            usermenu();
        }
        else if(checku==0&&checkp!=0)
        {
            gotoxy(20,11);
            printf("Incorrect Password/User ID.");
            getch();
            user();
        }
        else if(checku!=0)
        {
            gotoxy(20,11);
            printf("User doesn't exist.");
            getch();
            user();
        }

    }
    fclose(fp);

}
void userregister()//user sign up
{
    gotoxy(0,3);
    printf("=================================================================================\n");
    gotoxy(0,21);
    printf("=================================================================================\n");
    last++;
    gotoxy(0,5);
    printf("Enter your First name: ");
    scanf("%s",&p[last].firstname);
    gotoxy(0,7);
    printf("Enter your Middle name: ");
    scanf("%s",&p[last].middlename);
    gotoxy(0,9);
    printf("Enter your Last name: ");
    scanf("%s",&p[last].lastname);
    gotoxy(0,11);
    printf("Enter your Gender: ");
    scanf("%s",&p[last].gender);
    gotoxy(0,13);
    printf("Enter your Nationality: ");
    scanf("%s",&p[last].nationality);
    gotoxy(0,15);
    printf("Enter your Age: ");
    scanf("%d",&p[last].age);
    gotoxy(0,17);
    printf("Enter your User ID: ");
    scanf("%s",&p[last].userid);
    gotoxy(0,19);
    printf("Enter your Password: ");
    scanf("%s",&p[last].password);
    userdata();

}
void aboutus()
{
    system("cls");
    printf("Airline reservation system is a web-based booking solution that helps in\nconsolidating data from all airlines through the use of global distribution systemsThe system provides inventory and rates in real time to customers as well as travelagents.Which are application supporting the direct contact with the passenger.\nARS eventually evolved into the computer reservations system. Its goal is to\nsupport bookings through different distribution channels. It stores a database\nof fare tariffs, rules and booking conditions, all considering different zones,\nclasses, and inventory buckets.");
    getch();
}
void adminmenu()//for admin
{

}
void usermenu()//for user
{
    int choice;
    while(1)
    {
        system("cls");
        gotoxy(0,3);
        printf("=================================================================================\n");
        gotoxy(0,11);
        printf("=================================================================================\n");
        gotoxy(20,5);
        printf("[1] Search Flight \n");
        gotoxy(50,5);
        printf("[2] Booking History \n");
        gotoxy(20,7);
        printf("[3] Account \n");
        gotoxy(50,7);
        printf("[4] Book flight \n");
        gotoxy(20,9);
        printf("[5] Ticket \n");
        gotoxy(50,9);
        printf("[6] Logout \n");
        gotoxy(20,13);
        printf("Enter Your Choice: ");

        switch(choice=(char) getch() - '0')
        {
            case 1: system("cls"); searchflight(); break;
            case 2: system("cls"); bookinghistory(); break;
            case 3: system("cls"); account(); break;
            case 4: system("cls"); bookflight(); break;
            case 5: system("cls"); ticket(); break;
            case 6: system("cls"); user(); break;
            default: printf("Invalid Choice."); getch();
        }
    }
}
void searchflight()
{
    int choice;
    while(1)
    {
        system("cls");
        printf("Cabin Class \n");
        gotoxy(0,3);
        printf("=================================================================================\n");
        gotoxy(0,11);
        printf("=================================================================================\n");
        gotoxy(20,5);
        printf("[1] Economy Class \n");
        gotoxy(20,7);
        printf("[2] Business Class \n");
        gotoxy(20,9);
        printf("[3] Back \n");
        gotoxy(20,13);
        printf("Enter Your Choice: ");


        switch(choice=(char) getch() - '0')
        {
            case 1: system("cls"); economyflights(); break;
            case 2: system("cls"); businessflights(); break;
            case 4: system("cls"); usermenu(); break;
            default: printf("Invalid Choice."); break;
        }
    }
}
void economyflights()//economy flights
{
    int choice;
    while(1)
    {
        system("cls");
        printf("Cabin Class (Economy)\n");
        printf("Departure \n");
        gotoxy(0,3);
        printf("=================================================================================\n");
        gotoxy(0,13);
        printf("=================================================================================\n");
        gotoxy(20,5);
        printf("[1] Philippines \n");
        gotoxy(20,7);
        printf("[2] Singapore \n");
        gotoxy(20,9);
        printf("[3] Korea \n");
        gotoxy(20,11);
        printf("[4] Back \n");
        gotoxy(20,15);
        printf("Enter Your Choice: ");

        switch(choice=(char) getch() - '0')
        {
            case 1: system("cls"); ecophilippines(); break;
            case 2: system("cls"); ecosingapore(); break;
            case 3: system("cls"); ecokorea(); break;
            case 4: system("cls"); searchflight(); break;
            default: printf("Invalid Choice."); getch();
        }
    }
}
void businessflights()//business flights
{
    int choice;
    while(1)
    {
        system("cls");
        printf("Cabin Class (Business)\n");
        printf("Departure \n");
        gotoxy(0,3);
        printf("=================================================================================\n");
        gotoxy(0,13);
        printf("=================================================================================\n");
        gotoxy(20,5);
        printf("[1] Philippines \n");
        gotoxy(20,7);
        printf("[2] Singapore \n");
        gotoxy(20,9);
        printf("[3] Korea \n");
        gotoxy(20,11);
        printf("[4] Back \n");
        gotoxy(20,15);
        printf("Enter Your Choice: ");

         switch(choice=(char) getch() - '0')
        {
            case 1: system("cls"); busiphilippines(); break;
            case 2: system("cls"); busisingapore(); break;
            case 3: system("cls"); busikorea(); break;
            case 4: system("cls"); searchflight(); break;
            default: printf("Invalid Choice."); getch();
        }


    }
}
void bookinghistory()//booking history not available
{
    printf("Not available.");
    getch();
}
void account()// passenger's personal information
{
    printf("Passenger Name Record \n");
    gotoxy(0,3);
    printf("=================================================================================\n");
    gotoxy(0,13);
    printf("=================================================================================\n");
    gotoxy(20,5);
    printf("Name: %s %s %s\n",p[last].firstname,p[last].middlename,p[last].lastname);
    gotoxy(20,7);
    printf("Gender: %s \n",p[last].gender);
    gotoxy(20,9);
    printf("Age: %d \n",p[last].age);
    gotoxy(20,11);
    printf("Nationality: %s \n",p[last].nationality);
    getch();
}
void bookflight()//payment process
{
    char PNR[10];
    gotoxy(0,3);
    printf("=================================================================================\n");
    gotoxy(0,9);
    printf("=================================================================================\n");
    gotoxy(20,5);
    printf("Enter your PNR Number:");
    scanf("%s",&PNR);
    if(strcmp(pnr,PNR)==0)
    {
        ticket();
    }
    else
    {
        gotoxy(20,11);
        printf("Wrong PNR");
        getch();
    }
}
void ticket()//ticket booked
{
    if(price==0)
    {
        printf("Empty");
    }
    else
    {

        system("cls");
        printf("Boarding Pass \n");
        printf("%s \n",cabinclass);
        gotoxy(0,3);
        printf("=================================================================================\n");
        gotoxy(0,15);
        printf("=================================================================================\n");
        gotoxy(10,5);
        printf("PNR number: %s \n",pnr);
        gotoxy(40,5);
        printf("from: %s \n",departure);
        gotoxy(60,5);
        printf("To: %s \n",arrival);
        gotoxy(40,7);
        printf("Date: %s \n",flightdate);
        gotoxy(60,7);
        printf("time: %s \n",flighttime);
        gotoxy(10,7);
        printf("Name: %s, %s %s \n",p[last].lastname,p[last].firstname,p[last].middlename);
        gotoxy(10,9);
        printf("Gender: %s \n",p[last].gender);
        gotoxy(40,9);
        printf("Age: %d \n",p[last].age);
        gotoxy(10,11);
        printf("Nationality: %s \n",p[last].nationality);
        gotoxy(10,13);
        printf("Seat no : %i\n",s[j]);
        gotoxy(40,11);
        printf("Number of passengers: %d \n",n);
        gotoxy(40,13);
        printf("Total price: %d \n",price);
    }
        getch();
}
void ecophilippines()//start economic class flights
{
    int choice;

        system("cls");
        char cabinclass1[]="Economy Class";
        strcpy(cabinclass,cabinclass1);
        printf("Cabin Class (Economy)\n");
        gotoxy(0,3);
        printf("=================================================================================\n");
        gotoxy(0,13);
        printf("=================================================================================\n");
        gotoxy(0,7);
        printf("=================================================================================\n");
        gotoxy(0,5);
        printf("Flights \t\t\t Price \t Available Seats \t Date \t   time \n");
        gotoxy(0,9);
        printf("1. Philippines to Singapore \t 2,000 \t   15 seast\t\t01/25/21  10:00am\n");
        gotoxy(0,11);
        printf("2. Philippines to Korea     \t 2,500 \t   10 seats\t\t01/26/21  12:00pm\n");
        gotoxy(0,15);
        printf("Enter Your Choice: ");
        scanf("%d",&choice);
        if(choice==1)
        {
            char pnr1[]="EMNLSPR";
            strcpy(pnr,pnr1);
            char departure1[]="Philippines";
            strcpy(departure,departure1);
            char arrival1[]="Singapore";
            strcpy(arrival,arrival1);
            char flightdate1[]="01/25/21";
            strcpy(flightdate,flightdate1);
            char flighttime1[]="10:00pm";
            strcpy(flighttime,flighttime1);
            printf("Number of Passengers: ");
            scanf("%d",&n);
            price =(2000*n);
            seatreserve15();
            printf("Date: %s \n",flightdate);
            printf("time: %s \n",flighttime);
            printf("Seat no : %i\n",s[j]);
            printf("Your PNR Number is %s \n",pnr);
            printf("Total price: %d",price);
            getch();
        }
        else if(choice==2)
        {
            char pnr1[]="EMNLKRA";
            strcpy(pnr,pnr1);
            char departure1[]="Philippines";
            strcpy(departure,departure1);
            char arrival1[]="Korea";
            strcpy(arrival,arrival1);
            char flightdate1[]="01/26/21";
            strcpy(flightdate,flightdate1);
            char flighttime1[]="12:00am";
            strcpy(flighttime,flighttime1);
            printf("Number of Passengers: ");
            scanf("%d",&n);
            price=(2500*n);
            seatreserve10();
            printf("Date: %s \n",flightdate);
            printf("time: %s \n",flighttime);
            printf("Seat no : %i\n",s[j]);
            printf("Your PNR Number is %s \n",pnr);
            printf("Total price: %d",price);
            getch();
        }
        else
        {
            printf("Invalid Choice.");
            getch();
            ecophilippines();
        }
        usermenu();
}
void ecosingapore()
{
    int choice;
        system("cls");
        char cabinclass1[]="Economy Class";
        strcpy(cabinclass,cabinclass1);
        printf("Cabin Class(Economy)\n");
        gotoxy(0,3);
        printf("=================================================================================\n");
        gotoxy(0,13);
        printf("=================================================================================\n");
        gotoxy(0,7);
        printf("=================================================================================\n");
        gotoxy(0,5);
        printf("Flights \t\t\t Price \t Available Seats \t Date \t   time \n");
        gotoxy(0,9);
        printf("1. Singapore to Philippines \t 2,000     10 seats\t\t01/25/21  12:00am\n");
        gotoxy(0,11);
        printf("2. Singapore to Korea       \t 2,500     10 seats\t\t01/27/21  5:00am\n");
        gotoxy(0,15);
        printf("Enter Your Choice: ");
        scanf("%d",&choice);

        if(choice==1)
        {
            char pnr1[]="ESPRMNL";
            strcpy(pnr,pnr1);
            char departure1[]="Singapore";
            strcpy(departure,departure1);
            char arrival1[]="Philippines";
            strcpy(arrival,arrival1);
            char flightdate1[]="01/25/21";
            strcpy(flightdate,flightdate1);
            char flighttime1[]="12:00am";
            printf("Number of Passengers: ");
            scanf("%d",&n);
            price=(2000*n);
            seatreserve10();
            printf("Date: %s \n",flightdate);
            printf("time: %s \n",flighttime);
            printf("Seat no : %i\n",s[j]);
            printf("Your PNR Number is %s \n",pnr);
            printf("Total price: %d \n",price);
            getch();
        }
        else if(choice==2)
        {
            char pnr1[]="ESPRKRA";
            strcpy(pnr,pnr1);
            char departure1[]="Singapore";
            strcpy(departure,departure1);
            char arrival1[]="Korea";
            strcpy(arrival,arrival1);
            char flightdate1[]="01/27/21";
            strcpy(flightdate,flightdate1);
            char flighttime1[]="5:00am";
            printf("Number of Passengers: ");
            scanf("%d",&n);
            price=(2500*n);
            seatreserve10();
            printf("Date: %s \n",flightdate);
            printf("time: %s \n",flighttime);
            printf("Seat no : %i\n",s[j]);
            printf("Your PNR Number is %s \n",pnr);
            printf("Total price: %d",price);
            getch();
        }
        else
        {
            printf("Invalid Choice.");
            getch();
            ecosingapore();
        }
        usermenu();

}
void ecokorea()//end of economic class flights
{
    int choice;

        system("cls");
        char cabinclass1[]="Economy Class";
        strcpy(cabinclass,cabinclass1);
        printf("Cabin Class(Economy)\n");
        gotoxy(0,3);
        printf("=================================================================================\n");
        gotoxy(0,13);
        printf("=================================================================================\n");
        gotoxy(0,7);
        printf("=================================================================================\n");
        gotoxy(0,5);
        printf("Flights \t\t\t Price \t Available Seats \t Date \t   time \n");
        gotoxy(0,9);
        printf("1. Korea to Philippines \t 2,500     10seats\t\t01/25/21 10:00am \n");
        gotoxy(0,11);
        printf("2. Korea to Singapore   \t 2,500     10seats\t\t01/26/21 5:00pm \n");
        gotoxy(0,15);
        printf("Enter Your Choice: ");
        scanf("%d",&choice);


        if(choice==1)
        {
            char pnr1[]="EKRAMNL";
            strcpy(pnr,pnr1);
            char departure1[]="Korea";
            strcpy(departure,departure1);
            char arrival1[]="Philippines";
            strcpy(arrival,arrival1);
            char flightdate1[]="01/25/21";
            strcpy(flightdate,flightdate1);
            char flighttime1[]="10:00am";
            printf("Number of Passengers: ");
            scanf("%d",&n);
            price=(2500*n);
            seatreserve10();
            printf("Date: %s \n",flightdate);
            printf("time: %s \n",flighttime);
            printf("Seat no : %i\n",s[j]);
            printf("Your PNR Number is %s \n",pnr);
            printf("Total price: %d \n",price);
            getch();
        }
        else if(choice==2)
        {
            char pnr1[]="EKRASPR";
            strcpy(pnr,pnr1);
            char departure1[]="Korea";
            strcpy(departure,departure1);
            char arrival1[]="Singapore";
            strcpy(arrival,arrival1);
            char flightdate1[]="01/26/21";
            strcpy(flightdate,flightdate1);
            char flighttime1[]="5:00pm";
            printf("Number of Passengers: ");
            scanf("%d",&n);
            price=(2500*n);
            seatreserve10();
            printf("Date: %s \n",flightdate);
            printf("time: %s \n",flighttime);
            printf("Seat no : %i\n",s[j]);
            printf("Your PNR Number is %s \n",pnr);
            printf("Total price: %d \n",price);
            getch();
        }
        else
        {
            printf("Invalid Choice.");
            ecokorea();
            getch();
        }
        usermenu();
}
void busiphilippines()//start of business class flights
{
    int choice;
        system("cls");
        char cabinclass1[]="Business Class";
        strcpy(cabinclass,cabinclass1);
        printf("Cabin Class (Business)\n");
        gotoxy(0,3);
        printf("=================================================================================\n");
        gotoxy(0,13);
        printf("=================================================================================\n");
        gotoxy(0,7);
        printf("=================================================================================\n");
        gotoxy(0,5);
        printf("Flights \t\t\t Price \t Available Seats \t Date \t   time \n");
        gotoxy(0,9);
        printf("1.Philippines to Singapore \t 4,000      15 seats\t\t01/26/21  1:00am\n");
        gotoxy(0,11);
        printf("2.Philippines to Korea     \t 5000       15 seats\t\t01/27/21  12:00pm\n");
        gotoxy(0,15);
        printf("Enter Your Choice: ");
        scanf("%d",&choice);
   ;

        if(choice==1)
        {
            char pnr1[]="BMNLSPR";
            strcpy(pnr,pnr1);
            char departure1[]="Philippines";
            strcpy(departure,departure1);
            char arrival1[]="Singapore";
            strcpy(arrival,arrival1);
            char flightdate1[]="01/26/21";
            strcpy(flightdate,flightdate1);
            char flighttime1[]="1:00am";
            printf("Number of Passengers: ");
            scanf("%d",&n);
            price=(2500*n);
            seatreserve15();
            printf("Date: %s \n",flightdate);
            printf("time: %s \n",flighttime);
            printf("Seat no : %i\n",s[j]);
            printf("Your PNR Number is %s \n",pnr);
            printf("Total price: %d \n",price);
            getch();
        }
        else if(choice==2)
        {
            char pnr1[]="BMNLKRA";
            strcpy(pnr,pnr1);
            char departure1[]="Philippines";
            strcpy(departure,departure1);
            char arrival1[]="Korea";
            strcpy(arrival,arrival1);
            char flightdate1[]="01/27/21";
            strcpy(flightdate,flightdate1);
            char flighttime1[]="12:00pm";
            printf("Number of Passengers: ");
            scanf("%d",&n);
            price=(5000*n);
            seatreserve15();
            printf("Date: %s \n",flightdate);
            printf("time: %s \n",flighttime);
            printf("Seat no : %i\n",s[j]);
            printf("Your PNR Number is %s \n",pnr);
            printf("Total price: %d \n",price);
            getch();
        }
        else
        {
            printf("Invalid Choice.");
            busiphilippines();
            getch();
        }
        usermenu();
}
void busisingapore()
{
    int choice;
        system("cls");
        char cabinclass1[]="Business Class";
        strcpy(cabinclass,cabinclass1);
        printf("Cabin Class(Business)\n");
        gotoxy(0,3);
        printf("=================================================================================\n");
        gotoxy(0,13);
        printf("=================================================================================\n");
        gotoxy(0,7);
        printf("=================================================================================\n");
        printf("Flights \t\t\t Price \t Available Seats \t Date \t   time \n");
        gotoxy(0,9);
        printf("1. Singapore to Philippines \t 4,000      10 seats\t\t01/27/21  12:00am\n");
        gotoxy(0,11);
        printf("2. Singapore to Korea       \t 5000       10 seats\t\t01/28/21  6:00am \n");
        gotoxy(0,15);
        printf("Enter Your Choice: ");
        scanf("%d",&choice);

        if(choice==1)
        {
            char pnr1[]="BSPRMNL";
            strcpy(pnr,pnr1);
            char departure1[]="Singapore";
            strcpy(departure,departure1);
            char arrival1[]="Philippines";
            strcpy(arrival,arrival1);
            char flightdate1[]="01/27/21";
            strcpy(flightdate,flightdate1);
            char flighttime1[]="12:00am";
            printf("Number of Passengers: ");
            scanf("%d",&n);
            price=(4000*n);
            seatreserve10();
            printf("Date: %s \n",flightdate);
            printf("time: %s \n",flighttime);
            printf("Seat no : %i\n",s[j]);
            printf("Your PNR Number is %s \n",pnr);
            printf("Total price: %d \n",price);
            getch();
        }
        else if(choice==2)
        {
            char pnr1[]="BSPRKRA";
            strcpy(pnr,pnr1);
            char departure1[]="Singapore";
            strcpy(departure,departure1);
            char arrival1[]="Korea";
            strcpy(arrival,arrival1);
            char flightdate1[]="01/26/21";
            strcpy(flightdate,flightdate1);
            char flighttime1[]="6:00am";
            printf("Number of Passengers: ");
            scanf("%d",&n);
            price=(5000*n);
            seatreserve10();
            printf("Date: %s \n",flightdate);
            printf("time: %s \n",flighttime);
            printf("Seat no : %i\n",s[j]);
            printf("Your PNR Number is %s \n",pnr);
            printf("Total price: %d",price);
            getch();
        }
        else
        {
            printf("Invalid Choice.");
            busisingapore();
            getch();
        }
        usermenu();
}
void busikorea()//end of business class flights
{
    int choice;
        system("cls");
        char cabinclass1[]="Business Class";
        strcpy(cabinclass,cabinclass1);
        printf("Cabin Class(Business)\n");
        gotoxy(0,3);
        printf("=================================================================================\n");
        gotoxy(0,13);
        printf("=================================================================================\n");
        gotoxy(0,7);
        printf("=================================================================================\n");
        printf("Flights \t\t\t Price \t Available Seats \t Date \t   time \n");
        gotoxy(0,9);
        printf("1. Korea to Philippines \t 4,000     15 seats\t\t01/27/21  10:00am \n");
        gotoxy(0,11);
        printf("2. Korea to Singapore   \t 5000      15 seats\t\t01/28/21  11:00pm \n");
        gotoxy(0,15);
        printf("Enter Your Choice: ");
        scanf("d",&choice);

        if(choice==1)
        {
            char pnr1[]="BKRAMNL";
            strcpy(pnr,pnr1);
            char departure1[]="Korea";
            strcpy(departure,departure1);
            char arrival1[]="Philippines";
            strcpy(arrival,arrival1);
            char flightdate1[]="01/27/21";
            strcpy(flightdate,flightdate1);
            char flighttime1[]="10:00am";
            printf("Number of Passengers: ");
            scanf("%d",&n);
            price=(4000*n);
            seatreserve15();
            printf("Date: %s \n",flightdate);
            printf("time: %s \n",flighttime);
            printf("Seat no : %i\n",s[j]);
            printf("Your PNR Number is %s \n",pnr);
            printf("Total price: %d",price);
            getch();
        }
        else if(choice==2)
        {
            char pnr1[]="BKRASPR";
            strcpy(pnr,pnr1);
            char departure1[]="Korea";
            strcpy(departure,departure1);
            char arrival1[]="Singapore";
            strcpy(arrival,arrival1);
            char flightdate1[]="01/28/21";
            strcpy(flightdate,flightdate1);
            char flighttime1[]="11:00pm";
            printf("Number of Passengers: ");
            scanf("%d",&n);
            price=(5000*n);
            seatreserve15();
            printf("Date: %s \n",flightdate);
            printf("time: %s \n",flighttime);
            printf("Seat no : %i\n",s[j]);
            printf("Your PNR Number is %s \n",pnr);
            printf("Total price: %d",price);
            getch();
        }
        else
        {
            printf("Invalid Choice.");
            busikorea();
            getch();
        }
        usermenu();
}
void seatreserve10()
{
   for (j=0; j<10; j++)
	{

			printf("Seats available are 1,2,3,4,5,6,7,8,9,10.\n");
			do
			{
                printf("Pick a seat:");
                scanf("%i",&p1);
                s[j]=p1;
                //system("cls");
			    for (i=0; i<j; i++)
			    {
                    if (s[j]==s[i])
                    {
                        printf("\n\nSeat taken.\n\n");
                        break;
                    }
			    }
            }
            while (i!=j);
                if(s[j] <= 10)
                {

                    break;
                }
                else
                printf("Seat is not available");
                 system("cls");
    }
	return 0;

}
void seatreserve15()
{
    for (j=0; j<10; j++)
	{

			printf("Seats available are 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15.\n");
			do
			{
                printf("Pick a seat:");
                scanf("%i",&p1);
                s[j]=p1;
                //system("cls");
			    for (i=0; i<j; i++)
			    {
                    if (s[j]==s[i])
                    {
                        printf("\n\nSeat taken.\n\n");
                        break;
                    }
			    }
            }
            while (i!=j);
                if(s[j] <= 15)
                {

                    break;
                }
                else
                printf("Seat is not available");
                 system("cls");
    }
	return 0;
}
void userdata()
{
    FILE *fp;
    fp=fopen("user_register.txt","a");
    for(int i=1;i<=last;i++)
    fprintf(fp,"%s %s %s %s %s %d %s %s \n",p[i].firstname,p[i].middlename,p[i].lastname,p[i].gender,p[i].nationality,p[i].age,p[i].userid,p[i].password);
    fclose(fp);
}
void insertcard()
{
    FILE *fp;
    printf("Please insert card...\n");
    do
    {
    fp=fopen("F:\pin.txt","r");
    } while (fp==NULL);
    fclose(fp);
}
void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
     while (goal > clock());
}
void logo()
{
    delay(100);
 printf("\n*******                                                      ");
 printf("\n *      *                                                    ");
 printf("\n  *       *                                                  ");
 printf("\n***        ******************************************        ");
 printf("\n *                                                  *****    ");
 printf("\n  *                                                 ******   ");
 printf("\n   *                   PHILIPPINE AIRWAYS                 *  ");
 printf("\n    *                                                     *  ");
 printf("\n     *****      *************           *****************    ");
 printf("\n        *      *           *          *                      ");
 printf("\n       *     *            *         *                        ");
 printf("\n      *******            *        *                          ");
 printf("\n                        *       *                            ");
 printf("\n                       *      *                              ");
 printf("\n                      *******                                ");
 delay(100);
 system("cls");
 printf("\n       *******                                                      ");
 printf("\n        *      *                                                    ");
 printf("\n         *       *                                                  ");
 printf("\n       ***        ******************************************        ");
 printf("\n        *                                                  *****    ");
 printf("\n         *                                                 ******   ");
 printf("\n          *                   PHILIPPINE AIRWAYS                 *  ");
 printf("\n           *                                                     *  ");
 printf("\n            *****      *************           *****************    ");
 printf("\n               *      *           *          *                      ");
 printf("\n              *     *            *         *                        ");
 printf("\n             *******            *        *                          ");
 printf("\n                               *       *                            ");
 printf("\n                              *      *                              ");
 printf("\n                             *******                                ");
 delay(100);
 system("cls");
 printf("\n             *******                                                      ");
 printf("\n              *      *                                                    ");
 printf("\n               *       *                                                  ");
 printf("\n             ***        ******************************************        ");
 printf("\n              *                                                  *****    ");
 printf("\n               *                                                 ******   ");
 printf("\n                *                   PHILIPPINE AIRWAYS                 *  ");
 printf("\n                 *                                                     *  ");
 printf("\n                  *****      *************           *****************    ");
 printf("\n                     *      *           *          *                      ");
 printf("\n                    *     *            *         *                        ");
 printf("\n                   *******            *        *                          ");
 printf("\n                                     *       *                            ");
 printf("\n                                    *      *                              ");
 printf("\n                                   *******                                ");
 delay(100);


 getch();
 system("cls");
 printf("Loading...");
 delay(1000);
}
