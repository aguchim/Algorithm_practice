#include <iostream>
#include <string>
#include <list>
#include <random>
void swap(int* i, int* j);
void Sort1(int index[], int count);
int binarysearch(int index[], int size, int count);

int main(void)
{
	int Index[100];

	for (int i = 0; i < sizeof(Index)/ sizeof(int); i++)
	{
		Index[i] = rand() % 1000;
	}
	Sort1(Index, sizeof(Index) / sizeof(int));

	for (int i = 0; i < sizeof(Index) / sizeof(int); i++)
	{
		std::cout << Index[i];
		std::cout << "\n";
	}

	std::cout << "리스트 탐색 : ";
	int select = 450;
	std::cout << select;
	std::cout << "\n";
	std::cout << binarysearch(Index, sizeof(Index) / sizeof(int), select);
}

int binarysearch(int index[], int size,int count)
{
	int first = 0 , last = size -1 ,midle = (first+last)/2;

	while (first >= last)
	{
		midle = (first + last) / 2;
		if (index[midle] == count)
		{
			return count;
		}
		else if (index[midle] > count)
		{
			last = midle-1;
			continue;
		}
		else if (index[midle] < count)
		{
			first = midle+1;
			continue;
		}
	}
	return -1;
}

//선택 정렬
void Sort1(int index[],int count)
{
	int minindex;
	for (int i = 0; i < count; i++){
		minindex = i;
		for (int j = i; j < count; j++){
			if (index[j] < index[minindex]){
				minindex = j;
			}
		}
		swap(&index[i], &index[minindex]);
	}
}

//스왑 
void swap(int* i, int* j)
{
	int z = *i;
	*i = *j;
	*j = z;
}