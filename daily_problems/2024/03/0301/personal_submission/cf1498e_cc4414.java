import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);
        Task solver = new Task();
        solver.solve(1, in, out);
        out.close();
    }

    static class Task {
        InputReader in;
        PrintWriter out;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
            for (int t = 0; t < testNumber; t++) {
                int n = in.nextInt();
                int[][] k = new int[n][2];
                for (int i = 0; i < k.length; i++) {
                    k[i] = new int[]{in.nextInt(), i};
                }
                List<Integer>[] sets = new List[n];
                for (int i = 0; i < sets.length; i++) {
                    sets[i] = new ArrayList<>();
                }
                for (int i = 0; i < n; i++) {
                    sets[k[i][0]].add(k[i][1]);
                }
                for (int i = n - 1; i > 0; i--) {
                    for (int j = i; j < n; j++) {
                        for (Integer v : sets[j]) {
                            for (Integer w : sets[j - i]) {
                                if (query(v, w)) {
                                    ret(w, v);
                                    return;
                                }
                            }
                        }
                    }
                }
                for (List<Integer> set : sets) {
                    if (set.size() > 1) {
                        ret(set.get(0), set.get(1));
                        return;
                    }
                }
                ret(-1, -1);
            }
        }

        public void ret(int a, int b) {
            out.println("! " + (a + 1) + " " + (b + 1));
            out.flush();
        }

        public boolean query(int a, int b) {
            out.println("? " + (a + 1) + " " + (b + 1));
            out.flush();
            return "Yes".equals(in.next());
        }
    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }
    }
}
