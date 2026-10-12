#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
void wert()
{
    int n;
    cin>>n;
    int x=2;
    int a=1;
    for(int i=3;i<=n;i++)
    {
        cout<<"? "<<a<<" "<<x<<" "<<i<<endl;
        int xx;
        cin>>xx;
        if(xx==1)
        {
            x=i;
        }
    }
    cout<<"! "<<x<<endl;
}   
signed main()
{
    
    int t=1;
    // cin >> t;
    while(t--)
    {
        wert();
    }
    return 0;
}
