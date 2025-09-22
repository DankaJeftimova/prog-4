#include <bits/stdc++.h>
using namespace std;


int dis(int i, int k, vector<vector<int>> &edges)
{
    for(auto vec:edges)
    {
        if(vec[0]==i and vec[1]==k)
        {
            return vec[2];
        }
    }

    return INT_MAX;

}

void change(int i, int j, int value, vector<vector<int>> &edges)
{
    for(auto &vec:edges)
    {
        if(vec[0]==i and vec[1]==j)
        {
            vec[2] = value;
            return;
        }
    }
}


void floyd_warshall(int n, vector<vector<int>> &edges)
{
    for(int k=0; k<n;k++)
    {
        for(int i=0; i<n;i++)
        {
            for(int j=0; j<n;j++)
            {
                int d1 = dis(i,k,edges);
                int d2 = dis(k,j,edges);
                if(d1 < INT_MAX and d2 < INT_MAX)
                {
                    if(d1+d2 < dis(i,j,edges))
                    {
                        change(i,j,d1+d2,edges);
                    }
                }
            }
        }
    }
}


int main()
{
    int n=0,m=0;
    cin >> n >> m;
    vector<vector<int>> edges;

    for(int i=0;i<m;i++)
    {
        int a=0,b=0,weight=0;
        cin >> a >> b >> weight;

        edges.push_back({a,b,weight});
    }

    floyd_warshall(n,edges);

    for(auto vec:edges)
    {
        cout << vec[0] << "->" << vec[1] << " :" << vec[2] << endl;
    }

    cout << "All other paths are infinite";

    return 0;
}