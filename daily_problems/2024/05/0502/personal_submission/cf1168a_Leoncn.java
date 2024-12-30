import java.util.Scanner;

/**
 * @Description:
 * @Author: Leon
 * @Date: 2024/5/2
 */
public class A {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] g = new int[n];
        for (int i = 0; i < n; i++) {
            g[i] = sc.nextInt();
        }
        int l = 0, r = m;
        while (l<r){
            int mid = l + r >>1;
            int pre = 0;
            boolean f = true;
            for (int i = 0; i < n; i++) {
                if(g[i]<pre){
                    if(g[i] + mid < pre){
                        f = false;
                        break;
                    }
                }else if(g[i]>pre){
                    if( m - g[i] + pre>mid){
                        pre = g[i];
                    }
                }
            }
            if(!f){
                l = mid +1;
            }else {
                r = mid;
            }
        }
        System.out.println(l);
    }
}