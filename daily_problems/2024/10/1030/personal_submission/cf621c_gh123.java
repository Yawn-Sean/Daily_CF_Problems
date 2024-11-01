//https://codeforces.com/problemset/submission/621/288834313
import java.util.Scanner;

public class C621 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int p=sc.nextInt();
        double[]a=new double[n];
        for (int i = 0; i < n; i++) {
            int l=sc.nextInt();
            int r=sc.nextInt();
            a[i]=(double)1.0*(r/p-(l-1)/p)/(r-l+1);
        }
        double ans=0;
        for (int i = 0; i < n; i++) {
            ans+=a[i];
            ans+=a[(i+1)%n];
            ans-=a[i]*a[(i+1)%n];
        }
        System.out.println(ans*2000);
    }
}
