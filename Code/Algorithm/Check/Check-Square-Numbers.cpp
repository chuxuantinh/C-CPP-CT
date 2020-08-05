/* Code by KingNNT */
#include <bits/stdc++.h>

#define pathio "/mnt/Learning And Working/Code/C-CPP/GNU-Compiler/In-Out/"
// #define pathio "E:/Code/C-CPP/GNU-Compiler/In-Out/"
#define lfi pathio"input.txt","r",stdin
#define lfo pathio"output.txt","w",stdout

using namespace std;

bool Check(int a)
{
	if ((float)sqrt(a) == (int)sqrt(a))
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