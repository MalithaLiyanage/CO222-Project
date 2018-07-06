#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


char newWords[10][10];


int impossible = 0;
int matrix[10][10];
char printMatrix[10][10];
char words[10][10];
int sizeOfthePuzzle;
int noOfWords = 0;
//int x;
int y = 0;


char tempWord[10];
int done = 0;
	
int counter = 0;

int similar = 0;


int noLine = 0;


int rowVacant = 1;
int coloumnVacant = 1;




int get_inputs();
void print_matrix();
int Check_Similarities();
void No_Similar_Words();
void Sorting_Word_List();
int Is_Similar();


int main()
{

	get_inputs();   // Getting inputs Turning to capitals And storing in words and matrix matrices
	
	

	//printf("Size of the puzzle : %d\n",sizeOfthePuzzle);


	if (impossible == 1)
	{
		printf("IMPOSSIBLE\n");
		return 0;
	}


	for (int m = 0; m < sizeOfthePuzzle; m++)
	{
		for (int n = 0; n < sizeOfthePuzzle; n++)
		{
			if (matrix[m][n] == 3)
			{
			
				printMatrix[m][n] = '*';			// Creating the Printing Matrix according to the given input (line by line)
			}
			else if (matrix[m][n] == 1)
			{
				printMatrix[m][n] = '#';
			}	
			
		}
	}



	if (Check_Similarities() > 0)
	{
 		printf("Similarities  : %d\n",similar);	// Words components are similar

 		if (noOfWords == 2)
 		{

 			printf("Yesq\n");
 		}

	}


	else

	{


		Sorting_Word_List();  // Words are sorted for easyness
		No_Similar_Words();   

													           // Words' components aren't simila
		//printf("Printing Matrix\n");

		for (int m = 0; m < sizeOfthePuzzle; m++)
		{
			for (int n = 0; n < sizeOfthePuzzle; n++)
			{
				printf("%c",printMatrix[m][n]);
				
			}

			if (printMatrix[m][0] != '\0')
			{
			printf("\n");
		    }

		}

	}
	
	
	//print_matrix();
	
	//printf("Yes\n"); 

	return 0;
}


int get_inputs()
{

	int enterPressed = 0;
	int flag1 = 0;
	
	int isWord = 1;
	

	char line[10];



	while(enterPressed != 2)
	{


		fgets(line,sizeof(line),stdin);

		//printf("Line Length : %d\n",strlen(line) - 1);




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

			//x = noOfWords;

			if (enterPressed == 0 && sizeOfthePuzzle < strlen(line) - 1)
			{
				flag1 = 1;
				sizeOfthePuzzle = strlen(line) - 1;

				/*for (int m = 0; m < sizeOfthePuzzle; m++)
				{
					for (int n = 0; n < sizeOfthePuzzle; n++)
					{
						matrix[m][n] = 2;                           // Giving 2 for the all values of the 10 x 10 matrix
					}
				}*/
			}


			


			for (int n = 0; n < sizeOfthePuzzle; n++)
			{
				if (line[n] >= 97 && line[n] <= 122)     // Turning to Capitals
				{
					line[n] = line[n] - 32;
				}

			}

			if ((strlen(line) - 1 > sizeOfthePuzzle && strlen(line) - 1 > noLine) && flag1 == 1 && (enterPressed == 1 || enterPressed == 2))
			{
				impossible = 1;
				//printf("hui\n");
			//	printf("Size of the Puzzle : %d\n",sizeOfthePuzzle);
			//	printf("No line : %d\n",noLine);
			//	printf("go1");
			//	printf("Line Length : %ld\n",strlen(line));
			///	printf("Size of the puzzle : %d\n",sizeOfthePuzzle);
			}

			/*for (int n = 0; n < sizeOfthePuzzle; n++)
				{
					if (line[n] >= 65 && line[n] <= 90)
					{
						isWord = 1;
					}
					else
					{
						isWord = 0;
					}	

				}*/


			if (enterPressed == 0)
			{

			for (int n = 0; n < strlen(line) - 1; n++)
				{

					//printf("work2\n");

					
					if (line[n] == 35)
					{
						matrix[noLine][n] = 1;
					}                                          // Creating the matrix 1 for vacants 0 for non vacant
					else
					{
						matrix[noLine][n] = 3;
					}

				}

				noLine ++;	
			}
		}


		if (enterPressed == 1 || enterPressed == 2)
		{                                                       // Creating the words array
			strcpy(words[y],line);
			y++;
		}

			
		
		


	  	
																							



		if (noOfWords > sizeOfthePuzzle)
		{                                          // If no. of words exceeds the size of the puzzel that is impossible
			impossible = 1;
			return 0;
		}



	}

	return 0;


}

	 

void print_matrix()
{

	printf("Size of the matrix is  =  %d\n",sizeOfthePuzzle);
	printf("%d\n%d\n",noOfWords,y);


	for (int m = 0; m < sizeOfthePuzzle; m++)
	{
		for (int n = 0; n < sizeOfthePuzzle; n++)
		{
			printf("%d",matrix[m][n]);
			
		}
		printf("\n");

	}

	printf("Word List Sort\n");

	  	for (int m = 0; m < sizeof(words)/sizeof(char *); m++)
	  	{
	  		printf("%s\n",words[m]);
		}

	for (int m = 1; m <= noOfWords; m++)
	{

		//printf("Word no : %d %s",m,words[m]);
		//printf("Word Size : %d\n",strlen(words[m]));
				
	}


}


int Check_Similarities()
{
	similar = 0;

	for (int m = 0; m < sizeof(words)/sizeof(char *); m++)
	{
		for (int n = 0, k = 0; n < strlen(words[m]), k < strlen(words[m+1]); n++, k++)
		{

			if (words[m][n] == words[m+1][k] && words[m][n] != '\n' && words[m][n] != '\0' && words[m][n] != ' ' && strlen(words[m]) > 0)
			{
				similar ++;

				/*printf("%d\n",m);
				printf("%s and %s\n",words[m],words[m+1]);
				printf("Lengths : %d and %d\n",strlen(words[m]),strlen(words[m+1]));
				printf("n and k : %d and %d\n",n,k);
				printf("%c and %c\n",words[m][n],words[m+1][k] );
				printf("similar\n");*/

			}
		}
	}

	return similar;

}

/*int Is_Similar()
{
	for (int m = 0; m < sizeof(words)/sizeof(char *); m++)
	{
		for (int n = 0, k = 0; n < strlen(words[m]), k < strlen(words[m+1]); n++, k++)
		{

			if (words[m][n] == words[m+1][k] && words[m][n] != '\n' && words[m][n] != '\0' && words[m][n] != ' ' && strlen(words[m]) > 0)
			{
				similar ++;

			}
		}

		if (similar == 1)
		{
			return m, n, k;
		}

		similar = 0;
	}


	
}*/




void No_Similar_Words()
{
	
	  	/*printf("Word List Sort\n");

	  	for (int m = 0; m < sizeof(words)/sizeof(char *); m++)
	  	{
	  		printf("%s\n",words[m]);

	

}*/
	int rowTotal = 0;
	int columnTotal = 0;
	int wordPrinted = 0;

	int rows = 0;
	int colomns = 0;

	int rowPrint = 0;

	for (int l = 1; l <= noOfWords; l++)
	{
		
	//	printf("Word Loop \n");

	//	printf("Size of the word %d\n",strlen(words[l]));

		rows = 0;

		while (rows < sizeOfthePuzzle)
		{
		//	printf("first loop\n");
		//	printf("%s\n",words[l]);

			rowTotal = 0;


			for (int n = 0; n < sizeOfthePuzzle; n++)
			{
				if (matrix[rows][n] == 1)
				{
				rowTotal = rowTotal + matrix[rows][n];
				}
			//	printf(" Row : %d\n",rows);
			}

			//printf("Row Total : %d\n",rowTotal);

			if (rowTotal >= strlen(words[l]) - 1)
			{
				

				for (int i = 0; i < sizeOfthePuzzle; i++)
				{
					if (matrix[rows][i] == 1 && matrix[rows][i+1] == 1)
					{
						for(int j = 0; j <strlen(words[l]) - 1; j++)
						{
							printMatrix[rows][i] = words[l][j];
							matrix[rows][i] = 0;
							i++;
						//	printf("work\n");	
							rowPrint = 1; 
						}

						wordPrinted = 1;
						break;	
						
					} 
					
					
				}

				if (wordPrinted == 1)
				{					
					break;
				} 

			}

			rows++;

			
		}

		wordPrinted = 0;

	}

	//printf("%d\n",rowPrint);
	wordPrinted = 0;

	if (rowPrint == 0)
	{
		if (sizeOfthePuzzle < noLine)
		{
			sizeOfthePuzzle = noLine;
		}
	//	printf("Column initiation\n");

		for (int l = 1; l <= noOfWords; l++)
		{
			
			//printf("Word Loop \n");

			//printf("Size of the word %d\n",strlen(words[l] - 1));

			colomns = 0;

			while (colomns < sizeOfthePuzzle)
			{
				printf("first loop\n");
				printf("%s\n",words[l]);

				columnTotal = 0;


				for (int n = 0; n < sizeOfthePuzzle; n++)
				{
					if (matrix[n][colomns] == 1)
					{
						columnTotal = columnTotal + matrix[n][colomns];
					}
					printf("Column : %d\n",colomns);
				}

				("Column Total : %d\n",columnTotal);

				if (columnTotal >= strlen(words[l]) - 1)
				{
					

					for (int i = 0; i < sizeOfthePuzzle; i++)
					{
						if (matrix[i][colomns] == 1)
						{
							for(int j = 0; j <strlen(words[l]) - 1; j++)
							{
								printMatrix[i][colomns] = words[l][j];
								matrix[i][colomns] = 0;
								i++;
								//printf("work\n");	
							}

							wordPrinted = 1;
							break;	 
						} 
						
						
					}

					if (wordPrinted == 1)
					{
						
						break;
					} 

				}

				colomns++;

				
			}

			wordPrinted = 0;

		}

	}

}


/*void Similar_Words()
{
	for (int n = 0; n < sizeof(words)/sizeof(char *); n++)
	{
		if (Is_Similar() > )

	}
	


}*/

void Sorting_Word_List()
{

	while (done == 0)
  	{	
	  		//printf("Go1\n");

	  		counter = 0;

	  		for (int n = 1; n < noOfWords; n++)
	  		{
	  			//printf("Go2\n");
	  			if (strlen(words[n]) < strlen(words[n+1]))
	  			{
	  			//	printf("Go3\n");
	  				strcpy(tempWord,words[n+1]);
	  				strcpy(words[n+1],words[n]);			// Sort the word list
	  				strcpy(words[n],tempWord);

	  				counter++;
	  			}
	  			

	  			
	  		}

	  		if (counter == 0)
	  			{
	  				done = 1;
	  			}

	  		
	}



}





