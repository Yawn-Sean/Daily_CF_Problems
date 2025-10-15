import java.util.Scanner;

public class J102409 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        long l=sc.nextLong();
        long[]a=new long[n+1];
        a[0]=0;
        a[n]=1;
        for (int i = 1; i <=n-1; i++) {
            a[i]=sc.nextLong();
        }
        int idx1=0,idx2=0;
        long ans=l;
        sc.close();
        for (int i = 2; i <=n-2; i++) {
            while (idx1<n-1&&a[idx1+1]<=a[i]-a[idx1+1]) {
                idx1++;
            }
            while (idx2<n-1&&a[idx2+1]-a[i]<=l-a[idx2+1]) {
                idx2++;
            }
            for (int x = idx1; x <=idx1+1; x++) {
                for (int y = idx2; y <=idx2+1; y++) {
                    long max=Math.max(a[x], a[i]-a[x]);
                    max=Math.max(max, a[y]-a[i]);
                    max=Math.max(max, l-a[y]);
                    long min=Math.min(a[x], a[i]-a[x]);
                    min=Math.min(min, a[y]-a[i]);
                    min=Math.min(min, l-a[y]);
                    ans=Math.min(ans, max-min);
                }
            }
        }
        System.out.println(ans);
    }
}
