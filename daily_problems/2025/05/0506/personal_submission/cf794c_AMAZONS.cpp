#include<bits/stdc++.h>
using namespace std;
const int N =2e5 + 10;
const int mod=1e9+7;
typedef long long ll;
bool cmp(char a,char b)
{return a>b;}
void solve(){
	string s1,s2;
    cin>>s1>>s2;s1=" "+s1;
    s2=" "+s2;
    int l=s1.size()-1;
    sort(s1.begin()+1,s1.end());
    sort(s2.begin()+1,s2.end(),cmp);
    
    string s=s1;int l1=1,l2=1;
    int nl=l/2,l3=1,r=l,cnt1=(l+1)/2,cnt2=l/2,pos=1,p2=0;
    s1=s1.substr(0,cnt1+1);
    s2=s2.substr(0,cnt2+1);
    // cout<<s1<<" "<<s2<<endl;
    l1=cnt1,l2=cnt2;int n1=1,n2=1;
    for(int i=1;i<=l;i++)
    {
        if(i%2){
            if(s2[n2]>s1[n1]){
                s[pos++]=s1[n1++];
            }
            else{
                s[r--]=s1[l1--];
            }
        }
        else{
            if(s2[n2]>s1[n1]){
                s[pos++]=s2[n2++];
            }
            else{
                // cout<<s2[l2];
                s[r--]=s2[l2--];
                // cout<<r+1<<endl;
            }
        }
        // cout<<r<<" ";
    }
    s=s.substr(1,l);
    // for(int i=1;i<=s.size();i++)
    cout<<s;
}
int main(){
    int t=1;
    // cin>>t;
    while(t--)
    {solve();}
    return 0;
}
