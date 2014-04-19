#include <stdio.h>
#include <string.h>

int fileParser()
{
	// file stream to open the input file
	FILE *ifp; 

	// to specify that we will be opning the file for reading it
	char *mode = "r"; 
	char str[1024];

	char *ptr1;
	char *ptr2;

	int count;
	count = 0;

	int num_select_attr = 0;

	ifp = fopen("input.txt", mode);

	if(ifp != NULL)
	{
		while (fgets(str, sizeof(str), ifp) != NULL)
		{
			count++;

			// select clause
			if(count == 1)
			{
				ptr1 = str;
				
				while(*ptr1 != '\0')
				{
					if(*ptr1 == ',')
						num_select_attr++;

					ptr1++;
				}

				num_select_attr++;

				char *select[num_select_attr];

				// bring it back at the start
				ptr1 = str;

				while(*ptr1 != ',')
				{
					ptr1++;
				}

				char temp[ptr1 - ptr2];
				memcpy(ptr1, ptr2, ptr1-ptr2+1);
				temp[ptr1-ptr2] = '\0';

				printf("%s\n", temp);

				/* printf("%i\n", num_select_attr); */
			}

			// number of grouping variables
			else if(count == 2)
			{

			}

			// grouping attributes
			else if(count == 3)
			{

			}

			// aggregate functions
			else if(count == 4)
			{

			}

			else
			{

			}
		}	

		return 0;
	}

	else
	{
		fprintf(stderr, "Can't open input file in.list!\n");
  		return -1;
	}
}

int main()
{
	fileParser();
}