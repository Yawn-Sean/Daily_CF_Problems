#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Pii = pair<int,int>;
using ull = unsigned long long;
const int N = 2000011, mod = 1000001, inf = 1e9;
int p[N], ptime[N];
vector <int> xblock[2*N], yblock[2*N];

int root(int x){
    if (x == p[x]) return x;
    int px = root(p[x]);
    int fmin = min(ptime[px], ptime[x]);
    ptime[px] = ptime[x] = fmin;
    return p[x] = px;
}
void merge(int x, int y){
    int px = root(x), py = root(y);
    if (px != py){
        p[px] = py;
        ptime[py] = min(ptime[py], ptime[px]);
    }
}

void solve(){
    // for (int i = 1; i < N; ++ i) p[i] = i;
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++ i) p[i] = i, xblock[i].clear(), yblock[i].clear();
    for (int i = n+1; i <= 2*n; ++ i) xblock[i].clear(), yblock[i].clear();
    vector <int> X(n+1), Y(n+1), xpos(n+1), ypos(n+1), dic;
    // xpos,ypos分别表示X和Y映射在dic的下标
    // xblock[i] 表示横坐标在 dic[xpos[i]]上 所有地雷的编号
    // yblock[i] 表示纵坐标在 dic[ypos[i]]上 所有地雷的编号

    for (int i = 1; i <= n; ++ i)
        cin >> X[i] >> Y[i] >> ptime[i], dic.push_back(X[i]), dic.push_back(Y[i]);
    
    sort(dic.begin(), dic.end());
    dic.erase(unique(dic.begin(), dic.end()), dic.end());
    auto find = [&](int x)->int{
        return lower_bound(dic.begin(), dic.end(), x) - dic.begin() + 1;
    };

    for (int i = 1; i <= n; ++ i){
        xpos[i] = find(X[i]), ypos[i] = find(Y[i]);
        xblock[xpos[i]].push_back(i), yblock[ypos[i]].push_back(i);
    }
    
    for (int i = 1; i <= 2*n; ++ i){
        sort(xblock[i].begin(), xblock[i].end(), [&](int i, int j){
            return dic[ypos[i]-1] < dic[ypos[j]-1];
        });
        sort(yblock[i].begin(), yblock[i].end(), [&](int i, int j){
            return dic[xpos[i]-1] < dic[xpos[j]-1];
        });
    }
    for (int i = 1; i <= 2*n; ++ i)
       for (int j = 1, delta; j < xblock[i].size(); ++ j){
            int nxt = xblock[i][j], lst = xblock[i][j-1];
            delta = dic[ypos[nxt]-1] - dic[ypos[lst]-1];
            if (delta <= k) merge(lst, nxt);
        }
    for (int i = 1; i <= 2*n; ++ i)
        for (int j = 1, delta; j < yblock[i].size(); ++ j){
            int nxt = yblock[i][j], lst = yblock[i][j-1];
            delta = dic[xpos[nxt]-1] - dic[xpos[lst]-1];
            if (delta <= k) merge(lst, nxt);
        }

    vector <int> block;
    for (int i = 1; i <= n; ++ i)
        if (p[i] == i) block.push_back(ptime[i]);
    sort(block.begin(), block.end());

    int bsize = block.size();
    int i = -1, j = bsize-1, res = 0;
    while (i+1 != j){
        if (res < block[i+1]) -- j, ++ res;
        else ++ i;
    }
    cout << res << "\n";
}
 
