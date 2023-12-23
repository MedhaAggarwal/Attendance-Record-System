#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
char Name[10000][30];
int present[10000] = {0};
int absent[10000] = {0};
int last= 0;
FILE *fptr;
FILE *pre;
FILE *ab;
// FILE *final;

COORD coord = {
    //for holding screen in x and y co ordinates
    0,
    0};
void position(int x, int y)
{
    //for assigning co ordinates
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void login();
void changecolor(int color)
{
    WORD wColor;
    //for changing text colour

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {

        wColor = (csbi.wAttributes & 0xF0) + (color & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}
void update1()
{
    //this function is for copying namr from file to array
    fptr = fopen("Stud.txt", "r");

    if (fptr == NULL)
    {
        return;
    }
    last = 0;

    char str[50];
    while (!feof(fptr))
    {
        fscanf(fptr, "%s", str);
        int j = strlen(str);
        int p = 0;
        while (p != j)
        {
            Name[last][p] = str[p];
            p++;
        }
        Name[last][p] = '\0';
        last++;
    }
    last--;
    fclose(fptr);
}
void update2()
{
    //this function is for copying prsent data from file
    pre = fopen("pre.txt", "r");

    if (pre == NULL)
    {
        return;
    }
    last = 0;

    char p[10];
    while (!feof(pre))
    {
        fscanf(pre, "%s", p);
        // printf("%s",p);
        int q = atoi(p);
        present[last] = q;

        // Name[last][p] = '\0';
        last++;
    }
    last--;
    fclose(pre);
}
void update3()
{
    //this function is for copying absent data from file
    ab = fopen("abs.txt", "r");
    last = 0;
    if (ab == NULL)
    {
        return;
    }

    char p[10];
    while (!feof(ab))
    {
        fscanf(ab, "%s", p);
        int q = atoi(p);
        absent[last] = q;

        last++;
    }
    last--;
    fclose(ab);
}

void pause()
{
    for (int i = 0; i < 2; i++)
    {
        changecolor(78);
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t Saving records...");
        Sleep(300);
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t  Saving records..");
        Sleep(300);
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t Saving records...");
        Sleep(300);
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t  Saving records....");
        Sleep(300);
        system("cls");
        changecolor(10);
    }
}

void wait()
{
    for (int i = 0; i < 2; i++)
    {
        changecolor(14);
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tPlease Wait.");
        Sleep(300);
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tPlease Wait..");
        Sleep(300);
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tPlease Wait...");
        Sleep(300);
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tPlease Wait....");
        Sleep(300);
        system("cls");
        changecolor(45);
    }
}

void viewattendance()
{
    int i;
    // final = fopen("fin.txt", "w");
    printf("\n +-------+----------------------------+-------------+----------+--------+-|\n");
    printf(" | S.No. |                       Name |      prsent |   absent | percentage|\n");
    printf(" +-------+----------------------------+-------------+----------+--------+----\n");

    for (i = 0; i < last; i++)
    {
         printf("   %d     |",i+1);
        printf("            %s   ", Name[i]);
       
        int h = (present[i] * 100) / (present[i] + absent[i]);

        printf("          | %d            |%d         | %d\n", present[i], absent[i], h);
        // fprintf(final, "            %d           %d       %d\n", present[i], absent[i], h);
        printf(" +-------+----------------------------+-------------+----------+--------+|\n");
    }

    printf("Enter 0 to log out :");
    int n;

    scanf("%d", &n);
    if (n == 0)
    {

        Sleep(1500);
        login();
    }
    else
    {
        printf("Press a valid key.");

        viewattendance();
    }
    // fclose(final);
}
void addStudent()
{

    fptr = fopen("Stud.txt", "w");
    pre = fopen("pre.txt", "w");
    ab = fopen("abs.txt", "w");
    fflush(stdin);
    int i, num, add;
    if (last == 0)
    {
        changecolor(10);
        printf("Enter how many students you want to add: ");
        fflush(stdin);
        scanf("%d", &num);
        for (i = 0; i < num; i++)
        {
            printf("\nEnter %d student name to add in attendance register: ", i + 1);
            fflush(stdin);
            gets(Name[i]);
            fprintf(fptr, "%s", Name[i]);
            fprintf(pre, "%d", 0);

            fputs(" ", fptr);
            fputs(" ", pre);
            fprintf(ab, "%d", 0);
            fputs(" ", ab);

            last++;
        }

        pause();
    }
    else
    {
        printf("Enter how many students you want to add: ");
        fflush(stdin);
        scanf("%d", &num);
        add = last + num;
        for (i = last; i < add; i++)
        {
            printf("\nEnter %d student name to add in attendance ragister: ", i + 1);
            fflush(stdin);
            gets(Name[i]);
            last++;
            fprintf(fptr, "%s", Name[i]);
            fprintf(pre, "%d", 0);

            fputs(" ", fptr);
            fputs(" ", pre);
            fprintf(ab, "%d", 0);
            fputs(" ", ab);
        }
        pause();
    }
    fclose(fptr);
    fclose(pre);
    fclose(ab);
}
void removeStudent()
{
    char name[30];
    printf("Enter student name to remove: ");
    fflush(stdin);
    gets(name);
    for (int i = 0; i < last; i++)
    {
        if (strcmp(name, Name[i]) == 0)
        {
            for (int j = i; j < last; j++)
            {
                strcpy(Name[j], Name[j + 1]);
                present[i] = present[i + 1];
                absent[i] = absent[i + 1];
            }
            last--;
            printf("\n%s student is removed\n", name);
            break;
        }
        else if (i == last - 1)
        {
            printf("This name doesn't exist in list.\n");
        }
    }
    fptr = fopen("Stud.txt", "w");
    for (int x = 0; x < last; x++)
    {
        fprintf(fptr, "%s ", Name[x]);
    }
    fclose(fptr);
    pre = fopen("pre.txt", "w");
    for (int x = 0; x < last; x++)
    {
        fprintf(pre, "%d ", present[x]);
    }
    fclose(ab);
    pre = fopen("abs.txt", "w");
    for (int x = 0; x < last; x++)
    {
        fprintf(ab, "%d ", absent[x]);
    }
    fclose(ab);
}

void markattendance()
{
    int i;
    changecolor(14);
    char ch;
    printf("\n Enter Y for present and N for absent\n");
    for (i = 0; i < last; i++)
    {
    repeate:
        printf("%d. %s is present: ", i + 1, Name[i]);
        fflush(stdin);
        scanf("%c", &ch);
        if (ch == 'Y' || ch == 'y')
        {
            present[i] += 1;
        }
        else if (ch == 'N' || ch == 'n')
        {
            absent[i] += 1;
        }
        else
        {
            printf("Invalid character :Try again\n");
            goto repeate;
        }
    }
    pre = fopen("pre.txt", "w");
    ab = fopen("abs.txt", "w");

    for (int x = 0; x < last; x++)
    {
        fprintf(pre, "%d ", present[x]);
    }
    for (int x = 0; x < last; x++)
    {
        fprintf(ab, "%d ", absent[x]);
    }
    fclose(pre);
    fclose(ab);
    pause();
}

void adminView()
{
    changecolor(12);

    int choose;

    do
    {
        printf("\n********Main Menu*********\n");
        printf("Enter 1 to  add a student\n\n\n\n\n");
        printf("Enter 2 for marking attendance\n\n\n\n\n");
        printf("Enter 3 for checking attendance\n\n\n\n\n");
        printf("Enter 4 for removing a student\n\n\n\n\n");
        printf("Enter 5 for logout\n\n\n\n\n");
        printf("Please choose any menu: ");
        fflush(stdin);
        scanf("%d", &choose);
        switch (choose)
        {
        case 1:
            wait();
            addStudent();
            break;
        case 2:
            wait();
            markattendance();
            break;
        case 3:
            wait();
            viewattendance();
            break;
        case 4:
            wait();
            removeStudent();
            break;
        case 5:
            wait();
            login();
            break;
        }
    } while (choose != 5);
}
void teacher_login()
{
    system("cls");
    int i, s = 0;
    char name[20], password[20], p;
    char ID[20] = {
        "harsh"};
    char tPASS[20] = {
        "harsh"};
    changecolor(14);
    printf("\n\n\t\t\t\t\t  ===Teacher's Portal===\n\n\n\n\n");
    changecolor(45);
    changecolor(11);
    printf("\n\n\t\t\t\t\tYou must log in first\n");
    changecolor(6);
    printf("\n\n\t\t\t\t\t Enter ID: ");
    changecolor(3);
    gets(name);
    changecolor(6);
    printf("\n\n\t\t\t\t\tPassword: ");
    changecolor(3);
    while (p != 13)
    {
        p = _getch();
        if (p != 13)
        {
            putch('*');
            password[s] = p;
            s++;
        }
    }
    password[s] = '\0';
    if (strcmp(ID, name) == 0)
    {
        if (strcmp(tPASS, password) == 0)
        {
            changecolor(11);
            printf("\n\n\n\t\t\t\t\tLog in sucessful\n");
            Sleep(1500);
            system("cls");
            wait();
            system("cls");
            adminView();
        }
        else
        {
            changecolor(4);
            printf("\n\n\t\t\t\tPlease Enter valid ID and Password\n");
            Sleep(3000);
            changecolor(45);
            teacher_login();
        }
    }
    else
    {
        changecolor(4);
        printf("\n\n\t\t\t\tPlease Enter valid ID and Password\n");
        Sleep(3000);
        changecolor(45);
        teacher_login();
    }
}

void student_login()
{
    system("cls");
    int i, s = 0;
    char name[20], password[20], p;
    char ID[20] = {
        "harsh"};
    char tPASS[20] = {
        "harsh"};
    changecolor(14);
    printf("\n\n\t\t\t\t\t  === Student's portal===\n\n\n\n\n");
    changecolor(45);
    changecolor(11);
    printf("\n\n\t\t\t\t\tYou must log in first\n");
    changecolor(6);
    printf("\n\n\t\t\t\t\t Enter ID: ");
    changecolor(3);
    gets(name);
    changecolor(6);
    printf("\n\n\t\t\t\t\tPassword: ");
    changecolor(3);
    while (p != 13)
    {
        p = _getch();
        if (p != 13)
        {
            putch('*');
            password[s] = p;
            s++;
        }
    }
    password[s] = '\0';
    if (strcmp(ID, name) == 0)
    {
        if (strcmp(tPASS, password) == 0)
        {
            changecolor(11);
            printf("\n\n\n\t\t\t\t\tLog In Successful\n");
            Sleep(1500);
            system("cls");
            wait();
            system("cls");
            viewattendance();
        }
        else
        {
            changecolor(4);
            printf("\n\n\t\t\t\tPlease Enter valid ID and Password\n");
            Sleep(3000);
            changecolor(45);
            student_login();
        }
    }
    else
    {
        changecolor(4);
        printf("\n\n\t\t\t\tPlease Enter Correct ID and Password\n");
        Sleep(3000);
        changecolor(45);
        student_login();
    }
}

void login()
{
    char req;
    system("cls");
    changecolor(26);
    printf("\n\n\n\t\t                             WELCOME TO                           \n");
    printf("\t                          STUDENT ATTENDANCE MANAGEMENT SYSTEM             \n\n\n");

    changecolor(35);
    printf("\n\n");
    printf("\t\t\t\t\t => 1. Log in as Teacher\n");
    printf("\t\t\t\t\t => 2. Log in as Student\n");
    changecolor(10);
    printf("\t\t\t\t\t Select an Option:");
    req = getche();
    changecolor(12);
    position(70, 25);
    changecolor(45);
    position(59, 14);
    switch (req)
    {
    case '1':
        teacher_login();
        break;
    case '2':
        student_login();
        break;

    default:
        printf("\n  INVALID KEYWORD. PLEASE TRY AGAIN\n");
        Sleep(1000);
        login();
    }
}
int main()
{
    changecolor(45);
    // for copying name from file to array
    update1();
    //for copying prsent data from file to array

    update2();
        //for copying absent data from file to array
    update3();
    login();
}