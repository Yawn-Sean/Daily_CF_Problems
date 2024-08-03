public class cf765d_Leoncn {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        int[] F = new int[N];
        for (int n=0; n<N; n++) {
            F[n] = in.nextInt()-1;
        }
        boolean possible = true;
        int M = 0;
        int[] g = new int[N];
        List<Integer> h = new ArrayList<>();
        for (int n=0; n<N; n++) {
            int fn = F[n];
            if (F[fn] != fn) {
                possible = false;
                break;
            }
            if (g[fn] == 0) {
                M++;
                g[fn] = M;
                h.add(fn+1);
            }
            g[n] = g[fn];
        }
        if (possible) {
            StringBuilder out = new StringBuilder();
            out.append(M).append('\n');
            for (int gx : g) {
                out.append(gx).append(' ');
            }
            out.append('\n');
            for (int hx : h) {
                out.append(hx).append(' ');
            }
            System.out.println(out);
        } else {
            System.out.println("-1");
        }
    }
}
