//https://codeforces.com/problemset/submission/1056/264662377
import java.util.Scanner;

public class B1056 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int m=sc.nextInt();
        int n=sc.nextInt();
        long[]ans=new long[n];
        for (int i = 0; i < n; i++) {
            if(m%n>=i&&i!=0){
                ans[i]=m/n+1;
            }else{
                ans[i]=m/n;
            }
        }
        long cnt=0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if((i*i+j*j)%n==0){
                    cnt+=ans[i]*ans[j];
                }
            }
        }
        System.out.println(cnt);
        sc.close();
    }
}
