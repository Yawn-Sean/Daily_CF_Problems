public class cf822c_WindLY {
    // 分别对原数组进行左端点和右端点进行排序，遍历左端点排序数组，用另一指针遍历右端点+哈希表存储，类似滑动窗口思想
    // https://codeforces.com/contest/822/submission/255177199
    public static void main(String[] args) throws IOException {
        int[] in = na();
        int n = in[0], x = in[1];
        Map<Integer, Integer> map = new HashMap<>();
        int min = Integer.MAX_VALUE;
        int[][] a = new int[n][3];
        int[][] b = new int[n][3];
        for (int i = 0; i < n; i++) {
            a[i] = na();
            b[i] = a[i].clone();
        }
        Arrays.sort(a, (i, j) -> i[0] == j[0] ? i[1] - j[1] : i[0] - j[0]);
        Arrays.sort(b, (i, j) -> i[1] == j[1] ? i[0] - j[0] : i[1] - j[1]);
        int left = 0, right = 0;
        while (right < n) {
            int l = a[right][0], r = a[right][1], c = a[right][2];
            while (b[left][1] < l) {
                int len = b[left][1] - b[left][0] + 1;
                if (b[left][2] < map.getOrDefault(len, Integer.MAX_VALUE)) map.put(len, b[left][2]);
                left++;
            }
            int ll = r - l + 1;
            if (map.containsKey(x - ll)) min = Math.min(min, map.get(x - ll) + c);
            right++;
        }
        out.println(min == Integer.MAX_VALUE ? -1 : min);
        out.flush();
    }
}