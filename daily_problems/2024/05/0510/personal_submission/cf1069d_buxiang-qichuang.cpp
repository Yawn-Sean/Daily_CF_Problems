#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x)	(x).begin(),(x).end()
int n, m, T;
struct dsu{
    vector<int> Size;
    vector<int> par;
    int cnt;
    void init(int N){
        Size.assign(N,1);
        par.assign(N,-1);
    	cnt = 0;
    }
    void unite(int a, int b){
        a = root(a); b = root(b);
        if(a == b) {
        	++cnt;
        	return ;
        }
        if(Size[a] < Size[b])   swap(a,b);
        // a bigger than b
        Size[a] += Size[b];
        Size[b] = 1;
        par[b] = a;
    }
    bool same(int a, int b){
        return root(a) == root(b);
    }
    int root(int a){
        if(par[a] == -1)    return a;
        return par[a] = root(par[a]);
    }
    int size(int a){
        return Size[root(a)];
    }
    int ans(){
    	vector<int> v;
    	for(int i = 1; i < par.size(); ++i)
    		if(root(i) == i)	v.push_back(Size[i]);
    	sort(all(v),greater<int>());
    	int res = 0;
    	for(int i = 0; i <= cnt; ++i)	res += v[i];
    	return res-1;
    }
};
dsu uf;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    T = 1;
    //cin >> T;
    remake:;
    while(T--){
    	cin >> n >> m;
    	uf.init(n+1);
    	for(int i = 0; i < m; ++i){
    		int x, y;
    		cin >> x >> y;
    		uf.unite(x,y);
    		cout << uf.ans() << '\n';
    	}
    }
    return 0;
}
