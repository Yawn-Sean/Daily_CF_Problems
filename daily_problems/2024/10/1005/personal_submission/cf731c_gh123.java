//https://codeforces.com/problemset/submission/731/284386652
//这里面第一次用map套map，但是没想到其他好的数据结构来表示，还好一次就ac了，居然没wa。。。
import java.util.HashMap;
import java.util.Scanner;

public class C731 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int m=sc.nextInt();
        int k=sc.nextInt();
        int[]wazi=new int[n];
        for (int i = 0; i < n; i++) {
            wazi[i]=sc.nextInt();
        }
        int[]p=new int[n];
        for (int i = 0; i < p.length; i++) {
            p[i]=i;
        }
        while (m-->0) {
            int u=sc.nextInt()-1;
            int v=sc.nextInt()-1;
            union(u,v,p);
        }
        HashMap<Integer,HashMap<Integer,Integer>>map=new HashMap<>();
        for (int i = 0; i < n; i++) {
            int tem=find(i, p);
            int col=wazi[i];
            if(map.containsKey(tem)){
                map.get(tem).put(col, map.get(tem).getOrDefault(col, 0)+1);
            }else{
                HashMap<Integer,Integer>linshi=new HashMap<>();
                linshi.put(col, 1);
                map.put(tem, linshi);
            }
        }
        sc.close();
        int ans=n;
        for (int tem : map.keySet()) {
            int max=0;
                for (int col_v : map.get(tem).values()) {
                    max=Math.max(col_v,max);
                }
                // System.out.println(max+" max");
                ans-=max;
        }
        
        System.out.println(ans);

    }
   static void union(int u,int v,int[]p){
        int pu=find(u,p);
        int pv=find(v,p);
        p[pu]=p[pv];
    }
   static int find(int x,int[]p){
        if(x==p[x]){
            return x;
        }
        return p[x]=find(p[x],p);
    }
}
