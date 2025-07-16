#include<bits/stdc++.h>
using namespace std;
const int N =2e5 + 10;
const int mod=1e9+7;
#define int long long
void solve(){
	string s;cin>>s;
    int n=s.size();
    vector<int> l(n+10,0);
    stack<int> sk;
    for(int i=0;i<n;i++){
        if(s[i]=='('||s[i]=='['){
            sk.push(i);  // 存储索引而不是字符
            l[i]=-1;  // 左括号
        }
        else if(s[i]==')'){
            if(!sk.empty() && s[sk.top()]=='('){
                l[i]=sk.top();
                sk.pop();

            }
            else{
                while(!sk.empty()){
                    sk.pop();
                }
                l[i]=-1;
            }
        }
        else if(s[i]==']'){
            if(!sk.empty() && s[sk.top()]=='['){
                l[i]=sk.top();
                sk.pop();
            }
            else{
                while(!sk.empty()){
                    sk.pop();
                }
                l[i]=-1;
            }
        }
        

    }
    // for(int i=0;i<n;i++){
    //     cout<<l[i]<<' ';
    // }
    // dp[i] 表示以 i 结尾的最长合法括号序列的起始位置
    vector<int> dp(n+10, -1);
    
    // 计算 '[' 的前缀和
    vector<int> psum(n+1, 0);
    psum[0]=(s[0]=='[');
    for(int i = 1; i < n; i++){
        psum[i] = psum[i-1] + (s[i] == '[');
    }
    int maxi=0,mx=-1;
    for(int i = 0; i < n; i++){
        if(s[i] == '(' || s[i] == '['){
            dp[i] = -1; // 左括号无法结尾
        }
        else if(l[i] == -1){
            dp[i] = -1; // 无匹配的右括号
        }
        else{
            dp[i]=(l[i]>0?dp[l[i]-1]:0)+psum[i]-(l[i] > 0 ? psum[l[i]-1] : 0);
            if(dp[i]>maxi){
                maxi=dp[i];
                mx=i;
            }
        }
    }
    if(maxi == 0){
        cout << 0 << '\n';
        return;
    }
    int tmp=mx;
    while(1){
        if(mx==0||l[mx-1]==-1)break;
        mx=l[mx-1];
    }

    cout << maxi << endl;
    for(int i = mx; i <= tmp; i++){
        cout << s[i];
    }
    cout << endl;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--)
    {solve();}
    return 0;
}
