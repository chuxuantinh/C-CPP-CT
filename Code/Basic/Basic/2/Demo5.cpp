/* Code by KingNNT */
#include <bits/stdc++.h>

#define pathio "/mnt/Learning And Working/Code/C-CPP/GNU-Compiler/In-Out/"
// #define pathio "E:/Code/C-CPP/GNU-Compiler/In-Out/"
#define lfi pathio "input.txt"
#define lfo pathio "output.txt"

using namespace std;

ifstream fi;
ofstream fo;

struct record
{
    int stt;
    string name;
    float d1, d2, d3;
};

void enterRecord(record &listRecord)
{
    cout << "Nhap STT: " << endl;
    cin >> listRecord.stt;
    cout << "Nhap Ho Ten: " << endl;
    fflush(stdin);
    getline(cin, listRecord.name);
    // cin >> listRecord.name;
    cout << "Nhap Diem 1/2/3: " << endl;
    cin >> listRecord.d1 >> listRecord.d2 >> listRecord.d3;
}

int DTB(float d1, float d2, float d3)
{
    return (d1 * 30 + d2 * 30 + d3 * 45) / 105;
}

string XL(int dtb)
{
    if (dtb >= 9)
        return "Gioi";
    else if (dtb >= 7)
        return "Kha";
    else if (dtb >= 5.5)
        return "Trung Binh";
    else
        return "Kem";
}

void printRecord(record listRecord)
{
    fo << "STT = " << listRecord.stt << endl;
    fo << "Ho Ten = " << listRecord.name << endl;
    fo << "Diem 1/2/3 = " << listRecord.d1 << " " << listRecord.d2 << " " << listRecord.d3 << endl;
    fo << "DTB = " << DTB(listRecord.d1, listRecord.d2, listRecord.d3) << endl;
    fo << "Xep Loai = " << XL(DTB(listRecord.d1, listRecord.d2, listRecord.d3)) << endl;
    fo << endl
       << endl;
}

int main()
{
    if (fi.fail() || fo.fail())
    {
        cout << "ERROR";
        return -1;
    }
    else
    {
        fi.open(lfi, fi.in);
        fo.open(lfo, fo.out);
    }
    // use "fi >> " to read from file
    // use "fo << " to write to file
    // ios_base :: sync_with_stdio (0);
    // cin.tie(0);

    int p;
    cout << "Nhap p = ";
    cin >> p;

    for (int i = 0; i < p; i++)
    {
        record listRecord;

        enterRecord(listRecord);
        printRecord(listRecord);
    }

    // fclose(stdin);
    // fclose(stdout);
    return 0;
}

/*
//////////////////////////////
/////		Input		//////
//////////////////////////////

4
1
Nguyen Van A
6 7 8
2
Nguyen Van B
7 8 9
3
Nguyen Van C
8 9 10
4
Nguyen Van D
9 9 9

//////////////////////////////
*/