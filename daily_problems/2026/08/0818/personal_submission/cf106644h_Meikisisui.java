
        void solve() {
            int n = io.nextInt();
            String s = io.nextString();
            if ((n & 1) == 1) {
                if ((s.charAt(n / 2 - 1) == 'B' && s.charAt(n / 2) == 'B')
                        || (s.charAt(n / 2 + 1) == 'B' && s.charAt(n / 2) == 'B'))
                    io.println("Doludu");
                else
                    io.println("DoIudu");
            } else {
                if (s.charAt(n / 2) == 'B' || s.charAt(n / 2 - 1) == 'B')
                    io.println("Doludu");
                else
                    io.println("DoIudu");
            }
        }
