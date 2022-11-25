#include <stdio.h>

int main(void) {
  float a, b, k, x, y, z, w, i, j, n, s, deg1, deg2, fact, pow, cos, sin, tan;
	char type;
	int check = 1;	//starting while

	while(check==1){	//loop to keeep asking
		printf("Type 'r' for radians and 'g' for degrees: ");
		scanf(" %c", &type);

		if(type=='r'){
			printf("\nEnter the angle in radians: ");
			scanf("%f", &x);
			check = 0;	//end loop
			
			deg1 = x * 180/3.14159265359;	//converting radians to degrees for final display

			while(deg1>360){	//the program loses accuracy with angles greater than 360
				deg1 = deg1 - 360;	//reducing it
				x = deg1 * 3.14159265359/180;	//conveting degrees to radians
			}

			k = x - (90 * 3.14159265359/180);	//calculating the complementary angle in radians
		}
		else{
			if(type=='g'){
			printf("\nEnter the angle in degrees: ");
			scanf("%f", &deg1);
			check = 0;	//end loop

			while(deg1>360){
				deg1 = deg1 - 360;
			}

			x = deg1 * 3.14159265359/180;	//conveting degrees to radians

			deg2 = deg1 - 90;	////calculating the complementary angle to find sin

			k = deg2 * 3.14159265359/180;	//complementary from degrees to radians
			}
			else{
			printf("\nUnfortunately what you typed is not 'g' or 'r'.\n");
			}
		}
	}

	y = -1;	//changes the sign of each term in the sequence
	w = 0;	//2-in-2 counter
	cos = 0; 
  
	a = -1;	//variables that will be used in the calculation of the cosine of the complement
	b = 0;	//same preparation of the variables for operation with the complementary angle
	sin = 0;

	printf("\ncos(x) sequence:\n");

	for(i=1; i<=25; i++){
		y = y * (-1);	//alternating the sign
		fact = 1;	//factorial and power will be used in multiplication, so they get 1
		pow = 1;	//and need to be reset in the first for
		if(i==1){
			n = 1;	//the first number must equal 1, since (x^0)/(0!)=1
		}
		else{	//otherwise
			w = w + 2;
			for(z=w; z>=1; z=z-1){	//factorial
				fact = fact * z;
			}
			for(j=1; j<=w; j++){	//power
				pow = pow * x;
			}
			n = y * pow/fact;
		}
		cos = cos + n;	//sum
		printf("+ (%.5f) ", n);
	}

	printf("\n\ncos(complementary) = sen(x) sequence:\n");

	for(i=1; i<=25; i++){
		a = a * (-1);
		fact = 1;
		pow = 1;
		if(i==1){
			s = 1;
		}
		else{
			b = b + 2;
			for(z=b; z>=1; z=z-1){
				fact = fact * z;
			}
			for(j=1; j<=b; j++){
				pow = pow * k;
			}
			s = a * pow/fact;
		}
		sin = sin + s;
		printf("+ (%.5f) ", s);
	}

	tan = sin/cos;	//property: tan(x) = sin(x)/cos(x)

	if((deg1/90 == 1) || (deg1/90==3)){	//checks if tan exists
		printf("\n\ncos(%.2frad or %.1f°) = %.3f.", x, deg1, cos);
		printf("\nsin(%.2frad or %.1f°) = %.3f.", x, deg1, sin);
		printf("\ntan(%.2frad or %.1f°) doesn't exist.", x, deg1);
	}
	else{
		printf("\n\ncos(%.2frad or %.1f°) =: %.3f.", x, deg1, cos);
		printf("\nsin(%.2frad or %.1f°) = %.3f.", x, deg1, sin);
		printf("\ntan(%.2frad or %.1f°) = %.3f.", x, deg1, tan);
	}
}