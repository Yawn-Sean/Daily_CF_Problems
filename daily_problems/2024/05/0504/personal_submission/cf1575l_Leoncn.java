public class cf1575l_Leoncn {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt()-1;
        }

        ArrayList<Integer>[] tmp = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            tmp[i] = new ArrayList<>();
        }

        for (int i = 0; i < n; i++) {
            if (i - nums[i] >= 0) {
                tmp[nums[i]].add(i-nums[i]);
            }
        }

        int[] dp = new int[n];
        int ans = 0;
        for (int i = 0; i < n; i++) {
            List<Integer> list = tmp[i];
            for (int j = list.size() - 1; j >= 0; j--) {
                int lo = 0, hi = ans;
                int num = list.get(j);
                while(lo < hi) {
                    int mid = lo+(hi-lo)/2;
                    if(dp[mid] <= num){
                        lo = mid+1;
                    }else {
                        hi = mid;
                    }
                }
                dp[lo] = num;
                if(lo == ans){
                    ans++;
                }

            }
        }
        System.out.println(ans);
    }
}
