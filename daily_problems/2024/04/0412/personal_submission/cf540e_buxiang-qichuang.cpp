#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define all(x)	(x).begin(),(x).end()
#define mst(x,val)  memset((x),(val),sizeof (x))
#define lowbit(x)   (x)&(-x)
typedef pair<int,int> pii;
int n, m, k, q, T;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    T = 1;
    //cin >> T;
    remake:;
    while(T--){
		cin >> n;
		vector<int> a;
		vector<array<int,2>> v;
		for(int i = 0; i < n; ++i){
			int x, y;
			cin >> x >> y;
			v.push_back({x,y});
			a.push_back(x);
			a.push_back(y);
		}
		sort(all(a));
		a.erase(unique(all(a)),a.end());
		auto get = [&](int x){
			return lower_bound(all(a),x) - a.begin() + 1;
		};
		const int N = a.size() + 1;
		vector<int> e(N);
		vector<int> pre(N);
		vector<int> diff(N);
		pre[1] = 0;pre[N-1] = 0;
		for(int i = 1; i < a.size(); ++i){
			pre[i+1] = pre[i] + a[i]-a[i-1]-1;
		}
		for(int i = N-2; i >= 1; --i){
			diff[i] = diff[i+1]+a[i]-a[i-1]-1;
		}
		iota(all(e),0);
		for(auto&t : v){
			int x = get(t[0]), y = get(t[1]);
			swap(e[x],e[y]);
		}
		vector<int> tree(N);
		auto update = [&](int x){
			while(x < N){
				tree[x] += 1;
				x += lowbit(x);
			}
		};

		auto query = [&](int x){
			int res = 0;
			while(x){
				res += tree[x];
				x -= lowbit(x);
			}
			return res;
		};
		ll res = 0;
		for(int i = N-1; i; --i){
			res += query(e[i]-1);
			if(i > e[i])    res += pre[i]-pre[e[i]];
			else    res += diff[i]-diff[e[i]];
			update(e[i]);
		}
		cout << res;
    }
    return 0;
}
