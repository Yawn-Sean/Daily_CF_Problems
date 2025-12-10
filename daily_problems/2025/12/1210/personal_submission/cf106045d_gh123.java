import java.util.Scanner;

public class D106056 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        double pi=Math.acos(-1.0);
        while (t-->0) {
            double r=sc.nextDouble();
            double l=sc.nextDouble();
            double theta=sc.nextDouble();
            double thetaRad=theta*pi/180.0;
            double w=2*r*Math.sin(thetaRad/2);
            double ans=Math.sqrt(l*l-w*w);
            System.out.printf("%.15f%n", ans);
        }   
        sc.close();
    }
}
