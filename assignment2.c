/* 
Program by Daniel Krasovski.
date: 24/02/2019
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 4

int* menu1(int *);
int menu2(int *);
int* menu3(int *);

int encrypted_code[SIZE];
int pin_entered[SIZE];
int access_code[SIZE] = {4,5,2,3};


int fail1 = 0;
int option_fail1 = 0;  //stops the user from going back into option 2
int option_fail2 = 0; //stops the user from going back into option 3
int option_fail3 = 0; //stops the user going into option 4, if the code hasnt been encrypted
int correct = 0; //counts times code was enetered correctly
int incorrect = 0; // counts times code was entered incorrectly


int main()
{
	
	float menu = 0;
  int loop = 0;

	while (loop == 0)
	{
		printf("\nWhat would you like to do? \n \n");
		printf("1. Enter code \n");
		printf("2. Encrypt and verify \n");
		printf("3. Decrypt code \n");
		printf("4. Times code has been entered correctly and incorrectly\n");
		printf("5. Exit program \n");

		scanf("%f",&menu);

		if (menu == 1)
		{
			int* ptr = menu1(pin_entered);
			if (fail1 != 1)
			{
				option_fail1 = 1;   // allows user to go into 2nd option
				printf("the code entered is: \n");
				
				for (int i = 0; i < SIZE; i++)
				{
					printf("%d ", *(ptr+i)); 
				}
			}    
      option_fail3 = 0; // stops person from option 4, until they encrypt code
		}

		if (menu == 2)
		{ 
			if( option_fail1 != 1)
			{
				printf("you must do option 1 first");
				main();  //goes back to the main menu.
				
			}
			int ret;
			ret = menu2(pin_entered);  //checks if pin entered is the same as one stored
			option_fail2 = 1;
			if (ret == 0)
			{
				printf("the code entered is Correct and has been encrypted \n");
				correct++;
			}
			else
			{
				printf("Wrong Code entered but it has been encrypted \n");
				incorrect++;
			}
      printf("The Encrypted code is: \n");
      for( int i = 0; i <SIZE; i++)
      {
        printf("%d",*(encrypted_code+i));
      }
		  option_fail1 = 0;  // stops the user from going back straight into option 2,
		}
				
		if (menu == 3)
		{
			if( option_fail2 != 1)
			{
				printf("you must do option 2 first"); 
				main();
			}
			int* ptr = menu3(encrypted_code); //decrypts the code and prints it
			printf("the decrypted code is: "); 
			for (int i = 0; i < SIZE; i++)
			{
				printf("%d ", *(ptr+i)); 
			}
    option_fail2 = 0; //stops the user from going back into option 3
		}

		if (menu == 4)
		{
      if( option_fail3 == 1)
			{
				printf("you must encrypt the code first"); 
				main();
      }
			printf("the code has been entered %d times correctly and %d times incorrectly \n",correct, incorrect);
      option_fail2 = 1;
		}

		if (menu == 5)
		{
			printf("The program is now closing");
			loop = 1;
      break;
		}

	}
}

int* menu1(int *pin_entered)
{
	
  int i = 0;
	printf("enter 4 seperate numbers \n");

	while(i != SIZE)
	{
		char term;
		if(scanf("%d%c", (pin_entered+i), &term) != 2 || term != '\n')
		{
			printf("failure, enter a intiger number,\nTry Again\n"); 
			fail1 = 1; //stops the programming from printing the numbers entered
			main();
		}
		
		if(pin_entered[i] >= 10)
		{
			printf("failure, enter a number less than 10\n");
			i-=1;
		}
    if(pin_entered[i] < 0)
		{
			printf("failure, enter a greater than -1\n");
			i-=1;
		}
		i++;
	}
	fail1 = 0;
	return pin_entered;
}

int menu2(int *pin_entered)
{
	
	*(encrypted_code+0) = *(pin_entered+2);  // swaps the numbers around for the encryption
	*(encrypted_code+1) = *(pin_entered+3);
	*(encrypted_code+2) = *(pin_entered+0);
	*(encrypted_code+3) = *(pin_entered+1);

	for(int i = 0; i < SIZE; i++)  //encryption algorithm
	{	
		*(encrypted_code+i) +=1;

		if (*(encrypted_code+i) == 10)
		{
			*(encrypted_code+i) = 0;
		}

	}
  
	printf("\n");
	
	int ret;
	ret = memcmp(encrypted_code, access_code,sizeof(access_code)); // compares the the encrypted pin with the stored pin
	return ret;
	
}

int* menu3(int *encrypted_code)
{
	*(pin_entered+0) = *(encrypted_code+2);
	*(pin_entered+1) = *(encrypted_code+3);
	*(pin_entered+2) = *(encrypted_code+0);
	*(pin_entered+3) = *(encrypted_code+1);

  for(int i = 0; i < SIZE; i++)  //decryption algorithm
	{	
		*(pin_entered+i) -= 1;
		if (*(pin_entered+i) == -1)
		{
			*(pin_entered+i) = 9;
		}
	}
  return pin_entered;
}
