public class cf891a_Leoncn {
    public static int minOperations(int[] nums) {
        int c = 0;
        int n = nums.length;
        int g = nums[0];
        for (int i = 0; i < n; i++) {
            g = gcd(g, nums[i]);
            if(nums[i]==1){
                c++;
            }
        }
        if(c>0){
            return n - c;
        }
        if(g!=1){
            return -1;
        }
        int min = n;
        for (int i = 0; i < n; i++) {
            int s = nums[i];
            for (int j = i+1; j <n ; j++) {
                s= gcd(s, nums[j]);
                if(s==1){
                    min = Math.min(min, j-i);
                }
            }
        }
        return n + min -1;
    }
    private static int gcd(int a, int b){
        if(b==0){
            return a;
        }
        return gcd(b, a%b);
    }
}
