

public class cf524c_Leoncn {
    public static void solve() {
        int n = sc.ni();
        int k = sc.ni();
        int[] g = sc.na(n);
        int q = sc.ni();
        Map<Integer,Integer> map = new HashMap<>();


       for (int j = 0; j < n; j++) {
           for (int i = 0; i <=k; i++) {
               map.put(i*g[j], i);
            }
        }

        while (q-->0){
            int s = sc.ni();
            int ans = k + 1;
            for(int key : map.keySet()){
                ans = Math.min(map.get(key)+ map.getOrDefault(s- key, k+1), ans);
            }
            out.println(ans>k?-1:ans);
        }
    }
}
