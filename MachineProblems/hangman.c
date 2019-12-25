/*
    created by: spitzc32/neet
    problem: Hangman
    date created: 12/25/19
    
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printHanged();
void wordGen();
int checkWord(size_t, size_t);
int checkLetter();
int exists();
void mysteryEncoder(size_t, size_t);
void filter();
void game();
void clear();
void screen();

//variable section
char letterguess[10],errorLetter[6],letter[1], confirm[3];
char *word[10] = {"cat","dog","pig","deer","eft","wolf","wasp","newt","goose","prawn"};
int error=0, wordNum, con=1;


int main()
{
    while(con > 0){
        wordGen();
        screen();
        while(checkWord(strlen(word[wordNum]),strlen(letterguess))){
            
            if (error == 6){
                printf("\n-----------------\nThe secret word is \"%s\"",word[wordNum]);
                puts("\n-----------------GAME OVER-----------------");
                return 0;
            }
            game();
            
        }
    }
    printf("CON: %i", con);
    return 0;
    
}

void printHanged(){
    char *err[50] = {"\t+==+\n\t|\n\t|\n\t|\\","\t+==+\n\t|  o\n\t|\n\t|\\",
                    "\t+==+\n\t|  o\n\t|  |\n\t|\\","\t+==+\n\t|  o\n\t| /|\n\t|\\",
                    "\t+==+\n\t|  o\n\t| /|\\\n\t|\\","\t+==+\n\t|  o\n\t| /|\\\n\t|\\/",
                    "\t+==+\n\t|  o\n\t| /|\\\n\t|\\/ \\"};
    puts(err[error]);
}

void wordGen(){
    wordNum = rand() % 10;
}

int checkWord(size_t tot, size_t ltot){
    char *ptr = word[wordNum];
    int cl = 0; 
    for(int i=0;i < tot ; i++){
        for(int j=0; j< ltot;j++){
            if(letterguess[j] == ptr[i]){
                cl++;}
    
        }
    }
    //checking if the desired words are all there
    if (cl == tot){
        printf("\nYes! The secret word is \"%s\".\n Do you want to play again?\n", ptr);
        scanf("%s", confirm);
        if(!strcmp(confirm, "yes")){ 
            con =1;
            clear();
            screen();
        }
        else{con = 0;
            return 0;
        }
        
        }
    return 1;
}

int exists(){

    for(int i=0;i < strlen(letterguess) ; i++){
        if(letter[0] == letterguess[i]){
            return 1;}
    }
    
    return 0;
}

int checkLetter(){
    char *ptr = word[wordNum];
    
    for(int i=0;i < strlen(word[wordNum]) ; i++){
        if(letter[0] == ptr[i]){
            return 1;}
    }
    
    return 0;
    
}

void mysteryEncoder(size_t tot, size_t ltot){
    char *ptr = word[wordNum];
    int c = 0;
    for(int i=0;i < tot ; i++){
        for(int j=0; j< ltot;j++){
            if(letterguess[j] == ptr[i]){
                printf(" %c ",ptr[i]);c = 1;
                break;}
            else{
                c=0;}
        }
        
        if(c == 0){
            printf(" _ ");}
    }
}

void filter(){
    if (checkLetter()){ 
        strcat( letterguess, letter);
    }
    else{
        error++;
        strcat(errorLetter, letter);
    }
    
}

void game(){
    puts("\nGuess a letter.");
    scanf(" %c", &letter[0]);

    if(exists()){
        error++;
        strcat(errorLetter, letter);
        screen();
        }
    else {
        filter();
        memset(&letter[0],0,sizeof(char));
        screen();

    }
    
        
    memset(&letter[0],0,sizeof(char));
}

void screen(){
    puts("HANGMAN\n");
    printHanged();
    if (error < 6){
        if (letterguess == NULL){
            printf("missed letters: ");}
        else{
            printf("missed letters: %s\n", errorLetter);} 
        printf("Mystery Word ");
        mysteryEncoder(strlen(word[wordNum]),strlen(letterguess));
    
        if(exists())
            puts("\nYou already entered that letter. try again.");
    }
}

void clear(){
    memset(&letter,0,sizeof(char*));
    memset(&letterguess,0,sizeof(char*));
    memset(&errorLetter,0,sizeof(char*));
    memset(&confirm,0,sizeof(char*));
    wordGen();
    error = 0;
    con = 1;
}





