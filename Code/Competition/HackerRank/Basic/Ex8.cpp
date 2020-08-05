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

    int n; cin >> n;
    long long int max = -((1LL << 31) - 1);
    int dem = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (max <= a) {
            if (max < a) dem = 0;
            max = a;
            dem++;
        }
    }
    cout << dem;

    // fclose(stdin);
    // fclose(stdout);
    return 0;
}