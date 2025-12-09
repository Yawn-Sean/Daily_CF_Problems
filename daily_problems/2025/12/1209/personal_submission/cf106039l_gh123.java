import java.util.*;
import java.io.*;
public class L106039 {
    static int n;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);

        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        long K = Long.parseLong(st.nextToken());

        char[][] grid = new char[N][];
        for (int i = 0; i < N; i++) {
            grid[i] = br.readLine().toCharArray();
        }

        int[][] id = new int[N][N];
        List<int[]> cells = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] != '#') {
                    id[i][j] = cells.size();
                    cells.add(new int[]{i, j});
                } else {
                    id[i][j] = -1;
                }
            }
        }

        int m = cells.size();
        if (m == 0) {
            for (int i = 0; i < N; i++) {
                out.println(new String(grid[i]));
            }
            out.close();
            return;
        }

        // Build transition matrix T = I + M (over GF(2))
        long[][] T = new long[m][m];
        int[] dx = {-1, -1, -1, 0, 0, 1, 1, 1};
        int[] dy = {-1, 0, 1, -1, 1, -1, 0, 1};

        for (int idx = 0; idx < m; idx++) {
            int i = cells.get(idx)[0];
            int j = cells.get(idx)[1];
            T[idx][idx] = 1; // identity
            for (int d = 0; d < 8; d++) {
                int ni = i + dx[d];
                int nj = j + dy[d];
                if (ni >= 0 && ni < N && nj >= 0 && nj < N && id[ni][nj] != -1) {
                    int nidx = id[ni][nj];
                    T[idx][nidx] = (T[idx][nidx] + 1) % 2;
                }
            }
        }

        // Initial state vector
        long[] x0 = new long[m];
        for (int idx = 0; idx < m; idx++) {
            int i = cells.get(idx)[0];
            int j = cells.get(idx)[1];
            x0[idx] = (grid[i][j] == '1') ? 1 : 0;
        }

        // Compute T^K
        long[][] TK = matrixPower(T, K, m);

        // xK = TK * x0
        long[] xK = new long[m];
        for (int i = 0; i < m; i++) {
            long sum = 0;
            for (int j = 0; j < m; j++) {
                sum = (sum + TK[i][j] * x0[j]) % 2;
            }
            xK[i] = sum;
        }

        // Output
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == '#') {
                    out.print('#');
                } else {
                    int idx = id[i][j];
                    out.print(xK[idx] == 1 ? '1' : '0');
                }
            }
            out.println();
        }

        out.close();
    }

    static long[][] multiply(long[][] A, long[][] B, int n) {
        long[][] C = new long[n][n];
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (A[i][k] == 0) continue;
                for (int j = 0; j < n; j++) {
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % 2;
                }
            }
        }
        return C;
    }

    static long[][] matrixPower(long[][] base, long exp, int n) {
        long[][] res = new long[n][n];
        for (int i = 0; i < n; i++) {
            res[i][i] = 1;
        }
        while (exp > 0) {
            if ((exp & 1) == 1) {
                res = multiply(res, base, n);
            }
            base = multiply(base, base, n);
            exp >>= 1;
        }
        return res;
    }
}
