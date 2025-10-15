void solve(){
    int n;
    cin >> n;
    vector <int> A(n);
    int mi = 100;
    for (auto &x : A){
        cin >> x;
        fmin(mi, x);
    }
    
    int dep = 0;
    for (int i = 1; i <= mi; ++ i){  // 枚举深度
        vector <int> vec;
        int tot = 0;
        for (auto &x : A){
            tot += x-i;
            vec.push_back(x-i);
        }
    
        if (tot%2){
            bool jg = 1;
            if (vec.size() >= 5){
                sort(vec.begin(), vec.end(), greater<int>()), tot -= 5;
                for (int i = 0; i < 5; ++ i){
                    vec[i] -= 1;
                    if (vec[i] < 0) jg = 0;
                }
                if (tot < 0) jg = 0;
            } else jg = 0;
            if (!jg) continue;
        }

        assert(tot%2 == 0);
        bool jg = 1;
        for (auto &x : vec){
            if (x > tot-x){
                jg = 0;
                break;
            }
        }
        if (jg) dep = i;
    }
    // cout << dep;
    // return;
    vector <string> ans;
    string cur;
    int tot = 0;
    vector <int> vec;
    for (auto &x : A){
        tot += x-dep;
        vec.push_back(x-dep);
    }
    if (dep > 0 && tot%2){  // 奇数变偶数
        bool jg = 1;
        cur = string(n, '0');
        if (vec.size() >= 5){
            vector <int> idx(n);
            iota(idx.begin(), idx.end(), 0);
            sort(idx.begin(), idx.end(), [&](auto &u, auto &v){
                return vec[u] > vec[v];
            });
            tot -= 5;
            for (int id = 0; id < 5; ++ id){
                int i = idx[id];
                vec[i] -= 1, cur[i] = '1';
                if (vec[i] < 0) jg = 0;
            }
            if (tot < 0) jg = 0;
        } else jg = 0;
        assert(jg);
        ans.push_back(cur);
    }

    auto chk = [&]()->bool{
        for (int i = 1; i < n; ++ i){
            if (vec[i] != vec[i-1]){
                return false;
            }
        }
        return true;
    };
    priority_queue <pair<int,int>> pq;
    for (int i = 0; i < n; ++ i){
        pq.push({vec[i], i});
    }

    while (!chk()){
        auto [v1,i1] = pq.top();
        pq.pop();
        auto [v2,i2] = pq.top();
        pq.pop();
        cur = string(n, '0');
        cur[i1] = cur[i2] = '1';

        if (v1) v1 -= 1;
        if (v2) v2 -= 1;
        vec[i1] = v1, vec[i2] = v2;

        pq.push({v1,i1}), pq.push({v2,i2});

        ans.push_back(cur);
    }
    
    cout << dep << "\n";
    cout << ans.size() << "\n";
    for (auto &chs : ans){
        cout << chs << "\n";
    }
}
