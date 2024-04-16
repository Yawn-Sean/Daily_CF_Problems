//link : https://codeforces.com/contest/933/submission/256714199
void solve() {
    int n;
    cin >> n;
    vector<int> arr(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    vector<int> f(4, 0);
    for (int i = 1; i <= n; i++) {
        f[0]+= arr[i] == 1;
        f[1] =max(f[1] +(arr[i]==2), f[0]);
        f[2] =max(f[2] +(arr[i]==1), f[1]);
        f[3]=max(f[3] +(arr[i]==2), f[2]);
    }
    cout <<  f[3] << endl;
}
