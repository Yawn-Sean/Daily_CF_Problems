#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define cute_prov0nce main
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int N = 2e3+10; 
const int mod = 1e9 + 7;
void solve()
{
   int n,m;
   cin >> n >> m;
   vector<vector<int>> val(n+1, vector<int> (m));
   vector<array<int, 3>> ops(n+1);
   map<string, int> mp;
   vector<int> f(n+1);
   mp["?"] = 0;
   for(int i  =1; i <=n; i++){
    string s;
    cin >> s;mp[s] = i;
    cin >> s >> s;
    if(s[0] == '1'||s[0] == '0'){
        for(int j = 0; j <m; j ++)val[i][j] = s[j]-'0';
    }
    else{
        f[i] = 1;
        ops[i][0] = mp[s];
        cin >> s;
        if(s[0] == 'A')ops[i][1] = 1;
        else if(s[0] == 'O')ops[i][1] = 2;
        else ops[i][2] = 3; 
        cin >> s;
        ops[i][2] = mp[s];
    }
   }
   string ans1, ans2;
   for(int j = 0; j <m;j ++){
    int c1=0,c0=0;
    vector<int> cur1(n+1),cur0(n+1);
    for(int i = 1; i <=n; i ++){  
        if(f[i]){
            auto [x,o,y] = ops[i];
            int x0 = (x ? cur0[x]:0);
            int x1 = (x?cur1[x]:1);
            int y1 = (y?cur1[y]:1);
            int y0 = (y?cur0[y]:0);
            if(o==1)cur1[i] = x1&y1,cur0[i]=x0&y0;
            else if(o==2)cur1[i] = x1|y1,cur0[i] = x0|y0;
            else cur1[i] = x1^y1, cur0[i]=x0^y0;
        }  
        else{
            cur1[i] =cur0[i] =  val[i][j];
        }
        c1+=cur1[i],c0+=cur0[i];    
    }
    if(c0 >= c1)ans1 += '0';
        else ans1 += '1';

        if(c0 <= c1){
            ans2 += '0';
        }
        else ans2 += '1';
   }
   cout << ans2 <<'\n' <<ans1 <<'\n';
}
signed cute_prov0nce()
{
     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
     int t;
    //cin >> t;
     t = 1;
     while (t--)
     {
          solve();
     }

     return 0;
}
