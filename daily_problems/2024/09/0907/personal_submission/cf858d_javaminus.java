public class Main {
    private static void solve() throws IOException {
        n = sc.nextInt();
        HashMap<Pair<Integer, Integer>, Integer> map = new HashMap<>(); // p<子字符串， 长度>，id
        ss = new String[n];
        for (int i = 0; i < n; i++) {
            ss[i] = sc.next();
            for (int j = 0; j < 9; j++) {
                int cur = 0;
                for (int k = j; k < 9; k++) {
                    cur = cur * 10 + ss[i].charAt(k) - '0';
                    Pair<Integer, Integer> pair = new Pair<>(cur, k - j);
                    if (!map.containsKey(pair)) {
                        map.put(pair, i);
                    } else if (map.get(pair) != i) {
                        map.put(pair, -1);
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            int str_len = 10, start = 0;
            for (int j = 0; j < 9; j++) {
                int cur = 0;
                for (int k = j; k < 9; k++) {
                    cur = cur * 10 + ss[i].charAt(k) - '0';
                    if (map.getOrDefault(new Pair<>(cur, k - j), -1) == i) {
                        if (k - j < str_len) {
                            str_len = k - j;
                            start = j;
                        }
                    }
                }
            }
            sc.println(ss[i].substring(start, start + str_len + 1));
        }
    }
}
