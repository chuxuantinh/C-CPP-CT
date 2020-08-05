/* Code by KingNNT */
#include <bits/stdc++.h>

#define pathio "/mnt/Learning And Working/Code/C-CPP/GNU-Compiler/In-Out/"
// #define pathio "E:/Code/C-CPP/GNU-Compiler/In-Out/"
#define lfi pathio"input.txt","r",stdin
#define lfo pathio"output.txt","w",stdout

using namespace std;

void Delete(string &s, int vitrixoa)
{
	for (int i = vitrixoa; i < s.length(); i++)
		s[i] = s[i + 1];
	//s[s.length() - 1]= '\0'; // \0 là kí tự kết thúc chuỗi
	s.resize(s.length() - 1);
}

void Delete_Space(string &s)
{
	for (int i = 0; i < s.length(); i++)
		if (s[i] == ' ' && s[i + 1] == ' ')
		{
			Delete(s, i);
			i--;
		}
	if (s[0] == ' ')
		Delete(s, 0);
	if (s[s.length() - 1] == ' ')
		Delete(s, s.length() - 1);
}

int main()
{
	freopen(lfi);
	freopen(lfo);
	// ios_base :: sync_with_stdio (0);
	cin.tie(0);

	string s;
	fflush(stdin);
	getline(cin, s);
	Delete_Space(s);
	cout << s;

	fclose(stdin);
	fclose(stdout);
	return 0;
}