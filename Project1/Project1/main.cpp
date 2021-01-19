#include <iostream>
#include <string>
#include <list>
#include <random>


void Sort1(int index[], int count);
void swap(int* i, int* j);
int binarysearch(int index[], int size, int count);
int binarysearch(int index[], int Min, int Max, int midle, int count);
void mainBinarySearch();


int main(void)
{
	mainBinarySearch();
	return 0;
}


void mainBinarySearch()
{
	int Index[100];

	for (int i = 0; i < sizeof(Index)/ sizeof(int); i++)
	{
		Index[i] = rand() % 1000;
	}
	Sort1(Index, sizeof(Index) / sizeof(int));

	for (int i = 0; i < sizeof(Index) / sizeof(int); i++)
	{
		std::cout << "[";
		std::cout << i;
		std::cout << "]";
		std::cout << Index[i];
		std::cout << "\n";
	}

	std::cout << "����Ʈ Ž�� : ";
	int select = 966;
	std::cout << select;
	std::cout << "\n �Ϲ� : ";
	//�Ϲ�
	std::cout << binarysearch(Index, sizeof(Index) / sizeof(int), select);
	//���
	std::cout << "\n ��� : ";
	std::cout << binarysearch(Index, 0, sizeof(Index) / sizeof(int) - 1, (sizeof(Index) / sizeof(int) / 2), select);
}

//�Ϲ�
int binarysearch(int index[], int size,int count)
{
	int first = 0 , last = size -1 ,midle = (first+last)/2;
	while (first <= last)
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
//���
int binarysearch(int index[], int Min, int Max, int midle, int count)
{
	//std::cout << "[�ִ� : ";
	//std::cout << Max;
	//std::cout << "] [�ּ� : ";
	//std::cout << Min;
	//std::cout << "] [�߰� : ";
	//std::cout << midle;
	//std::cout << "] \n";

	if (index[midle] == count)
	{
		return count;
	}
	else if (Min >= Max)
	{
		return -1;
	}
	else if (index[midle] > count)
	{
		binarysearch(index, Min, midle - 1, (Min + midle - 1) / 2, count);
	}
	else if (index[midle] < count)
	{
		binarysearch(index, midle + 1, Max, (Max + midle + 1) / 2, count);
	}
}

//���� ����
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

//���� 
void swap(int* i, int* j)
{
	int z = *i;
	*i = *j;
	*j = z;
}