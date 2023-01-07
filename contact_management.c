#include<stdio.h>

#include<conio.h>

#include<string.h>

#include<process.h>

#include<stdlib.h>

#include<direct.h>

struct contact

{

    long ph;

    char name[20],add[30],email[30],city[20],group[20],dob[10];

} list;

char query[20],name[20];

FILE *fp, *ft;

int i,n,ch,l,found;

char groupl[100][50],cityl[100][50],temp[50];

int groupc=0,cityc=0;

int main()

{

main:

    system("cls");    /* ************ Main menu ***********************  */

    printf("\n\t **** Welcome to Contact Management System ****");

    printf("\n\n\n\t\t\tMAIN MENU\n\t\t=====================\n\t\t[1] Add a new Contact\n\t\t[2] List all Contacts\n\t\t[3] List all Groups\n\t\t[4] Contacts by city\n\t\t[5] Search for contact\n\t\t[6] Edit a Contact\n\t\t[7] Delete a Contact\n\t\t[0] Exit\n\t\t=================\n\t\t");

    printf("Enter the choice:");

    scanf("%d",&ch);

    switch(ch)

    {

    case 0:

        printf("\n\n\t\tAre you sure you want to exit?");

        break;

        /* *********************Add new contacts************  */

    case 1:

        system("cls");

        fp=fopen("contact.txt","a");

        for (;;)

        {
            fflush(stdin);

            printf("To exit enter blank space in the name input\nName (Use identical):");

            scanf("%[^\n]",&list.name);

            if(stricmp(list.name,"")==0 || stricmp(list.name," ")==0){

                break;
            }
            fflush(stdin);

            printf("Phone:");

            scanf("%ld",&list.ph);

            fflush(stdin);

            printf("Address:");

            scanf("%[^\n]",&list.add);

            fflush(stdin);

            printf("Email address:");

            gets(list.email);

            fflush(stdin);

            printf("City:");

            gets(list.city);

            if(cityc==0){
                strcpy(cityl[cityc],list.city);
                cityc++;
            }else{
                for(i=0;i<cityc;i++){
                    if(stricmp(cityl[i],list.city)==0){
                        break;
                    }
                }
                if(i==cityc){
                    strcpy(cityl[cityc],list.city);
                    cityc++;
                }
            }

            fflush(stdin);

            printf("Group:");

            gets(list.group);

            if(groupc==0){
                strcpy(groupl[groupc],list.group);
                groupc++;
            }else{
                for(i=0;i<groupc;i++){
                    if(stricmp(groupl[i],list.group)==0){
                        break;
                    }
                }
                if(i==groupc){
                    strcpy(groupl[groupc],list.group);
                    groupc++;
                }
            }

            fflush(stdin);

            printf("date of birth:");

            gets(list.dob);

            fflush(stdin);

            printf("\n");

            fwrite(&list,sizeof(list),1,fp);

        }

        fclose(fp);

        break;

        /* *********************list of contacts*************************  */

    case 2:


        system("cls");

        printf("\n\t\t================================\n\t\t\tLIST OF CONTACTS\n\t\t================================\n\n\n=================================================================\n\n");

        for(i=97; i<=122; i=i+1)

        {

            fp=fopen("contact.txt","r");

            fflush(stdin);

            found=0;

            while(fread(&list,sizeof(list),1,fp)==1)

            {

                if(list.name[0]==i || list.name[0]==i-32)

                {

                    printf("\nName\t: %s\nPhone\t: %ld\nAddress\t: %s\nEmail\t: %s\nCity\t: %s\nGroup\t: %s\nD.O.B\t: %s\n",list.name,

                           list.ph,list.add,list.email,list.city,list.group,list.dob);

                    found++;

                }

            }

            if(found!=0)

            {
                printf("=========================================================== [%c]-(%d)\n\n",i-32,found);

                getch();
            }

            fclose(fp);

        }

        break;
        /* *******************list of gropus**********************  */

    case 3:
        system("cls");

        printf("\n\t\t================================\n\t\t\tLIST OF GROUPS\n\t\t================================\n\n\n=================================================================\n\n");

        for(i=0; i<groupc; i=i+1)

        {
            strcpy(temp,groupl[i]);

            fp=fopen("contact.txt","r");

            fflush(stdin);

            found=0;

            while(fread(&list,sizeof(list),1,fp)==1)

            {

                if(stricmp(temp,list.group)==0)

                {


                    printf("\nName\t: %s\nPhone\t: %ld\nAddress\t: %s\nEmail\t: %s\nCity\t: %s\nGroup\t: %s\nD.O.B\t: %s\n",list.name,

                           list.ph,list.add,list.email,list.city,list.group,list.dob);

                    found++;

                }

            }

            if(found!=0)

            {
                printf("=========================================================== [%s]-(%d)\n\n",temp,found);

                getch();
            }

            fclose(fp);

        }

        break;

        /* *******************contacts by city************************ */
    
    case 4:
        system("cls");

        printf("\n\t\t================================\n\t\t\tLIST OF CONTACTS BY CITY\n\t\t================================\n\n\n=================================================================\n\n");   

        for(i=0; i<cityc; i=i+1)

        {
            strcpy(temp,cityl[i]);

            fp=fopen("contact.txt","r");

            fflush(stdin);

            found=0;

            while(fread(&list,sizeof(list),1,fp)==1)

            {

                if(stricmp(temp,list.city)==0)

                {

                    printf("\nName\t: %s\nPhone\t: %ld\nAddress\t: %s\nEmail\t: %s\nCity\t: %s\nGroup\t: %s\nD.O.B\t: %s\n",list.name,

                           list.ph,list.add,list.email,list.city,list.group,list.dob);

                    found++;

                }

            }

            if(found!=0)

            {
                printf("=========================================================== [%s]-(%d)\n\n",temp,found);

                getch();
            }

            fclose(fp);     
        
        }

        break;

        /* *******************search contacts**********************  */

    case 5:

        system("cls");

        do

        {

            found=0;

            printf("\n\n\t..::CONTACT SEARCH\n\t===========================\n\t..::Name of contact to search: ");

            fflush(stdin);

            scanf("%[^\n]",&query);

            l=strlen(query);

            fp=fopen("contact.txt","r");

            system("cls");

            printf("\n\n..::Search result for '%s' \n===================================================\n",query);

            while(fread(&list,sizeof(list),1,fp)==1)

            {

                for(i=0; i<=l; i++)

                    name[i]=list.name[i];

                name[l]='\0';

                if(stricmp(name,query)==0)

                {

                    printf("\n..::Name\t: %s\n..::Phone\t: %ld\n..::Address\t: %s\n..::Email\t: %s\n..::City\t: %s\n..::Group\t: %s\n..::D.O.B\t: %s\n",list.name,list.ph,list.add,list.email,list.city,list.group,list.dob);

                    found++;

                    if (found%4==0)

                    {

                        printf("..::Press any key to continue...");

                        getch();

                    }

                }

            }

            if(found==0)

                printf("\n..::No match found!");

            else

                printf("\n..::%d match(s) found!",found);

            fclose(fp);

            printf("\n ..::Try again?\n\n\t[1] Yes\t\t[0] No\n\t");

            scanf("%d",&ch);

        }
        while(ch==1);

        break;

        /* *********************edit contacts************************/

    case 6:

        system("cls");

        fp=fopen("contact.txt","r");

        ft=fopen("temp.txt","w");

        fflush(stdin);

        printf("..::Edit contact\n===============================\n\n\t..::Enter the name of contact to edit:");

        scanf("%[^\n]",name);

        while(fread(&list,sizeof(list),1,fp)==1)

        {

            if(stricmp(name,list.name)!=0)

                fwrite(&list,sizeof(list),1,ft);

        }

        fflush(stdin);

        printf("\n\n..::Editing '%s'\n\n",name);

        printf("..::Name(Use identical):");

        scanf("%[^\n]",&list.name);

        fflush(stdin);

        printf("..::Phone:");

        scanf("%ld",&list.ph);

        fflush(stdin);

        printf("..::Address:");

        scanf("%[^\n]",&list.add);

        fflush(stdin);

        printf("..::Email address:");

        gets(list.email);

        fflush(stdin);

        printf("..::City:");

        gets(list.city);

        fflush(stdin);

        printf("..::Group:");

        gets(list.group);

        fflush(stdin);

        printf("..::Date of birth:");

        gets(list.dob);

        printf("\n");

        fwrite(&list,sizeof(list),1,ft);

        fclose(fp);

        fclose(ft);

        remove("contact.txt");

        rename("temp.txt","contact.txt");

        break;

        /* ********************delete contacts**********************/

    case 7:

        system("cls");

        fflush(stdin);

        printf("\n\n\t..::DELETE A CONTACT\n\t==========================\n\t..::Enter the name of contact to delete:");

        scanf("%[^\n]",&name);

        fp=fopen("contact.txt","r");

        ft=fopen("temp.txt","w");

        while(fread(&list,sizeof(list),1,fp)!=0)

            if (stricmp(name,list.name)!=0)

                fwrite(&list,sizeof(list),1,ft);

        fclose(fp);

        fclose(ft);

        remove("contact.txt");

        rename("temp.txt","contact.txt");

        break;
    
    case 8:
        for(int i=0;i<groupc;i++){
            printf("%s",groupl[i]);
        }

        for(int i=0;i<cityc;i++){
            printf("%s",cityl[i]);
        }

    default:

        printf("Invalid choice");

        break;

    }

    printf("\n\n\n..::Enter the Choice:\n\n\t[1] Main Menu\t\t[0] Exit\n");

    scanf("%d",&ch);

    switch (ch)

    {

    case 1:

        goto main;

    case 0:

        break;

    default:

        printf("Invalid choice");

        break;

    }

    return 0;

}