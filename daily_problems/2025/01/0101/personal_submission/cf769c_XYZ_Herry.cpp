// Problem: C. Cycle In Maze
// Contest: Codeforces - VK Cup 2017 - Qualification 1
// URL: https://codeforces.com/problemset/problem/769/C
// Memory Limit: 256 MB
// Time Limit: 15000 ms

#include <bits/stdc++.h>
#define fi first 
#define se second

using namespace std;

typedef pair<int, int> PII;

int dx[4] = {1, 0, 0, -1}, dy[4] = {0, -1, 1, 0};
char op[4] = {'D', 'L', 'R', 'U'};
string path;

const int N = 1010;
char s[N][N];
int n, m, k;
int dist[N][N];

void bfs(int x, int y)
{
	queue<PII> q;
	q.push({x, y});
	memset(dist, -1, sizeof dist);
	dist[x][y] = 0;
	while (!q.empty())
	{
		auto t = q.front();
		q.pop();
		for (int i = 0; i < 4; i ++ )
		{
			int a = t.fi + dx[i], b = t.se + dy[i];
			if (a < 0 || a >= n || b < 0 || b >= m || s[a][b] == '*' || dist[a][b] != -1) continue;
			dist[a][b] = dist[t.fi][t.se] + 1;
			q.push({a, b});
		}
	}
}

void dfs(int x, int y, int step)
{
	bool flag = false;
	for (int i = 0; i < 4; i ++ )
	{
		int a = x + dx[i], b = y + dy[i];
		if (a < 0 || a >= n || b < 0 || b >= m || s[a][b] == '*' || dist[a][b] > k - step) continue;
		if (!flag) 
		{
			path += op[i];
			dfs(a, b, step + 1);
		}
		flag = true;
	}
}

void solve()
{
	cin >> n >> m >> k;
	PII be;
	for (int i = 0; i < n; i ++ )
		for (int j = 0; j < m; j ++ )
		{
			cin >> s[i][j];
			if (s[i][j] == 'X') be = {i, j};
		}
	if (k % 2) puts("IMPOSSIBLE");
	else
	{
		int cnt = 0;
		for (int i = 0; i < 4; i ++ )
		{
			int x = be.fi + dx[i], y = be.se + dy[i];
			if (s[x][y] == '.') cnt ++ ;
		}
		if (cnt == 0) {puts("IMPOSSIBLE"); return;}
		bfs(be.fi, be.se);
		dfs(be.fi, be.se, 0);
		cout << path << endl;
	}
}
//D < L < R < U
int main()
{
    int T = 1;
    //scanf("%d", &T);
    while (T--) solve();
    return 0;
}
