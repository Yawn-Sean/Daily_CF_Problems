# Submission link: https://codeforces.com/contest/1209/submission/264266842
class Solution {
    public int solve(int[] a) {
        Map<Integer, int[]> map = new HashMap<>();
        for (int i = 0; i < a.length; i++) {
            int[] arr = map.get(a[i]);
            if (arr == null) {
                map.put(a[i], new int[]{i, i});
            } else {
                arr[1] = i;
            }
        }
        List<int[]> list = new ArrayList<>(map.values());
        list.sort(Comparator.comparingInt(o -> o[0]));
        int ans = 0;
        int l = 0;
        int r = 0;
        for (int[] arr : list) {
            if (arr[0] <= r) {
                r = Math.max(r, arr[1]);
                continue;
            }
            ans += getCnt(a, l, r);
            l = arr[0];
            r = arr[1];
        }
        ans += getCnt(a, l, r);
        return ans;
    }

    private int getCnt(int[] a, int l, int r) {
        Map<Integer, Integer> cnt = new HashMap<>();
        for (int i = l; i <= r; i++) {
            cnt.put(a[i], cnt.getOrDefault(a[i], 0) + 1);
        }
        return r - l + 1 - cnt.values().stream().max(Comparator.comparingInt(o -> o)).orElse(0);
    }
}
