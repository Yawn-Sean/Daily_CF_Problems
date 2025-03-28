void solve(){
    string s;
    cin >> s;
    vector <i64> cnts(10);
    for (int i = 1; i < s.size(); ++ i){
        int c = (int)s[i] - (int)s[i-1];
        c %= 10;
        if (c < 0) c += 10;
        cnts[c] += 1;
    }
    vector<vector<i64>> ans(10,vector<i64>(10, -1));
    for (int i = 0; i < 10; ++ i){
        for (int j = 0; j < 10; ++ j){
            vector <int> dist(10, inf_int);
            dist[i] = 0, dist[j] = 0;
            queue <int> Q;
            Q.push(i), Q.push(j);
            while (!Q.empty()){
                auto u = Q.front();
                Q.pop();
                int ni = (u+i) % 10;
                int nj = (u+j) % 10;
                if (dist[ni] == inf_int){
                    dist[ni] = dist[u] + 1;
                    Q.push(ni);
                }
                if (dist[nj] == inf_int){
                    dist[nj] = dist[u] + 1;
                    Q.push(nj);
                }
            }
            i64 res = 0;
            bool jug = 1;
            for (int i = 0; i < 10; ++ i){
                if (cnts[i]){
                    if (dist[i] == inf_int){
                        jug = 0;
                        break;
                    }
                    res += cnts[i] * dist[i];
                }
            }
            if (jug) ans[i][j] = res;
        }
    }

    for (auto &vec : ans){
        print(vec);
    }
}
