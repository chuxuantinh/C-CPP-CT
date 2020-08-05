/* Code by KingNNT */
#include <bits/stdc++.h>

#define pathio "/mnt/Learning And Working/Code/C-CPP/GNU-Compiler/In-Out/"
// #define pathio "E:/Code/C-CPP/GNU-Compiler/In-Out/"
#define lfi pathio"input.txt","r",stdin
#define lfo pathio"output.txt","w",stdout

using namespace std;

bool Check(int a)
{
	if (a <= 1)
		return false;
	if (a == 2)
		return true;
	for (int i = 2; i <= (int)sqrt(a) + 1; i++)
	{
		if (a % i == 0)
			return false;
	}
	return true;
}

int main()
{
	freopen(lfi);
	freopen(lfo);
	// ios_base :: sync_with_stdio (0);
	cin.tie(0);

	int a;
	cin >> a;
	Check(a);

	fclose(stdin);
	fclose(stdout);
	return 0;
}