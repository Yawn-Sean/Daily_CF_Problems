import java.util.*;

public class cf926D {
    private static int INF = Integer.MAX_VALUE;

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        PriorityQueue<Long[]> pq = new PriorityQueue<>((a, b) -> {
            if (Objects.equals(a[0], b[0])) {
                return Long.compare(a[1], b[1]);
            } else {
                return Long.compare(a[0], b[0]);
            }
        });
        for (int i = 0; i < n; i++) {
            long num = scan.nextLong();
            pq.offer(new Long[]{num, (long) i});
        }
        List<Long[]> ans = new ArrayList<>();
        while (!pq.isEmpty()) {
            var cur1 = pq.poll();
            if (pq.isEmpty() || !Objects.equals(pq.peek()[0], cur1[0])) {
                ans.add(cur1);
            } else {
                var cur2 = pq.poll();
                cur2[0] *= 2;
                pq.offer(cur2);
            }
        }
        Collections.sort(ans, (a, b) -> Long.compare(a[1], b[1]));
        System.out.println(ans.size());
        for (var as : ans) {
            System.out.print(as[0] + " ");
        }
    }
}
