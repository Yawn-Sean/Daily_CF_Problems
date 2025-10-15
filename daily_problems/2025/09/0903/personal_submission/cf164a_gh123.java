//https://codeforces.com/problemset/submission/164/336699080
import java.util.ArrayList;
import java.util.Scanner;

public class A164 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int m=sc.nextInt();
        int[]a=new int[n];
        ArrayList<Integer>[]g=new ArrayList[n];
        ArrayList<Integer>[]rev=new ArrayList[n];
        for (int i = 0; i < n; i++) {
            a[i]=sc.nextInt();
            g[i]=new ArrayList<>();
            rev[i]=new ArrayList<>();
        }
        for (int i = 0; i < m; i++) {
            int x=sc.nextInt()-1;
            int y=sc.nextInt()-1;
            rev[x].add(y);
            g[y].add(x);
        }
        boolean[]visr=new boolean[n];
        boolean[]visg=new boolean[n];
        for (int i = 0; i < n; i++) {
            if(!visr[i]&&a[i]==1){
                dfs(i,rev,visr,0,a);
            }
            if(!visg[i]&&a[i]==2){
                dfs(i,g,visg,1,a);
            }
        }
        StringBuilder sb=new StringBuilder();
        sc.close();
        for (int i = 0; i < n; i++) {
            if(visg[i]&&visr[i]){
                sb.append(1).append("\n");
            }else{
                sb.append(0).append("\n");
            }
        }
        System.out.println(sb);
    }
    static void dfs(int n,ArrayList<Integer>[]g,boolean[]vis,int x,int[]a){
        vis[n]=true;
        if(x==1&&a[n]==1){
            return;
        }
        for (int next : g[n]) {
            if(!vis[next]){
                dfs(next, g, vis, x, a);
            }
        }
    }
}
