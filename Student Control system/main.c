
// IN the name of allah ,the most beneficent and most merciful

/* this is a control system takes the gpa of students
for 5 years and calculates the graduation GPA.
    << Have a nice time >> */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <math.h>
#define Student struct Stud

void add(FILE * fp); //to add to record
FILE * del(FILE * fp);//to delete from record
void modify(FILE * fp);//to modify a record
void displayList(FILE * fp);//display whole record
void searchRecord(FILE *fp);//find a particular record
void printChar(char ch,int n);//printing a character ch n times
void printHead();//printing head line for each screen

struct Stud
{
    char name[100];//store student name
    char branch[50];//store student department
    int id;//store student id
    float sgpa[10]; //store each input gpa
    float Ggpa; //store the graduation GPA
};


int main()
{
FILE * fp; //pointer to stare to the file
Student s;
int option;
char another;

if((fp=fopen("studentInfo.txt","r+"))==NULL) // r+=reading existing contents and writing new contents to a file
{    // check if the file can be opened ..
    if((fp=fopen("studentInfo.txt","w+"))==NULL) //w+= writing and reading mode
       {
           printf("can't open file");
           return 0;
       }
}

printHead();
printf("\n\n\t\t\t<<< WELCOME to MY SYSTEM >>>");
printf("\n\n\t\tCREATED BY:");
printf("\n\n\t\tMOHAMED REDA .");
printf("\n\n\t\tSTUDENT AT [HTI] .");
printf("\n\n\t\tpress any key to continue....");
getch();

while(1) // infinite while loop
{
    printHead();
    printf("\n\t");
    printChar('-',64);

    printf("\n\n\t\t\t1. ADD Student");
    printf("\n\n\t\t\t2. DELETE Student");
    printf("\n\n\t\t\t3. MODIFY Student");
    printf("\n\n\t\t\t4. DISPLAY Student LIST");
    printf("\n\n\t\t\t5. Search Record");
    printf("\n\n\t\t\t0. EXIT");

    printf("\n\n\t\tEnter Your Option :--> ");
    scanf("%d",&option);

    switch(option)
    {
        case 0: return 1;
                break;
        case 1: add(fp);
                break;
        case 2: fp=del(fp);
                break;
        case 3: modify(fp);
                break;
        case 4: displayList(fp);
                break;
        case 5: searchRecord(fp);
                break;
        default: printf("\n\t\tYou Pressed wrong key");
                  printf("\n\t\tProgram terminated");
                  getch();
                  exit(0); //

    }
}
return 1;

}

//----printing character ch at n times ------
/*
 * name :  printChar
 * inputs : ch and n
 * description : used for print a break line like "* ,& ,_.-,+" for the program shape
 */


void printChar(char ch,int n)
{
    while(n--)
    {
        putchar(ch);
    }
}

//-----Printing Head Line of the program -----
/*
 * name : printHead
 * inputs : no inputs just outputs.
 * description : used for print a line at the head of the program
 */


void printHead()
{
system("cls"); // clear  screen command

printf("\n\n\t");
printChar('*',16);
printf("[STUDENT] [control] [SYSTEM]");
printChar('*',16);
printf("\n");
}


// ==========ADDING NEW RECORD==========================
/*
 * name : add
 * inputs : file pointer
 * description : used for  adding students name , id , grades and departments
 */

void add(FILE * fp)
{
printHead();

char another='y';
Student s;
int i;
float Ggpa; // graduation GPA

fseek(fp,0,SEEK_END);
while(another=='y'||another=='Y')
{

    printf("\n\n\t\tEnter Full Name of Student\t");
    fflush(stdin);
    fgets(s.name,100,stdin); //fgets takes an extra \n character as input
    s.name[strlen(s.name)-1]='\0';

    printf("\n\n\t\tEnter Branch\t");
    fflush(stdin);
    fgets(s.branch,50,stdin);
    s.branch[strlen(s.branch)-1]='\0';

    printf("\n\n\t\tEnter ID number \t");
    scanf("%d",&s.id);

    printf("\n\n\tEnter studentGPA for 10 semesters\n\t");
    for(i=0,Ggpa=0;i<10;i++)
    {scanf("%f",&s.sgpa[i]);
    Ggpa+=s.sgpa[i];

    }

    Ggpa/=10.0;
    s.Ggpa=Ggpa;

    fwrite(&s,sizeof(s),1,fp);

    printf("\n\n\t\tWant to enter another student info (Y/N)\t");
    fflush(stdin);
    another=getchar();
}
}


//===================DELETING A RECORD FROM LIST ============
/*
 * name : add
 * inputs : file pointer
 * description : used for  adding students name , id , grades and departments
 */

FILE * del(FILE * fp)
{
 printHead();

Student s;
int flag=0,tempID,siz=sizeof(s);
FILE *ft; // temp file pointer
ft=fopen("temp.txt","wb+") ;
// check if the file can be opened ..
if((ft=fopen("temp.txt","wb+"))==NULL) //  "wb+"> open binary file in reading and writing mode .

{
    printf("\n\n\t\t\t\\t!!! ERROR !!!\n\t\t");
    system("pause");
     return fp;
}

printf("\n\n\tEnter ID number of Student to Delete the Record");
printf("\n\n\t\t\tID No. : ");
scanf("%d",&tempID);

rewind(fp); // fun to set the position to the beginning point


while((fread(&s,siz,1,fp))==1)
{
    if(s.id==tempID) //check if the searched id is equal the temp id
    { flag=1;
    printf("\n\tRecord Deleted for");
    printf("\n\n\t\t%s\n\n\t\t%s\n\n\t\t%d\n\t",s.name,s.branch,s.id);
    continue;
    }

    fwrite(&s,siz,1,ft);
}


fclose(fp); //close,file 1
fclose(ft); //close,file 2

remove("studentInfo.txt");
rename("temp.txt","studentInfo.txt");

if((fp=fopen("studentInfo.txt","rb+"))==NULL)
{
    printf("ERROR");
    return NULL; // return 0 if it delete successfully otherwise nonzero
}

if(flag==0) printf("\n\n\t\t!!!! ERROR RECORD NOT FOUND \n\t");

printChar('-',65); // to print line in the output screen
printf("\n\t");
system("pause"); // wait until the user press key
return fp;
}


//===========MODIFY A RECORD ===========================
/*
 * name : modify
 * inputs : file pointer, tempID
 * description : used for  adding students name , id , grades and departments
 */

void modify(FILE * fp)
{
printHead();

Student s;
int i,flag=0,tempID,siz=sizeof(s);
float Ggpa;

printf("\n\n\tEnter ID Number of Student to MODIFY the Record : ");
scanf("%d",&tempID);

rewind(fp);

while((fread(&s,siz,1,fp))==1)
{
    if(s.id==tempID)
        {flag=1;
        break;
        }
}

if(flag==1)
    {
    fseek(fp,-siz,SEEK_CUR);
    printf("\n\n\t\tRECORD FOUND");
    printf("\n\n\t\tEnter New Data for the Record");

    printf("\n\n\t\tEnter Full Name of Student\t");
    fflush(stdin);
    fgets(s.name,100,stdin);
    s.name[strlen(s.name)-1]='\0';

    printf("\n\n\t\tEnter Branch\t");
    fflush(stdin);
    fgets(s.branch,50,stdin);
    s.branch[strlen(s.branch)-1]='\0';

    printf("\n\n\t\tEnter ID number \t");
    scanf("%d",&s.id);


    printf("\n\n\tEnter SGPA for 8 semesters\n\t");
    for(i=0,Ggpa=0;i<10;i++)
    {scanf("%f",&s.sgpa[i]);
    Ggpa+=s.sgpa[i];

    }
    Ggpa=Ggpa/10.0;


    fwrite(&s,sizeof(s),1,fp);
}

else printf("\n\n\t!!!! ERROR !!!! RECORD NOT FOUND");

printf("\n\n\t");
system("pause");

}

//====================DISPLAY THE LIST =================

/*
 * name : DISPLAYDISPLAY
 * inputs : file pointer
 * description : used for  print student record  students name , id , grades and departments and each semester
 and the total GBA
 */



void displayList(FILE * fp)
{   printHead();
    Student s;
    int i,siz=sizeof(s);

    rewind(fp);

    while((fread(&s,siz,1,fp))==1)
    {
        printf("\n\t\tNAME : %s",s.name);
        printf("\n\n\t\tBRANCH : %s",s.branch);
        printf("\n\n\t\tID : %d",s.id);
        printf("\n\n\t\tStudentGPA: ");

        for(i=0;i<10;i++){
            printf("| %.2f |",s.sgpa[i]);}
        printf("\n\n\t\tGGPA : %.2f\n\t",s.Ggpa);
        printChar('-',65); //print a line in the out put screen
    }
    printf("\n\n\n\t");
     printChar('*',65);// print a line of *
    printf("\n\n\t");
    system("pause");
}
//==========SEARCH A RECORD ===========================
/*
 * name : search
 * inputs : file pointer, tempID,
 * description : used for  search students record
 */

void searchRecord(FILE *fp)
{printHead();

int tempID,flag,siz,i;
Student s;
char another='y';

siz=sizeof(s);

while(another=='y'||another=='Y')
{
printf("\n\n\tEnter ID Number of Student to search the record : ");
scanf("%d",&tempID);

rewind(fp);

while((fread(&s,siz,1,fp))==1)
{
    if(s.id==tempID) //check if this is the searched
        {flag=1;
        break;
        }
}

if(flag==1) // after checking if the condit
    {
    printf("\n\t\tNAME : %s",s.name);
        printf("\n\n\t\tBRANCH : %s",s.branch);
        printf("\n\n\t\tID : %d",s.id);
        printf("\n\n\tSGPA: ");

        for(i=0;i<10;i++){
            printf("| %.2f |",s.sgpa[i]);
        printf("\n\n\t\tGGPA : %.2f\n\t",s.Ggpa);
        printChar('-',65);
        }
}
else printf("\n\n\t\t!!!! ERROR RECORD NOT FOUND !!!!");


printf("\n\n\t\tWant to enter another search (Y/N)");
fflush(stdin);
another=getchar();
}
}
