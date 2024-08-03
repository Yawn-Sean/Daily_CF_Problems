https://codeforces.com/problemset/submission/1029/258181148
import java.util.Arrays;
import java.util.Scanner;

public class C1029 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[]l=new int[n],r=new int[n],a=new int[n],b=new int[n];
        for (int i = 0; i < n; i++) {
            l[i]=sc.nextInt();
            r[i]=sc.nextInt();
            a[i]=l[i];
            b[i]=r[i];
        }
        Arrays.sort(l);
        Arrays.sort(r);
        int ans=0;
        for (int i = 0; i < n; i++) {
            int ll=a[i]==l[n-1]?l[n-2]:l[n-1];
            int rr=b[i]==r[0]?r[1]:r[0];
            ans=Math.max(ans, rr-ll);
        }
        System.out.println(ans);
        sc.close();
    }
}
