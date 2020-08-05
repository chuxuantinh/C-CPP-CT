/* Code by KingNNT */
#include <bits/stdc++.h>

#define pathio "/mnt/Learning And Working/Code/C-Extend/GNU-Compiler/In-Out/"
#define lfi pathio"input.txt","r",stdin
#define lfo pathio"output.txt","w",stdout

using namespace std;



int main()
{
    // freopen(lfi);
    // freopen(lfo);
    // // ios_base :: sync_with_stdio (0);
    // cin.tie(0);
    long long int min = ((1LL << 31) - 1), max = -((1LL << 31) - 1), sum = 0;
    int n = 5;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        sum += a;
        if (min > a) min = a;
        if (max < a) max = a;
    }
    cout << sum - max << " " << sum - min;

    // fclose(stdin);
    // fclose(stdout);
    return 0;
}