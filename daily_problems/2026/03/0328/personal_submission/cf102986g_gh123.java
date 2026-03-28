import java.util.Arrays;
import java.util.Scanner;

public class cf102986g {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        double w=sc.nextDouble();
        long[]a=new long[n];
        for (int i = 0; i < n; i++) {
            a[i]=sc.nextLong();
        }   
        Arrays.sort(a);
        double ans=0;
        for (int i = 0; i < n; i++) {
            ans+=(double)(2l*i-(n-1))*a[i];
        }
        double res=(ans*2.0/n)+w;
        System.out.printf("%.10f\n",res);
        sc.close();
    }
}
