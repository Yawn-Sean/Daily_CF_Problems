public class cfsubmit {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
        int n = sc.nextInt();
        long[] arr = new long[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextLong();
        }
        arr[0] = 1;
        arr[n - 1] = 1;
        for (int i = 1; i < n - 1; i++) {
            arr[i] = Math.min(arr[i - 1] + 1,arr[i]);
        }
        for (int i = n - 2; i >= 1; i--) {
            arr[i] = Math.min(arr[i + 1] + 1,arr[i]);
        }
        Long ans = 0L;
        for (int i = 0; i < n; i++) {
            ans = Math.max(ans,arr[i]);
        }
        out.print(ans);
        sc.close();
        out.close();
    }
}
