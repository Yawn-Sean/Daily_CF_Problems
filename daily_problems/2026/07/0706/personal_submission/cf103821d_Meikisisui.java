        void solve() {
            int n = io.nextInt();
            n++;
            int tmp = (int) Math.sqrt(n);
            if (tmp * tmp != n)
                io.println(-1);
            else {
                io.println(tmp - 1);
                for (int i = 1; i < tmp; i++)
                    io.print(i + " ");
                io.println();
            }
        }
