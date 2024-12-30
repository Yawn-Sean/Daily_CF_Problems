
public class cf1073c_Leoncn {
    public static void solve() {
        Map<Character, int[]> map = new HashMap<>();
        int n = sc.ni();
        char[] cs = sc.ns().toCharArray();
        int x = sc.ni(), y = sc.ni();
        int sx = 0, sy = 0;
        map.put('U', new int[]{0, 1});
        map.put('D', new int[]{0, -1});
        map.put('L', new int[]{-1, 0});
        map.put('R', new int[]{1, 0});
        for(char c: cs){
            int[] d = map.get(c);
            sx += d[0];
            sy += d[1];
        }
        int difX = sx - x;
        int difY = sy - y;
        if((difX + difY)%2!=0){
            out.println(-1);
            return;
        }
        if(difX ==0 && difY == 0){
            out.println(0);
            return;
        }

        int loc = 0;
        int ans = n+1;
        int cntX = 0, cntY = 0;
        for (int i = 0; i < n; i++) {
            int[] d = map.get(cs[i]);
            cntX += d[0];
            cntY += d[1];
            while (loc<n&& i-loc+1>= Math.abs(sx- cntX - x)  +     Math.abs(sy- cntY - y)){
                ans = Math.min(ans, i-loc+1);
                d = map.get(cs[loc]);
                cntX -= d[0];
                cntY -= d[1];
                loc++;
            }
        }
        out.println(ans == n+1?-1: ans);

    }
}
