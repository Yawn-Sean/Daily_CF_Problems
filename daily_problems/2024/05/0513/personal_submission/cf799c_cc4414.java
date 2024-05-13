# Submission link: https://codeforces.com/contest/799/submission/260729311
class Solution {
    public int solve(int c, int d, List<int[]> list1, List<int[]> list2) {
        list1.sort((o1, o2) -> o2[0] - o1[0]);
        list2.sort((o1, o2) -> o2[0] - o1[0]);
        int max = 0;
        if (!list1.isEmpty() && !list2.isEmpty()) {
            max = Math.max(max, list1.get(0)[0] + list2.get(0)[0]);
        }
        max = Math.max(max, calcMax(c, list1));
        max = Math.max(max, calcMax(d, list2));
        return max;
    }

    private int calcMax(int c, List<int[]> list) {
        if (list.size() < 2) {
            return 0;
        }
        int max = 0;
        list.sort(Comparator.comparingInt(o -> o[1]));
        ArrayDeque<int[]> deque = new ArrayDeque<>();
        for (int[] arr : list) {
            while (!deque.isEmpty() && deque.peekLast()[1] + arr[1] > c) {
                deque.removeLast();
            }
            if (deque.isEmpty()) {
                deque.addLast(arr);
                continue;
            }
            int b = deque.peekLast()[0];
            max = Math.max(max, b + arr[0]);
            if (arr[0] > b) {
                deque.addLast(arr);
            }
        }
        return max;
    }
}
