import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * @Description 1512E
 * @Author Leon
 * @Date 2024/2/27
 */
public class E {
    static Scanner sc;
    public static void main(String[] args) {
        sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-->0){
            solve();
        }
    }
    private static void solve(){
        int n = sc.nextInt(), l = sc.nextInt(), r = sc.nextInt(), s = sc.nextInt();
        int len = r - l + 1;
        int minT = len *(len+1)/2;
        int maxT = (n- len) *(n-len+1)/2;
        if( minT > s || s> (n *(n+1)/2 - maxT)){
            System.out.println(-1);
            return;
        }
        int[] ans = new int[n];
        boolean[] vis = new boolean[n];
        for (int i = 0; i < n; i++) {
            ans[i] = i+1;
        }
        int last = n-1;

        for (int i = len-1; i>=0;i--) {
            while ( s != minT && vis[last] || (s- minT - (last - ans[i] + 1)<0)){
                last--;
            }
            vis[last] = true;
            vis[i] = false;
            minT += (last - ans[i] + 1);
            if(s == minT){
                break;
            }
            last--;
        }
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if(vis[i]){
                list.add(i+1);
            }
        }
        for (int i = 0; i < n; i++) {
            if(!vis[i]){
                list.add(i+1);
            }
        }
        StringBuilder sb = new StringBuilder();
        for (int i = len; i < len+l-1; i++) {
            sb.append(list.get(i)).append(" ");
        }
        for (int i = 0; i < len; i++) {
            sb.append(list.get(i)).append(" ");
        }
        for (int i = r; i < n; i++) {
            sb.append(list.get(i)).append(" ");
        }
        System.out.println(sb);
    }
}
