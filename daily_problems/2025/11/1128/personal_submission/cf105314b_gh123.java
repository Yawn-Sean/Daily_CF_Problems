import java.util.Arrays;
import java.util.Scanner;

public class B105314 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        while (t-->0) {
            int n=sc.nextInt();
            long m=sc.nextLong();
            int[]a=new int[n];
            for (int i = 0; i < a.length; i++) {
                a[i]=sc.nextInt();
            }
            Arrays.sort(a);
            int l=0,r=(int)1e7;
            int ans=-1;
            while (l<=r) {
                int mid=(l+r)/2;
                int pt=0;
                long cnt=0;
                for (int i = 0; i < n; i++) {
                    while (pt<n&&a[pt]-a[i]<mid) {
                        pt++;
                    }
                    cnt+=(n-pt)*2;
                }
                if(cnt<=m){
                    ans=mid;
                    r=mid-1;
                }else{
                    l=mid+1;
                }
            }
            long[]pre=new long[n+1];
            for (int i = 0; i < n; i++) {
                pre[i+1]=pre[i]+a[i];
            }
            int bound=ans,pt=0;
            long cnt=0,val=0;
            for (int i = 0; i < n; i++) {
                while (pt<n&&a[pt]-a[i]<bound) {
                    pt++;
                }
                cnt+=(n-pt)*2;
                val+=(pre[n]-pre[pt]-(n-pt)*a[i])*2;
            }
            val+=(m-cnt)*(bound-1);
            System.out.println(val);
        }   
        sc.close();
    }
}
