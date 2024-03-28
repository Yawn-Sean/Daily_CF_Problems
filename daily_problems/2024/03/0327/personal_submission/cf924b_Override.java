
import java.util.Scanner;

public class Main2 {

    private static final int N = 100005;
    private static int n,u;
 
    private static double[] a = new double[N];
    private static double res = -1;

  
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        u = scanner.nextInt();
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        int l=0,r=0;
        while(l<n) {
        	while(r<n && a[r]-a[l]<=u) {
        		r+=1;
        	}
        	if(r-l>=3) {
        		 res = Math.max(res, (a[r-1] - a[l+1]) / (a[r-1] - a[l]));
        	}
        	l+=1;
        }
        System.out.print(res);
        scanner.close();
    }
}
