#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define endl "\n"
//和dp有关系吗，还是正常的思维题,没有明显的状态转移
//对于每个不一样的位置，我们可以往后去找到最近的相同值，然后选择删掉远的那个(如果近的也超过了最近的相同的位置，那就没有贡献)，这样的时间复杂度合理吗
//显然不合理，最坏的情况应该是n2，从什么地方可以优化呢，如果我提前预处理一遍对应的位置呢，可以避免n2吗,预处理本身就是n2了，那也不对
//采用类似折半查找的方法呢，但是要是没有相同值呢，那也不行
//题目本质是lis吧，转化过来的化，但是lis也是n2呢，可能需要数据结构优化
//对于每一个相同的值，我们可以从他的前面和后面去找最大的lis，ans=max(ans,lis.lenth)
//对于每个值的lis，我们可以去用线段树维护，这样的时间复杂度就是nk2log(nk),复习下线段树
class SegTree
{
 private:
 int n;
 int size;
 vector<int>tree;//储存线段树节点
 int op(int a,int b)
 {
   return max(a,b);
 }
 int e()
 {
    return 0;
 }
 public:
 SegTree(int len)
 {
    n=len;
    size=1;
    while(size<n)size<<=1;
    tree.resize(2*size,e());//初始化
 }
 //将位置i的值更新为当前值和val的最大值
 void set(int i,int val)
 {
    if(i<0||i>=n)return;
    i+=size;//转化为叶子节点
    if(tree[i]>=val)return;
    tree[i]=val;
    //向上更新父节点
    for(i>>=1;i>=1;i>>=1)
    {
        int new_val=op(tree[2*i],tree[i*2+1]);
        if(new_val==tree[i])break;
        tree[i]=new_val;
    }
 }
 int prod(int l,int r)//查询[l,r)
 {
    if(l>=r)return e();
    l+=size;
    r+=size;
    int res=e();
    while(l<r)
    {
        if(l%2==1)
        {
            res=op(res,tree[l]);
            l++;
        }
        if(r%2==1)
        {
            r--;
            res=op(res,tree[r]);
        }
        l>>=1;
        r>>=1;
    }
    return res;
 }
 int all_prod()
 {
    return prod(0,n);
 }
 int get(int i)
 {
    if(i<0||i>=n)return 0;
    return tree[i+size];
 }
};
void sol()
{
    int n,k;cin>>n>>k;
    vector<int>a(n*k,0),b(n*k,0);
    for(int i=0;i<n*k;++i)cin>>a[i];
    for(int i=0;i<n*k;++i)cin>>b[i];
    vector<vector<int>>pos(n+1);
    for(int i=n*k-1;i>=0;--i)
    {
        pos[b[i]].emplace_back(i);
    }
    SegTree seg(n*k);
    for(int i=0;i<n*k;++i)
    {
        int x=a[i];
        for(int j:pos[x])
        {
            int now=seg.prod(0,j)+1;
            if(now>seg.get(j))
            {
                seg.set(j,now);
            }
        }
    }
    cout<<seg.all_prod()<<endl;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int _=1;
    //cin>>_;
    while(_--)sol();
    return 0;
}
