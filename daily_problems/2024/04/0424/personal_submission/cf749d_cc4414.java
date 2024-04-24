// Submission link: https://codeforces.com/contest/749/submission/257938063
class Solution {
    public int[][] solve(int[][] bids, Set<Integer>[] questions) {
        int n = bids.length;
        int q = questions.length;
        int[][] ans = new int[q][2];
        boolean[] vis = new boolean[n];
        List<Integer> list = new ArrayList<>();
        List<Integer>[] lists = new List[n];
        for (int i = 0; i < lists.length; i++) {
            lists[i] = new ArrayList<>();
        }
        for (int i = bids.length - 1; i >= 0; i--) {
            int[] bid = bids[i];
            int index = bid[0];
            lists[index].add(bid[1]);
            if (vis[index]) {
                continue;
            }
            list.add(index);
            vis[index] = true;
        }
        for (int i = 0; i < questions.length; i++) {
            Set<Integer> question = questions[i];
            int max1 = -1;
            int max2 = -1;
            for (Integer v : list) {
                if (question.contains(v)) {
                    continue;
                }
                if (max1 == -1) {
                    max1 = v;
                    continue;
                }
                max2 = v;
                break;
            }
            ans[i][0] = max1;
            if (max1 == -1) {
                continue;
            }
            if (max2 == -1) {
                ans[i][1] = lists[max1].get(lists[max1].size() - 1);
                continue;
            }
            ans[i][1] = lists[max1].get(-Collections.binarySearch(lists[max1], lists[max2].get(0), (o1, o2) -> Integer.compare(o2, o1)) - 2);
        }
        return ans;
    }
}
