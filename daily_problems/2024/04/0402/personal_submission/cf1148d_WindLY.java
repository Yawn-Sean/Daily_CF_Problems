public class cf1148d_WindLY {
    // 分成两组，pair降序的升序排序，pair升序的进行降序排序
    // https://codeforces.com/contest/1148/submission/254678988
    public static void main(String[] args) throws IOException {
        int n = ni();
        List<int[]> a = new ArrayList<>(), b = new ArrayList<>(); // id x1 x2
        for (int i = 0; i < n; i++) {
            int[] in = na();
            int[] ar = new int[3];
            ar[0] = i + 1;
            ar[1] = in[0];
            ar[2] = in[1];
            if (in[0] > in[1]) a.add(ar); // down
            else b.add(ar); // up
        }
        if (a.size() > b.size()) {
            out.println(a.size());
            Collections.sort(a, (i, j) -> i[1] - j[1]); // down
            for (int[] ar: a) out.print(ar[0] + " ");
        } else {
            out.println(b.size());
            Collections.sort(b, (i, j) -> j[1] - i[1]); // up
            for (int[] ar: b) out.print(ar[0] + " ");
        }
        out.flush();
    }
}
