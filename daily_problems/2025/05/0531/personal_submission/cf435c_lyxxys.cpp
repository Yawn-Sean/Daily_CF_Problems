void solve(){
    int n;
    cin >> n;
    int x_all = 0, y_max = 0, y_min = 0;
    vector <int> A(n);
    for (int i = 0, cur = 0; i < n; ++ i){
        cin >> A[i];
        x_all += A[i];
        cur += i%2 ? -A[i] : A[i];
        fmax(y_max, cur);
        fmin(y_min, cur);
    }

    vector<vector<char>> ans(y_max-y_min+1, vector<char>(x_all, ' '));

    int idx = 0, i = -1, j = 0;
    while (idx < n){
        int x = A[idx];
        if (idx%2){
            int to = i+x;
            while (i < to){
                i += 1;
                ans[j-y_min][i] = '\\';
                j -= 1;
            }
        } else {
            int to = i+x;
            while (i < to){
                i += 1, j += 1;
                assert(j >= y_min);
                ans[j-y_min][i] = '/';
            }
        }
        idx += 1;
    }

    // return;

    for (int i = ans.size()-1; i >= 1; -- i){
        for (int j = 0; j < ans[i].size(); ++ j){
            cout << ans[i][j];
        }
        cout << "\n";
    }
}
