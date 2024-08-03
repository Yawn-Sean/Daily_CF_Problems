//https://codeforces.com/contest/1114/submission/258053985
#include<iostream>
#include<vector>
using namespace std;
using LL = long long;
using PLL = pair<LL, LL>;
const LL INF = 0x3f3f3f3f3f3f3f3f;
int main(){
   LL n, b;
    cin >> n >> b;
    vector<PLL> prime_factor_cnt;
    for (LL i = 2; i * i <= b; i++){
        if (b % i == 0){
            LL cnt = 0;
            while (b % i == 0){
                b /= i;
                cnt++;
            }
            prime_factor_cnt.push_back({i, cnt});
        }
    }
    if (b > 1){
        prime_factor_cnt.push_back({b, 1});
    }
    LL ret = INF;
    for (auto [prime, cnt]: prime_factor_cnt){
        LL this_n = n;
        LL this_cnt = 0;
        while (this_n > 0){
            this_cnt += this_n / prime;
            this_n /= prime;
        }
        ret = min(ret, this_cnt / cnt);
    }
    cout << ret << endl;
    return 0;
}
