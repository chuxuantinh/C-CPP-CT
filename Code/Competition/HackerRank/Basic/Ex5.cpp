/* Code by KingNNT */
#include <bits/stdc++.h>

#define pathio "/mnt/Learning And Working/Code/C-Extend/GNU-Compiler/Test/"
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
    int positive = 0, negative = 0, zero = 0;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (a > 0) {
            positive++;
        }
        else if (a < 0) {
            negative++;
        }
        else
        {
            zero++;
        }
        
    }
    printf("%.6f\n%.6f\n%.6f", (float)positive / n, (float)negative / n, (float)zero / n);

    // fclose(stdin);
    // fclose(stdout);
    return 0;
}