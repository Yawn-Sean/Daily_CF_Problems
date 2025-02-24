void solve(){
    const int N = 1e7;
    static int cnts1[N+1], cnts2[N+1], mip[N+1], vis[N+1], cost1[N+1], cost2[N+1];
    vector <i64> prms;
    for (int i = 2; i <= N; ++ i){
        if (!vis[i]) prms.push_back(i);
        for (auto &y : prms){
            if (i*y > N) break;
            vis[i*y] = 1, mip[i*y] = y;
            if (i%y == 0) break; 
        }
    }

    int n, m;
    cin >> n >> m;
    vector <int> A(n), B(m);
    for (int i = 0; i < n; ++ i){
        cin >> A[i];
        int x = A[i];
        while (mip[x]){
            int y = mip[x];
            while (x%y == 0){
                x /= y;
                cnts1[y] += 1;
            }
        }
        if (x > 1) cnts1[x] += 1;
    }
    for (int i = 0; i < m; ++ i){
        cin >> B[i];
        int x = B[i];
        while (mip[x]){
            int y = mip[x];
            while (x%y == 0){
                x /= y;
                cnts2[y] += 1;
            }
        }
        if (x > 1) cnts2[x] += 1;
    }

    for (int i = 2; i <= N; ++ i){
        int c = min(cnts1[i], cnts2[i]);
        cost1[i] = cost2[i] = c;
    }

    for (int i = 0; i < n; ++ i){
        int x = A[i], cur = 1;
        while (mip[x]){
            int y = mip[x];
            while (x%y == 0){
                x /= y;
                if (cost1[y]){
                    cost1[y] -= 1;
                    cur *= y;
                }
            }
        }
        if (x > 1 && cost1[x]){
            cost1[x] -= 1;
            cur *= x;
        }
        A[i] /= cur;
    }

    for (int i = 0; i < m; ++ i){
        int x = B[i], cur = 1;
        while (mip[x]){
            int y = mip[x];
            while (x%y == 0){
                x /= y;
                if (cost2[y]){
                    cost2[y] -= 1;
                    cur *= y;
                }
            }
        }
        if (x > 1 && cost2[x]){
            cost2[x] -= 1;
            cur *= x;
        }
        B[i] /= cur;
    }

    cout << A.size() << " " << B.size() << "\n";
    print(A);
    print(B);
}
