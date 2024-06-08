# Submission link: https://codeforces.com/contest/1575/submission/264663842
class Solution {
    public long solve(long n, long m, long k, long r, long c, long ax, long ay, long bx, long by) {
        return BigInteger.valueOf(k).modPow(BigInteger.valueOf(n * m - ((ax == bx) && (ay == by) ? 0 : r * c)), BigInteger.valueOf((long) (1e9 + 7))).longValue();
    }
}
