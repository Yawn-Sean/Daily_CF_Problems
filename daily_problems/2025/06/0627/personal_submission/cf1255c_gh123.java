//https://codeforces.com/problemset/submission/1255/326214281
import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;
public class C1255 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
            int n=sc.nextInt();
        List<Integer>[]g=new List[n+1];
        for (int i = 1; i <=n; i++) {
            g[i]=new ArrayList<>();
        }   
        int[]cnt=new int[n+1];
        boolean[]vis=new boolean[n+1];
        for (int i = 1; i <=n-2; i++) {
            int a=sc.nextInt();
            int b=sc.nextInt();
            int c=sc.nextInt();
            g[a].add(b);
            g[a].add(c);
            g[b].add(a);
            g[b].add(c);
            g[c].add(b);
            g[c].add(a);
            cnt[a]++;
            cnt[b]++;
            cnt[c]++;
        }
        sc.close();
        int first=0;
        for (int i = 1; i <=n; i++) {
            if(cnt[i]==1){
                first=i;
                break;
            }
        }
        int second=0;
        if(cnt[g[first].get(0)]==2){
            second=g[first].get(0)  ;
        }else{
            second=g[first].get(1);
        }
        vis[first]=true;
        vis[second]=true;
        System.out.print(first+" "+second);
        for (int i = 1; i <=n-2; i++) {
            int next=0;
            for (int j = 0; j < g[first].size(); j++) {
                if(vis[g[first].get(j)]==false){
                    next=g[first].get(j);
                }
            }
            System.out.print(" "+next);
            vis[next]=true;
            first=second;
            second=next;
        }
 
    }    
