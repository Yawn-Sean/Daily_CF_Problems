private static void solve() throws IOException {
        String a = sc.next(), b = sc.next(), c = sc.next();
        int[] cntA = new int[26], cntB = new int[26], cntC = new int[26];
        for (int i = 0; i < a.length(); i++) {
            cntA[a.charAt(i) - 'a']++;
        }
        for (int i = 0; i < b.length(); i++) {
            cntB[b.charAt(i) - 'a']++;
        }
        for (int i = 0; i < c.length(); i++) {
            cntC[c.charAt(i) - 'a']++;
        }
        int x = 0, y = 0;
        boolean fl = true;
        for (int i = 0; i * b.length() < a.length(); i++) {
            int cnt = a.length();
            for (int j = 0; j < 26; j++) {
                if (cntA[j] < cntB[j] * i) {
                    fl = false;
                    break;
                }
                if (cntC[j] > 0) {
                    cnt = Math.min(cnt, (cntA[j] - cntB[j] * i) / cntC[j]);
                }
            }
            if (!fl) { // 剪枝
                break;
            }
            if (i + cnt > x + y) {
                x = i;
                y = cnt;
            }
        }
        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < x; i++) {
            ans.append(b);
        }
        for (int i = 0; i < y; i++) {
            ans.append(c);
        }
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < cntA[i] - cntB[i] * x - cntC[i] * y; j++) {
                ans.append((char) ('a' + i));
            }
        }
        sc.println(String.valueOf(ans));
    }
