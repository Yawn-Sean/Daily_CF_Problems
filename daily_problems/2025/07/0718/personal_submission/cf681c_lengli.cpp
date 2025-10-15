#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
struct node
{
    int x;
    char a[20];
}s[1000000];
int main ()
{
    int n,i=0,t;
    char a[20];
    scanf("%d",&n);
    priority_queue<int,vector<int>,greater<int> >q;
    while(n--)
    {

    cin>>a;
    if(a[0]=='i')
    {
        scanf("%d",&t);
        s[i].x=t;
        q.push(t);
        strcpy(s[i++].a,a);
    }
    else if(a[0]=='r')
    {
        if(q.size()==0)
        {
            s[i].x=1;
            q.push(1);
            strcpy(s[i++].a,"insert");
        }
        q.pop();
        strcpy(s[i++].a,a);
    }
    else
    {
        scanf("%d",&t);
    if(q.size()!=0&&t==q.top())
            {
                s[i].x=t;
                strcpy(s[i++].a,a);
            }
            else if(q.size()!=0&&q.top()>t)
            {
                s[i].x=t;
                strcpy(s[i++].a,"insert");
                q.push(t);
                s[i].x=t;
                strcpy(s[i++].a,"getMin");
            }
            else
            {
                while(q.size()!=0&&q.top()<t)
                {
                    q.pop();
                    strcpy(s[i++].a,"removeMin");
                }
                if(q.size()!=0&&q.top()>t||q.size()==0)
                {
                    q.push(t);
                    s[i].x =t;
                    strcpy(s[i++].a,"insert");
                }
                s[i].x =t;
                strcpy(s[i++].a,"getMin");
            }
    }
    }
      printf("%d\n",i);
      for(int j=0;j<i;j++)
      {
        if(s[j].a[0]=='r')
        printf("removeMin\n");
        else
        {
            if(s[j].a[0]=='i')
            {
                printf("insert %d\n", s[j].x);
              }
              else
              {
                printf("getMin %d\n", s[j].x);
              }
          }
      }
      return 0;
 } 
