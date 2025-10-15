void solve(){
    struct point {
        int score1, score2, set1, set2;
    };
    auto ID = [&](int score1, int score2, int set1, int set2)->int{
        return ((score1*201 + score2)*4 + set1)*4 + set2;
    };
    auto ufix = [&](int u)->point{
        int set2 = u%4;
        u /= 4;
        int set1 = u%4;
        u /= 4;
        int score2 = u%201;
        u /= 201;
        int score1 = u;
        return point({score1, score2, set1, set2});
    };

    vector <int> f(201*201*4*4, -2), vis(201*201*4*4);
    queue <int> Q;
    f[ID(0, 0, 0, 0)] = -1;

    Q.push(ID(0, 0, 0, 0));
    while (!Q.empty()){
        auto u = Q.front();
        Q.pop();
        if (vis[u]) continue;
        vis[u] = 1;

        auto [score1, score2, set1, set2] = ufix(u);

        int tar = set1+set2 < 4 ? 25 : 15;
        // 讨论 A 赢了常规淘汰或者加时赛
        if (set1+1 <= 3 && set2 < 3){
            if (score1+tar <= 200){
                for (int i = 0; i <= tar-2; ++ i){
                    if (score2+i > 200) break;
                    int to = ID(score1+tar, score2+i, set1+1, set2);
                    if (!vis[to]){
                        f[to] = u;
                        Q.push(to);
                    }
                }
            }
            for (int i = tar+1; i <= 200; ++ i){
                if (score1+i > 200 || score2+i-2 > 200) break;
                int to = ID(score1+i, score2+i-2, set1+1, set2);
                if (!vis[to]){
                    f[to] = u;
                    Q.push(to);
                }
            }
        }

        // 讨论 A以外的队伍 赢了常规淘汰或者加时赛
        if (set1 < 3 && set2+1 <= 3){
            if (score2+tar <= 200){
                for (int i = 0; i <= tar-2; ++ i){
                    if (score1+i > 200) break;
                    int to = ID(score1+i, score2+tar, set1, set2+1);
                    if (!vis[to]){
                        f[to] = u;
                        Q.push(to);
                    }
                }
            }
            for (int i = tar+1; i <= 200; ++ i){
                if (score1+i-2 > 200 || score2+i > 200) break;
                int to = ID(score1+i-2, score2+i, set1, set2+1);
                if (!vis[to]){
                    f[to] = u;
                    Q.push(to);
                }
            }
        }
    }

    int m;
    cin >> m;
    while (m--){
        int u, v;
        cin >> u >> v;

        int ix = -1, iy = -1, ans1, ans2;
        for (int i = 0; i <= 2; ++ i){
            if (f[ID(u,v,3,i)] != -2){
                ix = 3, iy = i;
                break;
            }
        }
        if (ix == -1){
            for (int i = 2; i >= 0; -- i){
                if (f[ID(u,v,i,3)] != -2){
                    ix = i, iy = 3;
                    break;
                }
            }
        }

        if (ix == -1){
            cout << "Impossible\n";
        } else {
            int j1 = ID(u, v, ix, iy);
            vector <array<int,2>> ans;

            while (j1 != 0){
                int j2 = f[j1];
                auto [s1, s2, _1, _2] = ufix(j1);
                auto [p1, p2, _3, _4] = ufix(j2);
                ans.push_back({s1-p1, s2-p2});
                j1 = j2;
            }

            reverse(ans.begin(), ans.end());
            cout << ix << ":" << iy << "\n";
            for (int i = 0; i < ans.size(); ++ i){
                if (i) cout << " ";
                cout << ans[i][0] << ":" << ans[i][1];
            }
            cout << "\n";
        }
    }
}
