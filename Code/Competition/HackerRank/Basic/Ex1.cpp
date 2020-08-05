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
    int sum = 0; int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        sum += temp;
    }
    cout << sum;

    // fclose(stdin);
    // fclose(stdout);
    return 0;
}