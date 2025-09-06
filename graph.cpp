#include <bits/stdc++.h>
using namespace std;

// implementacija na graf bez tezini so adj list i matrica

int main(){
    int n=0,m=0;
    char kakov='\0';
    cin >> n >> m;
    cout << "Directed or not? d/u" << endl;
    cin >> kakov;

    vector<vector<int>> adj_list(n, vector<int>());
    int mat[n][n];

    for(int i=0; i<n; i++)
    {
        for(int j=0; j < n; j++)
        {
            mat[i][j] = 0;
        }
    }

    for(int i=0;i<m;i++)
    {
        int from=0, to=0;
        cin >> from >> to;

        if(kakov=='d')
        {
            adj_list[from].push_back(to);
            mat[from][to] = 1;
        }
        else if (kakov=='u')
        {
            adj_list[from].push_back(to);
            adj_list[to].push_back(from);

            mat[from][to] = 1;
            mat[to][from] = 1;
        }
    }

  
    for(int i = 0; i<n; i++)
    {
        cout << i << ": ";
        for(int j=0; j<adj_list[i].size(); j++)
        {
            cout << adj_list[i][j] << ' ';
        }

        cout << '\n';
    }

    cout << '\n';

     for(int i = 0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout << mat[i][j] << ' ';
        }

        cout << '\n';
    }


}