//https://codeforces.com/problemset/submission/979/290796424
import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;
public class C979 {
    static int ans;
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int x=sc.nextInt();
        int y=sc.nextInt();
        List<Integer>[]adj=new ArrayList[n+1];
        for (int i = 0; i < adj.length; i++) {
            adj[i]=new ArrayList<>();
        }
        for (int i = 0; i < n-1; i++) {
            int a=sc.nextInt();
            int b=sc.nextInt();
            adj[a].add(b);
            adj[b].add(a);
        }
        dfs(adj,x,-1,y);
        int res=ans;
        ans=0;
        dfs(adj,y,-1,x);
        long xx=(long)n*(n-1)-(long)res*ans;
        System.out.println(xx);
        sc.close();
    }
    static int dfs(List<Integer>[]adj,int cur,int parent,int find){
        int sum=0;
        for (int i = 0; i < adj[cur].size(); i++) {
            if(adj[cur].get(i)!=parent){
                sum+=dfs(adj, adj[cur].get(i), cur, find);
            }
        }
            sum++;
            if(cur==find){
                ans=sum;
            }
        
        return sum;
    }
}
