#include <bits/stdc++.h>
using namespace std;


struct Edge
{
    int from, to;
    long long cap, flow=0;
    Edge(int u, int v, long long c){
        from = u;
        to=v;
        cap = c;
    }
};


struct Dinic
{
    long long inf = 1e18;
    vector<Edge> edges;
    vector<vector<int>> graph;

    int n, m=0;
    int s,t;

    vector<int> level, ptr;
    queue<int> q;

    Dinic(int ni, int si, int ti)
    {
        n = ni;
        s = si;
        t = ti;

        graph.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add(int v, int u, long long cap)
    {
        edges.push_back(Edge(v,u,cap));
        edges.push_back(Edge(u,v,0));

        graph[v].push_back(m);
        graph[u].push_back(m+1);

        m+=2;
    }

    bool bfs()
    {
        while(!q.empty())
        {
            int node = q.front();

            q.pop();

            for(int next_id:graph[node])
            {
                if(edges[next_id].cap == edges[next_id].flow)
                {
                    continue;
                }

                if(level[edges[next_id].to] != -1)
                    continue;

                level[edges[next_id].to] = level[node] + 1;
                q.push(edges[next_id].to);
            }

            
        }

        return level[t] != -1;
    }

    long long dfs(int v, long long pushed)
    {
        if(pushed==0)
        return 0;

        if (v==t)
        return pushed;

        for(int &node = ptr[v]; node< (int)graph[v].size(); node++)
        {
            int id = graph[v][node];
            int u = edges[id].to;

            if(level[v]+1 != level[u])
            continue;

            long long tr = dfs(u,min(pushed,edges[id].cap-edges[id].flow));
            if(tr == 0)
            continue;

            edges[id].flow += tr;

            edges[id^1].flow -=tr;
            return tr;
        }

        return 0;
    }


    long long flow()
    {
        long long f=0;

        while(true)
        {
            fill(level.begin(),level.end(), -1);
            level[s] = 0;

            q.push(s);

            if(!bfs())
            break;

            fill(ptr.begin(), ptr.end(), 0);

            while(long long pushed = dfs(s,inf))
            {
                f+=pushed;
            }
        }

        return f;

    }

};



int main() 
{
    int n = 0, m=0, s = 0, t = 0;
    cin >> n >> m >> s >> t;

    Dinic dinic(n, s, t);

    for(int i=0; i<m;i++)
    {
        int a=0,b=0,c=0;
        cin >> a >> b >> c;

        dinic.add(a,b,c);
    }

    long long fl = dinic.flow();
    cout << fl;

    return 0;
}