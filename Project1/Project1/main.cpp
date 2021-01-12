#include <iostream>
using namespace std;

int main()
{
	int v1,v2;
	cout << "n의 제곱수 구하기\n";
	cout << "n : ";
	cin >> v1;
	cout << "몇제곱 : ";
	cin >> v2;
	cout << "결과 : ";
	cout << pow(v1, v2);
	return 0;
}

int pow(int V1, int V2)
{
	int v1 = V1;
	for (size_t i = 0; i < V2; i++)
	{
		V1 *= v1;
	}
	return v1;
}