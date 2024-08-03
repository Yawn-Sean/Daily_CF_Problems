https://codeforces.com/problemset/submission/765/257931672
import java.util.Scanner;
import java.util.TreeSet;

public class D765 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[]f=new int[n];
        TreeSet<Integer>set=new TreeSet<>();
        for (int i = 0; i < n; i++) {
            f[i]=sc.nextInt();
            set.add(f[i]);
        }
        sc.close();
        int[]idx=new int[(int)1e5+2];
        int m=set.size();
        int[]h=new int[m];
        for (int i = 0; i < h.length; i++) {
            h[i]=set.first();
            idx[h[i]]=i+1;
            set.remove(set.first());
        }
        int[]g=new int[n];
        for (int i = 0; i < n; i++) {
            g[i]=idx[f[i]];
        }
        for (int i = 0; i < n; i++) {
            if(h[g[i]-1]!=f[i]){
                System.out.println(-1);
                return;
            }
        }
        for (int i = 0; i < m; i++) {
            if(g[h[i]-1]!=(i+1)){
                System.out.println(-1);
                return;
            }
        }
        System.out.println(m);
        for (int i = 0; i < n; i++) {
            System.out.print(g[i]+" ");
        }
        System.out.println();
        for (int i = 0; i < m; i++) {
            System.out.print(h[i]+" ");
        }
        System.out.println();

    }
}
