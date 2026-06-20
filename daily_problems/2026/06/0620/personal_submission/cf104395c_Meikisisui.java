void solve() {
            int n = io.nextInt();
            int k = io.nextInt();
            String s = io.nextString();
            StringBuilder sb = new StringBuilder();
            String res = "a";
            for (int i = 0; i < 2; i++) {
                List<String> tmp = new ArrayList<>();
                if (i == 1)
                    tmp.add(s.substring(0, 1));
                for (int j = i; j < n; j += 2) {
                    int len = Math.min(2, n - j);
                    tmp.add(s.substring(j, j + len));
                }
                Collections.sort(tmp);
                sb = new StringBuilder();
                for (String x : tmp) {
                    for (int kk = 0; kk < k; kk++)
                        sb.append(x);
                }
                String ans = sb.toString();
                if (ans.compareTo(res) < 0)
                    res = ans;
            }
            io.println(new String(res));
        }
