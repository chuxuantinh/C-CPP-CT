/* Code by KingNNT */
#include <bits/stdc++.h>

#define pathio "/mnt/Learning And Working/Code/C-CPP/GNU-Compiler/In-Out/"
// #define pathio "E:/Code/C-CPP/GNU-Compiler/In-Out/"
#define lfi pathio"input.txt","r",stdin
#define lfo pathio"output.txt","w",stdout

using namespace std;

// Dung Phep Tru
int gcd(int a, int b)
{
    if (a == 0 || b == 0)
    {
        return a + b;
    }
    while (a != b)
    {
        if (a > b)
        {
            a -= b;
        }
        else
        {
            b -= a;
        }
    }
    return a;
}

// Dung Phep Chia
int gcd2(int a, int b)
{
    while (a * b != 0)
    {
        if (a > b)
        {
            a %= b;
        }
        else
        {
            b %= a;
        }
    }
    return a + b;
}

// Dung Giai Thuat Euclid
int gcd3(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Khu De Quy
int gcd4(int a, int b)
{
    int tmp;
    while (b != 0)
    {
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

// Ham Co sSan Trong Thu Vien Algorithm
int gcd5(int a, int b)
{
    return __gcd(a, b);
}

int main()
{
    freopen(lfi);
    freopen(lfo);
    // ios_base :: sync_with_stdio (0);
    cin.tie(0);

    int a, b;
    cin >> a >> b;
    cout << "UCLN: " << gcd5(a, b);

    fclose(stdin);
    fclose(stdout);
    return 0;
}