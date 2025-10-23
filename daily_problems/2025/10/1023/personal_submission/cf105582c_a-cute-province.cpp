    #include <bits/stdc++.h>
    #define x first
    #define y second
    #define cute_prov0nce main
    using namespace std;
    #define int long long
    #define all(x) x.begin(),x.end()
    typedef pair<int, int> PII;
    using i64 = long long;
    const int mod =  1e9 + 7;
    const int N = 1e4 + 10;
    void solve()
    {
        int n, ma, mi;
        cin >> n >> mi >> ma;
        vector<int> m(n+1), c(n+1);
        for(int i =1 ; i<=n; i++)cin >> m[i] >> c[i];
        auto check = [&](int k)->int{
            vector<int> dp(ma+1);
            dp[0] = 1;
            for(int i = 1; i <= n; i ++){
                int count = c[i] / k;

                for(int rem = 0; rem < m[i]; rem ++){
                    int cnt = 0;
                    for (int j = ma-rem-m[i]; j >= max(ma - rem - count * m[i], 0ll); j -= m[i]) {
                        if (dp[j])cnt++;
                    }
                    for(int j = ma-rem; j >= 0; j -= m[i]){
                        if (cnt) dp[j] = 1;
                        if(j - m[i] >= 0 && dp[j - m[i]])cnt--;    
                        if(j - (count+1) * m[i] >= 0 && dp[j - (count+1) * m[i]])cnt++;

                    }
                }
            }
            int ans = 0;
            for(int i = mi; i <= ma; i ++)ans |= dp[i];
            return ans;
        };
        int l = 0, r = 1e6;
        while(l < r){
            int mid = (l + r )/2 + 1;
            if(!check(mid))r = mid-1;
            else l = mid;
        }
        cout << l << '\n';
    }

    signed cute_prov0nce()
    {
    #ifdef ACM_LOCAL
        freopen("data.in", "r", stdin);
        freopen("data.out", "w", stdout);
    #endif
        ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int t;
        t = 1;

        //cin >> t;
        while (t--)
        {
            solve();
        }
        return 0;
    }
