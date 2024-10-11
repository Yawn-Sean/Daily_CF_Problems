
public class cf946d_Leoncn {
    public static void solve() {
        int n = sc.ni();
        int m = sc.ni();
        int k = sc.ni();
        int[] dp = new int[k+1];
        int sum = 0;
        for (int i = 0; i < n; i++) {
            char[] cs = sc.ns().toCharArray();
            List<Integer> list = new ArrayList<>();
            for (int j = 0; j < m; j++) {
                if(cs[j] == '1'){
                    list.add(j);
                }
            }
            if(list.size()>0){
                int v = list.get(list.size()-1) - list.get(0) + 1;
                int size = list.size();
                int[] max = new int[size+1];
                sum += v;
                max[size] = v;
                for (int j = 0; j < size; j++) {
                    for (int h = j; h < size; h++) {
                        max[size - (h-j+1)] = Math.max(max[size-(h-j+1)], v - (list.get(h)-list.get(j) + 1));
                    }
                }

                for (int j = k; j >0 ; j--) {
                    for (int h = 0; h <=size ; h++) {
                        if(j<h){
                            break;
                        }
                        dp[j] = Math.max(dp[j], dp[j-h] + max[h]);
                    }
                }

            }
        }
        out.println(sum - dp[k]);

    }
}
