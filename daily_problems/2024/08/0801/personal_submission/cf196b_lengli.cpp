#include <map>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
struct Node
{
	int x, y;
} v[2250010];
struct Edge
{
	int v, nt, wx, wy;
} e[6010];
char s[1510][1510];
int n, m, sx, sy;
int f[2250010];
int b[1510][1510];
int sum;
int v2[6010];
map<int, int> mp, st;

void add_edge(int u, int v, int x, int y, int k)
{
	e[k].v = v;
	e[k].wx = x;
	e[k].wy = y;
	e[k].nt = st[u];
	st[u] = k;
}

void bfs(int p, int q, int k)
{
	int head = 0, tail = 1;
	v[1].x = p;
	v[1].y = q;
	b[p][q] = k;
	while (head < tail)
	{
		head++;
		int x = v[head].x, y = v[head].y;
		int xx, yy;

		xx = x + 1; yy = y;
		if (xx >= 0 && xx < n && yy >= 0 && yy < m)
			if (s[xx][yy] =='.' && !b[xx][yy])
			{
				tail++;
				v[tail].x = xx;
				v[tail].y = yy;
				b[xx][yy] = k;
			}

		xx = x - 1; yy = y;
		if (xx >= 0 && xx < n && yy >= 0 && yy < m)
			if (s[xx][yy] =='.' && !b[xx][yy])
			{
				tail++;
				v[tail].x = xx;
				v[tail].y = yy;
				b[xx][yy] = k;
			}

		xx = x; yy = y + 1;
		if (xx >= 0 && xx < n && yy >= 0 && yy < m)
			if (s[xx][yy] =='.' && !b[xx][yy])
			{
				tail++;
				v[tail].x = xx;
				v[tail].y = yy;
				b[xx][yy] = k;
			}

		xx = x; yy = y - 1;
		if (xx >= 0 && xx < n && yy >= 0 && yy < m)
			if (s[xx][yy] =='.' && !b[xx][yy])
			{
				tail++;
				v[tail].x = xx;
				v[tail].y = yy;
				b[xx][yy] = k;
			}
	}
}

bool bfs2(int k)
{
	int head = 0, tail = 1;
	v2[1] = k;
	mp[k] = 1;
	memset(v, 0, sizeof(v));
	while (head < tail)
	{
		head++;
		int kk = v2[head];
		int z = st[kk];
		while (z)
		{
			int vv = e[z].v, x = e[z].wx + v[kk].x, y = e[z].wy + v[kk].y;
			if (mp.find(vv) != mp.end())
			{
				if (v[vv].x != x || v[vv].y != y)
					return true;
			}
			else
			{
				tail++;
				v2[tail] = vv;
				mp[vv] = tail;
				v[vv].x = x;
				v[vv].y = y;
			}
			z = e[z].nt;
		}
	}
	return false;
}

bool pass()
{
	sum = 0;
	for (int i = 0; i < n; i++)
		if (b[i][0] && b[i][m - 1])
		{
			sum++;
			add_edge(b[i][0], b[i][m - 1], 0, 1, sum);
			sum++;
			add_edge(b[i][m - 1], b[i][0], 0, -1, sum);
		}
	for (int j = 0; j < m; j++)
		if (b[0][j] && b[n - 1][j])
		{
			sum++;
			add_edge(b[0][j], b[n - 1][j], 1, 0, sum);
			sum++;
			add_edge(b[n - 1][j], b[0][j], -1, 0, sum);
		}
	
	return bfs2(b[sx][sy]);
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", s[i]);
	memset(b, 0, sizeof(b));
	int k = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (s[i][j] == 'S')
			{
				sx = i;
				sy = j;
				s[i][j] = '.';
			}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (s[i][j] == '.' && b[i][j] == 0)
			{
				k++;
				bfs(i, j, k);
			}
	for (int i = 1; i <= k; i++)
		f[i] = i;
	if (pass())
		puts("Yes");
	else puts("No");
	return 0;
}
