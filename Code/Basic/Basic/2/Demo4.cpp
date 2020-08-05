/* Code by KingNNT */
#include <bits/stdc++.h>

#define pathio "/mnt/Learning And Working/Code/C-CPP/GNU-Compiler/In-Out/"
// #define pathio "E:/Code/C-CPP/GNU-Compiler/In-Out/"
#define lfi pathio"input.txt","r",stdin
#define lfo pathio"output.txt","w",stdout

using namespace std;



int main()
{
    freopen(lfi);
    freopen(lfo);
    // ios_base :: sync_with_stdio (0);
    cin.tie(0);

    int m,n; cin >> m >> n;
    int arr[m][n];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    int max = arr[0][0];
    for (int i = 0; i < m; i++)
    {
        for (int j = 1; j < n; j = j + 2)
        {
            if (arr[i][j] > max) max = arr[i][j];
        }
    }

    cout << "MAX = " << max << endl;

    int min = arr[0][0];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j = j + 2)
        {
            if (arr[i][j] < min)
                min = arr[i][j];
        }
    }
    cout << "MIN = " << min << endl;

    fclose(stdin);
    fclose(stdout);
    return 0;
}