//https://codeforces.com/problemset/submission/245/318681798
import java.util.Scanner;

public class C245 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[]a=new int[n];
        for (int i = 0; i < n; i++) {
            a[i]=sc.nextInt();
        }
        if(n>1&&n%2==1){
            int ans=0;
            for (int i = n-1; i >=0; i--) {
                if(2*i+2<n){
                    int x=Math.max(a[2*i+1], a[2*i+2]);
                    a[i]=Math.max(0, a[i]-x);
                    ans+=x;
                }
            }
            System.out.println(ans+a[0]);
        }else{
            System.out.println(-1);
        }
        sc.close();
    }
}
