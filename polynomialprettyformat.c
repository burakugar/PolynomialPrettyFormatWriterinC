#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* BURAK UGAR HW 4 200104004100 */
int isInteger(float x){
	if (x == (int)x) /* function decide whether given value is integer or not with using typecast */
	{
   return 1;
	}
	else
	return 0;
}
int countDigit(int x)
{
    int counter = 0; /* function counting the number of digits */
    for(x=x;x!=0;x/=10){
    	counter++;
	}
	return counter;
}

/* this function takes 3 significant digit of the given float value and round it to closest tenth with using ceil and log functions according to formula in wikipedia*/
double round_to_digits(double value) 
{	int significant_digits=4;
	double factor,result;
    if (value == 0.0) /* since log0 is undefined return the value's itself if it is 0 */
        return 0.0;
     factor = pow(10.0, significant_digits - ceil(log10(fabs(value))));
    result= round(value * factor) / factor;
    return result;
}
void write_polynomial(){
	float coef;
	int exp;
	int i,a=5;
	int flag;
	char space;
	int count=0; /* exponent is the degree of the polynomial */
	printf("Enter your polynomial [n a_n a_n-1 a_n-2 ... a_0]:"); /* taking the inputs from the user */
	scanf("%d%c",&exp,&space);
	i=exp; /* i is the exponents itself */
	t: 
	do{
	scanf("%f%c",&coef,&space); /* since user will enter \n at the end of the input we have to scanf till confront the char \n */
	coef=  round_to_digits(coef); /* rounding off the coefficients */
	if(coef==0){ /* if coefficient is 0 then increase the counter */
		count++;
		if(count==exp+1) /* if counted zeros are equals to term number+1 then we now all the terms are 0 there is no need to printf */
		printf("0.0");
			}
	 if(coef==0){
	 	i--; /* if the coefficient is 0 then decrease the exponent by 1 and recur down for other elements which have nonzero coeefficients */
	 	goto t;
	 }
	 
	 else if(coef!=0 && a==5){
	 	flag=i; /* flag is used for determining first nonzero element i use a to point out that we have already found the nonzero element so there is no need to enter the 
	 	else if */
	 	a=4;
	 }
	
	 	if(i==0 && coef != 0.0 ){ /* if the coeeficient is not zero but we are on the constant element */ 
			if(coef==1){
			printf("+1");	/*  if it's coefficient is 1 then print 1 if -1 then -1 */
			    }	
				else if(coef== -1){
				printf("-1");
				}
				   else{
				      if(coef<0){ /* if the coeefs are different than 1 or -1 than search but coef is less than 0 */
							printf("%.1f",coef);	/* if it is different from 1 or -1 like -2.4 then we have to printf it as coefficient */
					   }
				      else{
					  	 /* if the coeefs are different than 1 or -1 than search but coef is greater than 0 */
			              	printf("+%.1f",coef); 
			               }
			           }
		              }
		
		 if(coef<0.0 && i!=0 ){
				if(coef==-1 && i==1 ){ /*if any element has a -1 coeff and its degree is 1 then print is as -x */
			    printf("-x");
			   }
				else if(coef!=-1 && i==1){ /*if any element does not have -1 as a coeff and its degree is 1 then print it as -2x */
				      		printf("%.1fx",coef);
			   }
				else if(coef==-1 && i!=1){
				printf("-x^%d",i); /*if any element does have -1 as a coeff and its degree is not 1 then print it as -x^2 */
				}
				else{
							printf("%.1fx^%d",coef,i); /* other than above will be printed as -2x^2*/       
			   }
			   i--;
			}
		else if(coef>0.0 && i!=0 ){
			if(coef==1 && i==1){ /*if any element has a +1 coeff and its degree is 1 then print is as +x */
			    if(i==flag){
			    	printf("x");
				}
				else{
					printf("+x");
					}
			   }
				else if(coef!=1 && i==1){ /*if any element does not have 1 as a coeff and its degree is 1 then print it as 2x */
			    	if(i==flag){
			    			printf("%.1fx",coef);
					}
					else{
							printf("+%.1fx",coef);
			   			}
			   }
				else if(coef==1 && i!=1){
					if(i==flag){
					printf("x^%d",i);
					}
					else{
					printf("+x^%d",i); /*if any element does have 1 as a coeff and its degree is not 1 then print it as x^2 */
					}
				}
				else{
					if(i==flag){
							printf("%.1fx^%d",coef,i); /* other than above will be printed as +2x^2*/ 
					}
					else{
							printf("+%.1fx^%d",coef,i); /* other than above will be printed as +2x^2*/     
						}
			   }
			i--; /* decreasing the exponenets */
			}
			 if(count==exp+1 ){
				printf("0.0"); /* if all the elements are 0 then print 0.0 */
			}
		
}
	while(space != '\n'); 
	
}int main(){
    return 0;
}