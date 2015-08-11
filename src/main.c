#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *password;
FILE* keyfile;
FILE* wordbank;
unsigned int *wordcount;
char word[10];


int main(void)
{
	srand(time(NULL));
	int intLength = 0;
	unsigned int intComplex = 0;
	unsigned int i = 0;
	unsigned int k = 0;
	unsigned int Rando = 0;
	unsigned int Rado = 0;
	unsigned int Rndom = 0;
	unsigned int arraynum = 0;
	char chrUpperCase[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'}; //26
	char chrLowerCase[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'}; //26
	char chrNumbers[] = {'0','1','2','3','4','5','6','7','8','9'}; //10
	char chrSymbols[] = {' ','!','@','#','$','%','^','&','*','(',')','~','|','{','}','_','-','<','>','?','/',':',';'}; //23
	
	
	do
	{
		printf("\nPlease enter the length of your password from 1 to 255: ");
		scanf("%d",&intLength);
	} while (intLength > 255 || intLength < 1);
	
	do
	{
		printf("\nPlease enter the complexity of your password from 0 to 3, (3 is the most complex): ");
		scanf("%d",&intComplex);
	} while (intComplex > 3 || intComplex < 0);
	
	password = malloc(sizeof(char) * (intLength + 1));
	
	if (password == NULL) {printf("\nNot enough memory, program will exit.\n"); getchar(); return 0;}
	if (intComplex != 0)
	{
		for (i = 0; i < intLength; i++)
		{
		
			switch(intComplex)
			{
				break;
				case 1:
					//makes Password from random Upper and Lower case letters
					Rando = (int)(rand() % 2);
					Rado = (int)(rand() % 26);
					if (Rando == 0) {password[i] = chrUpperCase[Rado];}
					else {password[i] = chrLowerCase[Rado];}
				break;
				case 2:
					//makes Password from random Upper and Lower case letters and numbers
					Rando = (int)(rand() % 3);
					if (Rando == 0)
					{
						Rado = (int)(rand() % 26);
						password[i] = chrUpperCase[Rado];
					}
					else if (Rando == 1)
					{
						Rado = (int)(rand() % 26);
						password[i] = chrLowerCase[Rado];
					}
					else
					{
						Rado = (int)(rand() % 10);
						password[i] = chrNumbers[Rado];
					}
				break;
				case 3:
					//Makes Password from Random upper, lower case letters, numbers and symbols
					Rando = (int)(rand() % 4);
					if (Rando == 0)
					{
						Rado = (int)(rand() % 26);
						password[i] = chrUpperCase[Rado];
					}
					else if (Rando == 1)
					{
						Rado = (int)(rand() % 26);
						password[i] = chrLowerCase[Rado];
					}
					else if (Rando == 2)
					{
						Rado = (int)(rand() % 10);
						password[i] = chrNumbers[Rado];
					}
					else
					{
						Rado = (int)(rand() % 23);
						password[i] = chrSymbols[Rado];
					}
				break;
			
			}
		}
	}
	else
	{
		arraynum = 0;
		wordcount = malloc(sizeof(unsigned int) * 1);
		if(wordcount == NULL) {printf("\nNot enough memory, program will exit.\n"); getchar(); return 0;}
		while (intLength > 0)
		{
			Rndom = rand() % 8 + 1;
			while (intLength - Rndom < 0) {Rndom = rand() % 8 + 1;}
			wordcount = realloc(wordcount,sizeof(unsigned int) * (arraynum + 1));
			if(wordcount == NULL) {printf("\nNot enough memory, program will exit.\n"); getchar(); return 0;}
			wordcount[arraynum] = Rndom;
			arraynum++;
			intLength -= Rndom;			
		}
		for (i = 0; i <= arraynum; i++)
		{
			switch (wordcount[i])
			{
				case 1:
					Rando = rand() % 26;
					password[intLength] = chrLowerCase[Rando];
					intLength ++;
					break;
				case 2:
					Rando = rand() % 101;
					wordbank = fopen("2L words.txt","r");
					for (k = 0; k < Rando; k++) {fscanf(wordbank,"%s\n",&word);}
					fclose(wordbank);
					password[intLength] = word[0];
					password[intLength + 1] = word[1];
					intLength +=2;
					break;
				case 3:
					Rando = rand() % 1015;
					wordbank = fopen("3L words.txt","r");
					for (k = 0; k < Rando; k++) {fscanf(wordbank,"%s\n",&word);}
					fclose(wordbank);
					for (k = 0; k < 3; k++) {password[intLength + k] = word[k];}
					intLength +=3;
					break;
				case 4:
					Rando = rand() % 4030;
					wordbank = fopen("4L words.txt","r");
					for (k = 0; k < Rando; k++) {fscanf(wordbank,"%s\n",&word);}
					fclose(wordbank);
					for (k = 0; k < 4; k++) {password[intLength + k] = word[k];}
					intLength +=4;
					break;
				case 5:
					Rando = rand() % 8938;
					wordbank = fopen("5L words.txt","r");
					for (k = 0; k < Rando; k++) {fscanf(wordbank,"%s\n",&word);}
					fclose(wordbank);
					for (k = 0; k < 5; k++) {password[intLength + k] = word[k];}
					intLength +=5;
					break;
				case 6:
					Rando = rand() % 15788;
					wordbank = fopen("6L words.txt","r");
					for (k = 0; k < Rando; k++) {fscanf(wordbank,"%s\n",&word);}
					fclose(wordbank);
					for (k = 0; k < 6; k++) {password[intLength + k] = word[k];}
					intLength +=6;
					break;
				case 7:
					Rando = rand() % 24029;
					wordbank = fopen("7L words.txt","r");
					for (k = 0; k < Rando; k++) {fscanf(wordbank,"%s\n",&word);}
					fclose(wordbank);
					for (k = 0; k < 7; k++) {password[intLength + k] = word[k];}
					intLength +=7;
					break;
				case 8:
					Rando = rand() % 29766;
					wordbank = fopen("8L words.txt","r");
					for (k = 0; k < Rando; k++) {fscanf(wordbank,"%s\n",&word);}
					fclose(wordbank);
					for (k = 0; k < 8; k++) {password[intLength + k] = word[k];}
					intLength +=8;
					break;
			}
		}
		//intLength++;
		free(wordcount);
	}
	password[intLength] = '\0';
	printf("\n\n\n\n");
	printf("Your password is: \n%s",password);
	printf("\n\n");
	printf("\nWould you like to save it to key.txt?\n1 = Yes\n0 = No\n");
	scanf("%u",&intLength);
	if (intLength == 1)
	{
		keyfile = fopen("key.txt","w");
		fprintf(keyfile,"%s",password);
		fclose(keyfile);
		printf("\nPassword saved!\n");
	}
	free(password);
	getchar();
	return 0;
}





