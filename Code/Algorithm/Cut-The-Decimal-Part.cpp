
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

    double number = 2;
    size_t decimal_places(2);
    cout << showpoint << setprecision(static_cast<int>(log10(number)) + 1 + decimal_places);
    cout << number << endl;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
