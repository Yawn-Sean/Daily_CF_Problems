//! core logic only
//! submission: https://codeforces.com/problemset/submission/353/315720547
const MULTIPLE_TEST: bool = false;

fn solver(n: usize, scanner: &mut Scanner) -> impl Printable {
    let mut count = [0; 100];
    let cubes: Vec<usize> = scanner.iter(2 * n).collect();
    cubes.iter().for_each(|&x| count[x] += 1);
    let mut indice: Vec<_> = (0..2 * n).collect();
    indice.sort_unstable_by_key(|&i| (count[cubes[i]], cubes[i]));
    let mut in_heap = [[false; 100]; 2];
    let mut heap_cnt = [0; 2];
    let mut division = vec![0; 2 * n];

    let mut g = 0;
    for i in indice {
        division[i] = g + 1;
        let x = cubes[i];
        if !in_heap[g][x] {
            in_heap[g][x] = true;
            heap_cnt[g] += 1;
        }
        g ^= 1;
    }
    (heap_cnt[0] * heap_cnt[1])
        .cr()
        .then(Sep::<_, ' '>(division))
}
