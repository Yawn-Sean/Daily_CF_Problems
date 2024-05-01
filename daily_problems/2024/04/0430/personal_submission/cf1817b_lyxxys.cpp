using namespace std;
const int N = 2050;

void solve(){
    int n, m;
    cin >> n >> m;
    vector <int> g[N];
    for (int i = 1; i <= m; ++ i){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b), g[b].push_back(a);
    }

    vector <int> Pre(n+1);
    bitset <N> vit;
    int T;
    auto dfs = [&](auto self, int u, int fa, int aim)->bool{
        vit[u] = true;
        
        for (int &ver : g[u]){
            if (ver == fa) continue;
            if (ver == aim){
                T = u;
                return true;
            }
        }
        for (int &ver : g[u]){
            if (ver == fa) continue;
            if (!vit[ver]){
                Pre[ver] = u;
                if (self(self, ver, u, aim)) return true;
            }
        }
        return false;
    };
    vector <array<int,2>> res;
    vector <int> cnt(n+1);

    for (int i = 1; i <= n; ++ i)
        if ((int)g[i].size() > 3){ //度数大于4且有环一定是鱼骨图
            vit.reset(), fill(Pre.begin(), Pre.end(), 0);
            if (dfs(dfs, i, -1, i)){
                for (int j = T; j != i; j = Pre[j])
                    ++ cnt[j], res.push_back({Pre[j], j});
                int sum = 0;
                res.push_back({T, i});
                for (auto &ver : g[i])
                    if (!cnt[ver]){
                        res.push_back({i, ver});
                        if (++ sum == 2) break;
                    }
                
                break;
            }
        }
    if (res.size()){
        cout << "Yes\n" << res.size() << "\n";
        for (int i = 0; i < res.size(); ++ i)
            cout << res[i][0] << " " << res[i][1] << "\n";
    }
    else cout << "No\n";
}
