/* Code by KingNNT */
#include <bits/stdc++.h>

#define pathio "/mnt/Learning And Working/Code/C-Extend/GNU-Compiler/Test/"
#define lfi pathio "input.txt", "r", stdin
#define lfo pathio "output.txt", "w", stdout

using namespace std;

class book
{
private:
    string id, name;
    int publishingYear, price;

public:
    book()
    {
        this->id = this->name = "";
        this->publishingYear = this->price = 0;
    }
    ~book()
    {
        this->id = this->name = "";
        this->publishingYear = this->price = 0;
    }

    void enter()
    {
        cin.ignore();
        cout << "ID: "; getline(cin, this->id);
        cout << "Name: "; getline(cin, this->name);
        cout << "Publishing Year: "; cin >> this->publishingYear;
        cout << "Price: "; cin >> this->price;
    }

    void getInfo()
    {
        cout << "ID = " << this->id << endl;
        cout << "Name = " << this->name << endl;
        cout << "Publishing Year = " << this->publishingYear << endl;
        cout << "Price = " << this->price << endl;
    }

    int getPrice() {
        return this->price;
    }
};

void insertionSort(book* arr, int n)
{
    int i, j;
    book key;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j].getPrice() > key.getPrice())
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int
main()
{
    // freopen(lfi);
    // freopen(lfo);
    // // ios_base ::sync_with_stdio(0);
    // cin.tie(0);

    int n; cin >> n;
    book* arr = new book[n];
    for (int i = 0; i < n; i++)
    {
        arr[i].enter();
    }
    insertionSort(arr, n);

    cout << endl << endl;

    for (int i = 0; i < n; i++)
    {
        arr[i].getInfo();
        cout << endl;
    }

    // fclose(stdin);
    // fclose(stdout);
    return 0;
}

/*
//////////////////////////////
/////		Input		//////
//////////////////////////////

5
ID001
Sach 1
2000
15000
ID002
Sach 2
2003
50000
ID003
Sach 3
2003
35000
ID004
Sach 4
2007
70000
ID005
Sach 5
2010
25000

//////////////////////////////
*/

/*
//////////////////////////////
/////		Output		//////
//////////////////////////////

ID = ID001
Name = Sach 1
Publishing Year = 2000
Price = 15000

ID = ID005
Name = Sach 5
Publishing Year = 2010
Price = 25000

ID = ID003
Name = Sach 3
Publishing Year = 2003
Price = 35000

ID = ID002
Name = Sach 2
Publishing Year = 2003
Price = 50000

ID = ID004
Name = Sach 4
Publishing Year = 2007
Price = 70000


//////////////////////////////
*/