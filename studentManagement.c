#include<stdio.h>
#include<conio.h>
#define MAX 100
int totalStudent = 0; // total no. of student

struct student
{
    int rno;
    char name[30];
    float per;
};

struct  student st[MAX]; // array to store the details of all students


// add details function
void addStudent(){
    if(totalStudent > 100) printf("Seat Full\n");
    else{
        char ch;
        while (1){
            printf("\nEnter the Roll number of Student: ");
            scanf("%d",&st[totalStudent].rno);
            printf("Enter the Name of Student: ");
            scanf("%s",st[totalStudent].name);
            printf("Enter the Percentage of Student: ");
            scanf("%f",&st[totalStudent].per);
        
            totalStudent++; // add student then increment the total number of student
            printf("\n");
            printf("Enter m/M for main menu OR N/n for add more student:\n ");
            ch = getch();
            if(ch=='m'|| ch=='M'){
                break;
            }
        }
        
    }
}


//display the details of the students 
void display(){
    if(totalStudent == 0) printf("No data available\n");
    else{
        printf("\n--------------------------------------------------\n");
        printf("RollNo.\t|\tName\t|\tPercentage\t|\n");
        printf("\n--------------------------------------------------\n");

        for(int i=0; i<totalStudent; i++){
            printf("%d\t\t%s\t\t%f\n",st[i].rno, st[i].name, st[i].per);
        }
        printf("--------------------------------------------------\n");

    }
}

// updata the details of student
void update(){
     if(totalStudent == 0) printf("\nNo data available\n");
    else{
        int r,flag = -1;
        printf("\nEnter the roll no of student for updation: ");
        scanf("%d",&r);
        for(int i=0; i<totalStudent; i++){
            if(r == st[i].rno){
                flag = i;
                break;
            }
        }
        if(flag==-1) printf("\nRoll number not found\n");
        else{
            printf("\nEnter the Roll number of Student: ");
            scanf("%d",&st[flag].rno);
            printf("Enter the Name of Student: ");
            scanf("%s",st[flag].name);
            printf("Enter the Percentage of Student: ");
            scanf("%f",&st[flag].per);
        }
    }
}

// add data to a file
void addData(){
    FILE *fptr = NULL;
    fptr = fopen("C:\\Users\\annip\\OneDrive\\Desktop\\student_db\\data.txt","w");
    if(fptr == NULL) printf("file related issue\n");
    else{
        for(int i=0; i<totalStudent; i++){
            fprintf(fptr,"%d %s %f\n",st[i].rno,st[i].name,st[i].per);
        }
        printf("Data added to file\n");
        fclose(fptr);
    }
}

//load data from file
void loadData(){
    FILE *fptr = NULL;
    fptr = fopen("C:\\Users\\annip\\OneDrive\\Desktop\\student_db\\data.txt","r");
    if(fptr == NULL) printf("file related issue\n");
    else{
        while(fscanf(fptr,"%d %s %f",&st[totalStudent].rno,st[totalStudent].name,&st[totalStudent].per) != EOF){
            totalStudent++;
        }
        fclose(fptr);
    }
}

int main(){
    int choice;
    loadData(); // load the previous data from file
    
   do{
    printf("\n-------------MENU--------------\n");
    printf("Press 1 : ADD DETAILS\n");
    printf("Press 2 : DISPLAY DETAILS\n");
    printf("Press 3 : UPDATE DETAILS\n");
    printf("Press 4 : EXIT\n");
    printf("-------------------------------\n");

    printf("enter your choise: ");
    scanf("%d",&choice);

    switch (choice)
    {
    case 1: addStudent();
        break;
    case 2: display();
        break;
    case 3: update();
        break;
    case 4: addData();
            printf("exit");
        break;
    default: printf("INVALID CHOISE\n");
    }
   }while(choice != 4);

    return 0;
}