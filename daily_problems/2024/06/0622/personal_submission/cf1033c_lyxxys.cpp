vector <int> nums, to, f;
int n;

void solve(){
    cin >> n;
    f.resize(n+1), nums.resize(n+1), to.resize(n+1);
    for (int i = 1; i <= n; ++ i) cin >> nums[i], to[nums[i]] = i;
    // to[i]表示第 i 在nums中的下标
    // f[i] 表示在nums中下标为i的sg值

    for (int i = n; i >= 1; -- i){
        // 枚举数字i的下标， (j-to[i])%i==0的位置
        int p = to[i];
        if (to[i] > i) p = to[i]%i;
        for (int j = p; j <= n; j += i){
            if (i >= nums[j]) continue;
            if (f[j]==0){
                f[to[i]] = 1;
                break;
            }
        }
    }

    for (int i = 1; i <= n; ++ i){
        if (f[i]) cout << "A";
        else cout << "B";
    }
    cout << "\n";
}
