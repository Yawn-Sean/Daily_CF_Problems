#include<bits/stdc++.h>
using namespace std;
const int N = 5e3 + 10;
typedef long long ll;
int n;
int a[N];
int num[N], cnt[N];
ll dp[N], mx[N]; //dp[i]是以i为合法区间右端点的最大值
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        num[a[i]]++;
    }
    for(int i = 1; i <= n; i++){
        int no = 0;
        int sum = 0;
        memset(cnt, 0, sizeof cnt);
        for(int j = i; j >= 1; j--){
            if(!cnt[a[j]]){
                no++;//遇到一个新的数
                sum ^= a[j];
            }
            cnt[a[j]]++;
            if(cnt[a[j]] == num[a[j]]) no--;
            if(!no){
                dp[i] = max(dp[i], mx[j-1] + sum);
            }
        }
        mx[i] = max(mx[i - 1],dp[i]);
    }
    cout << mx[n];
}
