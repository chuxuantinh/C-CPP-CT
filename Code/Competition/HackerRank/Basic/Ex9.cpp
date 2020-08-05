/* Code by KingNNT */
#include <bits/stdc++.h>

#define pathio "/mnt/Learning And Working/Code/C-Extend/GNU-Compiler/In-Out/"
#define lfi pathio"input.txt","r",stdin
#define lfo pathio"output.txt","w",stdout

using namespace std;



int main()
{
    freopen(lfi);
    freopen(lfo);
    // ios_base :: sync_with_stdio (0);
    cin.tie(0);

    string s; cin >> s;
    string x = s[0] + s[1];
    stringstream sx(x);
    int x = 0; sx >> x;
    int hour = x;
    cout << hour;
    if (s[8] == 'P') {

    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}