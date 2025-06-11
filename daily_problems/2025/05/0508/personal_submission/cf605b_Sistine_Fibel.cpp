#include <bits/stdc++.h>
using namespace std;
#define int long long
#define debug(x) cerr << #x << " = " << (x) << endl
#define debugv(v) { cerr << #v << " = [ "; for (auto x : v) cerr << x << " "; cerr << "]" << endl; }
#define all(x) (x).begin(),(x).end()
void solve();
#define endl '\n'

const long long INF = 0x3f3f3f3f;
const long long MOD = 1e9; //模数

signed main (){ 
	std::cin.tie(NULL)->sync_with_stdio(false);
	int t = 1;
	// cin >> t;  //atc默认关闭，cf按需开启
	while(t --)
		solve();
}

void solve(){
	int n, m;
    cin >> n >> m;
    vector<pair<int, int > > part, notp;
    vector<pair<int, int > > ans(m);
    int p = 0;
    for(int i = 0; i < m; i ++){
        int a, b;
        cin >> a >> b;
        if(b == 1)
            part.push_back({a, i});
        else
            notp.push_back({a, i}), p ++;
    }
    if(part.size() >= n) {puts("-1"); return;}
    sort(all(part)); sort(all(notp));
    for(int i = 1; i <= part.size(); i ++)
        ans[part[i - 1].second] = {i, i + 1};
    int s = 0, cnt = 1;
    for(int i = 0; i < notp.size(); i ++){
        if(notp[i].first >= part[s + 1].first) {
            ans[notp[i].second] = {cnt, s + 3};
            cnt --;
            if(cnt == 0){
                cnt = s + 2;
                s ++;
            }
        }
        else {puts("-1"); return;}
    }

    for(auto c : ans)
        cout << c.first << ' ' << c.second << endl;
}
