//https://codeforces.com/problemset/submission/1056/261456395
import java.util.Arrays;
import java.util.Scanner;

public class D1056 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[]p=new int[n];
        for (int i = 1; i < n; i++) {
            p[i]=sc.nextInt();
        }
        if(n==1){
            System.out.println(1);
            return;
        }
        int[]d=new int[n];
        for (int i = n-1; i >0; i--) {
            if(d[i]==0)d[i]=1;
            d[p[i]-1]+=d[i];
        }
        Arrays.sort(d);
        for (int i = 0; i < n; i++) {
            System.out.println(d[i]);
        }
    }
}
