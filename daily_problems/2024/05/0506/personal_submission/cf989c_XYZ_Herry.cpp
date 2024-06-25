#include <bits/stdc++.h>
#define fi first
#define se second

using namespace std;

char s[55][55];
pair<int, char> cnt[5];

bool cmp(pair<int, char> a, pair<int, char> b)
{
	return a.fi > b.fi;
}

void solve()
{
    cin >> cnt[1].fi >> cnt[2].fi >> cnt[3].fi >> cnt[4].fi;
    cnt[1].se = 'A', cnt[2].se = 'B', cnt[3].se = 'C', cnt[4].se = 'D';
    sort(cnt + 1, cnt + 5, cmp);
    int idx = 4;
    bool flag = false;
    for (int i = 1; i <= 50; i += 2)
    {
    	for (int j = 1; j <= 50; j += 2)
    	{
    		if (idx == 2 && cnt[idx].fi == 1) {flag = true; break;}
    		s[i][j] = cnt[idx].se;
    		cnt[idx].fi -- ;
    		if (cnt[idx].fi == 0) idx -- ;
    	}
    	if (flag) break;
    }
    if (cnt[1].fi == 1) s[50][50] = cnt[2].se;
    if (cnt[1].fi > 1)
    {
    	flag = false;
    	for (int i = 50; i >= 1; i -= 2)
    	{
	    	for (int j = 1; j <= 50; j += 2)
	    	{
	    		s[i][j + 1] = s[i - 1][j + 1] = s[i - 1][j] = cnt[2].se;
	    		cnt[1].fi -- ;
	    		if (cnt[1].fi == 1) {flag = true; break;}
	    	}
	    	if (flag) break;
	    }
    }
    cout << 50 << ' ' << 50 << endl;
	for (int i = 1; i <= 50; i ++ , puts(""))
		for (int j = 1; j <= 50; j ++ )
		{
			if (!s[i][j]) cout << cnt[1].se;
			else cout << s[i][j];
		}
}
 
int main() 
{  
    int T = 1;
    //scanf("%d", &T);  
    while (T -- ) solve();
    return 0;  
}  
