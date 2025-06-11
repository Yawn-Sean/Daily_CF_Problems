import java.util.*;

public class Main {
    static class Node implements Comparable<Node> {
        int r, id;

        public Node(int r, int id) {
            this.r = r;
            this.id = id;
        }

        @Override
        public int compareTo(Node other) {
            if (this.r == other.r) {
                return Integer.compare(this.id, other.id);
            }
            return Integer.compare(this.r, other.r);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = 200005;
        Node[] a = new Node[N];
        int n, k, tot = 0;
        TreeSet<Node> s = new TreeSet<>();
        List<Node>[] v = new ArrayList[N];

        for (int i = 0; i < N; i++) {
            v[i] = new ArrayList<>();
        }

        n = scanner.nextInt();
        k = scanner.nextInt();

        for (int i = 1; i <= n; i++) {
            int a1 = scanner.nextInt();
            int b1 = scanner.nextInt();
            Node c = new Node(b1, i);
            v[a1].add(c);
        }

        for (int i = 1; i < N; i++) {
            while (!s.isEmpty() && s.first().r < i) {
                s.remove(s.first());
            }

            for (Node node : v[i]) {
                s.add(node);
            }

            while (s.size() > k) {
                a[++tot] = s.last();
                s.remove(s.last());
            }
        }

        System.out.println(tot);
        for (int i = 1; i <= tot; i++) {
            System.out.print(a[i].id + " ");
        }
    }
}
