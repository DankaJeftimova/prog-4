#include <bits/stdc++.h>
using namespace std;


void floyd_warshall(int n, vector<vector<int>>& mat, int inf)
{
    for(int k=0; k<n; k++)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(mat[i][k] < inf and mat[k][j] < inf)
                {
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                }
            }
        }
    }

}


int cost(int n, vector<vector<int>> mat, int inf, int l)
{
    long long int c = 0;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
            continue;

            if(mat[i][j] < inf)
            c += mat[i][j];
            else
            c+=l;
        }
    }

    return c;
}


int main()
{
    int n=0, m=0, l=0;
    cin >> n >> m >> l;

    vector<vector<int>> mat(n,vector<int>(n,-1)), dupla, dupla1;
    vector<vector<int>> edges;

    int maxe = 0;

    for(int i=0;i<m;i++)
    {
        int a=0,b=0,weight=0;
        cin >> a >> b >> weight;
        a--;
        b--;

        mat[a][b]=weight;
        mat[b][a] = weight; //nenasocen
        maxe = max(maxe, weight);

        edges.push_back({a,b,weight});
    }

    int inf = maxe + l;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(mat[i][j]==-1)
            {
                mat[i][j] = inf;
            }
        }
    }

    dupla1 = mat;

    floyd_warshall(n,mat,inf);

    cout << cost(n, mat, inf, l);

    int max_cost = 0;

    for(auto i:edges)
    {
        dupla = dupla1;
        int from = i[0];
        int to = i[1];
        int weight = i[2];
        
        dupla[from][to] = inf;
        dupla[to][from] = inf; //dvonasocen

        floyd_warshall(n,dupla,inf);
        int c = cost(n, dupla, inf, l);

        max_cost = max(max_cost, c);
    }

    cout << ' ' << max_cost; 


    return 0;
}