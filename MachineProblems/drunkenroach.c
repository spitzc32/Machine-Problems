#include <stdio.h>

/* 
    created by: Neet/Spitcz32
    compiler: C11
    
    Problem: Drunken Cockroach (random walk problem)
    Solution: Brute force Algorithm
    
    
    
*/
int n,m;
 //n= rows, m=columns, p = container array needed to be walked

int random(); // returns a random value that the cockroach needs to walk on 
int Cmoves(int[][m]); // checks if the roach walks on all the required tiles 
int bugMovement(int,int*,int*); // updates bugs current pos
int InRoom(int,int); // creates a wall so the bug wont go out of bounds
void Display(int[][m],int);




int main()
{
    
    int x,l,ibug,jbug,counter=0;
  
  puts("Enter the width of the room(between 2 & 40): ");
  scanf("%d", &n);
  
  puts("Enter the length of the room(between 2 & 20): ");
  scanf("%d", &m);
  
  while ((n<2) || (n> 40)){
        puts("Out of Bounds. Enter the width of the room(between 2 & 40): ");
        scanf("%d", &n);
  }
  
  while ((m<2) || (m> 20)){
        puts("Out of Bounds. Enter the length of the room(between 2 & 20): ");
        scanf("%d", &m);
  }
  
  puts("Enter the initial X position of the bug");
  scanf("%d", &ibug);
  puts("Enter the initial Y position of the bug");
  scanf("%d", &jbug);
  int p[n][m];
  memset(p, 0, sizeof p);;
  
  
  while((!Cmoves(p)) && (counter < 50000)){
      do{
          x = random();
          
      }
        
      while(!bugMovement(x,&ibug,&jbug));
      p[ibug][jbug]++;
      
      counter++;
  }
  
  display(p,counter);
     
    return 0;
}

int random(){
    return rand() % 8;
}

int Cmoves(int p[][m]){
    //returns true if cockroach walks at all tiles
    for(int i = 0;i<n;i++){
        for(int j=0;j<m;j++){
            if(p[i][j] == 0)
                return 0;
            
       }           
    }
    return 1;
}

int bugMovement(int x ,int* ibug, int* jbug){
    int iMovement[8] = {-1,0,1,1,1,0,-1,-1};
    int jMovement[8] = {1,1,1,0,-1,-1,-1,0};
    
    int moveI = *ibug + iMovement[x];
    int moveJ = *jbug + jMovement[x];
    
    if (InRoom(moveI, moveJ)){
       *ibug = moveI;
       *jbug = moveJ;
       
       return 1;                   
    }
    return 0;
         
}


int InRoom(int ibug,int jbug){
    //Checking if the cockroach is out of bound or not (legal moves)
    if (ibug >= n || ibug < 0 || jbug>= m || jbug < 0){
        return 0;
    }
    else{
         return 1;
    }         
}

void display(int p[][m],int counter){
     
     puts("Final Count ofthe number of steps the bug made during random walk: \n");
     for(int i =0; i < n; i++){
         for(int j = 0; j < m;j++){
               printf(" %d", p[i][j]);}
        printf("\n");
     }
     printf("Counted Number of steps: %d \n", counter);
     
}



