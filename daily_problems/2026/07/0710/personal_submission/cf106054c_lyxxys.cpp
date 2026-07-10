void solve() {
    int n;
    std::cin >> n;
    std::vector<int> A(n);
    for (auto &x : A){
        std::cin >> x;
        x -= 1;
    }

    std::map<int,int> M;
    using i64 = long long;
    i64 res{n};
    for (int i = 0; i < n; ++ i){
        int v = M[i+A[i]]+ M[i+A[i]-n];
        res += 2 * v;
        M[i+A[i]] += 1;
    }

    std::cout << res << "\n";
}
