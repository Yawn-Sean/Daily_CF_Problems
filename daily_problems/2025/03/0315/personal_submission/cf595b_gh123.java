//https://codeforces.com/problemset/submission/595/310649425
import java.util.Scanner;

public class B595 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int k=sc.nextInt();
        int[]a=new int[n/k];
        long ans=1;
        for (int i = 0; i < n/k; i++) {
            a[i]=sc.nextInt();
        }
        int mod=(int)1e9+7;
        
        for (int i = 0; i < a.length; i++) {
            ans*=cal(a[i],sc.nextInt(),(int)Math.pow(10, k));
            ans%=mod;
        }
        sc.close();
        System.out.println(ans);
    }
    public static long cal(long x,long y,long k){
        long inf,sup,num;
        if(y==0){
            inf=0;
        }else{
            inf=y*k/10-1;
        }
        sup=(y+1)*k/10-1;
        num=(k-1)/x-sup/x+inf/x;
        if(y!=0){
            num++;
        }
        return num;
    }
}
