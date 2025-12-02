
import java.util.Scanner;

public class H105316 {
    static long mod=998244353;
    static long quickpow(long a,long b,long mod){
        long res=1,base=a%mod;
        while (b>0) {
            if((b&1)==1){
                res=(res*base)%mod;
            }
            base=(base*base)%mod;
            b>>=1;
        }
        return res%mod;
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while (t-->0) {
             long n=sc.nextLong();
        long res=(-n%mod+mod)%mod;
          //换成-n能过，n就不能过。。
        for (int i = 1; i <=n; i++) {
            long inv=quickpow(i, mod-2, mod);
            res=(res+(n+1)%mod*inv)%mod;
            res%=mod;
        }
        
        res=(res%mod+mod)%mod;
        System.out.println(res);     
        }
       sc.close();
    }
}
