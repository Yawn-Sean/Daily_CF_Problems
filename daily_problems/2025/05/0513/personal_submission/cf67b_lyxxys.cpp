void solve(){
    int n, k;
    cin >> n >> k;
    vector <int> A(n), ans;
    for (auto &x : A){
        cin >> x;
    }
    

    for (int i = n-1; i >= 0; -- i){
        int need = A[i], tar = i+1 + k;
        if (need == 0){
            ans.insert(ans.begin(), i+1);
        } else {
            for (int j = 0; j < ans.size(); ++ j){
                if (ans[j] >= tar) need -= 1;

                if (need == 0){
                    ans.insert(ans.begin()+j+1, i+1);
                    break;
                }
            }
        }
    }

    print(ans);
}
