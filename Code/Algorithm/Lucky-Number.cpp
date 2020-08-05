/* Code by KingNNT */
#include <bits/stdc++.h>

#define pathio "/mnt/Learning And Working/Code/C-CPP/GNU-Compiler/In-Out/"
// #define pathio "E:/Code/C-CPP/GNU-Compiler/In-Out/"
#define lfi pathio"input.txt","r",stdin
#define lfo pathio"output.txt","w",stdout

using namespace std;

int Sum_Number(int n)
{
	if (n < 10)
		return n;
	int sum = 0;
	while (n / 10 != 0)
	{
		sum += n % 10;
		n /= 10;
	}
	return sum + n;
}

bool Check(int n)
{
	if (n % Sum_Number(n) == 0)
		return true;
	else
		return false;
}

int main()
{
	freopen(lfi);
	freopen(lfo);
	// ios_base :: sync_with_stdio (0);
	cin.tie(0);

	int a;
	cin >> a;
	if (Check(a) == true)
		cout << "YES";
	else
		cout << "NO";

	fclose(stdin);
	fclose(stdout);
	return 0;
}