#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int m, n, h, blank = 0, cnt = 0, ans = 0;
int tomato[102][102][102];
int date[102][102][102];
int dx[6] = {0, -1, 0, 0, 1, 0};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {1, 0, 0, 0, 0, -1};
queue<tuple<int, int, int>> Q;

int main(void)
{
  ios::sync_with_stdio();
  cin.tie();

  cin >> m >> n >> h;
  for(int k = 0; k < h; k++)
  {
    for(int i = 0; i < n; i++)
    {
      for(int j = 0; j < m; j++)
      {
        cin >> tomato[i][j][k];

        if(tomato[i][j][k] == -1) blank++;
        if(tomato[i][j][k] == 0) date[i][j][k] = -1;
        if(tomato[i][j][k] == 1)
        {
          Q.push({i, j, k});
          cnt++;
        }
      }
    }
  }

  while(!Q.empty())
  {
    tuple<int, int, int> cur = Q.front(); Q.pop();
    int curX, curY, curZ;
    tie(curX, curY, curZ) = cur;

    for(int i = 0; i < 6; i++)
    {
      int nx = curX + dx[i];
      int ny = curY + dy[i];
      int nz = curZ + dz[i];

      if(nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) continue;
      if(tomato[nx][ny][nz] == -1 || date[nx][ny][nz] >= 0) continue;

      Q.push({nx, ny, nz});
      cnt++;
      date[nx][ny][nz] = date[curX][curY][curZ] + 1;

      ans = max(ans, date[nx][ny][nz]);
    }
  }

  if(cnt + blank == m * n * h) cout << ans;
  else cout << -1;
}