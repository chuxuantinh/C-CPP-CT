/* Code by KingNNT */
#include <bits/stdc++.h>
using namespace std;

#define pathio "/media/kingnnt/Learning And Working/Code/C-Extend/GNU-Compiler/Test/"
#define lfi pathio "input.txt"
#define lfo pathio "output.txt"

// #define INFINITY ((1LL << 31) - 1)
#define INFINITY 9999
#define MAXNODE 10

int nodes;
// int GRAPH[MAXNODE][MAXNODE];

void readMatrix(ifstream &fi, int &nodes, int **&GRAPH)
{
    if (fi.is_open())
    {
        // fi >> nodes;

        // string line;
        // getline(fi, line);
        // fo << line << endl;
        for (int i = 0; i < nodes; i++)
        {
            for (int j = 0; j < nodes; j++)
            {
                fi >> GRAPH[i][j];
            }
        }
    }
    else
    {
        cout << "Error: Don't open file !!!";
    }
}

void printfMatrix(ofstream &fo, int nodes, int **GRAPH)
{
    for (int i = 0; i < nodes; i++)
    {
        for (int j = 0; j < nodes; j++)
        {
            fo << GRAPH[i][j] << " ";
        }
        fo << endl;
    }
}

void setInfinityInColumn(int **GRAPH[][], int i)
{
    int min = INFINITY;
    for (int j = 0; j < nodes; j++)
    {
        if (GRAPH[i][j] == 0)
        {
            GRAPH[i][j] = INFINITY;
        }
    }
}

void setInfinityForGraph() {
    for (int i = 0; i < nodes; i++)
        for (int j = 0; j < nodes; j++) {
            if (GRAPH[i][j] == 0) {
                GRAPH[i][j] = INFINITY;
            }
        }
}

    int
    findMinInColumn(int **GRAPH[][], int i)
{
    int min = INFINITY;
    for (int j = 0; j < nodes; j++)
    {
        if (min < GRAPH[i][j])
        {
            min = GRAPH[i][j];
        }
    }
    return min;
}

// Xet theo tung cot mot trong ma tran ke
void dijkstra(int **&GRAPH, int *&visited)
{

    int minInCol;
    for (int i = 0; i < nodes; i++)
    {
        setInfinityForGraph();
        if (visited[i] == false)
        {
            // setInfinityInColumn(GRAPH, i);
            minInCol = findMinInColumn(GRAPH, i);
            for (int j = 0; j < nodes; j++) {
                if (GRAPH[i][j] < pred[j]) {
                    pred[j] = GRAPH[i][j];
                }
            }
            visited[i] = true;
        }
    }
}

int main()
{
    ifstream fi;
    ofstream fo;
    fi.open(lfi, fi.in);
    fo.open(lfo, fo.out);
    // use "fi >> " to read from file
    // use "fo << " to write to file
    // ios_base :: sync_with_stdio (0);
    cin.tie(0);

    fi >> nodes;

    // GRAPH la ma tran ke bieu dien do thi
    int **GRAPH = new int *[nodes];
    for (int i = 0; i < nodes; i++)
    {
        GRAPH[i] = new int[nodes];
    }

    // pred la mang luu cac gia tri luc truoc cua hang
    int *pred = new int[MAXNODE];
    for (int i = 0; i < nodes; i++) {
        pred[i] = INFINITY;
    }

    // visited la mang luu xem da di den node nay hay chua
    bool *visited = new int[MAXNODE];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    readMatrix(fi, nodes, GRAPH);
    printfMatrix(fo, nodes, GRAPH);

    fo << "Chon Node Bat Dau: ";

    fclose(stdin);
    fclose(stdout);
    return 0;
}