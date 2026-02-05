import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int t = Integer.parseInt(st.nextToken());
        while (t-- > 0) {
            st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            st = new StringTokenizer(br.readLine());
            int[] nums = new int[n];
            for (int ez = 0; ez < n; ez++)
                nums[ez] = Integer.parseInt(st.nextToken());
            Integer[] pos = new Integer[n];
            for (int ez = 0; ez < n; ez++)
                pos[ez] = ez;
            Arrays.sort(pos, (a, b) -> Integer.compare(nums[a], nums[b]));
            FenWick fen = new FenWick(n);
            int[] res = new int[n];
            for (int ez = n - 1; ez >= 0; ez--) {
                res[ez] = fen.sum(pos[ez]);
                fen.add(pos[ez], 1);
            }
            int cur = 0;
            boolean isOk = true;
            for (int ez = 0; ez < n; ez++) {
                cur += res[ez];
                if (cur > nums[pos[ez]]) {
                    isOk = false;
                    break;
                }
            }
            pw.println(isOk ? "YES" : "NO");
        }
        pw.close();
    }

    private static class FenWick {
        int[] bit;
        int n;

        FenWick(int n) {
            this.n = n;
            bit = new int[n + 1];
        }

        void add(int ez, int v) {
            for (ez++; ez <= n; ez += ez & -ez)
                bit[ez] += v;
        }

        int sum(int ez) {
            int s = 0;
            for (; ez > 0; ez -= ez & -ez)
                s += bit[ez];
            return s;
        }
    }

}
