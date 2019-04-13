#include<stdio.h>
#include<stdlib.h>

void snale_matrix(int N);

int main()
{
	snale_matrix(5);
	
	return 0;
}

void snale_matrix(int N)
{
	int** arr = (int**)malloc(sizeof(int*)*N);
	int i,j, p, q;
	int delta = 1;
	int num = 1;
	int arr_len = N;
	
	
	for(i = 0; i < N; i++)
	{
		arr[i] = (int*)malloc(sizeof(int)*N);
	}
	
	i = 0, j = -1;
	
	while(1)
	{
		for(p = 0; p < N; p++)
		{
			j += delta;
			arr[i][j] = num++;
		}
		
		N--;
		
		if(N < 0) break;
		
		for(p = 0; p < N; p++)
		{
			i += delta;
		    arr[i][j] = num++;
		}
		
		delta = delta*(-1);
	}
	
	for(p = 0; p < arr_len; p++)
	{
		for(q = 0; q < arr_len; q++)
		{
			printf("%2d\t", arr[p][q]);
		}
		puts("");	 
	}

	
	for(i = 0; i < N; i++)
	{
		free(arr[i]);
	}
	free(arr);
}

