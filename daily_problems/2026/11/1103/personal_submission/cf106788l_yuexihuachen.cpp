
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
        // 状态压缩dp
        int n;
        std::cin >> n;
        std::vector<int> w(n);
        for(int i = 0; i < n; i++){
            std::cin >> w[i];
        }
        
        int W = *max_element(w.begin(), w.end()); // 最大重量
        int full = (1 << n) - 1; // 全集 

        // dp[S][d] 在已经挂好的S中所有衣服，两边重量查绝对值正好为d的情况下，整个过程中出现的最大不平衡度
        std::vector<std::vector<int>> dp(1<<n, std::vector<int>(W + 1, INF));
        dp[0][0] = 0; // 初始状态，什么都没挂，两边重量差为0，不平衡度为0

        for(int S = 0; S < (1<<n); ++S){
            for(int d = 0; d <= W; d++){
                if(dp[S][d] == INF) continue; // 如果当前状态不可达，跳过
                for(int i = 0; i < n; ++i){
                    if(S & (1 << i)) continue; // 如果衣服i已经挂了，跳过
                    int newS = S | (1 << i); // 挂上衣服i后的新状态
                    
                    int d1 = d + w[i]; // 挂在重的一边
                    if(d1 <= W) dp[newS][d1] = std::min(dp[newS][d1], std::max(dp[S][d], d1)); // 挂在重的一边
                    int d2 = abs(d - w[i]); // 挂在轻的一边
                    dp[newS][d2] = std::min(dp[newS][d2], std::max(dp[S][d], d2)); // 挂在轻的一边
                }
            }
        }

        int ans = INF;
        for(int i = 0; i <= W; i++){
            ans = std::min(ans, dp[full][i]);
        }
        std::cout << ans << '\n';
    }

    signed main() {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        int T = 1;
        // std::cin >> T;
        while (T--) {
            slove();
        }
        return 0;
    }  
