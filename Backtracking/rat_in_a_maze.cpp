#include <iostream>
using namespace std;
bool is_safe(int **arr, int x, int y, int n)
{
      if (x < n && y < n && arr[x][y] == 1)
      {
            return true;
      }
      return false;
}

bool maze_sol(int **arr, int x, int y, int n, int **sol)
{
      if (x == n - 1 && y == n - 1)
      {
            sol[x][y] = 1;
            return true;
      }
      if (is_safe(arr, x, y, n))
      {
            sol[x][y] = 1;
            if (maze_sol(arr, (x + 1), y, n, sol))
            {
                  return true;
            }
            if (maze_sol(arr, x, (y + 1), n, sol))
            {
                  return true;
            }
            sol[x][y] = 0;
            return false;
      }
      return false;
}
int main()
{
      int n;
      cout<<"Enter the maze size: ";
      cin >> n;

      int **arr = new int *[n];

      for (int i = 0; i < n; i++)
      {
            arr[i] = new int[n];
      }

      cout << "Enter the maze in the form of 0 and 1: " << endl;
      for (int i = 0; i < n; i++)
      {
            for (int j = 0; j < n; j++)
            {
                  cin >> arr[i][j];
            }
      }

      int **sol = new int *[n];

      for (int i = 0; i < n; i++)
      {
            sol[i] = new int[n];
      }

      for (int i = 0; i < n; i++)
      {
            for (int j = 0; j < n; j++)
            {
                  sol[i][j] = 0;
            }
      }

      cout << "Solution: " << endl;
      if (maze_sol(arr, 0, 0, n, sol))
      {
            for (int i = 0; i < n; i++)
            {
                  for (int j = 0; j < n; j++)
                  {
                        cout << sol[i][j] <<" ";
                  }
                  cout<<endl;
            }
      }
      return 0;
}

// 1 0 1 0 1
// 1 1 1 1 1
// 0 1 0 1 0
// 1 0 0 1 1
// 1 1 1 0 1