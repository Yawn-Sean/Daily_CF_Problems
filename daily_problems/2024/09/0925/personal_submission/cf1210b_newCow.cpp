// https://codeforces.com/contest/1210/problem/B
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;
const int N = 7010;

typedef long long ll;

ll n,a[N],b[N],ans = 0;
unordered_map<ll,ll> mp;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		mp[a[i]]++;
	}	
	
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}
	
	vector<bool> vis(n + 1);
	
	ll sum = 0;
	for (auto &p : mp) {
		ll k = p.first,v = p.second;
		if (v < 2) continue;
		
		for (int i = 1;i <= n; i++) {
			if (!vis[i] && (a[i] & k) == a[i]) {
				sum += b[i];
				vis[i] = true;
			}
		} 
	
	}
	
	cout << sum << endl;
	
	return 0;
}
