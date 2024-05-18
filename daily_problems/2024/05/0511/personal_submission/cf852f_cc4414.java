# Submission link: https://codeforces.com/contest/852/submission/260507992
class Solution {
    public long[] solve(int n, int m, int a, int q) {
        long[] ans = new long[n];
        long[] arr = new long[n];
        int x = 0;
        long t = 1;
        while (true) {
            x++;
            t *= a;
            t %= q;
            if (t == 1) {
                break;
            }
        }
        Factorial fac = new Factorial(m + 5, x);
        Arrays.fill(arr, BigInteger.valueOf(2).modPow(BigInteger.valueOf(m), BigInteger.valueOf(x)).longValue());
        arr[n - 1] = 1;
        for (int i = 1; i < Math.min(m, n); i++) {
            arr[n - 1 - i] = arr[n - i] + fac.comb(m, i);
            arr[n - 1 - i] %= x;
        }
        long[] arr2 = new long[x + 5];
        arr2[0] = 1;
        for (int i = 1; i < arr2.length; i++) {
            arr2[i] = arr2[i - 1] * a % q;
        }
        for (int i = 0; i < n; i++) {
            ans[i] = arr2[(int) arr[i]];
        }
        return ans;
    }
}
