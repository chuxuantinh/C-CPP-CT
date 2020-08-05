/* Code by KingNNT */
#include <bits/stdc++.h>

#define pathio "/mnt/Learning And Working/Code/C-CPP/GNU-Compiler/In-Out/"
// #define pathio "E:/Code/C-CPP/GNU-Compiler/In-Out/"
#define lfi pathio"input.txt","r",stdin
#define lfo pathio"output.txt","w",stdout

using namespace std;

void Filter_Duplicate_Dumbers_with_Dynamic_Memory(long int *&a, long int &n)
{
	for (long int i = 0; i < n; i++)
		for (long int t = i + 1; t < n; t++)
		{
			while (a[i] == a[t])
			{
				for (long int j = i; j < n; j++)
					a[j] = a[j + 1];
				n--;
			}
		}
}

int main()
{
	freopen(lfi);
	freopen(lfo);
	// ios_base :: sync_with_stdio (0);
	cin.tie(0);

	long int n;
	cin >> n;
	long int *a = new long int[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	Filter_Duplicate_Dumbers_with_Dynamic_Memory(a, n);
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";

	fclose(stdin);
	fclose(stdout);
	return 0;
}