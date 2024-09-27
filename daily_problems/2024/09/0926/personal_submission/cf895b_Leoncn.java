import java.util.Arrays;

public class cf895b_Leoncn {
    public static void solve(){
        int n = sc.ni();
        int x = sc.ni();
        int k = sc.ni();
        int[] g = sc.na(n);
        Arrays.sort(g);
        long ans = 0;
        int tag = 0;
        for (int i = 0; i < n; i++) {
            tag = Math.max(tag, i);
            while (tag<n-1 && g[tag] == g[tag+1]){
                tag++;
            }
            int l = 0, r = tag+1;
            while (l<r){
                int cnt = 0;
                int mid = l + r >> 1;
                cnt = g[i] /x -  (g[mid]-1)/x;
                if(cnt>k){

                    l = mid + 1;
                }else {
                    r = mid;
                }
            }

            int pre = l;
            l = 0;
            r = tag+1;
            while (l < r){
                int cnt = 0;
                int mid = l + r >> 1;
                cnt = g[i] /x -  (g[mid]-1)/x;
                if(cnt>=k){
                    l = mid + 1;

                }else {
                    r = mid;
                }
            }
            ans += l-pre;
        }
        out.println(ans);


    }
}
