#include<stdio.h>
#include<conio.h> //for getch()
#include<math.h> //for rand() and srand()
#include<windows.h>//for system() and kbhit()
#include<time.h>//for time() in srand()
//setting the border size
#define row 20
#define col 30

/*-----------------------------------
variables as global variables, removing the need to pass them in each function
-----------------------------------*/
int i,j,k,g=0,spd=100;
int x=15,y=10,fx,fy,tn=1,sc=10;
int tx[200],ty[200];
char ch='w';
char tch='w';
char confirm;

/*-----------------------------------
display the game
*///-----------------------------------

void draw(){
    for(i=1;i<=row;i++){
        for(j=1;j<=col;j++){
//border coordinate check
//border is printed at 1 and end of row or col
            if(i==1||j==1||i==row||j==col){
                printf("#");
            }
//fruit coordinate check
            else if(i==fy && j==fx){
                printf("@");
            }
//check for snakes head coordinate
            else if(i==y && j==x){
                printf("O");
            }
//tail is printed
/*----------------------------------------
each tail takes the previous tail/heads position
tn(x,y)=tn-1(x,y)
------------------------------------------------
*/
            else{
                int p=0;
                if(tn>0){
                    for(k=0;k<tn;k++){
                        if(i==ty[k] && j==tx[k]){
                            printf("o");
                            p=1;
                            break;
                        }
                    }
                }
                if(!p){
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}

 
 void logic(){
 /*
 -------------------------------
 checking for the heads collision with the fruit
 ----------------------------------
 */
     if(x==fx && y==fy){
 //increasing tail no,and relocating the fruit
         tn++;
         fx=(rand()%col);
            fy=(rand()%row);
//checking if fruit is outside the playground and if true relocating it
            if((fx>=30)||(fy>=20) || (fx<=1) || (fy<=1)){
                if(fx<=1)fx=2;
                else if(fy<=1)fy=2;
                else if(fx>=30)fx=29;
                else if(fy>=20)fy=19;
            }
//increasing socre
        sc+=10;
     }
//giving coordinate to each tail
     if(tn>0){
         for(i=tn-1;i>0;i--){
             tx[i]=tx[i-1];
             ty[i]=ty[i-1];
         }
         tx[0]=x;
         ty[0]=y;
     }
 }
 /*
 -----------
 moving the character/snake with 
 w=up 
 a=left
 s=down
 d=right
 -----------
 */
 void move(){
     if (ch=='w' && tch!='s')tch=ch;
     else if (ch=='a' && tch!='d')tch=ch;
     else if (ch=='s' && tch!='w')tch=ch;
     else if (ch=='d' && tch!='a')tch=ch;
     switch(tch){
                case 'w':
                    y--;
                    break;
                case 'a':
                    x--;
                    break;
                case 's':
                    y++;
                    break;
                case 'd':
                    x++;
                    break;                                                    
                default:
                    break;
            }

            //checking for border collision
            if((x<=1)||(y<=1)||(x>=col)||(y>=row))g=1;
 }
 /*----------
 gmeOver: checks if the game is over
 only checks the heads collison with its tails as border collison is aleready accounted for above.
 
 --can be combined with function move();
 -----------
 */
 void gmeOver(){
     for(i=0;i<tn;i++){
         if(tn==1){
             
         }
         else{
         if(x==tx[i] && y==ty[i]){
         g=1;
         break;
     }
 }
     }
 }
 
 //main function---------------------
int main(){
    srand(time(NULL));//for random fruit value
    start:
    fx=(rand()%30);
    fy=(rand()%20);
    if((fx>=30)||(fy>=20) || (fx<=1) || (fy<=1)){
                if(fx<=1)fx=2;
                else if(fy<=1)fy=2;
                else if(fx>=30)fx=29;
                else if(fy>=20)fy=19;
            }
    do{
    while(g!=1){
//run the game while g==0
//g==game over value
        if(kbhit()){//checking for keyboard press
//if true takes the value pressed by getch()
            ch=getch();
        }
//clearing acreen to draw every frame in one place
        system("cls");
        draw();
        printf("score : %d",sc);
        logic();
        move();
        gmeOver();
//sleep controls the frame rate
//lower the value of sleep higher the frame rate and vice-versa
        Sleep(spd);    
    }
    if(g==1){
//asking the user if they want to continue the game.
        printf("\npress [y] to continue: ");
        scanf(" %c",&confirm);
        if(confirm=='y'){
//resetting the values if the game restarts
            g=0;
            x=15;
            y=10;
            tn=1;
            sc=0;
            goto start;//starting the game again
        }
}
}while(confirm=='y');


/*
NOTE-------------------

--DOESNOT WORK IN THE APPS TERMINAL(the app doesnot have the necessary header files and terminal),USE A SEPARATE APP(FOR MOBILE) OR DEFAULT C COMPILER/ONILE COMPILERS FOR PC

--THE SCORE DISPLAY CAN BE AFFECTED IN THE MOBILE BUT IS FINE IN PC.

--STILL NEEDS A FEW TWEAKS.

--FOR FREE USE AND EXPERIMENTS.
------------------------
*/



///by:  Crystal_
}
