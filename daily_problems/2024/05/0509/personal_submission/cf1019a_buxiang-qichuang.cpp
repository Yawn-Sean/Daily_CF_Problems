#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x)	(x).begin(),(x).end()
typedef pair<int,int> pii;
int n, m, k, q, T;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    T = 1;
    //cin >> T;
    remake:;
    while(T--){
    	cin >> n >> m;
    	vector<int> cnt(m+1,0);
    	unordered_map<int,vector<int>> mp;
    	vector<pii> a, b;
    	for(int i = 0; i < n; ++i){
    		int x, y;
    		cin >> x >> y;
    		mp[x].push_back(y);
    		++cnt[x];
    		b.push_back({y,x});
    	}
    	for(int i = 1; i <= m; ++i)	if(cnt[i])	a.push_back(make_pair(cnt[i],i));
    	sort(all(a));sort(all(b));
    	for(auto&[x,y]:mp)	sort(all(y));
    	ll res = LONG_LONG_MAX;
    	for(int k = n; k >= 1; --k){
    		ll temp = 0, add = 0;
    		vector<int> flag(m+1,-1);
    		for(int i = a.size()-1; i >= 0; --i){
    			if(a[i].second == 1)	continue;
    			flag[a[i].second] = cnt[a[i].second]-k;
    			for(int j = 0; j <= cnt[a[i].second]-k; ++j){
    				temp += mp[a[i].second][j];
    				add++;
    			}
    		}
    		int idx = 0;
    		while(cnt[1]+add < k){
    			if(flag[b[idx].second] < 0 && b[idx].second != 1)	{
    				++add;
    				temp += b[idx].first;
    			}
    			--flag[b[idx].second];
    			++idx;
    		}
    		res = min(res,temp);
    	}
    	cout << res;
    }
    return 0;
}
