void solve(){
    const int mod = 1e9+9;
    int n;
    cin >> n;
    
    int tot = -1;
    unordered_map <i64,int> mps;
    auto key = [&](const i64 &x, const i64 &y)->i64{
        return (x + 1087645944) * 8393777 + ((y << 30) ^ (y * 99233683));
    };
    auto insert = [&](i64 x, i64 y)->void{
        i64 j = key(x,y);
        if (!mps.count(j)) mps[j] = ++ tot;
    };

    vector<array<int,2>> xys(n);
    vector <int> din(n);
    for (auto &[x, y] : xys){
        cin >> x >> y;
        insert(x, y);
    }

    auto chk = [&](int x, int y)->bool{  // 检查位置在 x,y 能否入队 
        for (int i = -1; i <= 1; ++ i){
            i64 u = key(x+i, y+1);
            if (mps.count(u)){
                u = mps[u];
                if (din[u] == 1) return false;
            }
        }
        return true;
    };

    for (auto &[x, y] : xys){
        for (int j = -1; j <= 1; ++ j){
            i64 u = key(x+j, y+1);
            if (mps.count(u)){
                din[mps[u]] += 1;
            }
        }
    }
    priority_queue <int> pq1;
    priority_queue <int, vector<int>, greater<int>> pq2;
    vector <int> ans, dels(n), ins(n);  // ins 用于入队优化，减少重复入队，dels用于标记取走的点
    int mark = 0;

    for (int i = 0; i < n; ++ i){
        auto &[x, y] = xys[i];
        if (chk(x, y)){
            pq1.push(i);
            pq2.push(i);
            ins[i] = 1;
        }
    }
    auto del = [&](int j)->void{  // 删去 j 带来的影响，入度减少的点 下面三个有可能入队
        auto &[x, y] = xys[j];
        dels[j] = 1, din[j] = 0;
        for (int i = -1; i <= 1; ++ i){
            i64 u = key(x+i, y+1);
            if (mps.count(u)){
                u = mps[u];
                if (!dels[u]){
                    assert(din[u] > 0);
                    din[u] -= 1;
                }
            }
        }

        for (int i = -2; i <= 2; ++ i){
            i64 u = key(x+i, y);
            if (mps.count(u)){
                u = mps[u];
                if (!ins[u] && !dels[u] && chk(xys[u][0], xys[u][1])){
                    pq1.push(u);
                    pq2.push(u);
                    ins[u] = 1;
                }
            }
        }
        
        if (y == 0) return;

        for (int i = -1; i <= 1; ++ i){
            i64 u = key(x+i, y-1);
            if (mps.count(u)){
                u = mps[u];
                if (!ins[u] && !dels[u] && chk(xys[u][0], xys[u][1])){
                    pq1.push(u);
                    pq2.push(u);
                    ins[u] = 1;
                }
            }
        }
    };

    while (ans.size() < n){
        if (mark == 0){
            int j = pq1.top();
            pq1.pop(), ins[j] = 0;

            if (dels[j] || !chk(xys[j][0], xys[j][1])){
                continue;
            }
            
            ans.push_back(j);
            mark = !mark;

            del(j);
        } else {
            int j = pq2.top();
            pq2.pop(), ins[j] = 0;

            if (dels[j] || !chk(xys[j][0], xys[j][1])){
                continue;
            }

            ans.push_back(j);
            mark = !mark;

            del(j);
        }
    }

    assert(ans.size() == n);
    i64 res = 0;
    for (int i = 0; i < n; ++ i){
        res = res*n + ans[i];
        res %= mod;
    }

    cout << res << "\n";
}
