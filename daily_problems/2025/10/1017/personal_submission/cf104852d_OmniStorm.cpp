void solve() {
    int n;
    std::cin >> n;
 
    i64 sum = 0;
 
    std::function<bool(int)> f = [&](int a) {
        std::set<int> S;
        while (a) {
            S.insert(a % 10);
            a /= 10;
        }
        return S.size() <= 2;
    };
    
    std::set<std::pair<i64, i64>> ans;
    if (f(n)) ans.insert({0, n});
    for (int i = 0; i <= 9; i++) {
        // std::cerr << "=============\n";
        for (int j = 0; j <= i; j++) {
            std::vector<i64> pre = {0};
            i64 T = 1;
            for (int k = 0; k < 10; k++) {
                std::vector<i64> nxt;
                bool flg = true;
                for (auto x : pre) {
                    nxt.push_back(x + 1LL * j * T);
                }
                for (auto x : pre) nxt.push_back(x + 1LL * i * T);   
                pre = std::move(nxt);
 
                for (auto x : pre) {
                    if (x <= n - x && f(n - x) && f(x)) ans.insert({x, n - x});
                }
                T *= 10;
            }
        }
    }
 
    // for (auto [x, y] : ans) std::cout << x << " " << y << "\n";
    std::cout << ans.size() << "\n";
}
