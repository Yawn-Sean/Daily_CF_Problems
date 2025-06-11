#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, k; cin >> n >> k;
    auto get = [](int x) ->int
    {
        int ans = 0;
        while(x)
        {
            ans++;
            x /= 10;
        }
        return ans;
    };

    vector<unordered_map<int, int> > cnt(11);
    for(int i = 1; i <= n; i++)
    {
        int t; cin >> t;
        cnt[get(t)][t % k]++;
    }

    long long ans = 0;

    for(int i = 1; i <= 10; i++)            //固定高位数字
    {
        for(const auto& [a, b] : cnt[i])
        {
            if((a * (long long)pow(10LL, i) % k + a) % k == 0) ans -= b;   //排除 i = j 的情况
            long long all = 0;
            for(int j = 1; j <= 10; j++)    //枚举低位数字
            {
                long long m = (long long)pow(10LL, j) % k;
                m = (k - (a * m) % k) % k;
                if(cnt[j].count(m))
                    all += cnt[j][m];
            }

            ans += b * all;
        }
    }

    cout << ans;
}
