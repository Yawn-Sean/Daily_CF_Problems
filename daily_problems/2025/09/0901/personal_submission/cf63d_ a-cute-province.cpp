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
   int a,b,c,d,n;
   cin >> a >> b >> c >> d >>n;
   vector<int> x(n+1);
   for(int i = 1; i <=n; i++)cin >> x[i];
   vector<vector<int>> v(max(b,d)+1, vector<int>(a+c+1));
   if(b >= d){
    int cnt = 0, id = 1;
        if(d&1){
            for(int i = 1; i <=d; i ++){
                for(int j = a+c; j >=1; j --){
                    v[i][j] = id, cnt++;
                    if(x[id] == cnt){
                        id++;
                        cnt = 0;
                    }
                }
                i++;
                if(i <= d){
                    for(int j = 1; j <= a+c; j ++){
                        v[i][j] = id, cnt++;
                        if(x[id] == cnt){
                            id++;
                            cnt = 0;
                        }
                    }
                }
            }
        }
        else{
            for(int i = 1; i <=d; i ++){
                for(int j = 1; j <= a+c; j ++){
                    v[i][j] = id, cnt++;
                    if(x[id] == cnt){
                        id++;
                        cnt = 0;
                    }
                }
                i++;
                if(i <= d){
                    for(int j = a+c; j >=1; j --){
                        v[i][j] = id, cnt++;
                        if(x[id] == cnt){
                            id++;
                            cnt = 0;
                        }
                    }
                }
            }
        }
        for(int i = d+1; i <=b; i ++){
                for(int j = 1; j <= a; j ++){
                    v[i][j] = id, cnt++;
                    if(x[id] == cnt){
                        id++;
                        cnt = 0;
                    }
                }
                i++;
                if(i <= b){
                    for(int j = a; j >=1; j --){
                        v[i][j] = id, cnt++;
                        if(x[id] == cnt){
                            id++;
                            cnt = 0;
                        }
                    }
                }
            }
    }
    else{
        int cnt = 0, id = 1;
        if(b&1){
            for(int i = 1; i <=b; i ++){
                for(int j = 1; j <= a+c; j ++){
                    v[i][j] = id, cnt++;
                    if(x[id] == cnt){
                        id++;
                        cnt = 0;
                    }
                }
                i++;
                if(i <= b){
                    for(int j = a+c; j >= 1; j --){
                        v[i][j] = id, cnt++;
                        if(x[id] == cnt){
                            id++;
                            cnt = 0;
                        }
                    }
                }
            }
        }
        else{
            for(int i = 1; i <=b; i ++){
                for(int j = a+c; j >= 1; j --){
                    v[i][j] = id, cnt++;
                    if(x[id] == cnt){
                        id++;
                        cnt = 0;
                    }
                }
                i++;
                if(i <= b){
                    for(int j = 1; j <= a+c; j ++){
                        v[i][j] = id, cnt++;
                        if(x[id] == cnt){
                            id++;
                            cnt = 0;
                        }
                    }
                }
            }
            
        }
        for(int i = b+1; i <=d; i ++){
                for(int j = a+c; j >= a+1; j --){
                    v[i][j] = id, cnt++;
                    if(x[id] == cnt){
                        id++;
                        cnt = 0;
                    }
                }
                i++;
                if(i <= d){
                    for(int j = a+1; j <= a+c; j ++){
                        v[i][j] = id, cnt++;
                        if(x[id] == cnt){
                            id++;
                            cnt = 0;
                        }
                    }
                }
            }
    }
    cout << "YES" << '\n';
    for(int i = 1; i <=max(b,d); i ++){
        for(int j = 1; j <= a+c;j ++){
            if(!v[i][j])cout <<'.';
            else cout << (char)(v[i][j]-1+'a');
        }
        cout << '\n';
    }
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
