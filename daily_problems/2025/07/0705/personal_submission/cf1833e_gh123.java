//https://codeforces.com/problemset/submission/1833/327520370
import java.util.Arrays;
import java.util.Scanner;

public class E1833 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while (t-->0) {
            int n=sc.nextInt();
            int[]a=new int[n];
            int[]p=new int[n];
            for (int i = 0; i < n; i++) {
                p[i]=i;
            }
            int[]rank=new int[n];
            Arrays.fill(rank, 1);
            for (int i = 0; i < n; i++) {
                a[i]=sc.nextInt()-1;
            }
             int cycle=0;
            for (int i = 0; i < n; i++) {
                int u=i;
                int v=a[i];
                if(v==-1)continue;
                if(a[v]==u)a[v]=-1;
                int pu=find(u,p);
                int pv=find(v,p);
                if(pu!=pv){
                    if(rank[pu]>rank[pv]){
                        p[pv]=pu;
                    }else if(rank[pv]>rank[pu]){
                        p[pu]=pv;
                    }else{
                        rank[pu]+=rank[pv];
                        p[pv]=pu;
                    }
                }else{
                    cycle++;
                }
            }
            int c=0;
            for (int i = 0; i < n; i++) {
                if(p[i]==i)c++;
            }
            if(cycle==c){
                System.out.println(c+" "+c);
            }else{
                System.out.println(cycle+1+" "+c);
            }

        }  
        sc.close();
       
    }
    static int find(int x,int[]p){
        if(p[x]==x){
            return x;
        }
        return p[x]=find(p[x], p);
    }
}
