#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define endl "\n"
const int N=5e5+9;
//括号匹配，非常容易想到并查集
//匹配的话，我们可以考虑栈跑一遍
//如何处理字符串，如果采用平常的删除的话，会导致字符串下标乱序，我们考虑使用链表进行操作
struct node
{
    int l,r;
    char c;
}k[N];
int pre[N];
void sol()
{
   int n,m,p;cin>>n>>m>>p;
   p--;
   string s;cin>>s;
   string op;cin>>op;
   stack<int>st;
   for(int i=0;i<n;++i)
   {
    k[i].c=s[i];
    k[i].l=i-1;
    k[i].r=i+1;
   }
   k[0].l=-1;
   k[n-1].r=-1;
   for(int i=0;i<n;++i)
   {
    if(s[i]=='(')
    {
        st.push(i);
    }
    else
    {
        int x=st.top();
        st.pop();
        pre[i]=x;
        pre[x]=i;
    }
   }
   for(char &c:op)
   {
    if(c=='L')
    {
        p=k[p].l;
    }
    else if(c=='R')
    {
        p=k[p].r;
    }
    else
    {
       int l=min(p,pre[p]);
       int r=max(p,pre[p]);
       int len=r-l+1;
       int match=pre[p];
       int new_p;
       if(k[r].r!=-1)
       {
        new_p=k[r].r;
       }
       else
       {
        new_p=k[l].l;
       }
       int L=k[l].l;
       int R=k[r].r;
       if(L!=-1)
       {
         k[L].r=R;
       }
       if(R!=-1)
       {
        k[R].l=L;
       }
       p=new_p;
    }
   }
   int now=p;
   while(k[now].l!=-1)
   {
    now=k[now].l;
   }
   while(now!=-1)
   {
     cout<<k[now].c;
     now=k[now].r;
   }
   cout<<endl;
    return;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int _=1;
    //cin>>1;
    while(_--)sol();
    return 0;
}
