#include<bits/stdc++.h>
#define L(i, l, r) for(int i = l; i <= r; i ++)
#define R(i, l, r) for(int i = l; i >= r; i --)
#define ll long long
#define fi first
#define se second
#define vi vector <int>
#define vl vector <long long>
#define sz(a) ((int) (a).size())
#define me(f, x) memset(f, x, sizeof(f))
#define ull unsigned long long
using namespace std;

const int N = 2e5 + 10;

int dict[N];
int n, m;
int sum[N], in[N];

struct Edge{
    int v, c, id;
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    // int T; cin >> T; while(T --) solve();

    cin >> n >> m;
    me(dict, -1);

    vector<vector<Edge>> edges(n + 1);

    for(int i = 1; i <= m; i ++){
        int a, b, c; cin >> a >> b >> c;
        sum[a] += c, sum[b] += c;

        if(a == 1 || b == 1){
            if(a == 1) dict[i] = 0, in[b] += c;
            if(b == 1) dict[i] = 1, in[a] += c;
            continue;
        }

        edges[a].push_back({b, c,  i});
        edges[b].push_back({a, c, -i});
    }

    queue<int> q;
    for(int i = 2; i < n; i ++){
        if(in[i] * 2 == sum[i]){
            q.push(i);
        }
    }
    
    while(!q.empty()){
        auto t = q.front(); q.pop();

        for(auto &[v, c, num] : edges[t]){
            in[v] += c;
            int id = abs(num);
            if(dict[id] != -1) continue;
            if(num > 0) dict[id] = 0;
            else dict[id] = 1;

            if(in[v] * 2 == sum[v]){
                if(v != n) q.push(v);
            }
        }
    }

    L(i, 1, m) cout << dict[i] << endl;

    return 0;
}
