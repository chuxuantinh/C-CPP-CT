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

void swap(book &a, book &b)
{
    book t = a;
    a = b;
    b = t;
}

int Partition_with_Dynamic_Memory (book* arr, int low , int high)
{
	int pivot = arr[high].getPrice();
	int left = low;
	int right = high - 1;
	while (true) {
		while (left <= right && arr[left].getPrice() < pivot) left ++;
		while (right >= left && arr[right].getPrice() > pivot) right --;
		if (left >= right) break;
		swap(arr[left],arr[right]);
		left ++;
		right --;
	}
		swap (arr[left],arr[high]);
		return left;
}

void Quicksort_with_Dynamic_Memory(book* arr, int low, int high)
{
	if (low < high){
		int pi = Partition_with_Dynamic_Memory(arr,low,high);
		Quicksort_with_Dynamic_Memory (arr,low,pi-1);
		Quicksort_with_Dynamic_Memory (arr,pi+1,high);
	}
	
}

int main()
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
    cout << endl << endl;

    cout << "Before Sort:" << endl;
    for (int i = 0; i < n; i++)
    {
        arr[i].getInfo();
        cout << endl;
    }

    Quicksort_with_Dynamic_Memory(arr, 0, n - 1);
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