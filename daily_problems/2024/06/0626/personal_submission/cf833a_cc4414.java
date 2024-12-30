// https://codeforces.com/problemset/submission/833/267472383
class Solution {
    public boolean solve(long a, long b) {
        long c = a * b;
        long d = Math.round(Math.pow(c, 1. / 3));
        return d * d * d == c && a % d == 0 && b % d == 0;
    }
}
