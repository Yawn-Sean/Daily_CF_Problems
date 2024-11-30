//https://codeforces.com/problemset/submission/319/293950342
import java.util.Scanner;

public class A319 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        String s=sc.next();
        sc.close();
        int n=s.length();
        int ans=0,cur=1,mod=(int)1e9+7;
        for (int i = n-1; i >=0; i--) {
            ans+=ans;
            if(ans>=mod){
                ans-=mod;
            }
            if(s.charAt(i)=='1'){
                ans+=1L*cur*cur%mod;
                if(ans>=mod){
                    ans-=mod;
                }
            }
            cur+=cur;
            if(cur>=mod)cur-=mod;
        }
        System.out.println(ans);
    }
}
