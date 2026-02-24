import java.util.Scanner;

public class cf104523a {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while (t-->0) {
            long n=sc.nextLong();
            long l=1,r=n,ans=-1;
            while (l<=r) {
                long mid=(r-l)/2+l;
                if(check(mid)<=n){
                    ans=mid;
                    l=mid+1;
                }else{
                    r=mid-1;
                }
            }
            System.out.println(n-ans);
        }   
        sc.close();
    }
    static long check(long x){
        long ans=0;
        while (x>0) {
            ans+=x;
            x/=10;
        }
        return ans;
    }
}
