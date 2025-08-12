#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define cute_prov0nce main
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int N = 1e6 + 10; 
int f[N];

void solve()
{
    int n;
    cin >> n;
    vector<int> nums(10);
    while(n){
        int j = n%10;
        n /= 10;
        nums[j]++;
    }
    vector<int> s(10);
    int ans = 0;
    auto count = [&]()->int{
        int L = 0, res = 1;
        for(int i = 0 ;i <=9; i++)L += s[i];
        res = f[L];
        for(int i = 0 ; i <= 9; i ++){
            res /= f[s[i]];
        }
        if(s[0]){
            int now = f[L-1]/ f[s[0]-1];
            for(int i = 1; i <= 9; i ++){
                now /= f[s[i]];
            }
            res -= now;
        }
        return res;
    };
    auto man = [&](auto &man, int k)->void{
        if(k == 10){
            ans += count();
            return;
        }
        if(nums[k]){
            for(int i = 1;i <= nums[k]; i ++){
                s[k] = i;
                man(man, k+1);
            }
        }
        else man(man,k+1);
        
    };
    man(man, 0);
    cout << ans << '\n';
    
    
}
signed cute_prov0nce()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // 取消同步流
    f[0] = 1;
    for(int i = 1; i <=20;i  ++)f[i] = f[i-1] * i;
    int t;
    //cin >> t;
     t = 1;
    while (t--)
    {
        solve();
    }

    return 0;
}
