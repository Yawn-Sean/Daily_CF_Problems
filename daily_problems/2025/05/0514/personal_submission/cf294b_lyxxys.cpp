void solve(){
    const int N = 200;
    int n;
    cin >> n;
    vector<vector<int>> f1(N+1,vector<int>(N+1)), f2(N+1,vector<int>(N+1));

    f1[0][0] = 1;
    for (int i = 0,x,y; i < n; ++ i){
        cin >> x >> y;
        for (int i = 0; i <= N; ++ i){
            for (int j = 0; j <= N; ++ j){
                if (f1[i][j]){
                    f2[i+x][j] = 1;
                    if (j+y <= N){
                        f2[i][j+y] = 1;
                    }
                }
            }
        }
        for (int i = 0; i <= N; ++ i){
            for (int j = 0; j <= N; ++ j){
                f1[i][j] = f2[i][j];
                f2[i][j] = 0;
            }
        }
    }

    for (int i = 1; i <= N; ++ i){
        for (int j = 0; j <= i; ++ j){
            if (f1[i][j]){
                cout << i << "\n";
                return;
            }
        }
    }

}
