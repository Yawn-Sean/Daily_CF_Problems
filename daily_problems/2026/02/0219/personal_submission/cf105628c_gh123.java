import java.util.Scanner;

public class cf105628c {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        long l=sc.nextLong(),r=sc.nextLong(),k=sc.nextLong(); 
        long[]a=new long[n];
        long min=Long.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            a[i]=sc.nextLong();
            if(min>a[i]){
                min=a[i];
            }
        }  
        if(min<k||r<k){
            System.out.println(-1);
        }else{
            long ans=1;
            long bound=(long)1e12;
            for (long x : a) {
                long g=gcd(x,ans);
                long mult=ans/g;
                if(x>bound/mult){
                    ans=bound;
                }else{
                    ans=mult*x;
                }
                if(ans>=bound){
                    ans=bound;
                    break;
                }
            }
            long val=((r-k)/ans)*ans+k;
            if(val>=l&&val<=r){
                System.out.println(val);
            }else{
                System.out.println(-1);
            }
        }
        sc.close();
    }
    static long gcd(long a,long b){
        return b==0?a:gcd(b, a%b);
    }
}
