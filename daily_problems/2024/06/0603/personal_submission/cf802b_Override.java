
import java.util.*;
public class b802 {
    static int k, n;
    static int ans, tot;
    static int[] succ = new int[400010];
    static boolean[] b = new boolean[400010];
    static Pair[] a = new Pair[400010];
    static PriorityQueue<BOOK> q = new PriorityQueue<>(Collections.reverseOrder());

    static class Pair {
        int first, second;
        Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }

    static class BOOK implements Comparable<BOOK> {
        int num, nxt;
        BOOK(int num, int nxt) {
            this.num = num;
            this.nxt = nxt;
        }

        @Override
        public int compareTo(BOOK other) {
            return Integer.compare(this.nxt, other.nxt);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        k = sc.nextInt();

        for (int i = 1; i <= n; i++) {
            a[i] = new Pair(sc.nextInt(), 0);
        }

        for (int i = n; i >= 1; i--) {
            if (succ[a[i].first] == 0) {
                a[i].second = Integer.MAX_VALUE; // 0x3f3f3f3f in C++
            } else {
                a[i].second = succ[a[i].first];
            }
            succ[a[i].first] = i;
        }

        for (int i = 1; i <= n; i++) {
            if (!b[a[i].first]) {
                ans++;
                tot++;
                if (tot > k) {
                    tot--;
                    BOOK tp = q.poll();
                    b[a[tp.num].first] = false;
                }
                b[a[i].first] = true;
            }
            q.add(new BOOK(i, a[i].second));
        }

        System.out.println(ans);
        sc.close();
    }
}
