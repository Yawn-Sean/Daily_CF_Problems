/*
    发现：
    不可能只有 1 个位置不合法
    最多只有 6 个位置不合法，超过就不可能满足条件了
    只有当有 2、3 个位置不合法时，内部和外部的交换才有意义。
    想要纠正这些位置，直接考虑暴力枚举内部之间的交换、内部和外部的交换。
*/
void solve(){
    int n;
    cin >> n;
    vector <int> A(n);
    for (auto &x : A){
        cin >> x;
    }
    auto w = [&](int i)->int{
        int v;
        if (i%2 == 0){
            v = inf_int;
            if (i) fmin(v, A[i-1]);
            if (i < n-1) fmin(v, A[i+1]);
        } else {
            v = -inf_int;
            if (i) fmax(v, A[i-1]);
            if (i < n-1) fmax(v, A[i+1]);
        }
        return v;
    };

    vector <int> ids;
    for (int i = 0; i < n; ++ i){
        int v = w(i);
        if (i%2 == 0){
            if (A[i] >= v){
                ids.push_back(i);
            }
        } else {
            if (A[i] <= v){
                ids.push_back(i);
            }
        }
    }

    if (ids.size() > 6) return void(cout << 0 << "\n");
    assert(ids.size() != 1);

    vector <int> chooses;
    set <int> st(chooses.begin(), chooses.end());
    if (ids.size() == 2){
        chooses = ids;
    } else if (ids.size() == 3){
        chooses.push_back(ids[1]);
    }

    int res = 0;
    // 考虑内部交换
    for (int u = 0; u < ids.size(); ++ u){
        for (int v = u+1; v < ids.size(); ++ v){
            bool jug = 1;
            swap(A[ids[u]], A[ids[v]]);
            for (int i = 0; i < n; ++ i){
                int v = w(i);
                if (i%2 == 0 && A[i] >= v) jug = 0;
                if (i%2 == 1 && A[i] <= v) jug = 0;
            }
            res += jug;
            swap(A[ids[u]], A[ids[v]]);
        }
    }

    // 考虑内外部交换
    for (auto &id : chooses){
        int v1 = w(id), x = A[id];
        if (id%2 == 0){
            for (int i = 0; i < n; ++ i){
                if (st.count(i) || A[i] >= v1) continue;
                int v2 = w(i);
                if (i%2==0){
                    res += x < v2;
                } else {
                    res += x > v2;
                }
            }
        } else {
            for (int i = 0; i < n; ++ i){
                if (st.count(i) || A[i] <= v1) continue;
                int v2 = w(i);
                if (i%2==0){
                    res += x < v2;
                } else {
                    res += x > v2;
                }
            }
        }
    }
    
    cout << res << "\n";
}
