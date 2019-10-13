#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

/* 
    created by: Neet/Spitzc32
    
    problem:Ohm(Machine Problem)
    
*/
int search(char arr[10][7], size_t size, char str[10]){
	
	for (int i=0;i<size;i++){
		if(!strcmp(arr[i],str)){
		    return i;}
	}
	return -1;
}

int main(){
	char COLOR_CODES[10] [7] = {"black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "gray", "white"};
	char Band[3][7];
	int counter =1,num1,num2,num3,result;
	while (counter){
	    char verify[1];
	    
		printf("Enter the colors of the resistor’s three bands, beginning with the band nearest the end. Type the colors in lowercase letters only, NO CAPS.\n");
		printf("Band 1 =>");
		scanf("%s", &Band[0]);
		printf("Band 2 =>");
		scanf("%s", &Band[1]);
		printf("Band 3 =>");
		scanf("%s", &Band[2]);
		
		num1 = search(COLOR_CODES,10,Band[0]);
		num2 = search(COLOR_CODES,10,Band[1]);
		num3 = search(COLOR_CODES,10,Band[2]);
		
		printf("%d, %d and %d\n", num1,num2,num3);
	
		if(num1 != -1 && num2 != -1 && num3 != -1){
			result = (num1 * 10 + num2)* pow(10,num3); 
			printf("Resistance value: %d kilo-ohms\n", result);
		}
		else{
			printf("Invalid color:%s\n", (num1 == -1)? Band[0]:(num2== -1)? Band[1]: Band[2]);
		}
	
		printf("Do you want to decode another resistor? => ");
		scanf(" %s", &verify);
		if(!strcmp("n",verify)){
		    break;
		}
	counter= 1;	
	}
	
    /* */
    return 0;
}

	