import java.util.Scanner;

public class F104287 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        int m=(int)1e5;
        long mod=(long)1e9+7;
        long[]pow2=new long[m+1];
        pow2[0]=1;
        for (int i = 0; i < m; i++) {
            pow2[i+1]=(pow2[i]*2)%mod;
        }
        long rev2=(mod+1)/2;
        while (t-->0) {
            int d=sc.nextInt();
            long ans=0;
            long edges=1;
            long total=(pow2[d]-1+mod)%mod;
            long cur=total;
            for (int i = 0; i < d-1; i++) {
                cur=((cur-1+mod)%mod*rev2)%mod;
                edges=(edges*2)%mod;
                long term=(cur*((total-cur+mod)%mod))%mod;
                term=(term*edges)%mod;
                ans=(ans+term)%mod;
            }
            System.out.println((ans*2)%mod);
        }
        sc.close();
    }    
}
