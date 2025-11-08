import java.util.Scanner;

public class C106174 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        long n=sc.nextLong();
        long k=sc.nextLong();
        long l=1,r=(long)1e17;
        sc.close();
        while (l<=r) {
            long mid=l+(r-l)/2;
            if(check(mid+n-1)-check(mid-1)<k){
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        if(check(l+n-1)-check(l-1)==k){
            System.out.println(l);
        }else{
            System.out.println(-1);
        }
    }
    static long check(long x){
        long start=1;
        int d=1;
        long ans=0;
        for (int i = 0; i < 18; i++) {
            if(start>x){
                break;
            }
            ans+=Math.min(start*9,x-start+1)*d;
            start*=10;
            d++;
        }
        return ans;
    }
}
