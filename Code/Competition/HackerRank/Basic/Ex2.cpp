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

    int a[5], b[5];
    cin >> a[0] >> a[1] >> a[2];
    cin >> b[0] >> b[1] >> b[2];

    int pa = 0, pb = 0;
    for (int i =0; i < 3; i++) {
        if (a[i] > b[i]) {
            pa ++;
        }
        else if (a[i] < b[i]) {
            pb++;
        }
    }
    cout << pa << " " << pb;
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}