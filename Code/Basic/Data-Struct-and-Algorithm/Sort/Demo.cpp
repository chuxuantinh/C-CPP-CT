/*
Lưu ý: Thay đổi path file input và output cho đúng
*/


/* Code by KingNNT */
#include <bits/stdc++.h>

#define pathio "E:/Code/C-Extend/GNU-Compiler/Test/"
#define lfi pathio"input.txt","r",stdin
#define lfo pathio"output.txt","w",stdout

using namespace std;

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int* arr, int n)
{
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        swap(&arr[min_idx], &arr[i]);
    }
}

void InterchangeSort(int* arr, int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] > arr[j])
                swap(arr[i], arr[j]);
}

void printArray(int* arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void enterArray(int* arr, int size)
{
    for (int i = 0; i < size; i++)
        cin >> arr[i];
}

int main()
{
    freopen(lfi);
    freopen(lfo);
    ios_base :: sync_with_stdio (0);
    cin.tie(0);

    int n; cin >> n;
    int* arr = new int[n];
    enterArray(arr, n);

    // selectionSort(arr, n);
    InterchangeSort(arr, n);
    cout << "Sorted array: " << endl;

    printArray(arr, n);

    fclose(stdin);
    fclose(stdout);
    return 0;
}

/*
//////////////////////////////
/////		Input		//////
//////////////////////////////

7
22 25 64 11 12 29 2

//////////////////////////////
*/

/*
//////////////////////////////
/////		Output		//////
//////////////////////////////

Sorted array: 
2 11 12 22 25 29 64 


//////////////////////////////
*/