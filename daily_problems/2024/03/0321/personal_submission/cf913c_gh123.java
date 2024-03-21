import java.util.Scanner;

public class C913 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt(),l=sc.nextInt();
        long[]a=new long[n];
        a[0]=sc.nextInt();
        for (int i = 1; i < n; i++) {
            long x=sc.nextLong();
            a[i]=Math.min(a[i-1]*2,x);
        }
        long x=(long)Math.pow(2, n-1);
        long[]ans=new long[n];
        for (int i = n-1; i >=0; i--) {
            ans[i]=l/x*a[i];
            l%=x;
            x/=2;
        }
        // for (int i = 0; i < ans.length; i++) {
        //     System.out.println(i+" "+ans[i]);
        // }
        for (int i = 1; i <n; i++) {
            ans[i]=Math.min(ans[i]+a[i], ans[i]+ans[i-1]);
            // ans[i]=ans[i]+ans[i-1];
        }
        System.out.println(ans[n-1]);
        sc.close();
    }
}
