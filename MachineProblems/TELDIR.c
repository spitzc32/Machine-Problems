/*
CREATED BY: SPITZC32

*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char name[MAX_SIZE];
    char address[MAX_SIZE];
    char Telephone[10];
}Records;

void get_init_list(Records *); // gets initial list
void sorter(int, Records *); // checks input and sorts array in order
void update_records(Records *); //encoder for records
void delete(char *, int, Records *);
void decorator(); //wrapper like in python

//variables

int size, noOfUp, del=0;


int main()
{
    puts("ENTER SIZE: ");
    scanf("%d", &size);
    puts("ENTER NUMBER OF UPDATES");
    scanf("%d", &noOfUp);
    Records r[size+noOfUp];
    
    printf("%d\n",sizeof(r));
    get_init_list(r);
    update_records(r);
    
    printf("\t\t\t\t\tINFORMATION\t\t\t\t\n");
    printf("|\tNAME\t\tADDRESS\t\tTELEPHONE\t|\n");
    printf("%d\n", del);
    for (int i=0;i<size+noOfUp-del;i++){
        if (!isalnum(r[i].name[0])){break;}
        printf("|\t %s \t %s \t %s \t|\n",r[i].name,r[i].address,r[i].Telephone);
        
    }
    
    puts("  ___________________________________________________________________");
    
    
    
    
    return 0;
}

void get_init_list(Records * r){
    char name[MAX_SIZE];
    for(int i=0; i< size; i++){   
        if (i == 0){fgets(name, MAX_SIZE, stdin);}
        puts("name(last,first,middle)");fgets(r[i].name, MAX_SIZE, stdin);
        puts("street address");fgets(r[i].address, MAX_SIZE, stdin);
        puts("phone number");fgets(r[i].Telephone, 10, stdin);
      
        sorter(i, r);
    }
    
}



void sorter(int i, Records * r){
    int didSwap = 1;
    Records  temp;
    while (didSwap) {
        didSwap = 0;
        for (; i > 0; i--) {
            if (strcmp (r[i].name, r[i-1].name) < 0) {
                temp  = r[i];
                r[i]   = r[i-1];
                r[i-1] = temp;
                didSwap = 1;
            }
        }
       
    }
    
}

void update_records(Records * r){
    char codeE [3] = "ID";
    char code;
    
    for (int i =size; i< size+noOfUp-del; i++){
        puts("ENTER CODE:");scanf(" %c", &code);

        if(code == 'I' || code == 'i'){
            fgets(r[i].name, MAX_SIZE, stdin);
            puts("name(last,first,middle)");fgets(r[i].name, MAX_SIZE, stdin);
            puts("street address");fgets(r[i].address, MAX_SIZE, stdin);
            puts("phone number");fgets(r[i].Telephone, 10, stdin);
            sorter(i, r);
        }
        else if (code == 'D' || code == 'd'){
            char name[MAX_SIZE], address[MAX_SIZE], Telephone[10];
            fgets(r[i].name, MAX_SIZE, stdin);
            puts("name(last,first,middle)");fgets(name, MAX_SIZE, stdin);
            puts("street address");fgets(address, MAX_SIZE, stdin);
            puts("phone number");fgets(Telephone, 10, stdin);
            delete(name, i, r);
            ++del;
            i--;
            
        }
        else {
            puts("ERROR INVALID CODE.");
            break;
        }
    }
    
}

void delete(char * name, int i, Records * r){
    int j = 0;
    while(strcmp(name, r[j].name) != 0){
        if (j >= i){
            printf("Error Not Found");
            return;}
        j++;    
    }
    
    for (; j < size+noOfUp; j++){
        r[j] = r[j + 1];
    }
    
    
    
    
}
