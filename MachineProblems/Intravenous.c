#include <stdio.h>
#include <stdlib.h>
#include <math.h> 

/*
    created by: spitzc32
    compiler: C11
    
    problem: Intravenous(Machine Problem 2.1)
    
*/
int get_problem(); // in param
void get_rate_drop_factor(float *, float*); //out param
void get_kg_rate_conc(float*, float*,float*); //out param
void get_units_conc(float*, float*); //out param
float fig_drops_min(float, float);
float fig_ml_hr(float);
float by_weight(float, float,float);
float by_units(float, float);
 
int main(){
	// initializing the values needed 
	int prob_no = get_problem();
	float rateMl, dropFactor, numOfHrs, rateMG, weightKg, concentrationMg, rateHr,concentrationMl;
	
	while(prob_no != 5){
		  
		switch (prob_no){
			case 1: 
				get_rate_drop_factor(&rateMl, &dropFactor);
				printf("The drop rate per minute is %.2f \n", fig_drops_min(rateMl, dropFactor));	
				break;
			case 2:
				puts("Enter number of hours=> ");
				scanf("%f", &numOfHrs);
				printf("The rate in milliliters per hour is %.2f \n", fig_ml_hr(numOfHrs));	
				break;
			case 3:
				get_kg_rate_conc(&rateMG, &weightKg, &concentrationMg);
				printf("The rate in milliliters per hour is %.2f \n", by_weight(rateMG, weightKg, concentrationMg));	
				break;
			case 4:
				get_units_conc(&rateHr,&concentrationMl);
				printf("The rate in milliliters per hour is %.2f \n", by_units(rateHr,concentrationMl));	
				break;
			case 5:
				return 0;
			default:
				puts("Error please enter a valid problem number.");			
		}
		prob_no = get_problem();		 	
	}
 
	return 0;	
}

int get_problem(){
	//Displays the user menu, then inputs and returns as the function value the problem number selected

	int prob;
	puts("Enter the number of the problem you wish to solve. \n");
	puts("GIVEN A MEDICAL ORDER IN CALCULATE RATE IN \n"); 
	puts("(1) ml/hr & tubing drop factor drops / min\n"); 
	puts("(2) 1 L for n hr ml / hr\n"); 
	puts("(3) mg/kg/hr & concentration in mg/ml ml / hr \n");
	puts("(4) units/hr & concentration in units/ml ml / hr\n"); 
	puts("(5) QUIT \n Problem => \n");
	scanf("%d", &prob);
	
	return prob;
}

void get_rate_drop_factor(float* rate, float* dropfactor){
	// Prompts the user to enter the data required for problem 1
	puts("Enter rate in ml/hr=> ");
	scanf("%f", rate);
	puts("Enter tubing’s drop factor (drops/ml)=> ");
	scanf("%f", dropfactor);	
} 

void get_kg_rate_conc(float *rateMG, float * weightKg, float *concentrationMg){
	// Prompts the user to enter the data required for problem 3

	puts("Enter rate in mg/kg/hr=> ");
	scanf("%f",rateMG);
	puts("Enter patient weight in kg=> ");
	scanf("%f",weightKg);
	puts("Enter concentration in mg/ml=> ");
	scanf("%f",concentrationMg);
}

void get_units_conc(float *rateHr, float *concentrationMl){
	// Prompts the user to enter the data required for problem 4
	
	puts("Enter rate in units/hr=> ");
	scanf("%f", rateHr);
	puts("Enter concentration in units/ml=> ");
	scanf("%f", concentrationMl);
}

float fig_drops_min(float rate, float dropFactor){
	return round((rate/60)*dropFactor);
}

float fig_ml_hr(float numOfHrs){
	return round(1000 / numOfHrs);
}

float by_weight(float rate , float weight ,float concentration){
	return round(weight/concentration * rate);
}

float by_units(float rate, float concentration){	
	return round(rate/concentration);
}
