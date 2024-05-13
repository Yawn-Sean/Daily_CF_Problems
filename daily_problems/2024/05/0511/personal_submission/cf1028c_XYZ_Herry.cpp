#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;

typedef pair<int,int> PII;

typedef pair<PII, PII> PPII;

const int N = 1.5e5 + 10;

PPII edge[N];
PPII a[N], b[N];

pair<PII, PII> merge(PPII x, PPII y)
{
	return {{max(x.fi.fi, y.fi.fi), max(x.fi.se, y.fi.se)}, {min(x.se.fi, y.se.fi), min(x.se.se, y.se.se)}};
}
 
int main() 
{  
    int n;
    cin >> n;
    PPII t, ans;
    a[0] = {{-2e9, -2e9}, {2e9, 2e9}};
    b[n + 1] = {{-2e9, -2e9}, {2e9, 2e9}};
    for (int i = 1; i <= n; i ++ )
    {
    	int ax, ay, bx, by;
    	cin >> ax >> ay >> bx >> by;
    	edge[i] = {{ax, ay}, {bx, by}};
    	a[i] = merge(a[i - 1], edge[i]);
    }
    for (int i = n; i >= 1; i -- ) b[i] = merge(b[i + 1], edge[i]);
    for (int i = 1; i <= n; i ++ )
    {
    	PPII t = merge(a[i - 1], b[i + 1]);
    	if (t.fi.fi <= t.se.fi && t.fi.se <= t.se.se) {cout << t.fi.fi << ' ' << t.fi.se << endl; break;}
    }
    return 0;  
}  
