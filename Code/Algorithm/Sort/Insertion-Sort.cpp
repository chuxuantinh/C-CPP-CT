/* Code by KingNNT */
#include <bits/stdc++.h>

#define pathio "/mnt/Learning And Working/Code/C-Extend/GNU-Compiler/In-Out/"
#define lfi pathio "input.txt", "r", stdin
#define lfo pathio "output.txt", "w", stdout

using namespace std;

void insertionSort(int* arr, int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void enterArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}
void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    // freopen(lfi);
    // freopen(lfo);
    // // ios_base ::sync_with_stdio(0);
    // cin.tie(0);

    int n; cin >> n;
    int *arr = new int[n];
    enterArray(arr, n);

    insertionSort(arr, n);
    
    printArray(arr, n);

    // fclose(stdin);
    // fclose(stdout);
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

2 11 12 22 25 29 64 

//////////////////////////////
*/