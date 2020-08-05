/* Code by KingNNT */
#include <bits/stdc++.h>

#define pathio "/mnt/Learning And Working/Code/C-Extend/GNU-Compiler/In-Out/"
#define lfi pathio"input.txt","r",stdin
#define lfo pathio"output.txt","w",stdout

using namespace std;

void CocktailSort(int *arr, int n)
{
    bool swapped = true;
    int start = 0;
    int end = n - 1;

    while (swapped)
    {
        swapped = false;
        for (int i = start; i < end; ++i)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }

        if (!swapped)
            break;

        swapped = false;
        --end;

        for (int i = end - 1; i >= start; --i)
        {
            if (arr[i] > arr[i + 1])
            {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        ++start;
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
    freopen(lfi);
    freopen(lfo);
    ios_base :: sync_with_stdio (0);
    cin.tie(0);

    cout << "Nhap so phan tu cua mang n = ";
	int n; cin >> n;
	int *arr = new int[n];
    enterArray(arr, n);
    cout << endl << "Before Sort" << endl;
    printArray(arr, n);

    CocktailSort(arr, n);
    
    cout << endl << "After Sort" << endl;
    printArray(arr, n);

    fclose(stdin);
    fclose(stdout);
    return 0;
}