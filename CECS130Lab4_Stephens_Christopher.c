/*
	Author Information: Christopher Stephens 
						CSE 130-01 Lab Section B
	Lab #4 
	Date: 2/11/2022
	Program Description: This program simulates a calculator much like the last lab, except this calculator utilizes functions and arrays
*/

#include <stdio.h>

float additionFunc(float, float); // addition function prototype
float subtractionFunc(float, float); //subtraction function prototype
float multiplicationFunc(float, float);//multiplication function prototype
float divisionFunc(float, float);//division function prototype
int remainderFunc(int, int);//remainder function prototype
int primeFunc(int);//prime function prototype
int factorialFunc(int);//factorial function prototype
float powerFunc(float, float);//power function prototype
int fibonacciFunc(int);//fibonacci function prototype


int main()
{
	float one = 1;
	int menuOption, dividend2, divisor2, modulus, isPrime, isPrime2, iFactorial, iFibonacci;// initializing int variables
	float addition1, addition2, subtraction1, subtraction2, multiplicand, multiplier, dividend, divisor, integer, power, fInteger, fPower;//initializes float variables
	//a do while loop is used because I need to output the menu to the user at least once
	do {
		//Giving intructions to the user and accepting their input
		printf("\n \n Calculator Menu \n");
		printf("(1) Addition \n");
		printf("(2) Subtraction \n");
		printf("(3) Multiplication \n");
		printf("(4) Division \n");
		printf("(5) Modulus (integers only) \n");
		printf("(6) Test if prime (integers only) \n");
		printf("(7) Factorial (integers only) \n");
		printf("(8) Power \n");
		printf("(9) Fibonacci Sequence \n");
		printf("(10) Exit \n");
		printf("\n Please enter the number of the operation you wish to perform:");
		scanf("%d", &menuOption);
		//used swich case cause it looks better
		switch(menuOption)
		{
			//addition case
			case 1:
				printf("\n Please enter the first number:");
				scanf("%f", &addition1);
				printf("\n Please enter the second number:");
				scanf("%f", &addition2);
				// I call the function and pass 2 parameters
				printf("\n %.2f + %.2f = %.2f \n", addition1, addition2, additionFunc(addition1, addition2));//I call the fucntion
				break;
			//subtraction case
			case 2:
				printf("\n Please enter the number you want to subtract from:");
				scanf("%f", &subtraction1);
				printf("\n Please enter the number you want to subtract from the previous number:");
				scanf("%f", &subtraction2);
				//I call the function and pass 2 parameters
				printf("\n %.2f - %.2f = %.2f \n", subtraction1, subtraction2, subtractionFunc(subtraction1, subtraction2));//i call the fucntion
				break;
			//multiplication case
			case 3: 
				printf("\n Please enter the multiplicand:");
				scanf("%f", &multiplicand);
				printf("\n Please enter the multiplier:");
				scanf("%f", &multiplier);
				//I call the function and pass 2 parameters
				printf("\n %.2f * %.2f = %.2f \n", multiplicand, multiplier, multiplicationFunc(multiplicand, multiplier));
				break;
			//fix it so the user cannot divide by 0
			case 4: 
				printf("\n Please enter the dividend:");
				scanf("%f", &dividend);
				printf("\n Please enter the divisor:");
				scanf("%f", &divisor);
				if(divisor == 0)//I do this so the user cannot divide by 0 and asks them to try again
				{
					printf("Division by 0 is impossible. Please try again");
					break;
				}
				else
				{
					//call the function and pass two parameters
				printf("\n %.2f / %.2f = %.2f \n", dividend, divisor, divisionFunc(dividend, divisor));
				break;
				}
			
			//modulus case
			case 5:
				printf("\n Please enter the dividend: ");
				scanf("%d", &dividend2);
				printf("\n Please enter the divisor: ");
				scanf("%d", &divisor2);
				printf("\n The remainder is %d \n", remainderFunc(dividend2, divisor2));
				break;
			
			//for this case I test if a number is prime
			case 6: 
				printf("\n Please enter a number to test: ");
				scanf("%d", &isPrime);
				printf(primeFunc(isPrime));
				break;
			//factorial case
			case 7:
				printf("Please enter a number: ");
				scanf("%d", &iFactorial);
				//calliing the factorial function
				printf("%d factorial is %d \n", iFactorial, factorialFunc(iFactorial));
				break;
			//power function case
			case 8:
				printf("Please enter a number: ");
				scanf("%f", &fInteger);
				printf("Please enter the power you would like it raised to: ");
				scanf("%f", &fPower);
				//calling the factorial function and passing 2 parameters
				if(fPower == 0)// checks if the power is zero, to make sure it doesn't screw up
				{
					printf("%.f raised to the power of %.f is %.f \n", fInteger, fPower, one);
				}
				else 
				{
					printf("%.f raised to the power of %.f is %.f \n", fInteger, fPower, powerFunc(fInteger, fPower));
				
				}
				break;
			case 9://fibonacci case
				printf("How many elements of the Fibonacci sequence would you like to see: ");
				scanf("%d", &iFibonacci);
				//calls the fibonacci function and passes a parameter
				printf(fibonacciFunc(iFibonacci));
				break;
			//this case exits the case swtich statement
			case 10: 
				printf("\n See ya");
				break;
			//this case will be used if the user does not enter a valid operation number	
			default:
				printf("\n The operation you chose does not exist. Please select another below. \n");
				break;
			
			
		}
		
		
	}
	while(menuOption != 10);//this loop makes sure the program will continue until 10 is chosen
	return 0;	
}
float additionFunc(float fAppend1, float fAppend2)//addition funtion will accept 2 float values input by the user
{
	return fAppend1 + fAppend2;//returned to the function when called
}
float subtractionFunc(float fMinuend, float fSubtrahend)//subtraction function wil accept 2 float values input by the user
{
	return fMinuend - fSubtrahend;
}
float multiplicationFunc(float fMultiplication1, float fMultiplication2)//multiplication function will accept 2 float values input by the user
{
	return fMultiplication1 * fMultiplication2;
}  
float divisionFunc(float fDivision1, float fDivision2)//division function will accept 2 float values
{
	return fDivision1 / fDivision2;
}       
int remainderFunc(int iRemainder1, int iRemainder2)//remainder function will accept two int values
{
	return iRemainder1 % iRemainder2;
}   
int primeFunc(int iPrime)//test if prime function
{
	int k, isPrime2;
	int counter = 0; //stores the values for the if statements
	if(iPrime == 0 || iPrime == 1) //these cannot be prime
	{
		printf("\n %d is not a prime \n", iPrime);
		
	}
	else 
	{	
		for(k = 2; k < iPrime / 2; k++)
		{
			if(iPrime % k == 0)
			{
				isPrime2 = iPrime / k;
				counter = 1;//this is for not prime numbers
				printf("\n %d is not a prime. %d * %d = %d \n", iPrime, isPrime2, k, iPrime);
				break;
			}
			else 
			{
				counter = 0;// for numbers that are prime
			}		
		}
			if(counter == 0)//all the numbers that aren't picked up during the loop conditional statement are prime
			{
				printf("\n %d is a prime.\n", iPrime);
			}	
	} 
	return 0;
}
int factorialFunc(int iFactorial1)//factorial function
{
	int i;
	int factorial = 1;
	int iFactorialResult = 0;
	for(i = 1; i <= iFactorial1; i++)
	{
		factorial *= i;
		iFactorialResult = factorial;
	}
	return iFactorialResult;//result will be returned when function is called
}

float powerFunc(float fNumber, float fPower)
{
	int j;
	float fPowerResult = 0;
	float fProcess = 1;
	for(j = 0; j < fPower; j++)
	{
		fProcess *= fNumber;
		fPowerResult = fProcess;
	}
	return fPowerResult;//result will be returned to the function call
}
int fibonacciFunc(int iNthnum)//fibonacci sequence 
{
int w;
int p;
int num1 = 0;
int num2 = 1;
int num3 = 0;
int fibonacciArr[iNthnum];//this array will store the sequence values
for(w = 0; w < iNthnum; ++w)//the work done in this for loop will initialize values into the array
{
	if(w == 0)//this is for the first value of fibonacci. 0 can't be computed in the sequence
	{
		fibonacciArr[w] = num1;
	}
	else if(w == 1)//this is for the second value of the fibonacci. Because 1 can't be computed in the sequence
	{
		fibonacciArr[w] = num2;
	}
	else
	{
		num3 = num1 + num2;
		fibonacciArr[w] = num3;
		num1 = num2;
		num2 = num3;
	}
}
for(p = 0; p < iNthnum; ++p)//this for loop will print the array values
{
	printf("\n %d,", fibonacciArr[p]);//this will be returned to the function call
}
return 0;
}
