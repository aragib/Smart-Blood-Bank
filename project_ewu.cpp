#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

struct contact
{
    char ph[30];
    char group[20],add[20],name[30];

} list;

char query[20],group[20];
FILE *fp, *ft;
int i,n,ch,l,found;

int main()
{
main:
    system("cls");    /* ************Main menu ***********************  */
    system("COLOR 04");
    printf("\n\t **** Welcome to SMART BLOOD BANK ****");
    printf("\n\n\n\t\t\tMAIN MENU\n\t\t=====================\n\t\t[1] Add a new Donner\n\t\t[2] List all Donners\n\t\t[3] Search for Donner\n\t\t[4] Edit a Donner\n\t\t[5] Delete a Donner\n\t\t[6] Some Tips About Blood Donation\n\t\t[7] BMI calculator\n\t\t[8] Credit\n\t\t[0] Exit\n\t\t=====================\n\t\t");
    printf("Enter the choice:");
    scanf("%d",&ch);
    switch(ch)
    {
    /* exit */
    case 0:
        printf("\n\n\t\tAre you sure u want to exit?");
        break;
    /* add new Donner */
    case 1:
        system("cls");
        system("COLOR 1C");
        fp=fopen("blood.dll","a");
        for (;;)
        {
            fflush(stdin);
            printf("To exit enter blank space in the name input\nName:");
            gets(list.name);
            if(strcmp(list.name,"")==0 || strcmp(list.name," ")==0)
                break;
            fflush(stdin);
            printf("group:");
            gets(list.group);
            fflush(stdin);
            printf("Phone:");
            gets(list.ph);
            fflush(stdin);
            printf("address:");
            gets(list.add);
            fflush(stdin);
            printf("\n");
            fwrite(&list,sizeof(list),1,fp);
        }
        fclose(fp);
        break;
        /* list of Donner */
    case 2:
        system("cls");
        system("COLOR 70");
        printf("\n\t\t================================\n\t\t\tLIST OF DONNERS\n\t\t================================\n\n");
        for(i=97; i<=122; i=i+1)
        {
            fp=fopen("blood.dll","r");
            fflush(stdin);
            found=0;
            while(fread(&list,sizeof(list),1,fp)==1)
            {
                if(list.group[0]==i || list.group[0]==i-32)
                {
                    printf("\nName\t: %s\nPhone\t: %s\nAddress\t: %s\nGroup\t: %s\n",list.name,list.ph,list.add,list.group);
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


        /* search Donner  */

    case 3:
        system("COLOR 56");
        system("cls");
        do
        {
            found=0;
            printf("\n\n\t..::DONNER SEARCH\n\t===========================\n\t..::Name of Group to search: ");
            fflush(stdin);
            gets(query);
            l=strlen(query);
            fp=fopen("blood.dll","r");
            system("cls");
            printf("\n\n..::Search result for '%s' \n===================================================\n",query);
            while(fread(&list,sizeof(list),1,fp)==1)
            {
                for(i=0; i<=l; i++)
                    group[i]=list.group[i];
                group[l]='\0';
                if(strcmp(group,query)==0)
                {
                    printf("\n..::Group\t: %s\n..::Name\t: %s\n..::Address\t: %s\n..::Phone\t: %s\n",list.group,list.name,list.add,list.ph);
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

        /* edit Donner */

    case 4:
        system("cls");
        system("COLOR 97");
        fp=fopen("blood.dll","r");
        ft=fopen("temp.dat","w");
        fflush(stdin);
        printf("..::Edit Donner\n===============================\n\n\t..::Enter the Name of donner to edit:");
        scanf("%[^\n]",group);
        while(fread(&list,sizeof(list),1,fp)==1)
        {
            if(strcmp(group,list.name)!=0)
                fwrite(&list,sizeof(list),1,ft);
        }

        printf("\n\n..::Editing '%s'\n\n",group);
        fflush(stdin);
        printf("..::name:");
        gets(list.name);
        printf("\n");
        fflush(stdin);
        printf("..::Group:");
        gets(list.group);
        fflush(stdin);
        printf("..::Phone:");
        scanf("%s",list.ph);
        fflush(stdin);
        printf("..::address:");
        gets(list.add);
        fflush(stdin);
        fwrite(&list,sizeof(list),1,ft);
        fclose(fp);
        fclose(ft);
        remove("blood.dll");
        rename("temp.dat","blood.dll");
        break;
        /* delete Donner */

    case 5:
        system("cls");
        system("COLOR 50");
        fflush(stdin);
        printf("\n\n\t..::DELETE A donner\n\t==========================\n\t..::Enter the Name of donner to delete:");
        gets(group);
        fp=fopen("blood.dll","r");
        ft=fopen("temp.dat","w");
        while(fread(&list,sizeof(list),1,fp)!=0)
            if(strcmp(group,list.name)!=0)
                fwrite(&list,sizeof(list),1,ft);
        fclose(fp);
        fclose(ft);
        remove("blood.dll");
        rename("temp.dat","blood.dll");
        break;
        /*  some tips */
    case 6:
        system("cls");
        system("COLOR 04");
        printf(" There are lots of reasons to donate blood:\n\nMaybe you know someone who needs a transfusion, maybe you were asked to give blood by a friend, or maybe you would really like those free movie tickets they are handing out to donors. Whatever your reason may be, giving blood is important — having a healthy blood supply ready for transfusion to patients who need it is key to saving lives, and so by giving blood, you are giving the gift of life (to as many as three people!).\n\nWhat should you, as the donor, know for a successful donation? Herein, some tips:\n\n\n\n\n\t\tpress ENTER to continue");
        getch();
        system("cls");
        printf("1. Who can donate?\n\n\t\tFirst, know if you are even eligible for donation. The most basic requirements are that donors must be healthy, at least 17 years old in most states, and weight at least 110 pounds. When you go to give blood, they will give you a mini-physical where they will check your pulse, blood pressure, hemoglobin level, and temperature. They will also ask you a few basic questions about your health and lifestyle. In some cases, the answers you give could disqualify you from donating blood. Be sure to check the Red Cross guidelines before you go.");
        getch();
        system("cls");
        printf("2. Before donating, eat and drink this:\n\n\t\tIf you are indeed eligible and plan on donating blood, be sure to eat a healthy meal the night before (if you are donating first thing in the morning) or immediately before donating (if you are donating later in the day). Try to avoid very fatty foods (like french fries or ice cream) since that will make your blood too fatty and difficult to test for infectious diseases. If this is the case, your blood will not be used for transfusion. Also, make sure to drink at least 16 ounces of fluid before you donate, and wear clothing with sleeves that can easily be rolled up above the elbow.");
        getch();
        system("cls");
        printf("3. After donating, eat and drink this:\n\n\t\tWhen you're done, it is important to drink water again to replenish your system, and to rest for a bit. Most blood donation centers will not allow you to get up right away anyway, so use the time to drink, drink, drink — and send an email or two. For the rest of the day after you donate blood, make sure to eat well, including foods rich in iron, and drink plenty of fluids (but back off the alcohol!).");
        getch();
        system("cls");
        printf("4. Take it easy:\n\n\t\tBe sure not to do too strenuous of an activity, like rigorous exercise or heavy lifting (i.e. do not head to the gym or help your friend move boxes out of her old apartment) on the day you have given blood. If you start to feel faint or dizzy, stop what you are doing and rest until you feel better. If you still do not feel well after a day or start to get sick or develop a fever, seek medical attention.");
        getch();
        system("cls");
        printf("5. How soon before you can donate again?\n\n\t\tBecause it takes eight weeks for the red cells in your blood to replenish themselves after donating blood, you have to wait at least that long between donations. If you are donating plasma, on the other hand (which is collected through a machine that separates your blood components to take only the plasma and then returns the red blood cells to you), then you can donate more often.While we are on the topic — there is another important blood-related substance you can donate — bone marrow. Thousands of blood cancer patients rely on a transfusion of bone marrow from a genetic match. You can easily join the bone marrow registry by swabbing the inside of your cheek with a kit you get online or at a donor drive.\n\n\n\n\n\n\t\tRead more: http://www.mnn.com/health/fitness-well-being/stories/5-blood-donation-tips-for-newbies-and-old-pros#ixzz3ixDywbO2");
        break;
        /*credit*/
    case 7:
        system("cls");
        system("COLOR 4A");
        float weight, height, bmi;
        printf("Enter your weight(in kgs):");
        scanf("%f", &weight);
        printf("Enter your height(in inch):");
        scanf("%f", &height);
        height=height/12;
        height = height * (0.3048);
        bmi = (weight)/(height * height);
        printf("\nYour Body Mass Index: %f\n", bmi);
        if(bmi>0 && bmi<18.5)
            printf("\nYou are in UNDERWEIGHT\n");
        else if(bmi>=18.5 && bmi<25)
            printf("\nYou are in NORMAL WEIGHT\n");
        else if(bmi>=25 && bmi<30)
            printf("\nYou are in OVERWEIGHT\n");
        else
            printf("\nYou are OBESE!\n");
        break;
    case 8:
        system("cls");
        system("COLOR 04");
        printf("\t\t\t..::CREDIT::..\n\t\t===============================\n\nCredit goes to:\n\nMd. Rakibul Islam\nID: 2015-2-60-073\nDept. of Computer Science & Engineering\nEast West University\n\n\nMd. Ashfak Ragib\nID: 2015-2-60-086\nDept. of Computer Science & Engineering\nEast West University\n\n\nMd. Sazzad Hossain\nID: 2015-2-60-0**\nDept. of Computer Science & Engineering\nEast West University\n\n\n\n");
        getch();
        system("cls");
        printf("Special Thanks to:\nDr. Shamim Akhter\nAssistant Professor\nDept. of Computer Science & Engineering\nEast West University\n");
        break;
    default:
        printf("Invalid choice");
        break;

    }
    printf("\n\n\nEnter the Choice:\n\n\t[1] Main Menu\t\t[0] Exit\n");
    scanf("%d",&ch);
    switch (ch)
    {
    case 1:
        goto main;
    case 0:
        system("cls");
        system("COLOR 04");
        printf("\n\n\n\n\n\n\t\t\t ***      ***       ***\n");
        printf("\t\t\t*         *  *      *  *\n");
        printf("\t\t\t*         *  *      *  *\n");
        printf("\t\t\t***       ***       ***\n");
        printf("\t\t\t   *      *  *      *  *\n");
        printf("\t\t\t   *      *  *      *  *\n");
        printf("\t\t\t***   *   ***   *   ***\n\n\n\n\n\n");
        break;
    default:
        printf("Invalid choice");
        break;

    }
    return 0;

}

