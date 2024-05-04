https://codeforces.com/problemset/submission/1175/259442943

import java.util.Scanner;

public class C1175 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while (t-->0) {
            int n=sc.nextInt();
            int k=sc.nextInt();
            int[]a=new int[n];
            for (int i = 0; i < n; i++) {
                a[i]=sc.nextInt();
            }
            int dif=Integer.MAX_VALUE;
            int mid=a[0];
            for (int i = k; i < n; i++) {
                if(dif>a[i]-a[i-k]){
                    dif=a[i]-a[i-k];
                    mid=a[i-k]+(a[i]-a[i-k])/2;
                }
            }
            System.out.println(mid);
        }
        sc.close();
    }
}
