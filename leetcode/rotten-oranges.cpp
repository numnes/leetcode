#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int orangesRotting(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<bitset<20>> visited(n);

    int fresh = 0;
    int time = 0;

    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 2) {
          visited[i][j] = 1;
          q.push({i, j});
        } else if (grid[i][j] == 1)
          fresh++;
      }
    }

    if (!fresh)
      return 0;

    while (!q.empty() && fresh) {
      int qSize = q.size();

      int dX[4] = {-1, 1, 0, 0};
      int dY[4] = {0, 0, -1, 1};

      for (int k = 0; k < qSize; k++) {
        auto current = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
          int nx = current.first + dX[i];
          int ny = current.second + dY[i];

          if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
            int c = grid[nx][ny];
            if (c == 1 && !visited[nx][ny]) {
              visited[nx][ny] = 1;
              fresh--;
              q.push({nx, ny});
            }
          }
        }
      }
      time++;
    }

    if (fresh)
      return -1;
    return time;
  }
};

int main(void) {
  Solution s;

  vector<vector<int>> in = {{2,1,1},{0,1,1},{1,0,1}};

  cout << s.orangesRotting(in) << "\n";
}
