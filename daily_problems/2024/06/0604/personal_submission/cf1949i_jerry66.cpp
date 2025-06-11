#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1010, M = N * N;
int n;

int x[N], y[N], r[N];

int sz[N];

int h[N], e[M], ne[M], idx;

void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx ++ ;
}

int color[N];
int ad, sub;

bool dfs(int u, int val)
{
    if (color[u]) return color[u] == val;
    color[u] = val;
    
    if (val == 1) ad ++ ;
    else sub ++ ;
    
    bool res = true;
    
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (!dfs(j, 3 - val)) res = false; // 这里不能直接return false，否则会导致一个联通的图，被遍历多次
    }
    
    return res;
}


void solve()
{
	cin >> n;
	for (int i = 1; i <= n; i ++ ) cin >> x[i] >> y[i] >> r[i];


	memset(h, -1, sizeof h);	

	for (int i = 1; i <= n; i ++ )
	{
		for (int j = 1; j < i; j ++ )
		{
			// 看i和j的圆是否相切
			int dx = x[i] - x[j];
			int dy = y[i] - y[j];
			if (dx * dx + dy * dy == (r[i] + r[j]) * (r[i] + r[j]))
			{
				sz[i] ++ ;
				sz[j] ++ ;
				add(i, j);
				add(j, i);
			}
		}
	}
	
	for (int i = 1; i <= n; i ++ )
	    if (!color[i])
	    {
	        ad = 0, sub = 0;
	        if (dfs(i, 1) && ad != sub)	
	        {
            cout << "YES\n";
            return;
          }
	    }
	
	
	cout << "NO\n";
}

signed main()
{
	cin.tie(0) -> ios::sync_with_stdio(false);
	solve();
}
