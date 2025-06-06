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
const int N = 2e5 + 10;

signed main (){ 
	std::cin.tie(NULL)->sync_with_stdio(false);
	int t = 1;
	// cin >> t;  //atc默认关闭，cf按需开启
	while(t --)
		solve();
}
int h[N];
vector <int> adj[N];
bool vis[N];
void solve(){
	int n; cin >> n;
    for(int i = 1; i <= n; i ++){
        int x;
        cin >> x;
        adj[i].push_back(x);
    }
    adj[1].push_back(2);adj[n].push_back(n - 1);
    for(int i = 2; i <= n - 1; i ++){
        adj[i].push_back(i - 1);
        adj[i].push_back(i + 1);
    }

    auto bfs = [&]() {
        queue<int> s;
        s.push(1);
        h[1] = 0;
        while (s.size()) {
            int x = s.front();
            vis[x] = 1;
            s.pop();
            for (int v : adj[x]) {
                if (!vis[v] && (h[v] > h[x] + 1 || !h[v])) {
                    s.push(v);
                    if (h[v] > h[x] + 1 || !h[v]) h[v] = h[x] + 1;
                }
            }
        }
    };

    bfs();
    for(int i = 1; i <= n; i ++)
        cout << h[i] << ' ';
    cout << endl;
}
