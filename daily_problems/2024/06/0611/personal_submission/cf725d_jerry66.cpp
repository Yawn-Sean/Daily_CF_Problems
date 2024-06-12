#include <bits/stdc++.h>
#define int long long
#define x first
#define y second

using namespace std;
typedef pair<int, int> PII;
typedef long long LL;


const int N = 300100;
const int mod = 998244353;

int n;
PII a[N];

void solve()
{
    cin >> n;
    for (int i = 0; i < n; i ++ ) cin >> a[i].x >> a[i].y;
    
    sort(a + 1, a + n, [&](PII& p1, PII& p2) {
        if (p1.x != p2.x) return p1.x  > p2.x;
        return p1.y - p1.x < p2.y - p2.x;
    });
    
    // for (int i = 1; i < n; i++) cout << a[i].x << ' ' << a[i].y << '\n';
    
    priority_queue<int, vector<int>, greater<int> > q;
    
    int res = 1e18;
    int cnt = 0;
    int i = 1;
    while (1)
    {
        bool change = false;
        while (i < n && a[i].x > a[0].x)
        {
            q.push(a[i].y - a[i].x + 1);
            cnt ++ ;
            i ++ ;
        }
        
        res = min(res, cnt + 1);
    // 这里好坑，一开始写成while了，但是每删除一个就要重新把比自己大的扔到heap里面，否则就会产生先处理了非最优解（有其他的队伍比q.top这支队伍用更少的气球就可以出局）的情况
        if (q.size() && q.top() <= a[0].x) 
        {
            a[0].x -= q.top();
            cnt -- ;
            q.pop();
            change = true;
        }
        
        
        if (!change) break;
        
    }
    
    
    cout << res << '\n';
}
    
signed main()
{
	cin.tie(0) -> ios::sync_with_stdio(false);
	int t = 1;
// 	cin >> t;
	while (t -- ) solve();
}
