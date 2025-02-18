package personal_submission;


import java.io.*;
import java.util.*;

public class cf681d_550N {
    static MyScanner scanner = new MyScanner();
    public static PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
    public static void main(String[] args) {
        int t = 1;
        while (t-- > 0) {
            solve();
        }
        out.close();
    }

    private static void solve() {
        int n = scanner.nextInt();
        int m = scanner.nextInt();

        List<Integer>[] path = new List[n];
        boolean[] isroot = new boolean[n];
        Arrays.fill(isroot, true);

        Arrays.setAll(path, a -> new ArrayList<>());

        while (m-- > 0) {
            int u = scanner.nextInt() - 1;
            int v = scanner.nextInt() - 1;
            path[u].add(v);
            isroot[v] = false;
        }

        int[] to_get = new int[n];
        boolean[] used = new boolean[n];

        for (int i = 0; i < n; i++) {
            to_get[i] = scanner.nextInt() - 1;
            used[to_get[i]] = true;
        }

        int[] ans = new int[n];
        Arrays.fill(ans, -1);
        List<Integer> order = new ArrayList<>();
        Stack<Integer> stack = new Stack<>();

        for (int i = 0; i < n; i++) {
            if (isroot[i]) {
                stack.push(i);
            }
        }

        while (!stack.isEmpty()) {
            int u = stack.pop();
            if (used[u]) {
                order.add(u);
                ans[u] = u;
            }
            for (int v : path[u]) {
                ans[v] = ans[u];
                stack.push(v);
            }
        }

        boolean isEqual = true;
        for (int i = 0; i < n; i++) {
            if (ans[i] != to_get[i]) {
                isEqual = false;
                break;
            }
        }

        if (!isEqual) {
            System.out.println(-1);
        } else {
            System.out.println(order.size());
            for (int i = order.size() - 1; i >= 0; i--) {
                System.out.println(order.get(i) + 1);  // Convert back to 1-based index
            }
        }
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
