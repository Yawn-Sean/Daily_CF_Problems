void solve(){
    const int N = 4000000, inf = 1e9;
    static int trie[N][26];
    static array<int,2> from[N];

    int tot = 0;
    auto insert = [&](string s, int id)->void{
        int cur = 0, m = s.size();
        for (int i = 0; i < m; ++ i){
            char ch = s[i];
            int c = ch-'a';
            if (!trie[cur][c]){
                trie[cur][c] = ++ tot;
                from[tot] = {id, i};
            }
            cur = trie[cur][c];
        }
    };

    string s1, t;
    cin >> s1 >> t;
    int m = s1.size();
    for (int i = 0; i < m; ++ i){
        insert(s1.substr(i), i);
    }
    string s2 = s1;
    reverse(s2.begin(), s2.end());
    for (int i = 0; i < m; ++ i){
        insert(s2.substr(i), m+i);
    }

    int n = t.size();
    vector <int> f(n+1, inf_int), last(n+1), go_lst(n+1);
    t = " " + t;
    f[0] = 0;
    for (int i = 0; i <= n; ++ i){
        if (f[i] == inf_int) continue;
        for (int j = i+1, cur = 0; j <= n; ++ j){
            int c = t[j]-'a';
            if (!trie[cur][c]) break;
            cur = trie[cur][c];
            if (f[i]+1 < f[j]){
                f[j] = f[i]+1;
                last[j] = i;
                go_lst[j] = cur;
            }
        }
    }

    if (f[n] == inf_int){
        cout << -1 << "\n";
    } else {
        vector<array<int,2>> asks;
        int cur = n;
        while (cur > 0){
            int lst = last[cur];
            asks.push_back({cur-lst, go_lst[cur]});
            cur = lst;
        }
        reverse(asks.begin(), asks.end());

        int len = asks.size();
        assert(f[n] == len);

        auto find = [&](int len, int who)->pair<int,int>{
            auto j = from[who];
            int l, r;
            if (j[0] < m){
                r = j[0]+j[1], l = r-len+1;
            } else {
                r = j[0]+j[1]-m, l = r-len+1;
                r = m-r-1, l = m-l-1;
            }
            return {l+1, r+1};
        };

        vector <array<int,2>> ans;
        for (int i = 0; i < len; ++ i){
            int L = asks[i][0], u = asks[i][1], u0, u1;
            tie(u0, u1) = find(L, u);
            ans.push_back({u0,u1});
        }

        cout << f[n] << "\n";
        for (auto &it : ans){
            cout << it[0] << " " << it[1] << "\n";
        }
    }
}
