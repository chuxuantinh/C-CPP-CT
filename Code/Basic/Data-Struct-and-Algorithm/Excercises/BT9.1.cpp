/* Code by KingNNT */
#include <bits/stdc++.h>
using namespace std;

#define pathio "E:/Code/C-Extend/GNU-Compiler/Test/"
#define fi pathio"input.txt","r",stdin
#define fo pathio"output.txt","w",stdout

class Date
{
private:
	int ngaysinh;
	int thangsinh;
	int namsinh;
public:
	Date()
	{
		ngaysinh = thangsinh = namsinh = 0;
	}
	~Date()
	{
		ngaysinh = thangsinh = namsinh = 0;
	}

	void input()
	{
		cout << "Nhap Ngay Sinh: "; cin >> this->ngaysinh;
		cout << "Nhap Thang Sinh: "; cin >> this->thangsinh;
		cout << "Nhap Nam Sinh: "; cin >> this->namsinh;
	}
	void output()
	{
		cout << "Ngay/Thang/Nam Sinh: " << this->ngaysinh << "/" << this->thangsinh << "/" << this->namsinh << endl;	
	}
};

class sinhvien
{
private:
	string malop, msv,ten;
	Date namsinh;
	int diem1, diem2, diem3;
public:
	sinhvien()
	{
		malop = msv = ten = "";
		diem1 = diem2 = diem3 = 0;
	}
	void input()
	{
		cin.ignore();
		cout << "Nhap Ma Lop: "; getline(cin,malop);
		cout << "Nhap Ma Sinh Vien: "; getline(cin,msv);
		cout << "Nhap Ten: "; getline(cin,ten);
		namsinh.input();
		fflush(stdin);
		cout << "Nhap Diem 1: "; cin >> diem1;
		cout << "Nhap Diem 2: "; cin >> diem2;
		cout << "Nhap Diem 3: "; cin >> diem3;
	}

	void output()
	{
		cout << "Ma Lop: " << malop << endl;
		cout << "Ma Sinh Vien: " << msv << endl;
		cout << "Ten: " << ten << endl;
		namsinh.output();
		cout << "Diem 1 = " << diem1 << endl;
		cout << "Diem 2 = " << diem2 << endl;
		cout << "Diem 3 = " << diem3 << endl;
	}

	string getMaSinhVien()
	{
		return msv;
	}
};

struct node
{
	int key;
	sinhvien data;
	node* next;
};

node* head = NULL;

void PrintTypeJSON (node* &ptr)
{
		cout << endl << "{" << endl;
		cout << "Key: " << ptr->key << endl;
		cout << "Data: " << endl;
		cout << "{" << endl;
		ptr->data.output();
		cout << "}" << endl;
		cout << "}" << endl;
		ptr = ptr->next;
}

void DisplayForWard()
{
	node* ptr = head;
	while (ptr != NULL)
	{
		PrintTypeJSON(ptr);
	}
}

void InsertFirst(int temp_key)
{
	sinhvien temp_data;
	temp_data.input();

	node* ptr = new node;
	ptr->key = temp_key;
	ptr->data = temp_data;

	ptr->next = head;
	head = ptr;
}

bool IsEmpty ()
{
	if (head == NULL) return true; else return false;
}

node* DeleteNodeWithMSV(string msv)
{
	if (IsEmpty() == true) return NULL;

	node * prev = new node;
	node* ptr = head;
	while (ptr->data.getMaSinhVien() != msv)
	{
		if (ptr->next == NULL) break;
		else
		{
			prev = ptr;
			ptr = ptr->next;
		}
		
	}

	ptr == head ? ptr = ptr->next :	prev->next = ptr->next;
	return ptr;
}
int main()
{
	freopen(fi);
    freopen(fo);
	ios_base :: sync_with_stdio (0);
	cin.tie(0);
	
	int n;
	cout << "Nhap So Sinh Vien: "; cin >> n;
	for (int i = 0; i < n; i++) InsertFirst(i);

	cout << endl << endl << "Output" << endl << endl;
	DisplayForWard();

	cout << "Nhap Ma Sinh Vien Can Xoa: "; string msv; fflush(stdin); getline(cin,msv);
	node* Node_Delete = DeleteNodeWithMSV(msv);
	if (Node_Delete == NULL) cout << "Don't have node"; else DisplayForWard();

}

/*
//////////////////////////////
/////		INPUT		//////
//////////////////////////////

3
D13CNPM1
18810310100
Nguyen Van A
1 1 2000
8 9 10
D13CNPM2
18810310101
Nguyen Van B
2 2 1999
8 8 8
D13CNPM3
18810310101
Nguyen Van C
3 3 1998
7 7 7

*/
/*
//////////////////////////////
/////		BUG			//////
//////////////////////////////

- Hỡi nhân loại vì sao lại code simple linked list.
- Don't have Bug :)

//////////////////////////////
*/