import java.io.*;
import java.util.*;

public class Main {
    static MyScanner sc = new MyScanner();
    public static PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
    public static void main(String[] args) {
        int t = 1;
        while (t-- > 0) {
            solve();
        }
        out.close();
    }

    private static void solve() {
        int n = sc.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) nums[i] = sc.nextInt();
        System.out.println(totalSteps(nums));

    }

    public static int totalSteps(int[] nums) {
        var ans = 0;
        // st[i] = [x，当前元素被删掉的时间]
        var st = new ArrayDeque<int[]>();
        for (var num : nums) {
            // 当前元素被删掉的最大时间
            var maxT = 0;
            while (!st.isEmpty() && st.peek()[0] <= num)
                // 如果当前元素比左边的要大，先假设它能被左边的杀掉，所以取max
                maxT = Math.max(maxT, st.pop()[1]);
            // 如果比左边的要小，那可以默认是0 / 1了
            // 假如左边没有更大的了，就是0，不然就是左边被杀的最晚时间+1
            maxT = st.isEmpty() ? 0 : maxT + 1;
            ans = Math.max(ans, maxT);
            st.push(new int[]{num, maxT});
        }
        return ans;
    }

    //-----------PrintWriter for faster output---------------------------------


    //-----------MyScanner class for faster input----------
    public static class MyScanner {
        BufferedReader br;
        StringTokenizer st;

        public MyScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine(){
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }

    }
}
