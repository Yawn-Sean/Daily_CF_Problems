
#include<bits/stdc++.h>
using namespace std;      // acceptable in interviews, not in production

//using namespace std::numbers; //pi,e
//using namespace std::ranges;
using namespace std;
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
typedef pair<int, int> pii;
const int N = 110 + 5;
#define PI acos(-1)



void slove() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int re = n*(n+1)/2 - n - 1;
    int sum = 0;
    for(int i = 0; i< n; i++){
        re = max(re,sum - a[i]);
        sum += a[i];
    }

    sum = 0;
    for(int i = n-1; i >= 0; i--){
        re = max(re,sum  - a[i]);
        sum += a[i];
    }
    cout << re << endl;
    

}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) {
        slove();
    }
    return 0;
}