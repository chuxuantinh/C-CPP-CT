/* Code by KingNNT */
#include <bits/stdc++.h>

#define pathio "/mnt/Learning And Working/Code/C-Extend/GNU-Compiler/In-Out/"
#define lfi pathio "input.txt", "r", stdin
#define lfo pathio "output.txt", "w", stdout

using namespace std;

int shellSort(int *arr, int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
    return 0;
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
    freopen(lfi);
    freopen(lfo);
    // ios_base ::sync_with_stdio(0);
    cin.tie(0);

    cout << "Nhap so phan tu cua mang n = ";
    int n;
    cin >> n;
    int *arr = new int[n];
    enterArray(arr, n);
    cout << endl
         << "Before Sort" << endl;
    printArray(arr, n);

    shellSort(arr, n);

    cout << endl
         << "After Sort" << endl;
    printArray(arr, n);

    fclose(stdin);
    fclose(stdout);
    return 0;
}