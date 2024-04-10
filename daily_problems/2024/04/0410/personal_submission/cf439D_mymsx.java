import java.io.BufferedOutputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;
public class cfsubmit {
    public static void main(String[] args) {
        int m,n;
        Scanner sc = new Scanner(System.in);
        PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
        m = sc.nextInt();
        n = sc.nextInt();
        int[] arr1 = new int[m];
        int[] arr2 = new int[n];
        for (int i = 0; i < m; i++) {
            arr1[i] = sc.nextInt();
        }
        for (int i = 0; i < n; i++) {
            arr2[i] = sc.nextInt();
        }
        CF cf = new CF();
        out.println(cf.minCount(arr1,arr2));
        sc.close();;
        out.close();
    }
}
class CF{
    public long minCount(int[] a,int[] b){
        Arrays.sort(a);
        Arrays.sort(b);
        long[] sum1 = new long[a.length];
        sum1[0] = a[0];
        long[] sum2 = new long[b.length];
        sum2[0] = b[0];
        for (int i = 1; i < a.length; i++) {
            sum1[i] = sum1[i - 1] + a[i];
        }
        for (int i = 1; i < b.length; i++) {
            sum2[i] = sum2[i - 1] + b[i];
        }
        long ans = Long.MAX_VALUE;
        for (int x : a) {
            int index1 = lowerBound(a, x);
            int index2 = lowerBound(b, x);
            ans = Math.min((long) x * (index1 + 1) - sum1[index1] + sum2[sum2.length - 1] - (index2 >= 0 ? sum2[index2] : 0) - (long) x * (sum2.length - index2 - 1), ans);
        }
        for (int x : b) {
            int index1 = lowerBound(a, x);
            int index2 = lowerBound(b, x);
            ans = Math.min((long) x * (index1 + 1) - (index1 >= 0 ? sum1[index1] : 0) + sum2[sum2.length - 1] - sum2[index2] - (long) x * (sum2.length - index2 - 1), ans);
        }
        return ans;
    }
    public int lowerBound(int[] a,int target){
        int l = 0;
        int r = a.length;
        while (l < r){
            int mid = l + (r - l) / 2;
            if(target < a[mid]) r = mid;
            else l = mid + 1;
        }
        return r - 1;
    }
}
