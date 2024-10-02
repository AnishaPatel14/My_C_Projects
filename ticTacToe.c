#include<stdio.h>
#include<windows.h>
#include<conio.h>

    //array of chars of tic tac toe
    char arr[3][3];
    int position;
    char CurrentPlayer = 'O';
    int row,col;
    int n = 0; 

    //set default value of tic tac toe
    void setup(){ 
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            arr[i][j] = ' ' ;
        }
    }
    }

    void display(){
        printf(" %c  | %c  | %c \n",arr[0][0], arr[0][1], arr[0][2]);
        printf("--------------\n");
        printf(" %c  | %c  | %c \n",arr[1][0], arr[1][1], arr[1][2]);
        printf("--------------\n");
        printf(" %c  | %c  | %c \n",arr[2][0], arr[2][1], arr[2][2]);
    }
    
    void SetPosition(){
         switch (position)
        {
        case 1: row = 0, col = 0; break;
        case 2: row = 0, col = 1; break;
        case 3: row = 0, col = 2; break;
        case 4: row = 1, col = 0; break;
        case 5: row = 1, col = 1; break;
        case 6: row = 1, col = 2; break;
        case 7: row = 2, col = 0; break;
        case 8: row = 2, col = 1; break;
        case 9: row = 2, col = 2; break;
        default:
           break;
        }
    }

    int checkWin(){
        if(arr[0][0]==CurrentPlayer && arr[0][1]==CurrentPlayer && arr[0][2]==CurrentPlayer) return 1;
        if(arr[1][0]==CurrentPlayer && arr[1][1]==CurrentPlayer && arr[1][2]==CurrentPlayer) return 1;
        if(arr[2][0]==CurrentPlayer && arr[2][1]==CurrentPlayer && arr[2][2]==CurrentPlayer) return 1;

        if(arr[0][0]==CurrentPlayer && arr[1][0]==CurrentPlayer && arr[2][0]==CurrentPlayer) return 1;
        if(arr[0][1]==CurrentPlayer && arr[1][1]==CurrentPlayer && arr[2][1]==CurrentPlayer) return 1;
        if(arr[0][2]==CurrentPlayer && arr[1][2]==CurrentPlayer && arr[2][2]==CurrentPlayer) return 1;
        
        if(arr[0][0]==CurrentPlayer && arr[1][1]==CurrentPlayer && arr[2][2]==CurrentPlayer) return 1;
        if(arr[0][2]==CurrentPlayer && arr[1][1]==CurrentPlayer && arr[2][0]==CurrentPlayer) return 1;
        
        return 0;
    }

int main(){
 setup(); 
 int i=0;
 while(i!=9){

    checkPos:
 system("cls"); // clear screen
 display();

 printf("Current Player = %c\n",CurrentPlayer);
 printf("Enter the position: ");
 scanf("%d",&position);

 if(position<1 || position>9){
    printf("Wrong position\n");
    getch();
    //sleep(1000);
    goto checkPos;
 }

    SetPosition();

    if(arr[row][col] == ' '){
        arr[row][col] = CurrentPlayer;
        i++;
        int c  = checkWin();
        if(c==1){
            system("cls");
            display();
            printf("player %c win the game\n",CurrentPlayer);
           // sleep(2000);
            printf("*****Thanks for playing*****\n");
            return 1;
        }
        if(n==0){
            CurrentPlayer = 'X';
            n=1;
        } else{
            CurrentPlayer = 'O';
            n=0;
        }

    }else {
        printf("element already available\n");
        getch();
       // sleep(1000);
        goto checkPos;
    }

 }
    system("cls");
    display();
    printf("Game Draw\n");  
    printf("*****Thanks for playing*****\n");
    //sleep(2000);

    
    return 0;
}