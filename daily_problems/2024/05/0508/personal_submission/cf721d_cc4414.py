# Submission link: https://codeforces.com/contest/721/submission/259975452
class Solution {
    public long[] solve(long[] a, int k, int x) {
        PriorityQueue<long[]> queue1 = new PriorityQueue<>((o1, o2) -> Long.compare(o1[0], o2[0]));
        PriorityQueue<long[]> queue2 = new PriorityQueue<>((o1, o2) -> Long.compare(o2[0], o1[0]));
        for (int i = 0; i < a.length; i++) {
            if (a[i] >= 0) {
                queue1.add(new long[]{a[i], i});
            } else {
                queue2.add(new long[]{a[i], i});
            }
        }
        if (queue2.size() % 2 == 0) {
            if (queue2.isEmpty() || (!queue1.isEmpty() && (queue1.peek()[0] < -queue2.peek()[0]))) {
                long[] remove = queue1.remove();
                long t = remove[0] / x + 1;
                if (t >= k) {
                    a[(int) remove[1]] -= (long) k * x;
                    return a;
                }
                remove[0] -= t * x;
                k -= t;
                queue2.add(remove);
            } else {
                long[] remove = queue2.remove();
                long t = -remove[0] / x + 1;
                if (t >= k) {
                    a[(int) remove[1]] += (long) k * x;
                    return a;
                }
                remove[0] += t * x;
                k -= t;
                queue1.add(remove);
            }
        }
        for (int i = 0; i < k; i++) {
            if (queue2.isEmpty() || (!queue1.isEmpty() && (queue1.peek()[0] < -queue2.peek()[0]))) {
                long[] remove = queue1.remove();
                remove[0] += x;
                queue1.add(remove);
            } else {
                long[] remove = queue2.remove();
                remove[0] -= x;
                queue2.add(remove);
            }
        }
        for (long[] arr : queue1) {
            a[(int) arr[1]] = arr[0];
        }
        for (long[] arr : queue2) {
            a[(int) arr[1]] = arr[0];
        }
        return a;
    }
}
