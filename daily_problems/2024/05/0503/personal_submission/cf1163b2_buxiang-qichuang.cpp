#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
    	unordered_map<int,int> mp;
    	unordered_map<int,int> cnt;
    	int res = -1;
    	for(int i = 0; i < n; ++i){
    		++mp[a[i]];
    		cnt[mp[a[i]]]++;
    		if(mp[a[i]] != 1)	{
    			cnt[mp[a[i]]-1] --;
    			if(cnt[mp[a[i]]-1] == 0)	cnt.erase(mp[a[i]]-1);
    		}
    		auto check = [&](){
    			if(cnt.size() == 1){
    				if(cnt.count(1) || cnt[mp[a[i]]] == 1)	res = i+1;
    			}else if(cnt.size() == 2){
    				if(cnt.count(mp[a[i]]+1) && cnt[mp[a[i]]+1] == 1)	res = i+1;
    				if(cnt.count(mp[a[i]]-1) && cnt[mp[a[i]]] == 1)	res = i+1;
    				if(cnt.count(1) && cnt[1] == 1)	res = i+1;
    			}
    		};
    		check();
    	}
    	cout << res;
    }
    return 0;
}
