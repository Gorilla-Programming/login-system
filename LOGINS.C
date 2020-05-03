#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
struct entry
{
 char name[BUFSIZ],dob[BUFSIZ],age[BUFSIZ],uniname[BUFSIZ],mob[BUFSIZ],email[BUFSIZ];
}s;
void frame();
void frame()
{
 int i;
 clrscr();
 textcolor(YELLOW);
 textbackground(BLACK);
 for(i=3;i<=24;i++)
 {
  gotoxy(77,i);
  cprintf("*");
  gotoxy(2,i);
  cprintf("*");
 }
 for(i=4;i<=76;i+=2)
 {
  gotoxy(i,24);
  cprintf("* ");
  gotoxy(i,2);
  cprintf("* ");
 }
}


void main()
{
 FILE *f1,*f2,*f3;
 int ch,chk=0,i=0;
 char ent,name[12],path[16],pass[12],check_pass[12],check_name[12];
 frame();
 gotoxy(26,11);
 cprintf("1. Sign Up");
 gotoxy(26,13);
 cprintf("2. Log In : :");
 gotoxy(37,13);
 scanf("%d",&ch);
 switch(ch)
 {
   case 1:
	A :
	frame();
	f1=fopen("ids.txt","a+");
	f2=fopen("passwords.txt","a+");
	rewind(f1);
	gotoxy(26,11);
	cprintf("Enter Username :: ");
	fflush(stdin);
	gets(check_name);
	while(fscanf(f1,"%s",&name)!=EOF)
	{
	 if(strcmp(name,check_name)==0)
	 {
	  frame();
	  gotoxy(26,11);
	  cprintf("Username already exist");
	  getch();
	  fclose(f1);
	  goto A;
	 }
	}
	gotoxy(26,13);
	cprintf("Enter Password :: ");
	while(1)
	{
	 ent=getch();
	 if(ent==13)
	 {
	  pass[i]='\0';
	  break;
	 }
	 else if(ent==8)
	 {
	  i--;
	  printf("\b \b");
	  continue;
	 }
	 else
	 {
	  pass[i] = ent;
	  i++;
	  printf("*");
	 }
	}
	strcpy(name,check_name);
	fprintf(f1,"%s \n",&name);
	fprintf(f2,"%s \n",&pass);
	strcpy(path,name);
	strcat(path,".txt");
	f3=fopen(path,"w");
	frame();
	gotoxy(15,8);
	cprintf("Enter Your Name :: ");
	fflush(stdin);
	gets(s.name);
	gotoxy(15,9);
	cprintf("Enter Your DOB (dd/mm/yyyy) :: ");
	fflush(stdin);
	gets(s.dob);
	gotoxy(15,10);
	cprintf("Enter Your University Name :: ");
	fflush(stdin);
	gets(s.uniname);
	gotoxy(15,11);
	cprintf("Enter Your Age :: ");
	fflush(stdin);
	gets(s.age);
	gotoxy(15,12);
	cprintf("Enter Your Mobile Number :: ");
	fflush(stdin);
	gets(s.mob);
	gotoxy(15,13);
	cprintf("Enter Your Email :: ");
	fflush(stdin);
	gets(s.email);
	fprintf(f3,"%s\n%s\n%s\n%s\n%s\n%s\n",s.name,s.dob,s.uniname,s.age,s.mob,s.email);
	fclose(f3);
	frame();
	gotoxy(26,12);
	cprintf("Registration Successful....");
	rewind(f1);
	rewind(f2);
	break;
   case 2:
	B:
	frame();
	f1=fopen("ids.txt","a+");
	f2=fopen("passwords.txt","a+");
	rewind(f1);
	rewind(f2);
	gotoxy(26,11);
	cprintf("Enter Username :: ");
	fflush(stdin);
	gets(check_name);
	gotoxy(26,13);
	cprintf("Enter Password :: ");
	fflush(stdin);
	while(1)
	{
	 ent=getch();
	 if(ent==13)
	 {
	  check_pass[i]='\0';
	  break;
	 }
	 else if(ent==8)
	 {
	  i--;
	  printf("\b \b");
	  continue;
	 }
	 else
	 {
	  check_pass[i] = ent;
	  i++;
	  printf("*");
	 }
	}
	while(fscanf(f1,"%s",&name)!=EOF)
	{
	 fscanf(f2,"%s",&pass);
	 if(strcmp(name,check_name)==0 && strcmp(pass,check_pass)==0)
	 {
	  chk=1;
	  break;
	 }
	 else
	 continue;
	}
	if(chk==1)
	{
	 frame();
	 gotoxy(23,12);
	 cprintf("Login Successful...Click to Continue ");
	 strcpy(path,name);
	 strcat(path,".txt");
	 f3=fopen(path,"r");
	 frame();
	 fgets(s.name,BUFSIZ,f3);
	 fgets(s.dob,BUFSIZ,f3);
	 fgets(s.uniname,BUFSIZ,f3);
	 fgets(s.age,BUFSIZ,f3);
	 fgets(s.mob,BUFSIZ,f3);
	 fgets(s.email,BUFSIZ,f3);
	 gotoxy(8,6);
	 cprintf("|.................WELCOME BACK TO YOUR PROFILE.................|");
	 cprintf("");
	 gotoxy(25,12);
	 cprintf("Name :: ");
	 puts(s.name);
	 gotoxy(25,13);
	 cprintf("Date Of Birth :: ");
	 puts(s.dob);
	 gotoxy(25,14);
	 cprintf("University Name :: ");
	 puts(s.uniname);
	 gotoxy(25,15);
	 cprintf("Age :: ");
	 puts(s.age);
	 gotoxy(25,16);
	 cprintf("Mobile Number :: ");
	 puts(s.mob);
	 gotoxy(25,17);
	 cprintf("Email :: ");
	 puts(s.email);
	 fclose(f1);
	 fclose(f2);
	 fclose(f3);
	}
	else if(chk==0)
	{
	 frame();
	 gotoxy(24,12);
	 cprintf("Invalid Password or username");
	 fclose(f1);
	 fclose(f2);
	 exit(0);
	}
	else
	{
	 frame();
	 gotoxy(21,12);
	 cprintf("OOPS SOMETHING WENT WRONG...TRY AGAIN LATER");
	}
	gotoxy(1,1);
	break;
 }
 getch();
}