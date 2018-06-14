#include <stdio.h>
#include <string.h>


char firstRowPuzzle[4];
char secondRowPuzzle[4];
char thirdRowPuzzle[4];
char fourthRowPuzzle[4];

char word1[30];
char word2[30];

int impossible = 0;

int matrix[10][10];




int get_inputs();
void turn_to_capital();
void understanding_Puzzle();
void print_matrix();



int main()
{

	get_inputs();
	turn_to_capital();  // Turning simples to capitals
	
	understanding_Puzzle();

	print_matrix();

	printf("Yes\n"); 

	return 0;
}


int get_inputs()
{


	scanf("%s %s %s %s %s %s", firstRowPuzzle,secondRowPuzzle,thirdRowPuzzle,fourthRowPuzzle,word1,word2);  // Getting the Inputs


}


void turn_to_capital()
{

	for(int n = 0, m = 0; n < strlen(word1), m <strlen(word2);n++,m++)
	{
		if (word1[n] >= 97 && word1[n] <= 122 )
		{
			word1[n] = word1[n] - 32;
		}

		if (word2[m] >= 97 && word2[m] <= 122)
		{
			word2[m] = word2[m] - 32;
		}

	}

}

void understanding_Puzzle()
{

	int sizeOfThePuzzle = strlen(firstRowPuzzle);
	int matrix[sizeOfThePuzzle][sizeOfThePuzzle];


	for (int n = 0; n < strlen(firstRowPuzzle); n++)
	{
		if (firstRowPuzzle[n] == 42)
		{
			matrix[1][n] = 0;
		}
		else if (firstRowPuzzle[n] == 35)
		{
			matrix[1][n] = 1;
		}
		else
		{
			impossible = 1;
		}

	}

	for (int n = 0; n < strlen(secondRowPuzzle); n++)
	{
		if (secondRowPuzzle[n] == 42)
		{
			matrix[1][n] = 0;
		}
		else if (secondRowPuzzle[n] == 35)
		{
			matrix[1][n] = 1;
		}
		else
		{
			impossible = 1;
		}

	}

	for (int n = 0; n < strlen(thirdRowPuzzle); n++)
	{
		if (thirdRowPuzzle[n] == 42)
		{
			matrix[1][n] = 0;
		}
		else if (thirdRowPuzzle[n] == 35)
		{
			matrix[1][n] = 1;
		}
		else
		{
			impossible = 1;
		}

	}

	for (int n = 0; n < strlen(fourthRowPuzzle); n++)
	{
		if (fourthRowPuzzle[n] == 42)
		{
			matrix[1][n] = 0;
		}
		else if (fourthRowPuzzle[n] == 35)
		{
			matrix[1][n] = 1;
		}
		else
		{
			impossible = 1;
		}

	}

	 



}

void print_matrix()
{

	for (int m = 0; m < 4; m++)
	{
		for (int n = 0; n < strlen(firstRowPuzzle); n++)
		{
			printf("%d",matrix[m][n]);
			printf("Go\n");

		}
		printf("\n");
		printf("Go2\n");

	}



}










