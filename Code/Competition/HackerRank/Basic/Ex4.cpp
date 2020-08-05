/* Code by KingNNT */
#include <bits/stdc++.h>

#define pathio "/mnt/Learning And Working/Code/C-Extend/GNU-Compiler/Test/"
#define lfi pathio "input.txt", "r", stdin
#define lfo pathio "output.txt", "w", stdout

using namespace std;

int main()
{
    // freopen(lfi);
    // freopen(lfo);
    // // ios_base ::sync_with_stdio(0);
    // cin.tie(0);

    int n;
    cin >> n;
    int arr[n + 5][n + 5];
    int left = 0,
        right = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            if (i == j)
            {
                left += arr[i][j];
            }
            if ((i + j) == (n - 1))
            {
                right += arr[i][j];
            }
        }
    cout << abs(left - right);

    // fclose(stdin);
    // fclose(stdout);
    return 0;
}