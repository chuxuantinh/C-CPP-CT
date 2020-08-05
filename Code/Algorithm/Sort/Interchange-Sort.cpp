/* Code by KingNNT */
#include <bits/stdc++.h>

#define pathio "/mnt/Learning And Working/Code/C-Extend/GNU-Compiler/In-Out/"
#define lfi pathio "input.txt", "r", stdin
#define lfo pathio "output.txt", "w", stdout

using namespace std;

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
void enter(int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Phan tu arr[" << i << "]"
			 << " = ";
		cin >> arr[i];
	}
}

void print(int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
}

void InterchangeSort(int *arr, int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (arr[i] > arr[j])
				swap(arr[i], arr[j]);
}

int main()
{
	freopen(lfi);
	freopen(lfo);
	// ios_base ::sync_with_stdio(0);
	cin.tie(0);

	cout << "Nhap so phan tu cua mang n = ";
	int n;
	cin >> n;
	int *arr = new int[n];
	enter(arr, n);
	cout << endl << "Before Sort" << endl;
	print(arr, n);

	InterchangeSort(arr, n);
	
	cout << endl << "After Sort" << endl;
	print(arr, n);

	fclose(stdin);
	fclose(stdout);
	return 0;
}

/*
//////////////////////////////
/////		Input		//////
//////////////////////////////

5
2 1 5 4 3

//////////////////////////////
*/

/*
//////////////////////////////
/////		Output		//////
//////////////////////////////

Before Sort
2 1 5 4 3 
After Sort
1 2 3 4 5 

//////////////////////////////
*/