import java.util.Arrays;
import java.util.Scanner;

/**
 * @Description:
 * @Author: Leon
 * @Date: 2024/5/2
 */
public class E {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int t = sc.nextInt();
        long[][] g = new long[n][2];
        long sT = 0;
        double sA = 0;
        for (int i = 0; i < n; i++) {
            int a = sc.nextInt();
            g[i][0] = a;
            sA += a;
        }
        for (int i = 0; i < n; i++) {
            int b = sc.nextInt() - t;
            g[i][1] = b;
            sT += g[i][0] * b;
        }
        Arrays.sort(g,(a,b)->Long.compare(a[1],b[1]));
        if(sT>0){
            for (int i = n-1; i >=0 ; i--) {
                if(sT<=g[i][0]*g[i][1]){
                    sA -= ((double) sT)/g[i][1];
                    break;
                }else {
                    sT -= g[i][0]*g[i][1];
                    sA -= g[i][0];
                }
            }
        }else if(sT<0){
            for (int i = 0; i < n; i++) {
                if(sT - g[i][0] * g[i][1]>=0){
                    sA -= ((double) sT)/g[i][1];
                    break;
                }else {
                    sT -= g[i][0]*g[i][1];
                    sA -= g[i][0];
                }
            }
        }
        System.out.println(sA);


    }
}
