#include "libft.h"
#include <libc.h>
#include <stdio.h>

char	**ft_split(char const *s, char c)
{
	char		**splitAr;
	char		**tmpPtr;
	char		*occu;
	int			lenOfSplit;
	long int	actualAlloc;
	char		**resizedArr;

	// search until find 1st occurence of c
	// then create create new var for what is found
	// add the pointer to the array??
	// move to next
	splitAr = (char **)malloc(sizeof(char *) * ft_strlen(s));
	tmpPtr = splitAr;
	while (*s)
	{
		occu = ft_memchr(s, c, ft_strlen(s));
		lenOfSplit = (occu == NULL ? ft_strlen(s) : occu - s);
		if (lenOfSplit < 1)
		{
			s++;
			continue ;
		}
		*tmpPtr = (char *)malloc(lenOfSplit + 1);
		if (tmpPtr == NULL)
		{
			printf("Allocation failed\n");
			return (NULL);
		}
		ft_strlcpy(*tmpPtr, s, lenOfSplit + 1);
		s += (occu == NULL ? lenOfSplit : lenOfSplit + 1);
		tmpPtr++;
	}
	// Resize final output
	actualAlloc = (tmpPtr - splitAr);
	resizedArr = (char **)malloc(sizeof(char *) * (actualAlloc + 1));
	if (resizedArr == NULL)
	{
		printf("Allocation failed\n");
		return (NULL);
	}
	for (int i = 0; i < actualAlloc; i++)
	{
		resizedArr[i] = splitAr[i];
	}
	resizedArr[(actualAlloc)] = NULL;
	free(splitAr);
	return (resizedArr);
}

// int printArr(char **ptr)
// {
//     int i = 0;
//     while (ptr[i])
//     {
//         printf("%d\t%p -> %s\n", i, ptr[i], ptr[i]);
//         i++;
//     }

//     return (0);
// }

// int main()
// {
//     char tst0[] = "anatlpha\tlie\t";
//     char **res = ft_split(tst0, 'l');
//     printArr(res);

//     char **res1 = ft_split(&"      split       this for   me  !       "[0],'\t');
		//     printArr(res1);

		//     char **res2 = ft_split(&"      split       this for   me  !       "[0],' ');
		//     printArr(res2);

		//     return (0);
		// }