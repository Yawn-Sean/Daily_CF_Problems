#include <bits/stdc++.h>
#define int long long
#define x first
#define y second

using namespace std;
typedef pair<int, int> PII;


const int N = 2e5 + 100;


int n, m, k;

PII a[N];

int fa[N];

int find(int x)
{
    if (fa[x] != x) fa[x] = find(fa[x]);
    return fa[x];
}

bool out[N];

void solve()
{
	cin >> n >> m >> k;
	
	int mxCnt = 0;
	for (int i = 0; i < m; i ++ )
	{
	    int x, y;
	    cin >> x >> y;
	    a[i] = {x, y};
	    
	    mxCnt += (x == 1 || y == 1);
	}

	// 并查集分连通块
	for (int i = 1; i <= n; i ++ ) fa[i] = i;
	
	
	// 把1号节点排除
	for (int i = 0; i < m; i ++ )
	{
	    if (a[i].x == 1 || a[i].y == 1) continue;
	    
	    int pa = find(a[i].x);
	    int pb = find(a[i].y);
	    
	    
	    if (pa == pb) continue;
	    if (pa > pb) swap(pa, pb);
	    
	    fa[pb] = pa;
	}
	
	
	map<int, bool> needConnect;
	
	int stockCnt = 0;
	for (int i = 2; i <= n; i ++ )
	    if (i == find(i))
	    {
	        stockCnt += 1;
	        needConnect[i] = true;   
	    }
	
	 if (k < stockCnt || k > mxCnt)
	 {
	     cout << "NO\n";
	     return;
	 }
	
	
	
	// 从这k个节点里面选节点先和1连接上
	for (int i = 0; i < m; i ++ )
	{
	    if (a[i].x == 1 || a[i].y == 1)
	    {
	        int u = a[i].x;
	        if (u == 1) u = a[i].y;
	        if (needConnect[find(u)])
	        {
	            out[i] = true;
	            needConnect[find(u)] = false;
	            k -- ;
	        }
	    }
	}
	
	for (int i = 0; i < m; i ++ )
	    if (a[i].x == 1 || a[i].y == 1)
	    {
	        if (!out[i] && k)
	        {
	            out[i] = true;
	            k -- ;
	        }
	    }
    // 现在1号点和其他连通块的连上了
    // 重新利用并查集计算出来剩下的边，每个连通块的都有，所以一定ok
    for (int i = 1; i <= n; i ++ ) fa[i] = i;
    
    for (int i = 0; i < m; i ++ )
        if (out[i])
        {
            int pa = find(a[i].x);
    	    int pb = find(a[i].y);
    	    if (pa == pb) continue;
    	    if (pa > pb) swap(pa, pb);
    	    fa[pb] = pa;
        }
    
    
    for (int i = 0; i < m; i ++ )
        if (!out[i] && a[i].x != 1 && a[i].y != 1)
        {
            int pa = find(a[i].x);
    	    int pb = find(a[i].y);
    	    if (pa == pb) continue;
    	    if (pa > pb) swap(pa, pb);
    	    fa[pb] = pa;
    	    out[i] = true;
        }
	cout << "YES\n";
	for (int i = 0; i < m; i ++ )
	    if (out[i])
	        cout << a[i].x << ' ' << a[i].y << '\n';
}

signed main()
{
	cin.tie(0) -> ios::sync_with_stdio(false);
	solve();
}
