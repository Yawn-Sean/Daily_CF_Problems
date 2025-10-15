#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define cute_prov0nce main
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int N = 2e6+10; 
const int mod = 1e9 + 7;
void solve()
{
   int a1, a2,a3,a4;//4 7 47 74
   cin >> a1 >> a2 >> a3 >> a4;
   if(abs(a3-a4)>1){
    cout <<-1 << '\n';
    return;
   }
   int y = min(min(a1, a2-1), min(a3, a4));
   a3-=y;
   a4-=y;
   a1-=y;
   a2-=y;
   if(a3 > 1 || a4>1){
    cout <<-1 << '\n';
    return;
   }
   if(a3 == 1 && a4==1){
    if(a1>= 2){
         string s1(a1-1,'4' ),s2, s3(a2, '7');for(int i = 1; i <=y;i ++)s2+="74";
    cout << s1 + s2 + s3 + "4"  <<'\n';
    }
    else{
        cout <<-1 << '\n';
    }
   }
   else if(a3 == 1){
    if(a1 > 0){
        string s1(a1,'4' ),s2,s3(a2,'7' );for(int i = 1; i <=y;i ++)s2+="74";
    cout << s1 + s2 + s3  <<'\n';
    }
    else{
        cout <<-1 << '\n';
    }
   }
   else if(a4 == 1){
    if(a1 > 0){
        string s1( a1-1,'4'),s2, s3(a2, '7');
    for(int i = 1; i <=y-1;i ++)s2+="74";
    cout << "74" + s1 + s2 + s3 +"4" <<'\n';
    }
    else{
        cout <<-1 << '\n';
    }
   }
   else {
    if(a1 > 0){
        y--;
        a1++;
        a2++;
        string s1(a1-1, '4'),s2, s3(a2,'7' );for(int i = 1; i <=y;i ++)s2+="74";
    cout << s1 + s2 + s3 + "4"  <<'\n';
    }
    else{
        string s1(a1,'4' ),s2, s3(a2, '7');for(int i = 1; i <=y;i ++)s2+="74";
    cout << s1 + s2 + s3 <<'\n';
    }
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
