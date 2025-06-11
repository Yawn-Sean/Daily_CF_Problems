import java.util.ArrayList;
import java.util.List;

public class cf243b_Leoncn {
        static ArrayList<Integer>[] g;
    static int[] used;
    static int x;
    static int y;
    public static void solve() {
        int n = sc.ni();
        int m = sc.ni();
        x = sc.ni();
        y = sc.ni();

        g = new ArrayList[n];
        used = new int[n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<>();
        }
        for (int i = 0; i < m; i++) {
            int a = sc.ni() - 1;
            int b = sc.ni() - 1;
            g[a].add(b);
            g[b].add(a);
        }
        for (int i = 0; i < n; i++) {
            for(int w:g[i]){
                if(check(i,w)){
                    return;
                }
            }
        }
        out.println("NO");

    }
    private static boolean check(int c, int w){
        if(g[c].size()<= x || g[w].size()<=y){
            return false;
        }
        int cnt = 0;
        used[c] = -1;
        used[w] = -1;
        for(int i: g[c]){
            if(used[i] == 0) cnt++;
            used[i] |= 1;
        }
        for(int i: g[w]){
            if(used[i] == 0) cnt++;
            used[i] |= 2;
        }
        if(cnt >= x + y){
            List<Integer> ans1 = new ArrayList<>();
            List<Integer> ans2 = new ArrayList<>();
            for(int i: g[c]){
                if(used[i] == 1 && x>0){
                    ans1.add(i);
                    x--;
                }
            }
            for(int i: g[w]){
                if(used[i] == 2 && y>0){
                    ans2.add(i);
                    y--;
                }
            }
            for(int i:g[c]){
                if(used[i] ==3){
                    if(x>0){
                        ans1.add(i);
                        x--;
                    }else if(y>0){
                        ans2.add(i);
                        y--;
                    }
                }
            }
            out.println("YES");
            out.println((c+1) + " "+ (w+1) );
            for(int l: ans1){
                out.print(l+1 + " ");
            }
            out.println("");
            for(int l: ans2){
                out.print(l+1 + " ");
            }
            return true;
        }
        for(int i: g[c]){
            used[i] = 0;
        }
        for(int i: g[w]){
            used[i] = 0;
        }
        return false;

    }
}
