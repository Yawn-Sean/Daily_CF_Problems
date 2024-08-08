public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n, a, b, k;
        n = sc.nextInt();
        a = sc.nextInt();
        b = sc.nextInt();
        k = sc.nextInt();
        String S = sc.next();
        char[] s = S.toCharArray();
        PriorityQueue<Integer[]> h = new PriorityQueue<>((Integer[] i, Integer[] j) -> Integer.compare(j[0], i[0]));

        for (int i = 0; i < n;) {
            if (s[i] == '0') {
                int st = i++;
                while (i < n && s[i] == '0') {
                    i++;
                }
                h.add(new Integer[]{i - st, st});
            } else {
                i++;
            }
        }
        List<Integer> ans = new ArrayList<>();
        while (a > 1 && !h.isEmpty()) {
            Integer[] v = h.poll();
            int x = v[0], y = v[1];
            x = Math.max(0, x - b);
            a--;
            if (x > 0) {
                h.add(new Integer[]{x, y});
            }
        }
        while (!h.isEmpty()) {
            Integer[] v = h.poll();
            int x = v[0], y = v[1] - 1 + b;
            int c = x / b;
            while (c-- > 0) {
                ans.add(y);
                y += b;
            }
        }
        System.out.println(ans.size());
        for (int i = 0; i < ans.size(); i++) {
            System.out.printf("%d ", ans.get(i) + 1);
        }
        sc.close();
    }
}
