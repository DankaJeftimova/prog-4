#include <bits/stdc++.h>
using namespace std;


const int inf = 1000000000;

int n;
vector<vector<int>> capacity, flow;
vector<int> height, excess, seen;
queue<int> excess_vertices;

void push(int u, int v) {
    int d = min(excess[u], capacity[u][v] - flow[u][v]);
    flow[u][v] += d;
    flow[v][u] -= d;
    excess[u] -= d; 
    excess[v] += d;
    if (d && excess[v] == d)
        excess_vertices.push(v);
}

void relabel(int u) {
    int d = inf;
    for (int i = 0; i < n; i++) {
        if (capacity[u][i] - flow[u][i] > 0)
            d = min(d, height[i]);
    }
    if (d < inf)
        height[u] = d + 1;
}

void discharge(int u) {
    while (excess[u] > 0) {
        if (seen[u] < n) {
            int v = seen[u];
            if (capacity[u][v] - flow[u][v] > 0 && height[u] > height[v])
                push(u, v);
            else 
                seen[u]++;
        } else {
            relabel(u);
            seen[u] = 0;
        }
    }
}

vector<vector<int>> make_graph(int n) 
{
    vector<vector<int>> edges;

    for(int i = 0; i < n - 1; i++)
    {
        int weight = 100 + (rand() % 300); 
        edges.push_back({i, i + 1, weight});
    }

    for(int i = 0; i < 7; i++)
    {
        int from = rand() % n;
        int to   = rand() % n;
        if (from == to) continue;

        int weight = 1 + (rand() % 145);  
        edges.push_back({from, to, weight});
    }

    return edges;
}



int max_flow(int s, int t) {
    height.assign(n, 0);
    height[s] = n;
    flow.assign(n, vector<int>(n, 0));
    excess.assign(n, 0);
    excess[s] = inf;
    for (int i = 0; i < n; i++) {
        if (i != s)
            push(s, i);
    }
    seen.assign(n, 0);

    while (!excess_vertices.empty()) {
        int u = excess_vertices.front();
        excess_vertices.pop();
        if (u != s && u != t)
            discharge(u);
    }

    int max_flow = 0;
    for (int i = 0; i < n; i++)
        max_flow += flow[i][t];
    return max_flow;
}


int main() {
    srand(time(0));

    bool koe;
    cout << "random graph = 0, input = 1\n";
    cin >> koe;

    if (koe == 0) {
        n = 50;
        auto edges = make_graph(n);

        capacity.assign(n, vector<int>(n, 0));

        for (auto &e : edges) {
            int u = e[0], v = e[1], c = e[2];
            if (c > 0)
                capacity[u][v] = c;
        }

        int result = max_flow(0, n - 1);
        cout << result << "\n";
        return 0;
    }

    int m;
    cin >> n >> m;

    capacity.assign(n, vector<int>(n, 0));

    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        capacity[u][v] = c;
    }

    int result = max_flow(0, n - 1);
    cout << result << "\n";

    return 0;
}