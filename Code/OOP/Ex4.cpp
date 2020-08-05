/* Code by KingNNT */
#include <bits/stdc++.h>

#define pathio "/mnt/Learning And Working/Code/C-CPP/GNU-Compiler/In-Out/"
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
        cout << "ID: ";
        getline(cin, this->id);
        cout << "Name: ";
        getline(cin, this->name);
        cout << "Publishing Year: ";
        cin >> this->publishingYear;
        cout << "Price: ";
        cin >> this->price;
    }

    void getInfo()
    {
        cout << "ID = " << this->id << endl;
        cout << "Name = " << this->name << endl;
        cout << "Publishing Year = " << this->publishingYear << endl;
        cout << "Price = " << this->price << endl;
    }

    int getPrice()
    {
        return this->price;
    }
};

void swap(book &a, book &b)
{
    book t = a;
    a = b;
    b = t;
}

void merge(book *arr, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    book L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];

    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2)
    {
        if (L[i].getPrice() <= R[j].getPrice())
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(book *arr, int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main()
{
    // freopen(lfi);
    // freopen(lfo);
    // // ios_base ::sync_with_stdio(0);
    // cin.tie(0);

    int n;
    cin >> n;
    book *arr = new book[n];
    for (int i = 0; i < n; i++)
    {
        arr[i].enter();
    }
    cout << endl
         << endl;

    cout << "Before Sort:" << endl;
    for (int i = 0; i < n; i++)
    {
        arr[i].getInfo();
        cout << endl;
    }

    mergeSort(arr, 0, n-1);

    cout << "After Sort:" << endl;
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

Before Sort:
ID = ID001
Name = Sach 1
Publishing Year = 2000
Price = 15000

ID = ID002
Name = Sach 2
Publishing Year = 2003
Price = 50000

ID = ID003
Name = Sach 3
Publishing Year = 2003
Price = 35000

ID = ID004
Name = Sach 4
Publishing Year = 2007
Price = 70000

ID = ID005
Name = Sach 5
Publishing Year = 2010
Price = 25000

After Sort:
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