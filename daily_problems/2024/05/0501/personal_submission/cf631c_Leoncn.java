import java.util.*;

/**
 * @Description:
 * @Author: Leon
 * @Date: 2024/5/1
 */
public class C {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] g = new int[n];
        for (int i = 0; i < n; i++) {
            g[i] = sc.nextInt();
        }
        Deque<int[]> dq = new ArrayDeque<>();
        int max = 0;
        for (int i = 0; i < m; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            max = Math.max(b, max);
            while (dq.size()>0 && dq.peekFirst()[1]<=b){
                dq.pollFirst();
            }
            dq.offerFirst(new int[]{a,b});
        }
        int[] arr = Arrays.copyOf(g, max);
        Arrays.sort(arr);
        int l = 0, r = max - 1;
        int loc = max - 1;
        while (dq.size()>0){
            int[] p = dq.pollLast();
            int f = dq.size() == 0? 0: dq.peekLast()[1];
            if(p[0] == 1){
                while (p[1]>f){
                    p[1]--;
                    g[loc--] = arr[r--];
                }
            }else {
                while (p[1]>f){
                    p[1]--;
                    g[loc--] = arr[l++];
                }
            }
        }
        for (int i = 0; i < n; i++) {
            System.out.print(g[i] + " ");
        }


    }
}
