
public class cf1278c_Leoncn {
    public static void solve() {
        int n = sc.ni();
        int[] left = sc.na(n);
        int[] right = sc.na(n);
        int[] maxRight = new int[2*n+5];
        int diff = n;
        Arrays.fill(maxRight, -2*n);
        maxRight[n] = 0;
        for(int i = n-1; i >= 0; i--) {
            if(right[i] == 1) {
                diff--;
            } else{
                diff++;
            }
            maxRight[diff] = Math.max(maxRight[diff], n-i);
        }

        int max = maxRight[n];
        diff = n;
        for(int i = 0; i < n; i++) {
            if(left[i] == 1) {
                diff++;
            }else {
                diff--;
            }
            max = Math.max(max, i+1+maxRight[diff]);
        }
        out.println(2*n-max);
    }
}
