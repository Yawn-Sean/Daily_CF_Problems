//https://codeforces.com/problemset/submission/731/275462094
import java.util.Scanner;

public class E731 {
    public static void main(String[] args) {
        //不看题解，根本做不出来系列。。。
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        long[]a=new long[n];
        for (int i = 0; i < a.length; i++) {
            a[i]=sc.nextLong();
        }
        for (int i = 1; i < n; i++) {
            a[i]+=a[i-1];
        }
        for (int i = n-2; i >0; i--) {
            a[i]=Math.max(a[i+1],a[i]-a[i+1]);
        }
        System.out.println(a[1]);
        sc.close();
    }
}
