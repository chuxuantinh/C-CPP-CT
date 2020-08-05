/* Code by KingNNT */
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

	// Cấp phát bộ nhớ động cho ma trận m x n
	// Cách này phức tạp nhưng bạn sẽ có 1 mảng 2 chiều đúng nghĩa và có thể lấy phần tử bằng cách gọi a[i][j] thông thường như mảng tĩnh.
	int **a = new int *[m];
	for (int i = 0; i < m; i++)
		a[i] = new int[n];

	// Giải phóng bộ nhớ động cho ma trận
	for (int i = 0; i < m; i++)
		delete[] a[i];
	delete[] a;

	fclose(stdin);
	fclose(stdout);
	return 0;
}