/*
	created by: Spitzc32/Neet
	date Modified: 10/18/19
	
	problem: Game of life
        Compiler:C11
	
*/
#include<stdio.h>
#include<stdlib.h>

int r,c,**b;
void getBoard(int **); //setting up the initial board
void initBoard(int**); // setting board to computing board to zero
int Xadd(int,int); //Accumulating the rows
int Yadd(int,int); //Accumulating the columns
int AdjTo(int**,int,int);// this is where the real game is counted 
void Game(int**); // gives the condition whether alive or dead
void display(int**,int);//Displays generation to generation 

int main(){
	
	int gen; 	
    puts("Enter the number of rows in the board: \n");
    scanf("%d",&r);

    puts("Enter the number of columns in the board: \n");
    scanf("%d",&c);

    puts("Enter the number of generations you wish to generate: \n");
    scanf("%d",&gen);

    b = calloc(r,sizeof *b);
    initBoard(b);
    
    getBoard(b);
    
    
    for(int i=1;i<=gen;i++){
	display(b,i);
	Game(b);
    }
    
    return 0;
}

void getBoard(int **b){
    char init [r][c];
    int c1 = c + 1;
    
    puts("Enter the board you want to start with (using X->blank or O->alive) press (;) to stop: ");
    for (int i=0; i<r;i++){
        if(fgets(init[i],c1,stdin) == '\n'){
            i--;
            continue;
        }
        else{
            printf("Scanning %d",i);
            fgets(init[i],c1,stdin);}
    }
    
    
    for(int i=0; i<r;i++){
        for(int j=0;j<c;j++){
            if(init[i][j] == 'X'){
                b[i][j] = 0;
                //printf("B[%d][%d]= %d \n", i,j,b[i][j]);
            }
            else{
                b[i][j] = 1;
                //printf("b[%d][%d]=%d \n",i,j, b[i][j]);
            }
            
        }
    }
    
    
}

void initBoard( int** b){
    for(int i=0;i<r;i++){
        b[i] =(int *) calloc(c,sizeof *b[i]);
    }
    
    
   
   
 
}

int Xadd(int i,int a){
    i+=a;
    while(i<0)
	i+=r;
    while(i>=r)
	i-=r;

    return i;  
}

int Yadd(int i,int a){
    i+=a;
    while(i<0)
	i+=c;
    while(i>=r)
	i-=c;

    return i;

}

adjTo(int**b,int i,int j){
    int count=0;
    
    for(int k=-1;k<=1;k++)
	    for(int l=-1;l<=1;l++)
	        if(k || 1)
		        if(b[Xadd(i,k)][Yadd(j,l)])
		        count++;
    return count;	
}

void Game(int ** b){
    
    int a,nBoard[r][c];

    for(int i=0; i<r; i++)
	for(int j=0; j<c; j++){
	    a = adjTo(b,i,j);

	    if(a == 2) nBoard[i][j] = b[i][j];
	    if(a == 3) nBoard[i][j] = 1;
	    if(a < 2)  nBoard[i][j] = 0;
	    if(a < 2)  nBoard[i][j] = 0;
	}  
    
    for(int i=0; i<r; i++)
	for(int j=0; j<c; j++)
		b[i][j] = nBoard[i][j];
	
}

void display(int **b,int gen){
    printf("\nGEN %d:\n",gen);
    for (int j=0; j<c; j++) {

	for (int i=0; i<r; i++) {
	    printf ("%c", b[i][j] ? 'O' : 'X');
	}

	printf ("\n");
    } 
}
