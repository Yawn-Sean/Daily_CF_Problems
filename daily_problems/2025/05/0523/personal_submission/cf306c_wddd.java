import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Math2 {

    void solve() {
        int n = is.ni();
        int white = is.ni();
        int black = is.ni();

        int mod = (int) (1e9 + 9);
        long[][] as = new long[Math.max(white, black) + 1][Math.max(white, black) + 1];
        for (int i = Math.max(white, black); i >= 1; i--) {
            as[i][0] = 1;
            as[i][1] = i;
            for (int j = 2; j <= i; j++) {
                as[i][j] = as[i][j - 1] * (i - j + 1);
                as[i][j] %= mod;
            }
        }

        BCMod bcMod = new BCMod(Math.max(white, black) + 1, Math.max(white, black) + 1, mod);

        long result = 0;
        for (int bDay = 1; bDay <= black; bDay++) {
            int wDay = n - bDay;
            if (wDay <= 1 || wDay > white) {
                continue;
            }

            long curr = arrangement(black, bDay, as);
            curr %= mod;
            if (black - bDay > 0) {
                curr *= arrangement(black - bDay, black - bDay, as);
                curr %= mod;
                curr *= bcMod.comb(black - 1, bDay - 1);
                curr %= mod;
            }

            curr *= arrangement(white, wDay, as);
            curr %= mod;
            if (white - wDay > 0) {
                curr *= arrangement(white - wDay, white - wDay, as);
                curr %= mod;
                curr *= bcMod.comb(white - 1, wDay - 1);
                curr %= mod;
            }

            curr *= wDay - 1;
            curr %= mod;

            result += curr;
            result %= mod;
        }
        out.println(result);
    }

    private long arrangement(int x, int y, long[][] as) {
        return as[x][y];
    }

    public class BCMod {
        private long[][] triangle;

        public BCMod(int maxN, int maxK, int mod) {
            triangle = new long[maxN + 1][maxK + 1];
            triangle[0][0] = 1;

            for (int i = 1; i <= maxN; i++) {
                triangle[i][0] = 1;
                for (int j = 1; j <= maxK; j++) {
                    triangle[i][j] = triangle[i - 1][j] + triangle[i - 1][j - 1];
                    triangle[i][j] %= mod;
                }
            }
        }

        public long comb(int n, int k) {
            if (n < 0 || k < 0) {
                return 0;
            }

            return triangle[n][k];
        }
    }

}
