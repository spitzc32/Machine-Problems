/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

typedef struct {
    char name[MAX_SIZE];
    char address[MAX_SIZE];
    char Telephone[10];
    struct Records * next;
}Records;

//methods
void get_init_list(); // gets initial list
void insert(); // pangtamad at pangpaganda
void sort(); //para sa mga maarteng cleanfreaks
void delete(char *); // malamang sa malamang
void update_records(); //encoder for records


//variables
Records *r, *head, *tail;
int size= 0, noOfUp, del=0;


int main(){
    get_init_list();
    update_records();
    
    r = head;
    
    while (r != NULL){
        puts(r->name);
        puts(r->address);
        puts(r->Telephone);
        r = r->next;
        
    }
    

}

void get_init_list(){
    char ans = 'Y';
    while (ans == 'Y'){
        r = (Records *)malloc(sizeof(Records));
        insert();
    	sort();
        puts("Another Y/N?");
        scanf(" %c", &ans);
        if (ans != 'Y'){break;}
        size++;
       
    }
    
}

void insert(){
    printf("Enter name: ");
	scanf(" %[^\n]", r->name);
	printf("Enter address: ");
	scanf(" %[^\n]", r->address);
	printf("Enter phone: ");
	scanf(" %[^\n]", r->Telephone);
    
    r->next = NULL;
}

void sort(){
    Records * curr,* currN;
    
    if (head == NULL || strcmp(head->name, r->name) > 0){
    	    r->next = head;
    		head = r;
    	}
    	else{ 
    	    curr = head;
    	    currN = curr->next;
    	    while(curr->next != NULL && strcmp(currN->name, r->name) < 0 ){
    	        curr = curr->next;
    	        currN = currN->next;
    	    }
    	    r->next = curr->next;
    		curr->next = r;
    		
    	}
    	tail = curr->next;
}

void delete(char * name){
    Records *curr = head, *prev, *next;
    while (curr !=NULL){
        if (strcmp(name, curr->name) == 0){
            next = curr->next;
            curr = prev;
            curr->next = next; 
            
        }
        prev = curr;
        curr = curr->next;
    }
}
void update_records(){
    puts("UPDATES FOR THE INITIAL LIST");
    char ans= 'Y', code;
    while (ans == 'Y'){
        puts("ENTER CODE:");scanf(" %c", &code);
        if (code == 'I' || code == 'i'){
            r = (Records *)malloc(sizeof(Records));
            insert();
            sort();
        }
        else if (code == 'D' || code == 'd'){
            char name[MAX_SIZE], address[MAX_SIZE], Telephone[10];
            
            printf("Enter name: ");
            scanf(" %[^\n]", name);
            delete(name);
            printf("Enter address: ");
	        scanf(" %[^\n]", address);
        	printf("Enter phone: ");
        	scanf(" %[^\n]", Telephone);
        }
        else{
            puts("ERROR INVALID CODE.");
            break;
        }
        puts("Another Y/N?");
        scanf(" %c", &ans);
        if (ans != 'Y'){break;}
        
    }
    
    
}












