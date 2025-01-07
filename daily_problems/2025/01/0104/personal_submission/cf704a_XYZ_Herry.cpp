// Problem: A. Thor
// Contest: Codeforces - Codeforces Round 366 (Div. 1)
// URL: https://codeforces.com/problemset/problem/704/A
// Memory Limit: 256 MB
// Time Limit: 2000 ms

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

typedef pair<int, int> PII; 

const int N = 3e5 + 10;
int readed[N];//当前读到了程序x的第i条通知
int now[N];//程序x已经产生了i条通知
int all[N];//all[i] = x表示第i调通知是程序x产生的
int t3[N];//type3已经读到了程序x的第几条通知

void solve()
{
	int n, q, ans = 0, idx = 0;
	int maxv = 0;//最大的type3的值
	cin >> n >> q;
	for (int i = 1; i <= q; i ++ )
	{
		int type, x;
		cin >> type >> x;
		if (type == 1)
		{
			now[x] ++ ;
			all[ ++ idx] = x;
			ans ++ ;
		}
		else if (type == 2)
		{
			ans -= now[x] - readed[x];
			readed[x] = now[x];
		}
		else
		{
			if (maxv < x)
			{
				for (int i = maxv + 1; i <= x; i ++ )
				{
					t3[all[i]] ++ ;
					if (t3[all[i]] > readed[all[i]])
					{
						readed[all[i]] ++ ;
						ans -- ;
					}
				}
				maxv = max(maxv, x);
			}
		}
		cout << ans << endl;
	}
}

int main()
{
    int T = 1;
    //scanf("%d", &T);
    while (T--) solve();
    return 0;
}
