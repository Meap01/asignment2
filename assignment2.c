/* 

Program by Daniel Krasovski.
*/
#include <stdio.h>
#include <stdlib.h>

#define SIZE 4

int* menu1(int *);
float menu2(float);
float menu3(float);
float menu4(float);

int main()
{
	int loop = 0;
	int menu;
	int pin_entered[SIZE];
	*pin_entered = malloc(SIZE);
	
	while (loop == 0)
	{
		printf("\nWhat would you like to do? \n \n");
		printf("1. Enter code \n");
		printf("2. Encrypt and verify \n");
		printf("3. Decrypt code \n");
		printf("4. Times code has been entered correctly and incorrectly\n");
		printf("5. Exit program \n");

		scanf("%d", &menu);

		if (menu == 1)
		{
		    
            int* ptr = menu1(pin_entered);
            
            for (int i = 0; i < SIZE; i++)
            {
            	printf("%d ", *ptr+i); 
            }
        }

		if (menu == 2)
		{

		}
		
		if (menu == 3)
		{

		}

		if (menu == 4)
		{

		}

		if (menu == 5)
		{
			printf("The program is now closing");
			loop = 1;
		}

	}
}

int* menu1(int *pin_entered)
{
	printf("enter 4 seperate numbers \n");
	for (int i = 0; i < SIZE; i++)
	{
		scanf("%[^0-9]%d", pin_entered+i); // stops the code from crashing if user enters a float number or character.
	}

	return pin_entered;
}

