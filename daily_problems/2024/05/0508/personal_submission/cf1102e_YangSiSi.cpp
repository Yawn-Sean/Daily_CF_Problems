#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define int long long 
typedef long long LL;
const LL mod = 998244353;
const int N = 2e5+10;
typedef pair<int, int> PII;

LL qmi(LL m, LL k,LL p){
	 LL res = 1 % p, t = m;
	 while (k){
		 if (k&1) res = res * t % p;
		 t = t * t % p;
		 k >>= 1;
	 }
	 return res%p;
 }

void merge(vector<PII> &segs){
    vector<PII> res;

    sort(segs.begin(), segs.end());

    int st = -2e9, ed = -2e9;
    for (auto seg : segs)
        if (ed < seg.first)
        {
            if (st != -2e9) res.push_back({st, ed});
            st = seg.first, ed = seg.second;
        }
        else ed = max(ed, seg.second);

    if (st != -2e9) res.push_back({st, ed});

    segs = res;
}

inline void solve(){
	int n ; cin >> n ; 
	vector<int> a(n+1) ; vector<PII> b; set<int> st ; map<int,vector<int>> mp ;
	for(int i=1;i<=n;i++) cin >> a[i] ,mp[a[i]].push_back(i) ;
	for(int i=1;i<=n;i++){
		if(st.count(a[i])) continue ;
		b.push_back({i,mp[a[i]].back()}) ;
		st.insert(a[i]) ;
	}
	merge(b) ;//区间合并 
	int t = b.size() - 1 ;
	LL ans = qmi(2,t,mod) ;
	cout << ans << endl ;
}
 
signed main(){
    IOS
    int _ = 1;
    while(_ --) solve();
    return 0;
}
