/* Code by KingNNT */
#include <bits/stdc++.h>

#define pathio "/mnt/Learning And Working/Code/C-Extend/GNU-Compiler/In-Out/"
#define lfi pathio"input.txt","r",stdin
#define lfo pathio"output.txt","w",stdout

using namespace std;

long int Partition (long int *arr, long int low , long int high)
{
	long int pivot = arr[high];
	long int left = low;
	long int right = high - 1;
	while (true) {
		while (left <= right && arr[left] < pivot) left ++;
		while (right >= left && arr[right] > pivot) right --;
		if (left >= right) break;
		swap(arr[left],arr[right]);
		left ++;
		right --;
	}
		swap (arr[left],arr[high]);
		return left;
}

void quickSort(long int *arr, long int low, long int high)
{
	if (low < high){
		long int pi = Partition(arr,low,high);
		quickSort (arr,low,pi-1);
		quickSort (arr,pi+1,high);
	}
}

void enterArray(long int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

void printArray(long int *arr, int n)
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

    cout << "N = ";
    int n;
    cin >> n;
    long int *arr = new long int[n];
    enterArray(arr, n);
    cout << endl
         << "Before Sort" << endl;
    printArray(arr, n);

    quickSort(arr, 0, n-1);

    cout << endl
         << "After Sort" << endl;
    printArray(arr, n);

    fclose(stdin);
    fclose(stdout);
    return 0;
}