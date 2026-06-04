void solve() {

            String s = io.nextString();
            char[] ch = s.toCharArray();
            boolean isP = false, isC = false;
            for (int i = 0; i < 26; i++) {
                char c = ch[i];
                if (c == 'p') {
                    isP = true;
                    if (isC) {
                        io.println("NO");
                        return;
                    }
                } else if (c == 'c')
                    isC = true;
                else if (c == 'z') {
                    if (isP) {
                        io.println("NO");
                        return;
                    }
                } else if (c == 'e') {
                    if (isC) {
                        io.println("NO");
                        return;
                    }
                }
            }
            io.println("YES");

        }
