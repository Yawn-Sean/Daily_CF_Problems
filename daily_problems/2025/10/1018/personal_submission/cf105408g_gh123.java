import java.util.Scanner;

public class G105408 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[]a=new int[n];
        int g=0;
        for (int i = 0; i < n; i++) {
            a[i]=sc.nextInt();
            g=gcd(g,a[i]);
        }   
        int m=0;
        for (int i = 0; i < n; i++) {
            a[i]=a[i]/g;
            m=Math.max(a[i], m);
        }
        int[]prime=new int[m+1];
        for (int i = 0; i < prime.length; i++) {
            prime[i]=i;
        }
        for (int i = 2; i <=m; i++) {
            if(prime[i]==i){
                for (int j = i; j <=m; j+=i) {
                    prime[j]=i;
                }
            }
        }
        boolean flag=true;
        int[]vis=new int[m+1];
        for (int i : a) {
            while (i>1) {
                int p=prime[i];
                // System.out.println("here? "+ p);
                if(vis[p]==1){
                    flag=false;
                }
                vis[p]=1;
                while (i%p==0) {
                        i/=p;
                    }
            }
        }
        System.out.println(flag?"YES":"NO");

        sc.close();
    }
    public static int gcd(int a,int b){
        if(b==0) return a;
        return gcd(b, a%b);
    }
}
