import java.util.*;
public class cf416c_yuxue_r {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        int[] cs = new int[n];
        int[] ps = new int[n];

        for (int i = 0; i < n; i++) {
            cs[i] = scanner.nextInt();
            ps[i] = scanner.nextInt();
        }

        int k = scanner.nextInt();
        int[] rs = new int[k];
        for (int i = 0; i < k; i++) {
            rs[i] = scanner.nextInt();
        }

        Integer[] stN = new Integer[n];
        Integer[] stK = new Integer[k];

        for (int i = 0; i < n; i++) {
            stN[i] = i;
        }
        for (int i = 0; i < k; i++) {
            stK[i] = i;
        }

        Arrays.sort(stN, Comparator.comparingInt(i -> cs[i]));
        Arrays.sort(stK, Comparator.comparingInt(i -> rs[i]));

        PriorityQueue<Pair> pq = new PriorityQueue<>((a, b) -> b.value - a.value);
        int[] ans = new int[n];
        Arrays.fill(ans, -1);
        int tot = 0, cnt = 0, pt = 0;

        for (int i : stK) {
            while (pt < n && cs[stN[pt]] <= rs[i]) {
                pq.add(new Pair(ps[stN[pt]], stN[pt]));
                pt++;
            }

            if (!pq.isEmpty()) {
                Pair top = pq.poll();
                tot += top.value;
                cnt++;
                ans[top.index] = i;
            }
        }

        System.out.println(cnt + " " + tot);

        for (int i = 0; i < n; i++) {
            if (ans[i] != -1) {
                System.out.println((i + 1) + " " + (ans[i] + 1));
            }
        }
    }

    static class Pair {
        int value;
        int index;

        Pair(int value, int index) {
            this.value = value;
            this.index = index;
        }
    }
}
