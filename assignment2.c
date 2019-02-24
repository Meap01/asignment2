/* 
Program by Daniel Krasovski.
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

int main()
{
	int loop = 0;
	int menu;
  int correct = 0;
  int incorrect = 0;
  int option_fail1 = 0;
  int option_fail2 = 0;
  

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
      if (fail1 != 1)
      {
        option_fail1 = 1;
        printf("the code entered is: \n");
        for (int i = 0; i < SIZE; i++)
        {
       	  printf("%d ", *(ptr+i)); 
        }
      }    

    }

		if (menu == 2)
		{ 
      if( option_fail1 != 1)
      {
        printf("you must do option 1 first");
        main();
        
      }
      int ret;
      ret = menu2(pin_entered);
      option_fail2 = 1;
      if (ret == 0)
      {
        printf("the code entered is Correct and encrypted");
        correct++;
      }
      else
      {
        printf("Wrong Code entered but it has been encrypted");
        incorrect++;
      }

		}
		
		if (menu == 3)
		{
      if( option_fail2 != 1)
      {
        printf("you must do option 2 first");
        main();
      }
      int* ptr = menu3(encrypted_code);
      printf("the decrypted code is: "); 
      for (int i = 0; i < SIZE; i++)
      {
       	printf("%d ", *(ptr+i)); 
      }

		}

		if (menu == 4)
		{
      printf("the code has been entered %d times correctly and %d times incorrectly \n",correct, incorrect);
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
			printf("failure, enter a intiger number,\nTry Again\n"); 
      fail1 = 1;
			menu1(pin_entered);
    }
    if(pin_entered[i] >= 10)
    {
      printf("failure, enter a number less than 10\n");
      i-=1;
    }
    i++;
	}

	return pin_entered;
}

int menu2(int *pin_entered)
{
	
	*(encrypted_code+0) = *(pin_entered+2);
	*(encrypted_code+1) = *(pin_entered+3);
	*(encrypted_code+2) = *(pin_entered+0);
	*(encrypted_code+3) = *(pin_entered+1);
  
	for(int i = 0; i < SIZE; i++)
	{	
		*(encrypted_code+i) +=1;
		if (*encrypted_code+i == 10)
		{
			*(encrypted_code+i) = 0;
		}
	}
  
	printf("\n");

  int ret;
  ret = memcmp(encrypted_code, access_code,sizeof(access_code));
	return ret;
	
}

int* menu3(int *encrypted_code)
{
	*(pin_entered+0) = *(encrypted_code+2);
	*(pin_entered+1) = *(encrypted_code+3);
	*(pin_entered+2) = *(encrypted_code+0);
	*(pin_entered+3) = *(encrypted_code+1);

  for(int i = 0; i < SIZE; i++)
	{	
		*(pin_entered+i) -=1;
		if (*pin_entered+i == -1)
		{
			*(pin_entered+i) = 9;
		}
	}
  return pin_entered;
}
