#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define endl "\n"
#define sz(x) (int)(x.size())
using LL=long long;
const LL inf = 1e18;

//
struct info{
	LL x,y;
};
template <typename T, class Op>
struct PrefixBIT {
    int n;
    vector<T> bit;
    T identity; 
    Op op;   
    PrefixBIT(int n, T identity, Op op = Op()) 
        : n(n + 1), bit(n + 2, identity), identity(identity), op(op) {}
    inline void update(int x, const T& val) {
        for (++x; x <= n; x += x & -x) {
            bit[x] = op(bit[x], val);
        }
    }
    inline T query(int x) {
        T res = identity;
        for (++x; x > 0; x -= x & -x) {
            res = op(res, bit[x]);
        }
        return res;
    }
};
struct Op {
    inline long long operator()(long long a, long long b) const {
        return min(a, b);
    }
};

void solve() {
	LL d,l;
	cin>>d>>l;
	int n;
	cin>>n;
	vector<info>a(n+1);
	for(int i=1;i<=n;++i){
		cin>>a[i].x>>a[i].y;
	}
	info ne;
	ne.x=d,ne.y=0;
	a.push_back(ne);
	++n;
	vector<LL>dp(n+1);  //dp[i] 到i最少多走多远
	vector<LL>K(n+1);
	PrefixBIT<LL,Op>fw(n+1,inf);
	for(int i=0;i<=n;++i){
		K[i]=a[i].y-2*a[i].x;
	}
	sort(K.begin(),K.end());
	K.erase(unique(K.begin(), K.end()), K.end());
	map<LL,LL>adj;
	for(int i=0;i<sz(K);++i){
		adj[K[i]]=i;
	}
	fw.update(adj[0],0);
	auto wk=[&](LL x)->int{
		int L=0,R=sz(K)-1,res=-1;
		while(L<=R){
			int mid=(L+R)>>1;
			if(K[mid]<=x){
				res=mid;
				L=mid+1;
			}else{
				R=mid-1;
			}
		}
		return res;
	};
	for(int i=1;i<=n;++i){
		LL cur=2*l-a[i].y-2*a[i].x;
		int res=wk(cur);
		if(res==-1){
			continue;
		}
		auto cc=fw.query(res);
		if(cc==inf){
			dp[i]=inf;
			continue;
		}
		dp[i]=cc+a[i].y;
		fw.update(adj[a[i].y-2*a[i].x],dp[i]);
	}
	if(dp[n]==inf){
		cout<<-1<<endl;
	}else{
		cout<<d+dp[n]<<endl;
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int loop = 1;
	//cin >> loop;
	while (loop--){
		solve();
	}
	return 0;
}