#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
//一开始会错题意的，cao
//只维护每次都大于目标颜色的颜色
int n, m, a[N], nums[N];
int cnt, k ,mx;
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        mx = max(a[i], mx);
        if(a[i] == m) cnt++;
        else if(nums[a[i]] >= cnt) nums[a[i]]++;//不行的已经被筛掉了
    }
    for(int i = 1; i <= mx; i++){
        if(nums[i] >= cnt && i != m){
            cout << i;
            return 0;
        }
    }
    cout << -1;
    return 0;
}
