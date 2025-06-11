
public class cf858d_Leoncn {
    public static void solve() {
        int n = sc.ni();
        String[] g = new String[n];
        for (int i = 0; i < n; i++) {
            g[i] = sc.ns();
        }
        long pre = (long)1e9;
        Map<Long, Integer> map = new HashMap<>();
        Map<Long, Integer> cnt = new HashMap<>();
        for (int i = 0; i < n; i++) {
            Set<Long> set = new HashSet<>();
            char[] cs = g[i].toCharArray();
            for (int j = 0; j < 9; j++) {
                long a = 0;
                for (int k = j; k <9; k++) {
                    a = a*10 + (cs[k]-'0');
                    set.add(pre*(k-j+1) + a);
                }
            }
            for(Long s: set){
                map.put(s,i);
                cnt.merge(s,1,Integer::sum);
            }
        }
        Long[] ans = new Long[n];
        for(Long s: map.keySet()){
            if(cnt.get(s)==1){
                int loc = map.get(s);
                if(ans[loc] == null || s/pre< ans[loc]/pre){
                    ans[loc] = s;
                }
            }
        }
        for(long s: ans){
            int size = (int)(s/pre);
            String f = s +"";
            out.println(f.substring(f.length()-size, f.length()));
        }

    }

}
