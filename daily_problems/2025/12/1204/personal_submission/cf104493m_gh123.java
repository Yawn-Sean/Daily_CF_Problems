import java.util.Scanner;

public class M104493 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        final double pi=Math.PI;
        while (t-->0) {
            int r=sc.nextInt();
            int n=sc.nextInt();
            int l=sc.nextInt();
            double ans=0;
            ans+=(double)l*r*n;
            ans+=pi*r*r;
            ans+=(double)l*l/2/Math.tan(pi/n)*n/2;
            System.out.printf("%.10f%n", ans);
        }   
        sc.close();
    }
}
