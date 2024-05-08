#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 998244353;
int n, m, k, q, T;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    T = 1;
    //cin >> T;
    remake:;
    while(T--){
    	cin >> n;
    	vector<int> a(n);
    	for(auto& x:a)	cin >> x;
    	map<int,int> mp;
    	for(int i = 0; i < n; ++i)	mp[a[i]] = i;
    	ll res = 0;
    	for(int i = 0; i < n; ++i)	a[i] = mp[a[i]];
    	for(int i = 1; i < n; ++i)	a[i] = max(a[i],a[i-1]);
    	for(int i = 0; i < n; ++i){
    		int f = a[i];
    		while(f != a[f])	f = a[f];
    		if(!res)	res = 1;
    		else	{
    			res <<= 1;
    			res %= mod;
    		}
    		i = f;
    	}
    	cout << res;
    }
    return 0;
}
