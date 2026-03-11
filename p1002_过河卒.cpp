#include<bits/stdc++.h>
using namespace std;
int main() {
    //定义棋盘最大尺寸
    const int MAXN = 25;
    //dp数组:存储到(i,j)的路径数
    long long dp[MAXN][MAXN];
    //标记是否为禁区
    bool forbidden[MAXN][MAXN];

    //马的8个方向偏移量
    int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

    //棋盘大小(n,m),马的位置(x,y);
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    if (n < 0 || m < 0 || n >= MAXN || m >= MAXN) {
        cout << 0 << endl;
        return 0;
    }

    //初始化禁区（默认都是可走的）
    memset(forbidden, false, sizeof(forbidden));

    //标记马的位置为禁区
    if (x >= 0 && x <= n && y >= 0 && y <= m) {
    forbidden[x][y] = true;

    //标记马能走到的8个位置为禁区
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        //检查nx和ny是否在棋盘范围内
        if (nx >= 0 && nx <= n && ny >= 0 && ny <= m) {
            forbidden[nx][ny] = true;
        }
    }
    }

    //初始化dp数组(起点)
    //如果起点不是禁区，路径数为1；否则直接输出0
    if (!forbidden[0][0]) {
        dp[0][0] = 1;
    } else {
        cout << 0 << endl;
        return 0;
    }

    //填充第一行（只能从左边来）
    for (int j = 1; j <= m; j++) {
        //如果当前位置不是禁区，路径数=左边位置的路径数，否则为0
        if (!forbidden[0][j]) {
            dp[0][j] = dp[0][j - 1];
        } else {
            dp[0][j] = 0;
        }
    }

    //填充第一列
    for (int i = 1; i <= n; i++) {
        if (!forbidden[i][0]) {
            dp[i][0] = dp[i - 1][0];
        } else {
            dp[i][0] = 0;
        }
    }

    //填充剩余位置（状态转移）
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            //如果是禁区，路径数为0
            if(forbidden[i][j]) {
                dp[i][j] = 0;
            } else {
                //路径数=上面的路径数+左边的路径数
                dp[i][j] = dp[i -1][j] + dp[i][j - 1];
            }
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}