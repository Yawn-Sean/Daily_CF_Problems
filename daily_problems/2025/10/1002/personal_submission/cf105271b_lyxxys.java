public class Main {
    public static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
    static InputReader sc = new InputReader();

    public static Character ask(int index, int value){
        out.println("? " + index + " " + value);
        out.flush();
        String res = sc.nextLine();
        return res.charAt(0);
    }
    public static void answer(List<Integer> lists){
        out.print('!');
        lists.forEach(ans -> {
            out.print(" " + ans);
        });
        out.println();
        out.flush();
    }
    public static void main(String[] args) {
        int n = sc.nextInt();

        List<Integer> ans = new ArrayList<>();
        int index = 1, value = 1;
        while (index <= n){
            while (ask(index, value) != '='){
                value += 1;
            }
            ans.add(value);
            index += 1;
        }

        answer(ans);

        out.close();
    }

    public static class InputReader {
        private StringTokenizer st;
        private BufferedReader bf;  // 字符缓冲流

        public InputReader(){
            bf = new BufferedReader(new InputStreamReader(System.in));
            st = null;
        }

        public String next(){
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(bf.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return st.nextToken();
        }
        public String nextLine() {
            try {
                return bf.readLine();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        public int nextInt() {
            return Integer.parseInt(next());
        }
    }
}
