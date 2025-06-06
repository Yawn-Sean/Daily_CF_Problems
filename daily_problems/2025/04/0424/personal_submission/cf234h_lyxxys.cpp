void solve(){
    int n, m;

    cin >> n;
    vector <int> A(n);
    for (auto &x : A){
        cin >> x;
    }

    cin >> m;
    vector <int> B(m);
    for (auto &x : B){
        cin >> x;
    }

    vector <int> ans1, ans2;

    int i1 = 0, i2 = 0;
    while (i1 < n || i2 < m){
        if (i1 < n){
            int v = A[i1];
            while (i1 < n && A[i1] == v){
                ans1.push_back(i1);
                i1 += 1;
            }
            while (i2 < m && B[i2] == v){
                ans1.push_back(n+i2);
                i2 += 1;
            }
        } else {
            ans1.push_back(n+i2);
            i2 += 1;
        }
    }
    i1 = 0, i2 = 0;
    while (i1 < n || i2 < m){
        if (i2 < m){
            int v = B[i2];
            while (i2 < m && B[i2] == v){
                ans2.push_back(i2+n);
                i2 += 1;
            }
            while (i1 < n && A[i1] == v){
                ans2.push_back(i1);
                i1 += 1;
            }
        } else {
            ans2.push_back(i1);
            i1 += 1;
        }
    }

    auto val = [&](int i)->int{
        if (i < n) return A[i];
        else return B[i-n];
    };
    auto w = [&](vector <int> vec)->int{
        int n = vec.size();
        vector <int> mark(n);
        for (int i = n-1; i >= 0; -- i){
            if (val(vec[i]) == 1) break;
            mark[i] = 1;
        }
        int cnt = 0;
        for (int i = 0; i < n; ++ i){
            if (mark[i]) break;
            if (i == n-1 || val(vec[i]) != val(vec[i+1])){
                cnt += 1;
            }
        }
        return cnt;
    };
    auto fout = [&](vector <int> vec)->void{
        int n = vec.size();
        vector <int> mark(n);
        for (int i = n-1; i >= 0; -- i){
            if (val(vec[i]) == 1) break;
            mark[i] = 1;
        }
        vector <int> ans;
        for (int i = 0; i < n; ++ i){
            if (mark[i]) break;
            if (i == n-1 || val(vec[i]) != val(vec[i+1])){
                ans.push_back(i+1);
            }
        }
        cout << ans.size() << "\n";
        print(ans);
    };

    int v1 = w(ans1), v2 = w(ans2);
    if (v1 < v2){
        print(ans1, 1);
        fout(ans1);
    } else {
        print(ans2, 1);
        fout(ans2);
    }
}
