//https://codeforces.com/problemset/submission/231/269002463
import java.util.Arrays;
import java.util.Scanner;

public class C231 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        long k=sc.nextLong();
        long[]a=new long[n];
        long[]s=new long[n];
        long sum=0;
        for (int i = 0; i < n; i++) {
            a[i]=sc.nextInt();
        }
        Arrays.sort(a);
        for (int i = 0; i < n/2; i++) {
            long tem=a[i];
            a[i]=a[n-1-i];
            a[n-1-i]=tem;
        }
        for (int i = 0; i < n; i++) {
            sum+=a[i];
            s[i]=sum;
        }
        if(n==1){
            System.out.println(1+" "+a[0]);
            return;
        }
        sc.close();
        long[]ans=new long[2];
        long cs;
        for (int i = 0; i < n-1; i++) {
            int f=i+1,l=n-1,med;
            while (f<=l) {
                med=(f+l)/2;
                cs=s[med]-s[i];
                if(cs+k>=(med-i)*a[i]){
                    f=med+1;
                    if(ans[0]<=med-i){
                        ans[0]=med-i;
                        ans[1]=a[i];
                    }
                }else{
                    l=med-1;
                }
            }
        }
        System.out.println(ans[0]+1+" "+ans[1]);
    }
}
