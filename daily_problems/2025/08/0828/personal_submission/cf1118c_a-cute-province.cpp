#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define cute_prov0nce main
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int N = 2e5+10; 
const int mod = 1e9 + 7;


void solve()
{
   int n;
   cin >> n;
   vector<vector<int>> a(n+1,vector<int> (n+1));
    vector<int> nums(1005);
    for(int i = 1; i<=n*n; i++){
        int x;
        cin >> x;
        nums[x] ++;
    }
    vector<int> v4,v2,v1;
    for(int i = 1; i < 1005; i ++){
        while(nums[i] >= 4){
            nums[i]-=4;
            v4.emplace_back(i);
        }        
        while(nums[i] >= 2){
            nums[i]-=2;
            v2.emplace_back(i);
        }
        while(nums[i] >= 1){
            nums[i]-=1;
            v1.emplace_back(i);
        }
    }
    int c4 = (n/2)*(n/2);
    int c2=0,c1=0;
    if(n&1){
        c2 = n/2*2;
        c1 = 1;
    }
    if(c1 == v1.size() && v4.size() >= c4){
        cout << "YES" << '\n';
        if(c4){
            for(int i = 1; i <=n/2; i ++){
                for(int j = 1; j <= n/2; j ++){
                    int p = v4.back();v4.pop_back();
                    a[i][j] = a[n+1-i][j] = a[n+1-i][n+1-j] = a[i][n+1-j] = p;
                }
            }
        }
        
        while(v4.size()){
            v2.emplace_back(v4.back());
            v2.emplace_back(v4.back());
            v4.pop_back();
        }
        if(c2){
            for(int i = 1; i <=n/2; i ++){
                int p = v2.back();v2.pop_back();
                a[i][n/2+1] = a[n+1-i][n/2+1] = p;
            }
            for(int j = 1; j <=n/2; j ++){
                int p = v2.back();v2.pop_back();
                a[n/2+1][j] = a[n/2+1][n+1-j] = p;
            }
        }
        
        if(c1)a[n/2+1][n/2+1] = v1[0];
        for(int i = 1; i <=n; i ++){
            for(int j = 1; j <=n; j++)cout << a[i][j] << ' ';
            cout << '\n';
        }
    }
    else{
        cout << "NO" <<'\n';
    }
}
signed cute_prov0nce()
{
     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
     // 取消同步流
     int t;
     //cin >> t;
     t = 1;
     while (t--)
     {
          solve();
     }

     return 0;
}
