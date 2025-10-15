void solve(){
    int n, k;
    cin >> n >> k;
    vector <int> A(n);
    for (auto &x : A){
        cin >> x;
    }

    int ma = 0, l = 0, r = -1;
    for (int i = 0, j=-1,cur=0; i < n; ++ i){
        while (i > j || j+1 < n && cur+(!A[j+1]) <= k){
            j += 1;
            cur += !A[j];
        }
        if (cur <= k && j-i+1 > ma){
            ma = j-i+1;
            l = i, r = j;
        }
        cur -= !A[i];
    }

    for (int i = l; i <= r; ++ i){
        A[i] = 1;
    }
    cout << ma << "\n";
    print(A);
}
