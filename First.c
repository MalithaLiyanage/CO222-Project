#include <stdio.h>
#include <string.h>





int impossible = 0;
int matrix[10][10];
char printMatrix[10][10];
char words[10][10];
int sizeOfthePuzzle;
int noOfWords = 0;
int x;
int y = 0;


int rowVacant;
int coloumnVacant;




int get_inputs();
void print_matrix();
int Check_Similarities();



int main()
{

	get_inputs();   // Getting inputs Turning to capitals And storing in words and matrix matrices
	
	if (impossible == 1)
	{
		printf("IMPOSSIBLE\n");
		return 0;
	}

	if (Check_Similarities() > 0)
	{
 			// Words components are similar

	}


	else

	{



		// Words' components aren't similar

	}
	
	
	print_matrix();


	printf("Yes\n"); 

	return 0;
}


int get_inputs()
{

	int enterPressed = 0;
	int flag1 = 0;
	int noLine = 0;
	int isWord = 1;
	
	


	char line[10];



	while(enterPressed != 2)
	{


		fgets(line,sizeof(line),stdin);




		if (line[0] == '\n')
		{
			enterPressed++;
		}

		else
		{
			if (enterPressed == 1 )
			{
				noOfWords++;
			}

			x = noOfWords;

			if (flag1 == 0)
			{
				flag1 = 1;
				sizeOfthePuzzle = strlen(line) - 1;

				for (int m = 0; m < sizeOfthePuzzle; m++)
				{
					for (int n = 0; n < sizeOfthePuzzle; n++)
					{
						matrix[m][n] = 2;                           // Giving 2 for the all values of the 10 x 10 matrix
					}
				}
			}


			for (int n = 0; n < sizeOfthePuzzle; n++)
			{
				if (line[n] >= 97 && line[n] <= 122)     // Turning to Capitals
				{
					line[n] = line[n] - 32;
				}

			}

			if (strlen(line) > sizeOfthePuzzle && flag1 == 1)
			{
				impossible = 1;
			}

			for (int n = 0; n < sizeOfthePuzzle; n++)
				{
					if (line[n] >= 65 && line[n] <= 90)
					{
						isWord = 1;
					}
					else
					{
						isWord = 0;
					}	

				}


			for (int n = 0; n < sizeOfthePuzzle; n++)
				{
					if (line[n] == 35)
					{
						matrix[noLine][n] = 1;
					}                                          // Creating the matrix 1 for vacants 0 for non vacant
					else 
					{
						matrix[noLine][n] = 0;
					}

				}

				noLine ++;	

		}


		if (enterPressed == 1 || enterPressed == 2)
		{
			strcpy(words[y],line);
			y++;
		}

		if (noOfWords > sizeOfthePuzzle)
		{
			impossible = 1;
			return 0;
		}



	}

	return 0;


}

	 

void print_matrix()
{

	printf("Size of the matrix is  =  %d\n",sizeOfthePuzzle);
	printf("%d\n%d\n%d\n",noOfWords,x,y);


	for (int m = 0; m < sizeOfthePuzzle; m++)
	{
		for (int n = 0; n < sizeOfthePuzzle; n++)
		{
			printf("%d",matrix[m][n]);
			
		}
		printf("\n");

	}


	for (int m = 1; m <= noOfWords; m++)
	{

		printf("%s",words[m]);
				
	}


}


int Check_Similarities()
{
	int similar = 0;

	for (int m = 0; m < noOfWords - 1; m++)
	{
		for (int n , k = 0; n < strlen(words[m]), k < strlen(words[m+1]); n++, k++)
		{

			if (words[m][n] == words[m+1][k])
			{
				similar ++;

			}
		}
	}

	return similar;

}




void No_Similar_Words()
{
	int m;
	int n;



	for (m = 0; m < sizeOfthePuzzle; m++)
	{
		for (n = 0; n < sizeOfthePuzzle; n++)
		{

			if (matrix[m][n] == 1)
			{

				for(int k = n,i = m; k < sizeOfthePuzzle, i < sizeOfthePuzzle; k++, i++)
				{

					if (matrix[m][k] == 1)
					{
						rowVacant ++;
					}

					if (matrix[i][n] == 1)
					{
						coloumnVacant ++;
					}


				}

				for (int l = 0; l < noOfWords; l++)
				{
					for (int j = 0; j < sizeOfthePuzzle; j++)
					{

						if (coloumnVacant >= strlen(words[l]))
						{
							printMatrix[m][n] = words[l][n];
						}
					}
					
				}


			}


		}


	}




}


void Similar_Words()
{

	


}





