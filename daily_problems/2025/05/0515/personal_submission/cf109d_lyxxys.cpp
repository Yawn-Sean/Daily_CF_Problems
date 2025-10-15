void solve(){
    using ary2 = array<int,2>;
    auto isLucky = [&](int x)->bool{
        while (x){
            if (!(x%10==4 || x%10==7)) return false;
            x /= 10;
        }
        return true;
    };

    int n;
    cin >> n;

    map <array<int,2>, int> mps;
    vector <ary2> A;
    ary2 chose = {-1, -1};
    bool jug = 1;
    for (int i = 0, x; i < n; ++ i){
        cin >> x;
        A.push_back({x, i});
        mps[{x, i}] = i;
        if (i){
            jug &= A[i][0] >= A[i-1][0];
        }
        if (isLucky(x)){
            chose = A[i];
        }
    }
    if (chose == array<int,2>{-1, -1}){
        if (!jug){
            cout << -1 << "\n";
        } else {
            cout << 0 << "\n";
        }
        return;
    }


    vector <ary2> ans;
    vector <ary2> B = A;
    sort(B.begin(), B.end(), [&](auto &u, auto &v){
        return u[0] == v[0] ? u[1] < v[1] : u[0] < v[0];
    });

    auto fswap = [&](ary2 u, ary2 v)->void{
        int p1, p2;
        p1 = mps[u], p2 = mps[v];
        
        A[p1] = v, A[p2] = u;
        mps[u] = p2, mps[v] = p1;

        ans.push_back({p1, p2});
    };

    for (int i = 0; i < n; ++ i){
        ary2 tar = B[i];
        if (tar == A[i]) continue;

        if (A[i] != chose){
            fswap(A[i], chose);
        }
        if (chose != tar){
            fswap(chose, tar);
        }
    }

    cout << ans.size() << "\n";
    for (auto &[x, y] : ans){
        cout << x+1 << " " << y+1 << "\n";
    }
}
