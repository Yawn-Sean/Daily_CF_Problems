void solve(){
    const int N = 1e6, base = 13331;
    auto pows = [&](u64 a, i64 b)->u64{
        u64 res = 1;
        while (b){
            if (b&1) res = res*a;
            a = a*a;
            b >>= 1;
        }
        return res;
    };
    vector<vector<u64>> w(26, vector<u64>(N+1));
    for (int i = 0; i < 26; ++ i){
        for (int j = 1; j <= N; ++ j){
            w[i][j] = w[i][j-1]*base + ('a' + i);
        }
    }
    
    int n, m;
    cin >> n >> m;
    vector <array<i64,2>> A, B; // <字符，数量>
    vector <u64> haA, haB;  // <哈希值>
    for (int i = 0; i < n; ++ i){
        i64 x, y;
        char ch;
        cin >> y >> ch >> ch;
        x = ch-'a';
        u64 v = w[x][y];
        assert(y <= N);
        while (!A.empty() && A.back()[0] == x){
            v = haA.back()*y + v;
            y += A.back()[1];

            A.pop_back();
            haA.pop_back();
        }

        A.push_back({x, y});
        haA.push_back(v);
    }

    for (int i = 0; i < m; ++ i){
        i64 x, y;
        char ch;
        cin >> y >> ch >> ch;
        x = ch-'a';
        assert(y <= N);
        u64 v = w[x][y];

        while (!B.empty() && B.back()[0] == x){
            v = haB.back()*y + v;
            y += B.back()[1];

            B.pop_back();
            haB.pop_back();
        }

        B.push_back({x, y});
        haB.push_back(v);
    }

    n = A.size(), m = B.size();
    int t1 = B[0][0], t2 = B[m-1][0];
    i64 b1 = B[0][1], b2 = B[m-1][1];
    
    i64 res = 0;
    if (m == 1){
        for (int i = 0; i < n; ++ i){
            auto &[x, y] = A[i];
            if (x == t1 && y >= b1){
                res += y - b1 + 1;
            }
        }
    } else if (m == 2){
        for (int i = 0; i < n-1; ++ i){
            auto &[x1, y1] = A[i];
            auto &[x2, y2] = A[i+1];
            if (x1 == t1 && x2 == t2){
                if (y1 >= b1 && y2 >= b2){
                    res += 1;
                }
            }
        }
    } else {
        u64 tar = 0;
        i64 l = 0;

        for (int i = 1; i < m-1; ++ i){  // tar 是中间部分的哈希值
            auto &[x, y] = B[i];
            tar = tar*pows(base, y) + haB[i];
            l += y;
        }

        vector <i64> pr(n+1);
        vector <u64> ha(n+1);
        for (int i = 0; i < n; ++ i){
            auto &[x, y] = A[i];
            pr[i+1] = pr[i] + y;
            ha[i+1] = ha[i]*pows(base, y) + haA[i];
        }

        auto code = [&](int l, int r)->u64{
            return ha[r] - ha[l-1] * pows(base, pr[r]-pr[l-1]);
        };

        for (int i = 1; i <= n; ++ i){
            int i1 = i-1, i2 = i1+m-1;
            if (i2 >= n) break;
            
            if (A[i1][0] == t1 && A[i2][0] == t2){
                if (A[i1][1] >= b1 && A[i2][1] >= b2){
                    if (pr[i+m-2]-pr[i] == l && code(i+1, i+m-2) == tar){
                        res += 1;
                    }
                }
            }
        }
    }

    cout << res << "\n";
}
