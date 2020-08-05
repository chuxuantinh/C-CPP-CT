/* Code by KingNNT */
#include <bits/stdc++.h>

#define pathio "/mnt/Learning And Working/Code/C-CPP/GNU-Compiler/In-Out/"
#define lfi pathio"input.txt","r",stdin
#define lfo pathio"output.txt","w",stdout

using namespace std;



int main()
{
    freopen(lfi);
    freopen(lfo);
    // ios_base :: sync_with_stdio (0);
    cin.tie(0);


    int mang1[100];

    int a[10][30];
    int m,n;


    m = 3; n = 4;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }


    fclose(stdin);
    fclose(stdout);
    return 0;
}