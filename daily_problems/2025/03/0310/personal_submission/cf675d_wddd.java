import java.io.*;
import java.util.*;

public class BruteForce1 {

    FastReader is;
    PrintWriter out;
//    String INPUT = "10\n" +
//            "991309218 517452607 870021923 978357992 136426010 10601767 302627526 883615372 163475700 600546765\n";
    String INPUT = "5\n" +
        "4 2 3 1 6\n";
//    String INPUT = "5\n" +
//            "976448812 982038278 986557527 969485871 997912564\n";

    private static final boolean oj = System.getProperty("ONLINE_JUDGE") != null;

    public static void main(String[] args) throws Exception {
        new BruteForce1().run();
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
        int[] a = is.na(n);

        Node root = new Node(a[0]);
        for (int i = 1; i < n; i++) {
            Node curr = new Node(a[i]);
            Node parent = root.add(curr);
            out.println(parent.val);
        }
    }

    class Node {
        int val;
        List<Node> left;
        List<Node> right;

        public Node(int val) {
            this.val = val;
            this.left = new ArrayList<>();
            this.right = new ArrayList<>();
        }

        public Node add(Node node) {
            if (node.val < val) {
                if (left.isEmpty()) {
                    left.add(node);
                    return this;
                } else {
                    int ind = Collections.binarySearch(left, node, Comparator.comparingInt(n -> -n.val));
                    ind = ~ind;
                    if (ind == left.size()) {
                        left.add(node);
                        return left.get(left.size() - 2);
                    } else {
                        if (left.get(ind).right.isEmpty()) {
                            left.get(ind).right.add(node);
                            return left.get(ind);
                        } else {
                            return left.get(ind).right.get(0).add(node);
                        }
                    }
                }
            } else {
                if (right.isEmpty()) {
                    right.add(node);
                    return this;
                } else {
                    int ind = Collections.binarySearch(right, node, Comparator.comparingInt(n -> n.val));
                    ind = ~ind;
                    if (ind == right.size()) {
                        right.add(node);
                        return right.get(right.size() - 2);
                    } else {
                        if (right.get(ind).left.isEmpty()) {
                            right.get(ind).left.add(node);
                            return right.get(ind);
                        } else {
                            return right.get(ind).left.get(0).add(node);
                        }
                    }
                }
            }
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
