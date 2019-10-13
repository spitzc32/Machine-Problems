#include<stdio.h>
#include<stdlib.h>

int get_problem();
void  get2_pt (float *,float *,float *,float*);
void get_pt_slope (float *,float *,float *);
void slope_intcpt_from2_pt(float,float,float,float,float*,float*);
float intcpt_from_pt_slope(float,float,float);
void display2_pt (float,float,float,float);
void display_pt_slope(float,float,float);
void display_slope_intcpt(float,float);

int main (){
	int prob_no = get_problem();
	float x1, y1, x2, y2, slope, yInt, counter = 1;
	while(counter){
		switch (prob_no){
			case 1: 
				get2_pt (&x1, &y1, &x2, &y2);
				slope_intcpt_from2_pt(x1, y1, x2, y2, &slope, &yInt);
				display2_pt(x1, y1, x2, y2);	
				display_slope_intcpt(slope,yInt);
				break;
			case 2:
				get_pt_slope(&x1, &y1,&slope);
				intcpt_from_pt_slope(x1, y1,slope);
				display_pt_slope(x1, y1,slope);	
				display_slope_intcpt(slope,yInt);
				break;
		}
	}
} 
int get_problem(){

	int prob;

	puts("Select the form that you would like to convert to slope-intercept form: \n");
	puts("1) Two-point form (you know the points on the line) \n");
	puts("2) Point–slope form (you know the line’s slope and one point) \n");
	puts("=> ");
	scanf("%d", &prob);
	
	return prob;	
}

void get2_pt (float *x1,float *y1,float *x2,float*y2){
	puts("Enter the x-y coordinates of the first point separated by a space=>");
	scanf("%f%f", x1, y1);
	puts("Enter the x-y coordinates of the second point separated by a space=>");
	scanf("%f%f", x2, y2);
}

void get_pt_slope (float *x1,float *y1,float *slope){
	puts("Enter the slope=> ");
	scanf("%f", slope);
	puts("Enter the x-y coordinates of the point separated by a space=>");
	scanf("%f%f", x1, y1);

}

void slope_intcpt_from2_pt(float x1, float y1, float x2, float y2, float *slope,float *yInt){
	*slope = ;
	*yInt = ;
}

float intcpt_from_pt_slope(float x1, float y1, float slope){
	return ;
}

void display2_pt(float x1, float y1, float x2, float y2){
	printf("\nTwo-point form \n");
	printf("\t (%.2f - %.2f)\n",y2,y1);
	printf("m = ---------------\n");
	printf("\t (%.2f - %.2f)\n", x2,x1);
}

void display_pt_slope(float x1,float y1,float slope){
	puts("\nPoint-slope form \n");
	printf("y – %.2f = %.2f (x – %.2f)\n", y1,slope,x1);
}

void display_slope_intcpt(float slope, float yInt)
	puts("\nSlope-intercept form \n");
	(slope >= 0) ? printf("y = %.2fx + %.2f",slope,yInt) : printf("y = %.2fx - %.2f",slope,yInt)