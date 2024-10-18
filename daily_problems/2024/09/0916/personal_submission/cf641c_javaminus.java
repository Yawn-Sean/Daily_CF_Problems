public class Main{
    private static void solve() throws IOException {
        int n = sc.nextInt(), q = sc.nextInt();
        int oddMove = 0, evenMove = 0, swap = 0;
        while (q-- > 0) {
            int t = sc.nextInt();
            if (t == 1) {
                int x = sc.nextInt() % n;
                oddMove += x;
                evenMove += x;
                swap ^= (x & 1); // 如果移动距离是奇数，则swap变化
            }else{
                if (swap == 1) {
                    evenMove++;
                    oddMove--;
                } else {
                    evenMove--;
                    oddMove++;
                }
                swap ^= 1;
            }
            oddMove %= n;
            evenMove %= n;
        }
        int[] ans = new int[n];
        for (int i = 0; i < n; i++) {
            if ((i & 1) == 1) {
                ans[(i + evenMove + n) % n] = i + 1;
            }else{
                ans[(i + oddMove + n) % n] = i + 1;
            }
        }
        for (int x : ans) {
            sc.print(x + " ");
        }
    }
}
