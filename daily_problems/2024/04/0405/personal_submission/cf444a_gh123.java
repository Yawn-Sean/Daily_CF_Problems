import java.util.Scanner;
//https://codeforces.com/problemset/submission/444/255040948

public class A444 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int q=sc.nextInt();
        int[]a=new int[n];
        for (int i = 0; i < n; i++) {
            a[i]=sc.nextInt();
        }
        double mx=0;
        for (int i = 0; i < q; i++) {
            int tem1=sc.nextInt()-1;
            int tem2=sc.nextInt()-1;
            double div=sc.nextInt();
            mx=Math.max(mx, ((a[tem1]+a[tem2]))/div);
        }
        System.out.println(mx);
        sc.close();
    }
}
