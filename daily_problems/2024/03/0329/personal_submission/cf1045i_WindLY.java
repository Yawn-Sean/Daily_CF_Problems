public class cf1045i_WindLY {
    // 哈希表，用一个int存储字符串各个字母奇偶信息
    // 对于每个字符串，找所有字母奇偶性相同和有一个字母奇偶不同的字符串
    // https://codeforces.com/contest/1045/submission/253876080
    public static void main(String[] args) throws IOException {
        int n = ni();
        long cnt = 0;
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            String s = sc.readLine();
            int h = hash(s);
            cnt += find(map, h);
            map.merge(h, 1, Integer::sum);
        }
        out.println(cnt);
        out.flush();
    }
    static int find(Map<Integer, Integer> map, int h) {
        int ans = 0;
        ans += map.getOrDefault(h, 0);
        for (int i = 0; i < 26; i++) {
            ans += map.getOrDefault(h ^ 1 << i, 0);
        }
        return ans;
    }
    static int hash(String s) {
        int[] a = new int[26];
        for (char c: s.toCharArray()) {
            a[c - 'a'] ^= 1;
        }
        int h = 0;
        for (int i = 0; i < 26; i++) {
            h = h << 1 | a[i];
        }
        return h;
    }
}
