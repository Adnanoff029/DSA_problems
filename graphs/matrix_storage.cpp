#include <bits/stdc++.h>
using namespace std;

int main()
{
      int n, m;
      cin >> n >> m;
      //Assuming the graph vertices are 1 based.
      int adj[n+1][m+1];
      for(int i = 0; i < n; i++)
      {
            int u ,v;
            cin >> u >> v;
            adj[u][v] = 1;
            adj[v][u] = 1;
      }
      for(int i = 0; i <= n; i++)
      {
            for(int j = 0; j <= m; j++)
            {
                  if(adj[i][j] == 1)
                  {
                        continue;
                  }
                  else{
                        adj[i][j] = 0;
                  }
            }
      }
      for(int i = 0; i <= n; i++)
      {
            for(int j = 0; j <= m; j++)
            {
                  cout << adj[i][j] << " ";
            }
            cout << endl;
      }
      return 0;
}