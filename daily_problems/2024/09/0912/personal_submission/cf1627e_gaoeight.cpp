
int main(void)
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(m, vector<int>(n));
    vector<int> ans(n), sum(n, 0);
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
            sum[j] += a[i][j];
        }
    }
    for(int i = 0; i < n; i++)ans[i] = i;
    auto check = [&](int x){
        vector<int> ind(m);
        for(int i = 0; i < m; i++)ind[i] = i;
        sort(ind.begin(), ind.end(), [&](int i, int j){
            return (a[i][x] - a[i][n - 1] < a[j][x] - a[j][n - 1]);
        });
        int sumx = sum[x], sumn = sum[n - 1];

        vector<int> temp;
        for(auto i : ind){
            if(sumx >= sumn)break;
            sumx -= a[i][x];
            sumn -= a[i][n - 1];
            temp.push_back(i);
        }
       // cout << x << ' ' << temp.size() << "\n";
        if(ans.size() >= temp.size()){
            ans = temp;
        }
    };

    for(int i = 0; i < n - 1; i++){
        check(i);
    }
    cout << ans.size() << "\n";
    for(auto it : ans){
        cout << it + 1 << ' ';
    }
}
