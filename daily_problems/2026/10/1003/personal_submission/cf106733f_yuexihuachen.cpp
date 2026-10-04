
#include<bits/stdc++.h>
using namespace std;      // acceptable in interviews, not in production

//using namespace std::numbers; //pi,e
//using namespace std::ranges;
// using namespace std;

#define ll long long
#define ull unsigned long long
#define u128 unsigned __int128
#define int long long
#define minheap priority_queue<int, vector<int>, greater<>>
#define maxheap priority_queue<int>
#define debugvec(a) cerr<<#a<<" "<<a.size()<<":\t"; for(int i=0;i<a.size();++i) cerr<<a[i]<<' '; cerr<<endl;
#define showvec(a) for(int i=0;i<a.size();++i) cout<<a[i]<<' '; cout<<endl;
#define show(a) cout<<a<<'\n';
#define debug(a) cerr <<#a<<":\t"<<a<<endl;
const int INF = 1e18 + 5;
const int MOD = 1e9 + 7; 
typedef std::pair<int, int> pii;
const int N = 110 + 5;
#define PI acos(-1)
//using i128 = __int128_t;


void slove() {
   int n, m, k;
   std::cin >> n >> m >> k;
   std::vector<int> w(n);
   for(int i = 0; i < n; ++i){
       std::cin >> w[i];
   }

   // w[i] = 8， k = 4，-> 4 3 *1 day->full_len = 2(4 ,3) ,day->no_full = 1
   std::vector<pii> days(n); 

   // val + val-1 + val-2 +...+val - x + 1
   auto getS = [&](int x){
       return (k + k - x +1)*x/2;
   };

   int total_s = getS(k);
   int total_work = 0;
   int useCups = 0;
   for(int i = 0; i < n;++i){
       int work = std::min(w[i],total_s);
       total_work += work;

       int l = 0, r = k;
       while(l < r){
           int mid = (l + r + 1) >> 1;
           if(getS(mid) <= work){
               l = mid;
           }else{
               r = mid - 1;
           }
       }

       days[i] = {l, work - getS(l)};

       useCups += l + (work-getS(l) > 0);
       useCups = std::min(useCups, m);
   }

   if(useCups < m){
        std::cout << total_work << '\n';
        return;
   }

   int ans = 0;

   auto check = [&](int x){
       int cnt = 0;
       for(auto [len, y]: days){
           if(y >= x) cnt++;
           if(k < x) continue;
           int t = k;
           cnt += std::min(k-x+1,len);
       }
       return cnt;
   };

   //每杯coffee的贡献只能在0~k之间，二分寻找第m大的coffee收益
   int l = 0, r = k;
   while(l  <  r){
       int mid = (l + r + 1) >> 1;
       if(check(mid) >= m) l = mid; //贡献值越大->r,则数量越少
       else r = mid - 1;
   }
   int lt = l;

   // 求收益大于lt的coffee收益
   int cnt_g = 0;
   for(auto [len, y]: days){
       if(y > lt){
           cnt_g ++;
           ans += y;
       }
       if(k <= lt) continue;
       int t = k - (lt+1) + 1;
       cnt_g += std::min(t, len);
       ans += std::min((k+lt+1)*t/2,getS(len));
   }
   ans += (m - cnt_g)*lt;
   std::cout << ans << '\n';

}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) {
        slove();
    }
    return 0;
}  