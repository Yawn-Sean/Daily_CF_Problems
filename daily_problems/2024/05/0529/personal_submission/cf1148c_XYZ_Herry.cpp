#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;

const int N = 3e5 + 10;
int n;
int a[N];
map<int, int> pos;
vector<PII> ans;
void change(int i, int j)
{
	swap(a[i], a[j]);
	pos[a[i]] = i, pos[a[j]] = j;
	ans.push_back({i, j});
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> a[i], pos[a[i]] = i;
    for (int i = 1; i <= n; i ++ )
    {
    	int idx = pos[i];
    	if (i == idx) continue;
    	else if (abs(i - idx) * 2 >= n) change(i, idx);
    	else
    	{
    		if (idx <= n / 2) 
    		{
    			change(idx, n), change(i, n), change(idx, n);
    		}
    		else if (i > n / 2)
    		{
    			change(1, i), change(1, idx), change(1, i);
    		}
    		else
    		{
    			change(i, n), change(1, idx), change(1, n), change(i, n), change(1, idx);
    		}
    	}
    }
    cout << ans.size() << endl;
    for (auto x : ans) cout << x.first << ' ' << x.second << endl;
}
 
int main() 
{  
    int T = 1;
    //scanf("%d", &T);  
    while (T -- ) solve();
    return 0;  
}  
