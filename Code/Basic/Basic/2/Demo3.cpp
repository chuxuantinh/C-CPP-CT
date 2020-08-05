/* Code by KingNNT */
#include <bits/stdc++.h>

#define pathio "/mnt/Learning And Working/Code/C-CPP/GNU-Compiler/In-Out/"
#define lfi pathio "input.txt", "r", stdin
#define lfo pathio "output.txt", "w", stdout

using namespace std;

class boat
{
private:
    int id;
    float x, y, r;

public:
    boat()
    {
        id = 0;
        x = y = r = 0;
    }
    ~boat()
    {
        id = 0;
        x = y = r = 0;
    }

    void enter()
    {
        cin >> this->id >> this->x >> this->y >> this->r;
    }

    float getR()
    {
        return this->r;
    }

    float getX()
    {
        return this->x;
    }

    float getY()
    {
        return this->y;
    }

    int getID() {
        return this->id;
    }
};

boat max(boat *arr, int n)
{
    boat max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (max.getR() < arr[i].getR())
        {
            max = arr[i];
        }
    }
    return max;
}

boat min(boat *arr, int n)
{
    boat min = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (min.getR() > arr[i].getR())
        {
            min = arr[i];
        }
    }
    return min;
}

void check(int k, boat *arr, int n)
{
    vector<boat> canSee;
    for (int i = 0; i < n; i++)
    {
        float x = arr[k].getX() - arr[i].getX();
        float y = arr[k].getY() - arr[i].getY();
        float d = sqrt(pow(x,2) + pow(y,2));
        if (d <= arr[k].getR() && d != 0)
        {
            canSee.push_back(arr[i]);
        }
    }
    cout << arr[k].getID() << " " << canSee.size() << " ";
    for (auto i = canSee.begin(); i != canSee.end(); i++)
    {
        cout << (*i).getID() << " ";
    }
    cout << endl;
}

int main()
{
    freopen(lfi);
    freopen(lfo);
    // ios_base ::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    boat *arr = new boat[n];
    for (int i = 0; i < n; i++)
    {
        arr[i].enter();
    }
    cout << min(arr, n).getID() << " " << max(arr, n).getID() << endl;
    for (int i = 0; i < n; i++)
    {
        check(i,arr,n);
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}