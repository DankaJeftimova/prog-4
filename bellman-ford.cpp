#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


vector<int> bellman_ford(int start, int n, vector<vector<int>> edges)
{
    vector<int> distance(n,INT_MAX);

    distance[start] = 0;

    for(int i=0; i<n; i++)
    {
        for(auto edge : edges)
        {
            int from = edge[0];
            int to = edge[1];
            int weight = edge[2];

            if(distance[from]!=INT_MAX && distance[from]+weight < distance[to])
            {
                if(i==n-1)
                {
                    return {-1};
                }

                distance[to] = distance[from] + weight;
            }
        }
    }

    return distance;
}


vector<vector<int>> make_graph(int n)
{
    vector<vector<int>> edges;

    for(int i=0; i<n-1; i++)
    {
        int weight = (rand() % 33) - 14;
        if(weight==0)
        weight = 1;

        edges.push_back({i,i+1,weight});
    }

    for(int i=0; i<7; i++)
    {
        int from = rand() % n;
        int to = rand() % n;

        if(from==to)
        continue;

        int weight = (rand() % 33) - 14;
        if(weight==0)
        weight = -11;

        edges.push_back({from,to,weight});
    }

    return edges;

}


int main()
{
    int n = 50;
    srand(time(0));
    
    ofstream file("output.txt");

    for(int i=0; i<10; i++)
    {
        
        vector<vector<int>> graph = make_graph(n);

        vector<int> dist = bellman_ford(0,n,graph);
        

        if(file.is_open())
        {
            for(auto v:graph)
            {
                file << v[0] << ' ' << v[1] << ' ' << v[2] << '\n';
            }

            file << '\n';

            if(dist.size() == 1)
            {
                file << -1;
            }
            else
            {
                for(int i=0;i<n;i++)
                {
                    file << dist[i] << ' ';
                }
            }
           

            file << endl << endl << endl;

            
        }

    }

    file.close();

    return 0;
}