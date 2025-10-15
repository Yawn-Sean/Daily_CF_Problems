public static void solve(){
        int n = sc.nextInt(), m = sc.nextInt();
        List<List<Integer>> lists = new ArrayList<>();
        int[] owners = new int[n+1];

        for (int i = 0; i < n+1; ++ i){
            lists.add(new ArrayList<>());
            owners[i] = -1;
        }
        for (int i = 2; i <= n; ++ i){
            for (int j = i; j <= n; j += i){
                lists.get(j).add(i);
            }
        }
        lists.get(1).add(1);

        for (int i = 0; i < m; ++ i){
            StringBuilder opt = new StringBuilder(sc.next());
            int num = sc.nextInt();

            if (opt.charAt(0) == '+'){
                int conflict = -1;
                for (Integer index : lists.get(num)) {
                    if (owners[index] != -1){
                        conflict = owners[index];
                        break;
                    }
                }
                if (conflict == -1){
                    lists.get(num).forEach(index -> owners[index] = num);
                    out.println("Success");
                } else if (num == conflict){
                    out.println("Already on");
                } else {
                    out.println("Conflict with " + conflict);
                }
            } else {
                boolean accept = true;
                for (Integer index : lists.get(num)) {
                    if (owners[index] != num){
                        accept = false;
                        break;
                    }
                }
                if (accept){
                    lists.get(num).forEach(index -> owners[index] = -1);
                    out.println("Success");
                } else {
                    out.println("Already off");
                }
            }
        }
    }
