  public static void solve(){
      int S = sc.nextInt();
      List<int[]> pairs = new ArrayList<>();
      pairs.add(new int[]{0, 500});
      pairs.add(new int[]{1, 500});
      pairs.add(new int[]{2, 499});
      pairs.add(new int[]{2, 498});
      pairs.add(new int[]{1, 501-S});
      pairs.add(new int[]{0, 499});

      for (int[] pair : pairs) {
          out.println(pair[0] + " " + pair[1]);
      }
  }
