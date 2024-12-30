# Submission link: https://codeforces.com/contest/551/submission/264533039
class Solution {
    public long solve(long n, long k, int l, long m) {
        if (l < 63 && k >= (1L << l)) {
            return 0;
        }
        long ans = 1;
        long s = BigInteger.valueOf(2).modPow(BigInteger.valueOf(n), BigInteger.valueOf(m)).longValue();
        for (int i = 0; i < l; i++) {
            long v = (k >> i) & 1;
            long[][] cur = new long[][]{{1, 0}, {0, 1}};
            long[][] a = new long[][]{{1, 1}, {1, 0}};
            long n1 = n;
            while (n1 > 0) {
                if ((n1 & 1) == 1) {
                    cur = mul(cur, a, m);
                }
                a = mul(a, a, m);
                n1 >>= 1;
            }
            long t = cur[0][0] + cur[0][1];
            t %= m;
            if (v == 0) {
                ans *= t;
            } else {
                ans *= s - t;
            }
            ans %= m;
        }
        return (ans % m + m) % m;
    }

    private long[][] mul(long[][] a, long[][] b, long mod) {
        long[][] c = new long[2][2];
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    c[i][j] += a[i][k] * b[k][j];
                    c[i][j] %= mod;
                }
            }
        }
        return c;
    }
}
