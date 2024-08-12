//https://codeforces.com/problemset/submission/1131/269820739
import java.util.ArrayList;
import java.util.Scanner;

public class F1131 {
    static int[]parent;
    static ArrayList<Integer>[]t;
    @SuppressWarnings("unchecked")
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        parent=new int[n+1];
        t=new ArrayList[n+1];
        for (int i = 1; i <=n; i++) {
            parent[i]=i;
            t[i]=new ArrayList<>();
        }
        for (int i = 0; i < n-1; i++) {
            int p=sc.nextInt();
            int q=sc.nextInt();
            union(p, q);
        }
        dfs(find(1));
        sc.close();
    }
    static void dfs(int root){
        System.out.print(root+" ");
        for (int i = 0; i < t[root].size(); i++) {
                dfs(t[root].get(i));
        }
    }
    static int find(int x){
        if(parent[x]==x){
            return x;
        }
        return parent[x]=find(parent[x]);
    }
    static void union(int a, int b){
        a=find(a);
        b=find(b);
        if(a!=b){
            t[a].add(b);
            parent[b]=a;
        }
    }
}
