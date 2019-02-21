/* 

Program by Daniel Krasovski.
*/
#include <stdio.h>
#include <stdlib.h>

#define SIZE 4

int* menu1(int *);
int* menu2(int *);
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
			int* ptr = menu2(pin_entered);
			for (int i = 0; i < SIZE; i++)
            {
            	printf("%d ", *ptr+i); 
            }
			
			
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
	char str[100];
	printf("enter 4 seperate numbers \n");
	for (int i = 0; i < SIZE; i++)
	{
		scanf("%[^0-9]%d",str, pin_entered+i); // stops the code from crashing if user enters a float number or character.
	}

	return pin_entered;
}

int* menu2(int *pin_entered)
{
	extern int encrypted_code[SIZE];
	*encrypted_code = malloc(SIZE);
	
	*(encrypted_code+1) = *pin_entered+3;
	*(encrypted_code+2) = *pin_entered+4;
	*(encrypted_code+3) = *pin_entered+1;
	*(encrypted_code+4) = *pin_entered+2;
	for(int i = 0; i < SIZE; i++)
	{	
		*(encrypted_code+i) = *(encrypted_code+i) + 1;
		if (*encrypted_code+i == 10)
		{
			*(encrypted_code+i) = 0;
		}
	}
	return encrypted_code;
	
	
	
	
}


