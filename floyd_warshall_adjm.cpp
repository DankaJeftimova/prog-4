#include <iostream>
#include <vector>
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

        cout << '\n';

        for(int i=0;i<n;i++)
        {
            for(int j=0; j<n; j++)
            {
                cout << mat[i][j] << ' ';
            }

            cout << '\n';
        }
    }

}



int main()
{
    int n=0,m=0;
    cin >> n >> m;

    vector<vector<int>> mat(n, vector<int>(n,-1));

    int maxe = 0;

    for(int i=0;i<m;i++)
    {
        int a=0,b=0,weight=0;
        cin >> a >> b >> weight;

        mat[a][b]=weight;
        maxe=max(maxe,weight);
    }

    int inf = maxe + maxe/2;

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

    floyd_warshall(n, mat, inf);

    vector<vector<int>> d = mat;
    cout << "Vtor pat za da vidime dali ima negativen ciklus:\n";
    
    floyd_warshall(n, mat, inf);

    if(mat!=d)
    {
        cout << "Ima negativen ciklus"; 
    }



    return 0;
}
