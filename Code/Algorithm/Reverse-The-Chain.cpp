// Đảo Ngược Chuỗi

/* Code by KingNNT */
#include <bits/stdc++.h>

#define pathio "/mnt/Learning And Working/Code/C-CPP/GNU-Compiler/In-Out/"
// #define pathio "E:/Code/C-CPP/GNU-Compiler/In-Out/"
#define lfi pathio"input.txt","r",stdin
#define lfo pathio"output.txt","w",stdout

using namespace std;

string Reverse_1(string s)
{
	string x;
	for (int i = s.length() - 1; i >= 0; i--)
		x += s[i];
	return x;
}

void Reverse_2(char c[])
{
	cout << strrev(c);
}

int main()
{
	freopen(lfi);
	freopen(lfo);
	// ios_base :: sync_with_stdio (0);
	cin.tie(0);

	char c[100];
	fflush(stdin);
	gets(c);
	Reverse_2(c);

	fclose(stdin);
	fclose(stdout);
	return 0;
}