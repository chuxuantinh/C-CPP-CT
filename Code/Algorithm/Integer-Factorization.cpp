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

    int n;
    cout << "Nhap n = ";
    cin >> n;
    int dem;
    for (int i = 2; i <= n; i++)
    {
        dem = 0;
        while (n % i == 0)
        {
            ++dem;
            n /= i;
        }
        if (dem)
        {
            cout << i;
            if (dem > 1)
                cout << "^" << dem;
            if (n > i)
            {
                cout << " * ";
            }
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}