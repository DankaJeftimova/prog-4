#include <bits/stdc++.h>
using namespace std;


void dijkstra(int start, int n, vector<vector<pair<int, int>>> & graph, vector<int> & dist)
{

    bool vis[n];
    for(int i=0; i<n; i++)
    {
        dist[i] = INT_MAX;
        vis[i] = 0;
    }

    priority_queue<pair<int,int>> pq;
    pq.push({0, start});

    dist[start] = 0;

    while(!pq.empty())
    {
        auto now = pq.top();
        pq.pop();

        int node = now.second;
        int w = -now.first;

        for(auto i:graph[node])
        {
            int next = i.second;
            int to_next = i.first;

            if(vis[next]==0)
            {
                vis[next]=1;
                if(dist[next] > w+to_next)
                {
                    dist[next] = w+to_next;
                    pq.push({-dist[next],next});
                }


            }
        }
    }


}


int main(){
    int n=0,m=0;
    char kakov='\0';
    cin >> n >> m;
    cout << "Directed or not? d/u" << endl;
    cin >> kakov;

    vector<vector<pair<int,int>>> adj_list(n, vector<pair<int,int>>());

    for(int i=0;i<m;i++)
    {
        int from=0, to=0, weight=0;
        cin >> from >> to >> weight;

        if(kakov=='d')
        {
            adj_list[from].push_back({weight,to});
        }
        else if (kakov=='u')
        {
            adj_list[from].push_back({weight,to});
            adj_list[to].push_back({weight,from});
        }
    }

    vector<int> dist(n,0);

    dijkstra(0,n,adj_list,dist);

    for(int i=0; i<n; i++)
    cout << dist[i] << ' ';

  
    

}