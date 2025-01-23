void solve(){
    auto error = [&]()->void{
        cout << -1 << "\n";
    };
    int n;
    cin >> n;
    vector <int> f(n), A(n);
    for (auto &x : A){
        cin >> x;
    }

    {
        int i = n-1;
        while (i >= 0){
            int j = i;
            if (j-1 >= 0 && A[j] > A[j-1]){
                while (j-1 >= 0 && A[j] > A[j-1]){
                    j -= 1;
                }
                f[j] = i-j+1;
                i = j;
            } else if (j-1 >= 0 && A[j] < A[j-1]){
                while (j-1 >= 0 && A[j] < A[j-1]){
                    j -= 1;
                }
                f[j] = -(i-j+1);
                i = j;
            } else {
                i = j-1;
            }
        }
    }
    for (int i = 0; i < n; ++ i){
        if (f[i] > 5){
            return error();
        }
    }

    auto other = [&](int x)->int{
        if (x < 4) return x+1;
        else return x-1;
    };
    vector <int> ans(n);
    {
        int i = 0;
        while (i < n){
            int len = abs(f[i]);
            if (f[i] > 0){
                ans[i] = 1;
                if (i > 0 && ans[i-1] == 1) ans[i] += 1;
                for (int j = i; j < i+len-1; ++ j){
                    ans[j+1] = ans[j]+1;
                    if (ans[j+1] > 5) return error();
                }
                i = i+len-1; 
            } else if (f[i] < 0){
                ans[i] = 5;
                if (i > 0 && ans[i-1] == 5) ans[i] -= 1;
                for (int j = i; j < i+len-1; ++ j){
                    ans[j+1] = ans[j]-1;
                    if (ans[j+1] < 1) return error();
                }
                i = i+len-1;
            } else {
                if (ans[i] == 0){
                    if (i == 0) ans[i] = 3;
                    else ans[i] = other(ans[i-1]);
                }
                i += 1;
            }
        }
    }

    print(ans);
}
