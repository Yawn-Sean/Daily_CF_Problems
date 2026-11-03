
#include<bits/stdc++.h>
//using namespace std;      // acceptable in interviews, not in production

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
    int n,m;
    std::cin >> n >> m;

    int sum = (1+m)*m/2;
    int maxcnt = (n+sum-1)/sum;// +1,but == not + 1
    std::vector<int>cnt(m+1,maxcnt);
    int over = maxcnt*sum - n;

    for(int i = m; i >= 1; i--){
        if(over >= i){
            over -= i;
            cnt[i]--;
        }
    }
    for(int i = 1; i <= m; i++){
        std::cout << cnt[i] << ' ';
    }
    std::cout << '\n';
    
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
