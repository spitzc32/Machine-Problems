#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int num;
	struct Node * next;
	
}Node;  

 Node *sum, *tail, *head;

//variables
char num1[22] = {0}, num2[22] = {0};
int size = sizeof(num1), carry = 0, i, n1,n2;

//methods
void printReverse( Node *,int);
void insert(Node *, Node *, Node *, int);


int main(){
	
	printf("enter the 1st number ");
	scanf(" %s",num1);
	printf("Enter the 2nd number ");
	scanf(" %s", num2);	
	
	tail= (Node*) malloc(sizeof(Node));
	head= (Node*) malloc(sizeof(Node));

	int len = (strlen(num1) > strlen(num2))? strlen(num1) : strlen(num2);
	
	for (i = 1; i <= len;i++){
		
		sum = (Node*) malloc(sizeof(Node));
		n1 =  (num1[strlen(num1)-i] >= 48 && num1[strlen(num1)-i] < 59 && strlen(num1)-i >= 0) 
		? (num1[strlen(num1)-i] - 48) : 0;
		n2 =  (num2[strlen(num2)-i] >= 48 && num2[strlen(num2)-i] < 59 && strlen(num2)-i >= 0) 
		? (num2[strlen(num2)-i] - 48) : 0;
		sum->num  = carry + (n1 + n2) ;
		
		if (i > 0){carry = (sum->num >= 10)? 1 : 0;}
		if (carry == 1){sum->num %= 10; }
		carry = 0;
		sum->next = NULL;
		if (i == 1){head = sum;}
		else{tail->next = sum;}
	
		tail = sum; 
	}
	if (carry == 1){
		sum->num = 1;
		sum->next = sum;
		tail = sum; 
		
	}
	
	
	sum = head;
	printReverse(sum, len);
	
	
	
	return 0;
	
	
}

void printReverse(Node* head_ref, int n) { 
    int j = 0; 
    Node * current = head_ref; 
    while (current != NULL) { 
   
        // For each node, print proper number 
        // of spaces before printing it 
        for (i = 0; i < 2 * (n - j); i++) 
            printf(" "); 
   
        // use of carriage return to move back 
        // and p,rint. 
        printf("%d\r", current->num); 
   
        current = current->next; 
        if (j == n){break;}
		
        j++; 
    } 
} 








