/* Code by KingNNT */
#include <bits/stdc++.h>

#define pathio "E:/Code/C-CPP/GNU-Compiler/In-Out/"
#define lfi pathio "input.txt"
#define lfo pathio "output.txt"

using namespace std;

ifstream fi;
ofstream fo;

void checkGiai(int i)
{
    if (i == 0)
    {
        fo << "Giai Dac Biet";
        return;
    }
    if (i == 1)
    {
        fo << "Giai Nhat" << endl;
        return;
    }
    if (i == 2 || i == 3)
    {
        fo << "Giai Nhi" << endl;
        return;
    }
    if (i >= 4 && i <= 9)
    {
        fo << "Giai Ba" << endl;
        return;
    }
    if (i >= 10 && i <= 13)
    {
        fo << "Giai Bon" << endl;
        return;
    }
    if (i >= 14 && i <= 19)
    {
        fo << "Giai Nam" << endl;
        return;
    }
    if (i >= 20 && i <= 23)
    {
        fo << "Giai Sau" << endl;
        return;
    }
    if (i >= 24 && i <= 27)
    {
        fo << "Giai Bay" << endl;
        return;
    }
}

// Check input co trung cac giai tu dac biet den giai 7
bool checkFromOnetoEnd(int n, string arr_str[], string s)
{
    for (int i = 0; i < n; i++)
    {
        if (s == arr_str[i])
        {
            checkGiai(i);
            return true;
        }
    }
    return false;
}

// Check xem input co trung Khuyen Khich hay khong
bool checkKhuyenKhich(int n, string arr_str[], string s)
{
    for (int i = 0; i < n; i++)
    {
        string temp1(1, s[s.length() - 1]); // "1" + "9" => "19"
        string temp2(1, s[s.length() - 2]); // "9" + "1" => "91"
        string x = temp2 + temp1;           // 2 so cuoi cua INPUT

        string temp3(1, arr_str[i][arr_str[i].length() - 1]);
        string temp4(1, arr_str[i][arr_str[i].length() - 2]);
        string a = temp4 + temp3;
        // a => 2 so cuoi cua phan tu trong mang
        if (x == a)
        {
            fo << "Trung Giai Khuyen Khich" << endl;
            return true;
        }
    }
    return false;
}

int main()
{
    fi.open(lfi, fi.in);
    fo.open(lfo, fo.out);
    // use "fi >> " to read from file
    // use "fo << " to write to file
    ios_base ::sync_with_stdio(0);
    cin.tie(0);

    string arr_str[100];
    int n = 27;
    for (int i = 0; i < n; i++)
    {
        fi >> arr_str[i];
    }
    string s;
    fi >> s;

    if (checkFromOnetoEnd(n, arr_str, s) == false && checkKhuyenKhich(n, arr_str, s) == false)
    {
        fo << "Khong Trung Giai";
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}