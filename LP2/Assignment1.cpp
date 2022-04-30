#include <bits/stdc++.h>
using namespace std;
void BFS(vector<vector<int>> &adjList, int n, int source)
{
    bool visited[15];
    for (int i = 0; i <= n; i++)
    {
        visited[i] = false;
    }

    queue<int> q;
    q.push(source);
    visited[source] = true;
    while (q.empty() == false)
    {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int v : adjList[u])
        { //traversing the list at that vertex index. u is the element at the queue front
            if (visited[v] == false)
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}
void DFSRec(vector<vector<int>> &adjList, int source2, bool visited2[])
{
    visited2[source2] = true;
    cout << source2 << " ";

    for (int u : adjList[source2])
    {
        if (visited2[u] == false)
            DFSRec(adjList, u, visited2);
    }
}
void DFS(vector<vector<int>> &adjList, int n, int source2)
{
    bool visited2[15];
    for (int i = 0; i < n; i++)
    {
        visited2[i] = false;
    }

    DFSRec(adjList, source2, visited2);
}
int main()
{
    //Adjacency matrix for undirected graph (hardcoded sizes, using array)
    // int n,m;
    // cout << "Enter no of nodes and no of edges:" << endl;
    // cin >> n >> m; //5,7
    // int adj_mat[6][6];
    // //make all elements 0 of adj_mat
    // for(int i=0;i<6;i++)
    // {
    //     for(int j=0;j<6;j++)
    //     {
    //         adj_mat[i][j] =0;
    //     }
    // }
    // //take edges as input
    // cout << "Enter edges:" << endl;
    // int u,v;
    // for(int i=0;i<7;i++) //since no of edges is 7
    // {
    //     cin >>u >> v;
    //     adj_mat[u][v]=1;
    //     adj_mat[v][u]=1;    //since undirected graph
    // }
    // //display matrix
    // for(int i=0;i<6;i++)
    // {
    //     for(int j=0;j<6;j++)
    //     {
    //         cout << adj_mat[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    //Adjacency matrix for undirected graph (using vector, dynamic sizes)
    // vector<vector<int>> adjMat;
    // int n, m;
    // cin >> n >> m;
    // adjMat.resize(n + 1, vector<int>(n + 1)); //no of rows, no of columns
    // for (int i = 0; i < m; i++)
    // {
    //     int u, v;
    //     cin >> u >> v;
    //     adjMat[u][v] = 1;
    //     adjMat[v][u] = 1;
    // }
    // for (vector<int> temp : adjMat)
    // {
    //     for (int i : temp)
    //     {
    //         cout << i << " ";
    //     }
    //     cout << endl;
    // }
    //Adjacency list for undirected graph
    int n, m;
    cout << "Enter no of vertices and no of edges:" << endl;
    cin >> n >> m;
    vector<vector<int>> adjList;
    adjList.resize(n + 1); //only specify no of rows, not number of columns
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cout << "Enter the edges (source and destination):" << endl;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    for (vector<int> temp : adjList)
    {
        for (int i : temp)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    char ans;
    int choice;
    do
    {
        cout << "MENU: \n 1.BFS \n 2.DFS \n"
             << endl;
        cout << "Enter choice:" << endl;
        cin >> choice;
        switch (choice)
        {

        case 1:
        {
            int source;
            cout << "Enter source vertex:" << endl;
            cin >> source;
            cout << "BFS:" <<endl;
            BFS(adjList, n, source);
        }
        break;
        case 2:
        {
            int source2;
            cout << "Enter source vertex:" << endl;
            cin >> source2;
            cout << "DFS:" <<endl;
            DFS(adjList, n, source2);
        }
        }
        cout << "Enter menu again?(y/n)" << endl;
        cin >> ans;
    } while (ans == 'y');

    return 0;
}