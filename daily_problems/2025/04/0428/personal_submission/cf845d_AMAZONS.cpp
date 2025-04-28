#include<bits/stdc++.h>
using namespace std;
const int N =2e5 + 10;
const int mod=1e9+7;
typedef long long ll;
// 1波利卡普将他的车速调整到指定速度（此事件带有一个正整数）；
// 2波利卡普的车超越了其他车辆；
// 3波利卡普的车经过 “限速” 标志（此标志带有一个正整数）；
// 4波利卡普的车经过 “允许超车” 标志；
// 5波利卡普的车经过 “无速度限制” 标志；
// 6波利卡普的车经过 “禁止超车” 标志 。
void clear(stack<int>& sk)
{
    stack<int> empty;
    swap(sk,empty);
}
void solve(){
	int t;cin>>t;int ans=0;
    stack<int> sk;
    int cur=0,fb=INT_MAX,pss=1,nop=0;
    for(int i=1;i<=t;i++)
    {
        int x;cin>>x;
        if(x==1){
            cin>>cur;
            // cur=x;
            while(!sk.empty())
            {
                int a=sk.top();
                if(a<cur){
                    sk.pop();
                    ans++;
                }
                else break;
            }
        }
        if(x==2){
            ans+=nop,nop=0;
        }
        if(x==3){
            cin>>fb;
            if(cur>fb){ans++;continue;}
            else sk.push(fb);
            
        }
        if(x==4){
            nop=0;
            pss=1;
        }
        if(x==5){
            clear(sk);
            fb=INT_MAX;
        }
        if(x==6){
            pss=0;
            nop++;
        }
        // cout<<pss<<endl;
    }
    cout<<ans<<endl;

}
int main(){
    int t=1;
    // cin>>t;
    while(t--)
    {solve();}
    return 0;
}
