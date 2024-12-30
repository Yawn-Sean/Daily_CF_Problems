// Problem: D. Social Network
// Contest: Codeforces - Deltix Round, Autumn 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/problemset/problem/1609/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms

/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define all(x) x.begin(),x.end()
#define pb push_back

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) "lengli"
#endif

const int N=100010;

struct DSU{
    vector<int> p, sz,add;
    DSU(int n): p(n+1), sz(n+1, 1),add(n+1,0){
        std::iota(p.begin(), p.end(), 0);
    }
    int find(int x){
        return x == p[x] ? x : p[x]=find(p[x]);
    }
    int sum(int x){
    	return x == p[x] ? add[x] : add[x]+sum(p[x]);
    }
    bool same(int x, int y){
        return find(x) == find(y);
    }
    bool merge(int x, int y){
        x = find(x);
        y = find(y);
        if (x == y) return 0;
        if(size(x) < size(y)) swap(x,y);
        sz[x] += sz[y];
        p[y] = x;
        add[y]-=add[x];
        return 1;
    }
    int size(int x){
        return sz[find(x)];
    }
};

void solve(){
	int n,m;
	cin>>n>>m;
	DSU dsu(n);
	int cnt=0;
	while(m--){
		int a,b;
		cin>>a>>b;
		if(dsu.same(a,b)) cnt++;
		else dsu.merge(a,b);
		vector<int> q;
		for(int i=1;i<=n;i++){
			if(dsu.find(i)==i) q.pb(dsu.size(i));
		}
		sort(all(q),greater<>());
		int res=0;
		for(int i=0;i<min((int)q.size(),cnt+1);i++) res+=q[i];
		cout<<res-1<<endl;
	}

}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
