public class Main{
    private static int n, k;
    
    private static void permute(List<Integer> list, int l, int r) {
        if (k == 0 || l + 1 == r) {
            return;
        }
        int mid = l + (r - l) / 2;
        k--;
        Collections.swap(list, mid, mid - 1); // 核心
        permute(list, l, mid);
        permute(list, mid, r);
    }

    private static void solve() throws IOException {
        n = sc.nextInt();
        k = sc.nextInt();
        if ((k & 1) == 0) {
            sc.println(-1);
            return;
        }
        ArrayList<Integer> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            list.add(i + 1);
        }
        k /= 2;
        permute(list, 0, n);
        if (k != 0) {
            sc.println(-1);
        }else{
            for (int x : list) {
                sc.print(x + " ");
            }
        }
    }
}
