#include<bits/stdc++.h>
using namespace std;
//对可能的时间进行二分？\
//每个星号只会被最左边/最右边的人吃掉，且每个人最多转向一次
//预处理每个星号最左边和最右边的人，
//可以假定每个人都会优先去先吃左边的星号
const int N = 1e5 + 10;
int n;
string s;
bool check(int mid){
    int pos = -1;
    int right = -1;
    for(int i = 0; i < n; i++){
        if(s[i] == '*' && right < i && pos == -1){//仅记录没被吃掉的最左边的星号
            pos = i;
        }
        if(s[i] == 'P'){
            int left = 0;
            if(pos >= 0){
                left = i - pos; 
            }
            if(left > mid) return 0;
            else{
                int x;
                if(mid >= left * 3){
                    x = i + mid - left * 2;
                }else{
                    x = i + (mid - left) / 2;
                }
                right = max(x, right);
            }
            pos = -1;//左边已经没星号了
        }
    }
    if(pos >= 0) return 0;
    return 1;
}
int main(){
    cin >> n;
    cin >> s;
    int l = 1, r = n * 2;
    int ans;
    while(l <= r){
        int mid = l + r >> 1;
        if(check(mid)){
            r = mid - 1;
            ans = mid;
        }else{
            l = mid + 1;
        }
    }
    cout << ans << endl;

}