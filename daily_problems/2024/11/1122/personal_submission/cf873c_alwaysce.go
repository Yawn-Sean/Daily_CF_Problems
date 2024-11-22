package main

import (
	"bufio"
	"fmt"
	"io"
)

func cf873C(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	/*

	 */
	var n, m, k int
	fmt.Fscan(in, &n, &m, &k)
	grid := make([][]int, n)
	for i := 0; i < n; i++ {
		grid[i] = make([]int, m)
		for j := 0; j < m; j++ {
			fmt.Fscan(in, &grid[i][j])
		}

	}
	ans, cnt := 0, 0
	pre := make([]int, n+1)
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			pre[j+1] = pre[j] + grid[j][i]
		}

		tmp := 0
		pick_idx := 0
		for j := 0; j < n; j++ {
			if grid[j][i] == 1 {
				cons := pre[min(j+k, n)] - pre[j]
				if cons > tmp {
					tmp = cons
					pick_idx = pre[j]
				}
			}
		}

		ans += tmp
		cnt += pick_idx
	}
	fmt.Fprintln(out, ans, cnt)
}

//func main() {
//	cf873C(bufio.NewReader(os.Stdin), os.Stdout)
//}
