
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;

public class A106260 {
    static final long MOD = 998244353;
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while (t-->0) {
            int n=sc.nextInt();
            List<Integer>[]path=new ArrayList[n];
            for (int i = 0; i < n; i++) {
                path[i]=new ArrayList<>();
            }
            for (int i = 0; i < n-1; i++) {
                int u=sc.nextInt()-1;
                int v=sc.nextInt()-1;
                path[u].add(v);
                path[v].add(u);
            }
            long ans=0;
            Queue<Integer>que=new ArrayDeque<>();
            int[]dep=new int[n];
            dep[0]=1;
            que.add(0);
            while (!que.isEmpty()) {
                int cur=que.poll();
                for (int next : path[cur]) {
                    if(dep[next]==0){
                        dep[next]=dep[cur]+1;
                        que.add(next);
                    }
                }
            }
            for (int i = 0; i < dep.length; i++) {
                ans=(ans+modInverse(dep[i]))%MOD;
            }
            System.out.println(ans);
        }   
        sc.close();
    }
    static long modInverse(long a){
        return modpow(a, MOD-2, MOD);
    }
    static long modpow(long a,long b,long mod){
        long res=1;
        a%=mod;
        while (b>0) {
            if((b&1)!=0){
                res=(res*a)%mod;
            }
            a=(a*a)%mod;
            b>>=1;
        }
        return res;
    }
}
