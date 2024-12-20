//https://codeforces.com/problemset/submission/297/297403185
import java.util.Arrays;
import java.util.Scanner;

public class B297{
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int m=sc.nextInt();
        int k=sc.nextInt();
        int[]a=new int[n];
        int[]b=new int[m];
        for (int i = 0; i < n; i++) {
            a[i]=sc.nextInt();
        }
        for (int i = 0; i < m; i++) {
            b[i]=sc.nextInt();
        }
        Arrays.sort(a);
        Arrays.sort(b);
        sc.close();
        if(n>m){
            System.out.println("YES");
            return;
        }
       for (int i = n-1,j=m-1; i>=0&&j>=0; i--,j--) {
        if(a[i]>b[j]){
            System.out.println("YES");
            return;
        }
       }
       System.out.println("NO");
    }
}
