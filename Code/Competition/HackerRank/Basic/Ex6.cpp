/* Code by KingNNT */
#include <bits/stdc++.h>

#define pathio "/mnt/Learning And Working/Code/C-Extend/GNU-Compiler/In-Out/"
#define lfi pathio "input.txt", "r", stdin
#define lfo pathio "output.txt", "w", stdout

using namespace std;

int main()
{
    // freopen(lfi);
    // freopen(lfo);
    // // ios_base :: sync_with_stdio (0);
    // cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j < n - i - 1)
                cout << " ";
            else
                cout << "#";
        }
        cout << endl;
    }

    // fclose(stdin);
    // fclose(stdout);
    return 0;
}