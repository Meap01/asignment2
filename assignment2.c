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

int encrypted_code[SIZE] = {0, 0, 0, 0};
int pin_entered[SIZE];

int main()
{
	int loop = 0;
	int menu;
	

	
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
  int i = 0;
	printf("enter 4 seperate numbers \n");

	while(i != SIZE)
	{
		char term;
		if(scanf("%d%c", (pin_entered+i), &term) != 2 || term != '\n')
    {
			printf("failure, enter a intiger number\n"); 
			i-=2;
    }
    if(pin_entered[i] >= 10)
    {
      printf("failure, enter a number less than 10\n");
      i-=2;
    }
    i++;
	}

	return pin_entered;
}

int* menu2(int *pin_entered)
{
	
	*(encrypted_code+0) = *pin_entered+2;
	*(encrypted_code+1) = *pin_entered+3;
	*(encrypted_code+2) = *pin_entered+0;
	*(encrypted_code+4) = *pin_entered+1;
	
	for(int i = 0; i < SIZE; i++)
	{	
		*(encrypted_code+i) +=1;
		if (*encrypted_code+i == 10)
		{
			*(encrypted_code+i) = 0;
		}
	}
	printf("\n");
	return encrypted_code;
	
}

