#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

void display_Q();
void Q_database();
void writeQdatabase();
void readQdatabase();
void add_Q();
void delete_Q();

void cropdatabase();
void readdatabase();
void writedatabase();
void displaycrops();
void deletecrops();
void searchcrops();
void modify_Q();

void add_crop();
void modify_c();

int found=0;
int ch,x,c=' ',choice1,choice2,cno;
char str1[20],str2[20],str3[20],str4[20];
char str5[]="admin",str6[]="admin",str7[20],str8[20];
char choice3[]="y",choice4[10],choice5[10];
 char adname[50],adpass[50];char input[255];
 int status1;

int n,m,i;

struct node
{
    char cname[30],cgender[2],cemail[50],cclas[10];
    char cna[100],soil[500],fertil[50];
    int mar,cno;
    char date[20],data[100],allcrops[500];

    char adname[50],adpass[50];

    char fertilizer[10];
    char market[10];

    struct node *next;
};
struct node *head=NULL,*headd=NULL,*p,*r,*last=NULL,*lastt=NULL,*q=NULL,*s=NULL;

struct pop
{
    int cno,mar;
    char cna[100],soil[500],fertil[50];

};
struct pop obj;
//int length();

char cname[20];
char str3[20],str4[20];


int main(){     // MAIN FUNCTION

	 FILE *infile;
do{
	printf("\n----------------------------------------------------------------------------\n");
    printf("                     Welcome to FARMERS AFRO DEPARTMENT System"                    );
    printf("\n----------------------------------------------------------------------------\n");
    printf("\tLog in as:\n");
    printf(" \n\t\t 1. ADMIN \n\n\t\t 2. USER \n\n\t\t 0. EXIT");
    printf("\n----------------------------------------------------------------------------\n");
    printf(""                    );
    printf("\n----------------------------------------------------------------------------\n");
    printf("\n\tChoice:\t\t");
    scanf("\t%d",&ch);
    switch(ch)
    {
        case 1:

        printf("\n----------------------------------------------------------------------------\n");
        printf("                     Welcome ADMIN"                    );
        printf("\n----------------------------------------------------------------------------\n");
        do
        {    system("CLS");
             printf("\n---------------------------------------------\n");
             printf("                   Menu                      ");
             printf("\n---------------------------------------------\n");
             printf("\n\t1.  CROP DETAILS ");
              printf("\n\t2. CROP database");
             printf(" \n\t0. EXIT \n\n\t\n");
             printf("Choice:\t");
            scanf("%d",&choice1);

                switch(choice1)
                {
                case 0: exit(0);
                        break;
                case 1:
                        system("CLS");
                        printf("\n----------------------------------------------------------------------------\n");
                        printf("                            CROP DETAILS : "                    );
                        printf("\n----------------------------------------------------------------------------\n");
                        displaycrops();
                        //displaysearchtrainticket();
						break;
                 case 2:
                        system("CLS");
                        cropdatabase();
                        break;

                }
        printf("\n----------------------------------------------------------------------------\n");
        printf("\n\tWant to Continue[Main Menu] (y/n):\t");
        scanf("%s",&choice4);
        strlwr(choice4);
        }while((strcmp(choice3,choice4))==0);
    case 2: do
        {    system("CLS");
             printf("\n---------------------------------------------\n");
             printf("                 USER Menu                      ");
             printf("\n---------------------------------------------\n");
             printf("\n\t1. VIEW CROP INFORMATION\n\t");
             printf("2. SEARCH CROP INFORMATION");
             printf("\n\t3. QURIES DATABASE**>");
             printf("\n\t0. EXIT \n\n\t");
             printf("Choice:\t");
            scanf("%d",&choice1);
                switch(choice1)
                {
                case 0: exit(0);
                        break;
                case 1: system("CLS");
                        printf("\n----------------------------------------------------------------------------\n");
                        printf("                            CROP DETAILS : "                    );
                        printf("\n----------------------------------------------------------------------------\n");
                        displaycrops();
                            printf("\n\n\n0. MAIN MENU\t\t\t");
                            printf("1. SUB MENU\n\n");
                            printf("Choice:\t");
                            scanf("%d",&choice2);
						break;

                case 2:system("CLS");
                            searchcrops();
                            printf("\n\n\n0. MAIN MENU\t\t\t");
                            printf("1. SUB MENU\n\n");
                            printf("Choice:\t");
                            scanf("%d",&choice2);
                            break;
                case 3:system("CLS");
                       Q_database();
                        printf("\n\n\n0. MAIN MENU\t\t\t");
                            printf("1. SUB MENU\n\n");
                            printf("Choice:\t");
                            scanf("%d",&choice2);
                            break;

                }
        printf("\n----------------------------------------------------------------------------\n");
        printf("\n\tWant to Continue[Main Menu] (y/n):\t");
        scanf("%s",&choice4);
        strlwr(choice4);
        }while((strcmp(choice3,choice4))==0);
        break;
    case 0: exit(0);
    }
    }while(!found==1);
}


void add_crop()
{   do{
    readdatabase();

    found=0;
    p=head;
    printf("\n-----------------------------------------------------------------------------------------------------------------------\n");
    printf("Crop BRED|| Crop Name || Req. Soil ||    CUR price  || Req. Fertilizers ||");
    printf("\n-----------------------------------------------------------------------------------------------------------------------\n   ");
    scanf("\t%d %s %s %d %s",&(obj.cno),obj.cna,obj.soil,&(obj.mar),obj.fertil);
    strlwr(obj.soil),strlwr(obj.fertil),strlwr(obj.cna);
                            for(i=1;p!=NULL;i++)
                            {
                            if(p->cno==obj.cno)
                            {
    printf("\n%d\t %s\t\t %s\t\t %d\t\t %s",(p->cno),p->cna,p->soil,(p->mar),p->fertil);
                            found=1;
                            printf("\n\t\t Oopps  !!!  Crop Already Present ....\n") ;
                            }
                            p=p->next;

                            }}while(found==1);

    struct node *p;
	int i=0;
	p=last;
	if(last==NULL)
	{
	i=1;
	last=(struct node*)malloc(sizeof(struct node));
	last->next=NULL;
	last->cno=obj.cno;
    strcpy(last->cna,obj.cna);
    strcpy(last->soil,obj.soil);
    last->mar=obj.mar;
    strcpy(last->fertil,obj.fertil);
    p=last;
	head=last;
	}//if
else{i=0;
	p=last;
	p->next=(struct node*)malloc(sizeof(struct node));
	p=p->next;
	last=p;
    p->cno=obj.cno;
    strcpy(p->cna,obj.cna);
    strcpy(p->soil,obj.soil);
    last->mar=obj.mar;
    strcpy(p->fertil,obj.fertil);
	p->next=NULL;
	}//i for
   writedatabase();
                         printf("\n\n\t\tCrop Added Successfully ....!!!!!!!\n\n") ;

}

void cropdatabase()
{                do{
                system("CLS");
                printf("\n--------------------------------------------------------\n");
                printf("                        MENU                      ");
                printf("\n--------------------------------------------------------\n\n");
                printf("\t1. Add Crops \n");
                printf("\t3. Delete the Crops \n");
                printf("\t5. Search the crops \n");
                printf("\t2. Display the crops \n");
                printf("\t4. Modify the cropS\n");
                printf("\t*********************<Q-PART>********************************\n");
                printf("\t7. Diplay Q_s\n");
                printf("\t6. Modify Q_s\n");
                printf("\t8. DELETE Q_s\n");
                printf("\t0. EXIT\n");
                printf("\n--------------------------------------------------------\n");
                printf("Choice:\t");
                scanf("%d",&choice2);
                switch(choice2)
                {
                    case 1: system("CLS");
                            displaycrops();
                            add_crop();
                      printf("\n\t\tPress Any Key to Continue ....!!!!!!!\n") ;
                            getch();
                            break;
                    case 2: system("CLS");
                            displaycrops();
                            //insertcropsbw();
                            printf("\n\n\n0. MAIN MENU\t\t\t");
                            printf("1. SUB MENU\n\n");
                            printf("Choice:\t");
                            scanf("%d",&choice2);
                            printf("\n\t\tPress Any Key to Continue ....!!!!!!!\n") ;
                            break;
                    case 3: system("CLS");
                            displaycrops();
                            deletecrops();
                            printf("\n\n\n0. MAIN MENU\t\t\t");
                            printf("1. SUB MENU\n\n");
                            printf("Choice:\t");
                            scanf("%d",&choice2);
                            break;
                    case 5:system("CLS");
                           searchcrops();
                            printf("\n\n\n0. MAIN MENU\t\t\t");
                            printf("1. SUB MENU\n\n");
                            printf("Choice:\t");
                            scanf("%d",&choice2);
                            break;
                    case 4: system("CLS");

                            modify_c();
                            printf("\n\n\n0. MAIN MENU\t\t\t");
                            printf("1. SUB MENU\n\n");
                            printf("Choice:\t");
                            scanf("%d",&choice2);
                            break;
                    case  6:system("CLS");
                            modify_Q();
                            printf("\n\n\n0. MAIN MENU\t\t\t");
                            printf("1. SUB MENU\n\n");
                            printf("Choice:\t");
                            scanf("%d",&choice2);
                            break;
                     case 7:system("CLS");
                            display_Q();
                            printf("\n\n\n0. MAIN MENU\t\t\t");
                            printf("1. SUB MENU\n\n");
                            printf("Choice:\t");
                            scanf("%d",&choice2);
                            break;
                     case 8:system("CLS");
                     delete_Q();
                            printf("\n\n\n0. MAIN MENU\t\t\t");
                            printf("1. SUB MENU\n\n");
                            printf("Choice:\t");
                            scanf("%d",&choice2);
                            break;
                    case 0:system("CLS");
                            break;

                }
                }while(choice2!=0);
}

void displaycrops()
{
    readdatabase();
	p=head;
	if(p==NULL)
	{
	printf("list is empty");
	}
	else
{
    printf("\n--------------------------------------------------------------------------------\n");
    printf("Crop BRED|| Crop Name || Req. Soil ||    CUR price    || Req. Fertilizers ||");
    printf("\n--------------------------------------------------------------------------------\n   ");
    for(i=0;p!=NULL;i++)
	{
 printf("\n%d\t %s\t\t %s\t\t %d\t\t %s",(p->cno),p->cna,p->soil,(p->mar),p->fertil);
	p=p->next;
	}
	printf("\n----------------------------------------------------------------------------------------------");
	}}

void writedatabase()
	{
	FILE *ne=fopen("Crop_database.txt","w");
	int i;
	struct node *temp;
	temp=head;
	if(temp==NULL)
	{
	    printf("Empty File");
	}
	else
	{
	for(i=0;temp!=NULL;i++)
	{
fprintf(ne,"\n%d\t\t %s\t\t %s\t\t %d\t\t %s",(temp->cno),temp->cna,temp->soil,(temp->mar),temp->fertil);
   temp=temp->next;
	}//for
	}//else
	fclose(ne);
	}

void readdatabase()
	{
	int i,filempty=0;
	FILE *infile=fopen("Crop_database.txt","r");
	p=head;
	fseek(infile,0,SEEK_END);
	if(p==NULL)
	{
	p=(struct node*)malloc(sizeof(struct node));
	head=p;
	}
	int len=(int)ftell(infile);
	if(len<=0)
	{
	filempty=1;
	printf("File empty");
	p=NULL;
	head=p;
	}
	if(filempty==0)
	{
	rewind(infile);
	while(fscanf(infile,"\n%d\t\t %s\t\t %s\t\t %d\t\t %s",&(p->cno),p->cna,p->soil,&(p->mar),p->fertil))
{
	if(feof(infile))
	{
	break;
	}
	p->next=(struct node*)malloc(sizeof(struct node));
	p=p->next;
	last=p;
	p->next=NULL;
}}}

void deletecrops()
{   struct node *p,*q;
	readdatabase();
	int loc,i;
	printf("\nEnter the location to delete:\t");
	scanf("%d",&loc);
	if(p!=NULL)
	{
	    if(loc==1)
    {
        p=head;
        head=head->next;
        writedatabase();
        displaycrops();
        free(p);
        return(head);
    }
    else{q=head;}
    for(i=1;i<loc-1;i++)
    {
        q=q->next;
    }
    p=q->next;
    q->next=p->next;
    writedatabase();
    displaycrops();
    free(p);
    n=n-1;
	}
	else
	{
	printf("\nSorry,The list is empty");
	}}


void searchcrops()
{ readdatabase();
	int ttt,found=0;
    char cna[100],src[50],dest[50];
	p=head;
	int choice2;
                do{
                system("CLS");
                printf("\n--------------------------------------------------------\n");
                printf("                       SEARCH MENU                      ");
                printf("\n--------------------------------------------------------\n\n");
                printf("\t1. Crop Name\n");
                printf("\t0. EXIT\n");
                printf("\n--------------------------------------------------------\n");
                printf("Choice:\t");
                scanf("%d",&choice2);
                switch(choice2)
                {
                    case 1: system("CLS");
                            readdatabase();
	p=head;
                            printf("\n\nEnter the Crop Name:\t");
                            scanf("%s",cna);
                            strlwr(cna);
    printf("\n-----------------------------------------------------------------------------------------------------------------------\n");
    printf("Crop BRED|| Crop Name || Req. Soil ||    CUR price    || Req. Fertilizers ||");
    printf("\n-----------------------------------------------------------------------------------------------------------------------\n   ");
                            for(i=1;p!=NULL;i++)
                            {
                            if(strcmp(p->cna,cna)==0)
                            {
    printf("\n%d\t\t %s\t\t %s\t\t %d\t\t %s",(p->cno),p->cna,p->soil,(p->mar),p->fertil);
                            found=1;
                            }
                            p=p->next;
                            }
            printf("\n------------------------------------------------------------------------------------------------------------");
                            if(!found)
                            {
                            printf("\n\t Oops !!!! Data not found\n\n");
                            }
                            printf("\n\n\n0. MAIN MENU\t\t\t");
                            printf("1. SUB MENU\n\n");
                            printf("Choice:\t");
                            scanf("%d",&choice2);
                            break;
                      case 2:system("CLS");
                            exit(0);

                }
                }while(choice2!=0);}

 void modify_c()
{
     struct node *p,*q;
	readdatabase();
	int loc,i;
	printf("\nEnter the location to Modify:\t");
	scanf("%d",&loc);
	if(p!=NULL)
	{
	    if(loc==1)
    {
        p=head;
        head=head->next;
        writedatabase();
        displaycrops();
        free(p);
        return(head);
    }
    else{q=head;}
    for(i=1;i<loc-1;i++)
    {
        q=q->next;
    }
    p=q->next;
    q->next=p->next;
    writedatabase();
    displaycrops();
    free(p);
    n=n-1;
	}
	else
	{
	printf("\nSorry,The list is empty");
	}
 readdatabase();
	p=head;
	q=head;
    int cno,ttt,mar;
    char cna[100],soil[50],fertil[50];
    float km,arr,dept;
    printf("\n---------------------------------------------------------------------------------------------------------------------\n");
    printf("Crop BRED|| Crop Name || Req. Soil ||    CUR price    || Req. Fertilizers ||");
    printf("\n---------------------------------------------------------------------------------------------------------------------\n   ");
    scanf("\t%d %s %s %d %s",&(cno),cna,soil,&(mar),fertil);
    strlwr(soil),strlwr(fertil),strlwr(cna);
    p=(struct node*)malloc(sizeof(struct node));
    p->cno=cno;
    strcpy(p->soil,soil);
    strcpy(p->fertil,fertil);
    strcpy(p->cna,cna);
    p->mar=mar;
    p->next=NULL;
    if(loc==1)
    {
        p->next=head;
	head=p;
        writedatabase();
        return(p);
    }
    q=head;
    for(i=1;i<loc-1;i++)
    {
        if(q!=NULL)
        {
            q=q->next;
        }
    }
    p->next=q->next;
    q->next=p;
    n=n+1;
   writedatabase();
    return(head);
}
//------------------------------------------------quries part---------------------------------------------------------------
void add_Q()
{   do{
    readQdatabase();

    found=0;
    p=head;
    printf("\n-----------------------------------------------------------------------------------------------------------------------\n");
    printf("QURIES NO. ||  Q_NAME   ||           DESCRIPTIONS                  ||");
    printf("\n-----------------------------------------------------------------------------------------------------------------------\n   ");
    scanf("\t%d %s %s",&(obj.cno),obj.cna,obj.soil);
    strlwr(obj.soil),strlwr(obj.cna);
                            for(i=1;p!=NULL;i++)
                            {
                            if(p->cno==obj.cno)
                            {
    printf("\n%d\t %s\t\t %s",(p->cno),p->cna,p->soil);
                            found=1;
                            printf("\n\t\t Oopps  !!!  QURIE Already Present ....\n") ;
                            }
                            p=p->next;

                            }}while(found==1);

    struct node *p;
	int i=0;
	p=last;
	if(last==NULL)
	{
	i=1;
	last=(struct node*)malloc(sizeof(struct node));
	last->next=NULL;
	last->cno=obj.cno;
    strcpy(last->cna,obj.cna);
    strcpy(last->soil,obj.soil);
    p=last;
	head=last;
	}//if
else{i=0;
	p=last;
	p->next=(struct node*)malloc(sizeof(struct node));
	p=p->next;
	last=p;
    p->cno=obj.cno;
    strcpy(p->cna,obj.cna);
    strcpy(p->soil,obj.soil);
	p->next=NULL;
	}//i for
   writeQdatabase();
                         printf("\n\n\t\tQURIE Added Successfully ....!!!!!!!\n\n") ;

}
void readQdatabase()
	{
	int i,filempty=0;
	FILE *infile=fopen("QU_database.txt","r");
	p=head;
	fseek(infile,0,SEEK_END);
	if(p==NULL)
	{
	p=(struct node*)malloc(sizeof(struct node));
	head=p;
	}
	int len=(int)ftell(infile);
	if(len<=0)
	{
	filempty=1;
	printf("File empty");
	p=NULL;
	head=p;
	}
	if(filempty==0)
	{
	rewind(infile);
	while(fscanf(infile,"\n%d\t\t %s\t\t %s",&(p->cno),p->cna,p->soil))
{
	if(feof(infile))
	{
	break;
	}
	p->next=(struct node*)malloc(sizeof(struct node));
	p=p->next;
	last=p;
	p->next=NULL;
}}}

void writeQdatabase()
	{
	FILE *ne=fopen("QU_database.txt","w");
	int i;
	struct node *temp;
	temp=head;
	if(temp==NULL)
	{
	    printf("Empty File");
	}
	else
	{
	for(i=0;temp!=NULL;i++)
	{
fprintf(ne,"\n%d\t\t %s\t\t %s",(temp->cno),temp->cna,temp->soil);
   temp=temp->next;
	}//for
	}//else
	fclose(ne);
	}
	void Q_database()
{                do{
                system("CLS");
                printf("\n--------------------------------------------------------\n");
                printf("                        MENU                      ");
                printf("\n--------------------------------------------------------\n\n");
                printf("\t1. Add Q \n");
               // printf("\t3. Delete the Q \n");
                printf("\t5. Search the Q \n");
                printf("\t2. Display the Q \n");
                //printf("\t4. Modify the Q\n");
                printf("\t0. EXIT\n");
                printf("\n--------------------------------------------------------\n");
                printf("Choice:\t");
                scanf("%d",&choice2);
                switch(choice2)
                {
                    case 1: system("CLS");
                            display_Q();
                            add_Q();
                      printf("\n\t\tPress Any Key to Continue ....!!!!!!!\n") ;
                            getch();
                            break;
                    case 2: system("CLS");
                            display_Q();
                            //insertcropsbw();
                            printf("\n\n\n0. MAIN MENU\t\t\t");
                            printf("1. SUB MENU\n\n");
                            printf("Choice:\t");
                            scanf("%d",&choice2);
                            printf("\n\t\tPress Any Key to Continue ....!!!!!!!\n") ;
                            break;

                    case 5:system("CLS");
                           search_Q();
                            printf("\n\n\n0. MAIN MENU\t\t\t");
                            printf("1. SUB MENU\n\n");
                            printf("Choice:\t");
                            scanf("%d",&choice2);
                            break;

                    case 0:system("CLS");
                            break;

                }
                }while(choice2!=0);
}
void display_Q()
{
    readQdatabase();
	p=head;
	if(p==NULL)
	{
	printf("list is empty");
	}
	else
{
    printf("\n--------------------------------------------------------------------------------\n");
    printf("QURIES NO. ||  Q_NAME   ||           DESCRIPTIONS                  || ");
    printf("\n--------------------------------------------------------------------------------\n   ");
    for(i=0;p!=NULL;i++)
	{
 printf("\n%d\t %s\t\t %s",(p->cno),p->cna,p->soil);
	p=p->next;
	}
	printf("\n----------------------------------------------------------------------------------------------");
	}}
void search_Q()
{ readQdatabase();
	int ttt,found=0;
    char cna[100],src[50],dest[50];
	p=head;
	int choice2;
                do{
                system("CLS");
                printf("\n--------------------------------------------------------\n");
                printf("                       SEARCH MENU                      ");
                printf("\n--------------------------------------------------------\n\n");
                printf("\t1. QU Name\n");
                printf("\t0. EXIT\n");
                printf("\n--------------------------------------------------------\n");
                printf("Choice:\t");
                scanf("%d",&choice2);
                switch(choice2)
                {
                    case 1: system("CLS");
                            readQdatabase();
	p=head;
                            printf("\n\nEnter the Crop Name:\t");
                            scanf("%s",cna);
                            strlwr(cna);
    printf("\n-----------------------------------------------------------------------------------------------------------------------\n");
    printf(" ||  QURIES NO. ||  Q_NAME   ||           DESCRIPTIONS                  || ");
    printf("\n-----------------------------------------------------------------------------------------------------------------------\n   ");
                            for(i=1;p!=NULL;i++)
                            {
                            if(strcmp(p->cna,cna)==0)
                            {
    printf("\n%d\t\t %s\t\t %s",(p->cno),p->cna,p->soil);
                            found=1;
                            }
                            p=p->next;
                            }
            printf("\n------------------------------------------------------------------------------------------------------------");
                            if(!found)
                            {
                            printf("\n\t Oops !!!! Data not found\n\n");
                            }
                            printf("\n\n\n0. MAIN MENU\t\t\t");
                            printf("1. SUB MENU\n\n");
                            printf("Choice:\t");
                            scanf("%d",&choice2);
                            break;
                      case 2:system("CLS");
                            exit(0);

                }
                }while(choice2!=0);}
void modify_Q()
{
     struct node *p,*q;
	readQdatabase();
	int loc,i;
	printf("\nEnter the location to Modify:\t");
	scanf("%d",&loc);
	if(p!=NULL)
	{
	    if(loc==1)
    {
        p=head;
        head=head->next;
        writeQdatabase();
        display_Q();
        free(p);
        return(head);
    }
    else{q=head;}
    for(i=1;i<loc-1;i++)
    {
        q=q->next;
    }
    p=q->next;
    q->next=p->next;
    writeQdatabase();
    display_Q();
    free(p);
    n=n-1;
	}
	else
	{
	printf("\nSorry,The list is empty");
	}
 readQdatabase();
	p=head;
	q=head;
    int cno,ttt,mar;
    char cna[100],soil[500],fertil[50];
    float km,arr,dept;
    printf("\n---------------------------------------------------------------------------------------------------------------------\n");
    printf(" ||  QURIES NO. ||  Q_NAME   ||           DESCRIPTIONS                  ||");
    printf("\n---------------------------------------------------------------------------------------------------------------------\n   ");
    scanf("\n%d \t%s\t\t %s",&(cno),cna,soil);
    strlwr(soil),strlwr(cna);
    p=(struct node*)malloc(sizeof(struct node));
    p->cno=cno;
    strcpy(p->soil,soil);
    strcpy(p->cna,cna);
    p->next=NULL;
    if(loc==1)
    {
        p->next=head;
	head=p;
        writeQdatabase();
        return(p);
    }
    q=head;
    for(i=1;i<loc-1;i++)
    {
        if(q!=NULL)
        {
            q=q->next;
        }
    }
    p->next=q->next;
    q->next=p;
    n=n+1;
   writeQdatabase();
    return(head);
}
void delete_Q()
{   struct node *p,*q;
	readQdatabase();
	int loc,i;
	printf("\nEnter the location to delete:\t");
	scanf("%d",&loc);
	if(p!=NULL)
	{
	    if(loc==1)
    {
        p=head;
        head=head->next;
        writeQdatabase();
        display_Q();
        free(p);
        return(head);
    }
    else{q=head;}
    for(i=1;i<loc-1;i++)
    {
        q=q->next;
    }
    p=q->next;
    q->next=p->next;
    writeQdatabase();
    display_Q();
    free(p);
    n=n-1;
	}
	else
	{
	printf("\nSorry,The list is empty");}}
