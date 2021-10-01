#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int snakeWaterGun(char user, char computer){
    // returns 1 if you win, -1 if you lose and 0 if draw
    // Condition for draw
    // Cases covered:
    // ss
    // gg
    // ww
    if(user == computer){
        return 0;
    }

    // Non-draw conditions
    // Cases covered:
    // sg
    // gs
    // sw 
    // ws
    // gw
    // wg
    

    if(user=='s' && computer=='g'){
        return -1;
    }
    else if(user=='g' && computer=='s'){
        return 1;
    }

    if(user=='s' && computer=='w'){
        return 1;
    }
    else if(user=='w' && computer=='s'){
        return -1;
    }

    if(user=='g' && computer=='w'){
        return -1;
    }
    else if(user=='w' && computer=='g'){
        return 1;
    }

}
int main(){
    char user, computer;
    srand(time(0));
    int number = rand()%100 + 1;

    if(number<33){
        computer = 's';
    }
    else if(number>33 && number<66){
        computer='w';
    }
    else{
        computer='g';
    }
    
    printf("Enter 's' for snake, 'w' for water and 'g' for gun\n");
    scanf("%c", &user);
    int result = snakeWaterGun(user, computer);
    if(result ==0){
        printf("Game draw!\n");
    }
    else if(result==1){
        printf("You win!\n");
    }
    else{
        printf("You Lose!\n");
    }
    printf("You chose %c and computer chose %c. ", user, computer);
    return 0;
}