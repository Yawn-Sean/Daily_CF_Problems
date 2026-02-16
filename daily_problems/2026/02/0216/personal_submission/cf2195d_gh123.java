import java.util.Scanner;
//又一年
public class CF2195d {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while (t-->0) {
            int n=sc.nextInt();
            long[]a=new long[n];
            for (int i = 0; i < n; i++) {
                a[i]=sc.nextLong();
            }
            long sum=(a[0]+a[n-1])/(n-1);
            long cur=0;
            for (int i = 0; i < n-1; i++) {
                long val=-(a[i]-a[i+1]-sum)/2-cur;
                cur+=val;
                System.out.print(val+" ");
            }
            System.out.println(sum-cur);
        }   
        sc.close();
    }    
}
