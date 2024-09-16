//https://codeforces.com/problemset/submission/682/281063305
//dfs
import java.util.ArrayList;
import java.util.Scanner;


public class C682 {
    static ArrayList<Integer>[]next;
    static ArrayList<Integer>[]cost;
    static int[]val;
    static int ans;
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        next=new ArrayList[n+1];
        cost=new ArrayList[n+1];
        val=new int[n+1];
        for (int i = 1; i <=n; i++) {
            val[i]=sc.nextInt();
            next[i]=new ArrayList<>();
            cost[i]=new ArrayList<>();
        }
        for (int i = 2; i <=n; i++) {
            int v=sc.nextInt();
            int w=sc.nextInt();
            next[v].add(i);
            cost[v].add(w);
        }
        dfs(1,0);
        sc.close();
        System.out.println(n-ans);;
    }
    static void dfs(int root,long dis){
        ans++;
        for (int i = 0; i < next[root].size(); i++) {
            int v=next[root].get(i),w=cost[root].get(i);
            long save=dis;
            dis+=w;
            if(dis<0) dis=0;
            if(dis<=val[v]){
                dfs(v, dis);
            }
            dis=save;
        }
    }
}
