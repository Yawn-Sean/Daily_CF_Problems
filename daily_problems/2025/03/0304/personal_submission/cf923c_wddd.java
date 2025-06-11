import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class C_Perfect_Security {

    FastReader is;
    PrintWriter out;
    String INPUT = """
    3
8 4 13
17 2 7
    """;

    private static final boolean oj = System.getProperty("ONLINE_JUDGE") != null;

    public static void main(String[] args) throws Exception {
        new C_Perfect_Security().run();
    }

    void run() throws Exception {
        is = oj ? new FastReader(System.in) : new FastReader(new ByteArrayInputStream(INPUT.getBytes()));
        out = new PrintWriter(System.out);

        long s = System.currentTimeMillis();
        solve();
        out.flush();
        objTr(System.currentTimeMillis() - s + "ms");
        out.close();
    }

    void solve() {
        int n = is.ni();
        int[] as = is.na(n);
        int[] ps = is.na(n);
        
        BinaryTrie bt = new BinaryTrie();
        for (int i = 0; i < n; i++) {
            bt.put(ps[i]);
        }

        int[] res = new int[n];
        for (int i = 0; i < n; i++) {
            int a = as[i];
            int pair = bt.getMinXorPair(a);
            res[i] = pair ^ a;
            bt.delete(pair);
        }
        for (int r : res) {
            out.print(r + " ");
        }
        out.println();
    }

    public class BinaryTrie {

        class Node {
            private Node[] next = new Node[2];
            private int freq = 0;
            public Node() {}
        }
    
        private final Node root;
        private final int maxBits;
    
        public BinaryTrie() {
            this(30);
        }
    
        public BinaryTrie(int maxBits) {
            this.root = new Node();
            this.maxBits = maxBits;
        }
    
        public void put(int num) {
            Node node = root;
    
            for (int i = maxBits; i >= 0; i--) {
                int next = ind(num, i);
                if (node.next[next] == null) {
                    node.next[next] = new Node();
                }
                node = node.next[next];
                node.freq++;
            }
        }
    
        public void delete(int num) {
            Node node = root;
            for (int i = maxBits; i >= 0; i--) {
                node = node.next[ind(num, i)];
                node.freq--;
            }
        }
    
        public int getMinXorPair(int num) {
            int pair = 0;
            Node node = root;
            for (int i = maxBits; i >= 0; i--) {
                int next = ind(num, i);
                if (next == 1) {
                    if (node.next[1] != null && node.next[1].freq > 0) {
                        pair |= (1 << i);
                        node = node.next[1];
                    } else if (node.next[0] != null && node.next[0].freq > 0) {
                        node = node.next[0];
                    } else {
                        return pair;
                    }
                } else {
                    if (node.next[0] != null && node.next[0].freq > 0) {
                        node = node.next[0];
                    } else if (node.next[1] != null && node.next[1].freq > 0) {
                        pair |= (1 << i);
                        node = node.next[1];
                    } else {
                        return pair;
                    }
                }
            }
            return pair;
        }
    
        private int ind(int num, int bit) {
            return (num >> bit) & 1;
        }
    
    }

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader(InputStream is) {
            br = new BufferedReader(new InputStreamReader(is));
        }

        String ns() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return st.nextToken();
        }

        int ni() {
            return Integer.parseInt(ns());
        }

        int[] na(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = ni();
            }
            return a;
        }
    }

    private void objTr(Object... o) {
        if (!oj) {
            System.out.println(Arrays.deepToString(o));
        }
    }

}
