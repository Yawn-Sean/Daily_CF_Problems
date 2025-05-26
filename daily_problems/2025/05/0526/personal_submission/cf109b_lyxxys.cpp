void solve(){
    int pl, pr, vl, vr, k;
    cin >> pl >> pr >> vl >> vr >> k;

    vector <int> A;
    auto build = [&](auto &&self, i64 x)->void{
        A.push_back(x);
        if (x*10 > inf_int) return;
        self(self, x*10 + 4);
        self(self, x*10 + 7);
    };
    build(build, 0);
    A.push_back(inf_int+1);
    sort(A.begin(), A.end());
    
    auto w = [&](int l1, int r1, int l2, int r2)->f64{
        f64 res = 0;
        // [pl,pr] 和 [l1,r1] 相交，[vl,vr] 和 [l2,r2] 相交
        if (!(r1<pl || l1>pr || r2<vl || l2>vr)){
            f64 w1 = min(pr, r1) - max(pl, l1) + 1;
            f64 w2 = min(vr, r2) - max(vl, l2) + 1;
            res += w1 * w2;
        }
        // [pl,pr] 和 [l2,r2] 相交，[vl,vr] 和 [l1,r1] 相交
        if (!(r2<pl || l2>pr || r1<vl || l1>vr)){
            f64 w1 = min(pr, r2) - max(pl, l2) + 1;
            f64 w2 = min(vr, r1) - max(vl, l1) + 1;
            res += w1 * w2;
        }
        return res;
    };
    
    int n = A.size();
    f64 res = 0;
    for (int i = 1; i+k-1 < A.size()-1; ++ i){
        int l1 = A[i-1]+1, r1 = A[i], l2 = A[i+k-1], r2 = A[i+k]-1;
        res += w(l1, r1, l2, r2);
        if (k == 1 && A[i] >= pl && A[i] <= pr && A[i] >= vl && A[i] <= vr) res -= 1;
    }

    res /= 1.0 * (pr-pl+1) * (vr-vl+1);
    cout << fixed << setprecision(15) << res << "\n";
}
