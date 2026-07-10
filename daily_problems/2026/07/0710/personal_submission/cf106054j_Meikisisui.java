
        void solve() {
            int t = io.nextInt();
            List<Integer> l1 = new ArrayList<>(), l2 = new ArrayList<>();
            List<List<Integer>> list1 = new ArrayList<>(), list2 = new ArrayList<>();
            for (int i = 0; i < t; i++) {
                int n = io.nextInt();
                List<Integer> tmp = new ArrayList<>();
                for (int j = 0; j < n; j++) {
                    int x = io.nextInt();
                    tmp.add(x);
                    l1.add(x);
                }
                list1.add(tmp);
            }
            for (int i = 0; i < t; i++) {
                int n = io.nextInt();
                List<Integer> tmp = new ArrayList<>();
                for (int j = 0; j < n; j++) {
                    int x = io.nextInt();
                    tmp.add(x);
                    l2.add(x);
                }
                list2.add(tmp);
            }
            Collections.sort(l1);
            Collections.sort(l2);
            if (!l1.equals(l2))
                io.println("N");
            else if (t != 2)
                io.println("S");
            else {
                List<Integer> l3 = new ArrayList<>(), l4 = new ArrayList<>();
                l3.addAll(list1.get(0));
                List<Integer> tmp1 = list1.get(1), tmp2 = list2.get(1);
                Collections.reverse(tmp1);
                l3.addAll(tmp1);
                l4.addAll(list2.get(0));
                Collections.reverse(tmp2);
                l4.addAll(tmp2);
                if (l3.equals(l4))
                    io.println("S");
                else
                    io.println("N");
            }
        }
