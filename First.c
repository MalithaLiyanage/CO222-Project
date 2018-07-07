#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


int impossible = 0;                 // Used for the impossible error
int matrix[20][20];					// Used to store the structure of the puzzle using 1 and 0	
char printMatrix[20][20];			// Used to print the final output
char words[20][20];					// Used to store the words given as the input 
int sizeOfthePuzzle;				// Used to store the size of the puzzle (and also No. of Columns)
int noOfWords = 0;					// Used to store the total no. of words
int wordIndex = 0;					// Used to store the words in the words array

char tempWord[20];					// Used in sorting the words list
int done = 0;						// Used to find the sorting of words list is done
int counter = 0;					// Used in the sorting function

int similar = 0;					// Used to find the words which has similar letters
int noLine = 0;						// Used for helping in creating a matrix array with 1 and 3


int rowTotal = 0;					// Used to find the sum of the ones in a row
int columnTotal = 0;				// Used to find the sum of the ones in a column

int wordPrinted = 0;				// Used to say that the word is printed

int rows = 0;						// Used in printing rowWise
int colomns = 0;					// Used in printing rowWise

int rowPrint = 0;					// Used to know whether the rowWisely printed 

int similarPlace = 0;				// Used to find the similar places of the words	
int found = 0;						// Used to show that there is a similar place 

int indexOfPrintedWord;				// Used to find the printed word so that word wouldnt print again

int crossPlace;

int totalNoOfWordsPrinted = 0;

int get_inputs();    			 	// Function for gettind inputs
void Print_Matrix();				// Function for printing the final output
int Check_Similarities();			// Function finding the similarities of the words
void No_Similar_Words();			// Function for actions that should be done when no similar words are given (Ex. Fire and Cat)
void Sorting_Word_List();			// Function for sorting the Words list according to the size
void Similar_Words();				// Function for actions that should be done when similar words are given (Ex. Fly and Glue)
void Print_RowWise();				// Function for printing in RowWise
void Print_ColumnWise();			// Function for printing in ColumnWise
int Is_Cross();


int main()
{

	get_inputs();   									// Getting inputs Turning to capitals And storing in words and matrix matrices
	
	if (impossible == 1)
	{
		printf("IMPOSSIBLE\n");							// Printing IMPOSSIBLE for impossible puzzels
		return 0;
	}

	if (noLine > sizeOfthePuzzle)
	{
		sizeOfthePuzzle = noLine;
	}


	

	for (int m = 0; m < sizeOfthePuzzle; m++)
	{
		for (int n = 0; n < sizeOfthePuzzle; n++)
		{
			if (matrix[m][n] == 3)
			{
			
				printMatrix[m][n] = '*';				// Creating the Printing Matrix according to the given input (line by line)
			}
			else if (matrix[m][n] == 1)
			{
				printMatrix[m][n] = '#';
			}	
			else if (matrix[m][n] == 0 )
			{
				printMatrix[m][n] = '\0';
			}
			
		}
	}

	//char line2[10] = "AT\n";

	//printf("%s\n",words[1]);

	/*if (strcmp(line2,words[1]) == 0)
	{
		//printf("Yeah\n");
		
		for (int m = 0; m < 20; m++ )
		{
			for (int n = 0; n < 20; n++)
			{
				printf("%c",testMat[m][n]);
			}

			if (testMat[m][0] != '\0')
			{
				printf("\n");
			}
		}
		return 0;
	}*/

	if (Is_Cross() == 1 && Check_Similarities() == 0)
	{
		
		

		//printf("Cross\n");

		if (noLine < sizeOfthePuzzle)
		{
			similarPlace = crossPlace ;

		}
		else
		{
			similarPlace = crossPlace - 1 ;

		}


		//printf("Size of puzzele : %d\n",sizeOfthePuzzle);

	//	printf("Similar Plaxe : %d\n",similarPlace);

		Sorting_Word_List();
		Print_RowWise();
		Print_ColumnWise();

	/*	for (int m = 0; m < sizeOfthePuzzle; m++)
		{
			for (int n = 0; n < sizeOfthePuzzle; n++)
			{
				printf("%d",matrix[m][n]);
			}
			printf("\n");
		}
*/

		if (totalNoOfWordsPrinted < noOfWords)
 		{

 			printf("IMPOSSIBLE\n");
 			return 0;
 			

 		}


		Print_Matrix();

		
		return 0;
	}

	if (Check_Similarities() == 1)						// Similarities of the given words are checked
	{
 		Sorting_Word_List();  							// Words are sorted since algorithm works correctly when longest word print first
 		Similar_Words();		

 		if (totalNoOfWordsPrinted < noOfWords)
 		{

 			printf("IMPOSSIBLE\n");
 			return 0;
 			

 		}

 		Print_Matrix();
 		return 0;

	}
	
	else
	{


		Sorting_Word_List();  							// Words are sorted since algorithm works correctly when longest word print first
		No_Similar_Words();  

		if (totalNoOfWordsPrinted < noOfWords)
 		{

 			printf("IMPOSSIBLE\n");
 			return 0;

 		}


		Print_Matrix();
		

	}


	
	

	return 0;
}


			/*User Defined Funtions*/

int get_inputs()
{

	int enterPressed = 0;               				// Used to find how many enters are pressed
	char line[20];										// Used to store the input line by line



	while(enterPressed != 2)							// Terminates getting inputs after pressing two enters
	{


		fgets(line,sizeof(line),stdin);					// Getting the inputs

		
		if (line[0] == '\n')
		{	
			enterPressed++;								// Checking the line is a new line 
		}

		else
		{
			if (enterPressed == 1 )
			{
				noOfWords++;	
			}

			
			if (enterPressed == 0 && sizeOfthePuzzle < strlen(line) - 1)
			{
				
				sizeOfthePuzzle = strlen(line) - 1;

			}

			for (int n = 0; n < strlen(line) - 1; n++)
			{
				if (line[n] >= 97 && line[n] <= 122)     // Turning to Capitals
				{
					line[n] = line[n] - 32;
				}
			}



			if ((strlen(line) - 1 > sizeOfthePuzzle && strlen(line) - 1 > noLine) && (enterPressed == 1 || enterPressed == 2))
			{
				impossible = 1;
				 
			}

			

			if (enterPressed == 0)
			{

			for (int n = 0; n < strlen(line) - 1; n++)
				{
						
					if (line[n] == 35)
					{
						matrix[noLine][n] = 1;
						
					}   
					                                 // Creating the matrix 1 for vacants 3 for non vacant
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
			strcpy(words[wordIndex],line);
			wordIndex++;
		}

			


		if (noOfWords > sizeOfthePuzzle)
		{                                          // If no. of words exceeds the size of the puzzel that is impossible
			impossible = 1;
			return 0;
		}

	}

	return 0;

}

	 

void Print_Matrix()
{

	
	for (int m = 0; m < sizeOfthePuzzle; m++)
	{
		for (int n = 0; n < sizeOfthePuzzle; n++)
		{
			if (matrix[m][n] != 0)
			{
			printf("%c",printMatrix[m][n]);		
			}	
		}													// Printing the Matrix

		if ((printMatrix[m][0] != '\0' && printMatrix[m][0] != '\n') || matrix[m][0] != 0)
		{
		printf("\n");
	    }
			

	}

	//printf("No of Words : %d\n",noOfWords);
	//printf("Words Printed : %d\n",totalNoOfWordsPrinted);

	/*for (int m = 0; m < sizeOfthePuzzle; m++)
	{
		for (int n = 0; n < sizeOfthePuzzle; n++)
		{
			printf("%d",matrix[m][n]);		
				
		}													// Printing the Matrix

		if ((matrix[m][0] != '\0' && matrix[m][0] != '\n') || matrix[m][0] != 0)
		{
		printf("\n");
	    }
			

	}*/




}


int Check_Similarities()
{
	similar = 0;											// Checking similarities

	for (int m = 0; m < sizeof(words)/sizeof(char *); m++)
	{
		for (int n = 0, k = 0; n < strlen(words[m]), k < strlen(words[m+1]); n++, k++)
		{

			if (words[m][n] == words[m+1][k] && words[m][n] != '\n' && words[m][n] != '\0' && words[m][n] != ' ' && strlen(words[m]) > 0)
			{
				similar ++;																									

			}
		}
	}

	return similar;

}


void No_Similar_Words()
{
	//printf("noSimilar\n");	


	if (sizeOfthePuzzle < noLine)
	{
		sizeOfthePuzzle = noLine;
	}


	Print_RowWise();

	



	
	wordPrinted = 0;

	if (rowPrint == 0 || Check_Similarities() == 1)
	{
		if (sizeOfthePuzzle < noLine)
		{
			sizeOfthePuzzle = noLine;
		}

		Print_ColumnWise();

	//	printf("Column printed No similar\n");


	}			


}


void Similar_Words()
{
	//printf("Similar\n");
	

	for (int m = 0; m < sizeof(words)/sizeof(char *); m++)
	{
		for (int n = 0 ; n < strlen(words[m]); n++)
		{

			for (int k = 0; k < strlen(words[m]); k++)						// Finding the similar place
			{

				if (words[m][n] == words[m+1][k] && words[m][n] != '\n' && words[m][n] != '\0' && words[m][n] != ' ' && strlen(words[m]) > 0)
				{
				
					similarPlace = n;

					found = 1;
					break;

				}

			}

			if (found == 1)
			{
				break;
			}

		}

		if (found == 1)
		{
			break;
		}	
		
	}	


	if (sizeOfthePuzzle < noLine)
	{
		sizeOfthePuzzle = noLine;
	}


	Print_RowWise();
	

	wordPrinted = 0;

	if (rowPrint == 0 || Check_Similarities() == 1)
	{
		if (sizeOfthePuzzle < noLine)
		{
			sizeOfthePuzzle = noLine;
		}

		Print_ColumnWise();

		//printf("Column printed similar\n");

	}

}

void Sorting_Word_List()
{

	while (done == 0)
  	{	

	  	counter = 0;

	  	for (int n = 1; n < noOfWords; n++)
	  	{
	  		if (strlen(words[n]) < strlen(words[n+1]))
	  		{
	  			strcpy(tempWord,words[n+1]);
	  			strcpy(words[n+1],words[n]);			// Sort the word list according to the strlen
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

void Print_RowWise()     // Printing the Rows
{

	for (int l = 1; l <= noOfWords; l++)
	{
		
		rows = 0;

		while (rows < sizeOfthePuzzle)
		{
		
			rowTotal = 0;


			for (int n = 0; n < sizeOfthePuzzle; n++)
			{
				if (matrix[rows][n] == 1)
				{
				rowTotal = rowTotal + matrix[rows][n];
				}
			}

			if (rowTotal >= strlen(words[l]) - 1)
			{
				

				for (int i = 0; i < sizeOfthePuzzle; i++)
				{
					if (matrix[rows][i] == 1 && matrix[rows][i+1] == 1)
					{

						

						for(int j = 0; j <strlen(words[l]) - 1; j++)
						{
							
							printMatrix[rows][i] = words[l][j];
							

							if (j != similarPlace)
							{
								matrix[rows][i] = 2;
							}

							i++;
							rowPrint = 1; 
							indexOfPrintedWord = l;

							
						}

						wordPrinted = 1;
						break;	
						
					} 
																	
					
				}

				if (wordPrinted == 1)
				{	

					totalNoOfWordsPrinted++;				
					break;
				} 

			}

			rows++;

			
		}

		wordPrinted = 0;

	}

}

void Print_ColumnWise()   // Printing the Columns
{


	for (int l = 1; l <= noOfWords; l++)
	{
		//printf("Column Printing\n");
			
		colomns = 0;

		while (colomns < sizeOfthePuzzle)
		{
				
			columnTotal = 0;


			for (int n = 0; n < sizeOfthePuzzle; n++)
			{
				if (matrix[n][colomns] == 1)
				{
					columnTotal = columnTotal + matrix[n][colomns];
				}
			}
		//	printf("go0\n");

			if ((columnTotal >= strlen(words[l]) - 1) && l != indexOfPrintedWord )
			{

				//printf("go1\n");

				for (int i = 0; i < sizeOfthePuzzle; i++)
				{
					//printf("go2\n");
					if (matrix[i][colomns] == 1)
					{
					//	printf("go3\n");
						for(int j = 0; j <strlen(words[l]) - 1; j++)
						{
							
							
							printMatrix[i][colomns] = words[l][j];
						
							matrix[i][colomns] = 2;
							i++;

						//	printf("Work\n");
						}

						wordPrinted = 1;
					} 			
						
				}

				if (wordPrinted == 1)
				{
					totalNoOfWordsPrinted++;
					break;
				} 

				}

			colomns++;
	
		}

		wordPrinted = 0;

	}

}

int Is_Cross()
{
	for (int m = 0; m < sizeOfthePuzzle; m++)
	{
		for (int n = 0; n < sizeOfthePuzzle; n++)
		{
			if (matrix[m][n] == 1)
			{
				if (matrix[m+1][n] == 1 || matrix[m-1][n] == 1)
				{
					if ((matrix[m+1][n-1] == 0 && matrix[m+1][n+1] == 0) || (matrix[m-1][n-1] == 0 && matrix[m-1][n+1] == 0))
					{
						crossPlace = n;
						//printf("Yesss\n");
						return 1;
						
					}
				}
			}

		}
	}

	return 0;


}