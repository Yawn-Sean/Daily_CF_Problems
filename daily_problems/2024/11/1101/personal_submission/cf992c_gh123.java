//https://codeforces.com/problemset/submission/992/289081387
import java.util.Scanner;
//才发现java里面的long 不能直接&1 要%2==1判断

public class C992 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        long x=sc.nextLong();
        long k=sc.nextLong();
        sc.close();
        int mod=(int)(1e9+7);
        if(x==0){
            System.out.println(0);
        }else{
            System.out.println(((x*2-1)%mod*quickpow(2,k,mod)+1)%mod);
        }
    }
   static long quickpow(long base,long power,long mod){
        if(power==0) return 1%mod;
        long cur=quickpow(base, power/2, mod);
        return power%2==1?base*cur%mod*cur%mod:cur*cur%mod;
    }
}
