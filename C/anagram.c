#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *create_word(char *word, int level)
{
	char *ret = strdup(word);
	unsigned int *rand_num[] = {NULL, NULL, NULL, NULL};
	unsigned int num, i, j;

	srand(time(0));
	if (level == 1)
	{
		num = rand() % strlen(word);
		ret[num] = '_';
	}
	if (level == 2)
	{
		for (i = 0; i < 2; i++)
			rand_num[i] = (unsigned int *)(rand() % strlen(word));
		rand_num[i] = NULL;
		for (i = 0; i < strlen(word); i++)
		{
			for (j = 0; j < 2; j++)
				if (*rand_num[j] == i)
					ret[i] = '_';
		}
	}
	if (level == 3)
	{
		for (i = 0; i < 3; i++)
			rand_num[i] = (unsigned int *)(rand() % strlen(word));
		rand_num[i] = NULL;
		for (i = 0; i < strlen(word); i++)
		{
			for (j = 0; j < 3; j++)
				if (*rand_num[j] == i)
					ret[i] = '_';
		}
	}
	for (i = 0; rand_num[i] != NULL; i++)
		free(rand_num[i]);
	return(ret);
}

int main()
{
	char *word = "sleepy";
	int level = 1;
	printf("%s\n",create_word(word, level));
	return 0;
}