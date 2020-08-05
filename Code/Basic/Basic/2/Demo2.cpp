/* Code by KingNNT */
#include <bits/stdc++.h>

#define pathio "/mnt/Learning And Working/Code/C-CPP/GNU-Compiler/In-Out/"
#define lfi pathio "input.txt"
#define lfo pathio "output.txt"

using namespace std;

int n;
int id[100];
float x[100], y[100], r[100];

ifstream fi;
ofstream fo;

void check(int k)
{

    int dem = 0;
    int j = 0;
    int id_tau_nhin_thay[100];

    for (int i = 0; i < n; i++)
    {
        float d = sqrt((x[k] - x[i]) * (x[k] - x[i]) + (y[k] - y[i]) * (y[k] - y[i]));
        cout << d << " " << r[i] << endl;
        if (d <= r[k] && d != 0)
        {
            dem++;
            id_tau_nhin_thay[j] = id[i];
            j++;
        }
    }

    fo << " " << dem;
    for (int i = 0; i < dem; i++)
    {
        fo << " " << id_tau_nhin_thay[i];
    }
    fo << endl;
}

int  max()
{
    int max = r[0];
    int max_i;
    for (int i = 1; i < n; i++)
    {
        if (max < r[i])
        {
            max = r[i];
            max_i = i;
        }
    }
    return id[max_i];
}

int min()
{
    int min = r[0];
    int min_i;
    for (int i = 1; i < n; i++)
    {
        if (min > r[i])
        {
            min = r[i];
            min_i = i;
        }
    }
    return id[min_i];
}

int main()
{
    fi.open(lfi, fi.in);
    fo.open(lfo, fo.out);
    // use "fi >> " to read from file
    // use "fo << " to write to file
    // ios_base :: sync_with_stdio (0);
    cin.tie(0);

    fi >> n;

    for (int i = 0; i < n; i++)
    {
        fi >> id[i] >> x[i] >> y[i] >> r[i];
    }

    fo << min() << " " << max() << endl;

    for (int i = 0; i < n; i++)
    {
        fo << id[i];
        check(i);
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}