#include <stdio.h>

/* 
    created by: Neet/Spitcz32
    compiler: C11
    
    Problem: Drunken Cockroach (random walk problem)
    Solution: Brute force Algorithm
    
    
    
*/
int n,m,**p; //n= rows, m=columns, p = container array needed to be walked

int random(int,int); // returns a random value that the cockroach needs to walk on 
int Cmoves(int**); // checks if the roach walks on all the required tiles 
int bugMovement(int,int*,int*); // updates bugs current pos
void ArrInit(int**); // initializes the array
int InRoom(int,int); // creates a wall so the bug wont go out of bounds
void Display(int**,int);




int main()
{
    
    int x,l,imv,jmv,counter=0;
  
  puts("Enter the width of the room(between 2 & 40): ");
  scanf("%d", &n);
  
  puts("Enter the length of the room(between 2 & 20): ");
  scanf("%d", &m);
  
  while ((n<2) || (n> 40)){
        puts("Out of Bounds. Enter the width of the room(between 2 & 40): ");
        scanf("%d", &n);
  }
  
  while ((n<2) || (n> 20)){
        puts("Out of Bounds. Enter the length of the room(between 2 & 20): ");
        scanf("%d", &m);
  }
  
  p = calloc(n,sizeof *p);
  
  
  ibug = n/2;
  jbug = m/2;
  
  
  ArrInit(p);
  
  while((!Cmoves(p)) && (counter < 10000)){
      do{
          x = random(1,8);
          
      }
      while(!bugMovement(x,&ibug,&jbug));
      p[ibug][jbug]++;
      
      counter++;
  }
  display(p,counter);
     
    return 0;
}

int random(int i, int j){
    return rand() % (j-i+1) + i;
}

int Cmoves(int **p){
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

void ArrInit(int **p){
    for(int i = 0; i < m; i++)
       p[i] = (int *) calloc (m,sizeof(*p[i]));

    for(int i = 0; i < n; i++){ 
       for(int j = 0; j < m; j++){
           p[i][j] =0;
        }
   }
			
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

void display(int **p,int counter){
     
     
     for(int i =0; i < n; i++){
         for(int j = 0; j < m;j++){
               printf("p[%d],[%d] = %d \n",i,j, p[i][j]);}
     }
     printf("Counted Number of steps: %d \n", counter);
     
}


