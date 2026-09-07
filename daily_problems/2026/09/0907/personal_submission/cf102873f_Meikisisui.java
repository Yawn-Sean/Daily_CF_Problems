
        void solve() {
            int n = io.nextInt();
            if (n % 4 == 2)
                io.println("Alice");
            else if (n % 4 == 0)
                io.println("Draw");
            else
                io.println("Bob");
        }
