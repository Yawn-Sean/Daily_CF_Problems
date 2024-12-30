package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

type pair struct{ l, r int }

func solveC(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var n, q int
	fmt.Fscan(in, &n, &q)
	ps := make([]pair, q)
	for i := range ps {
		fmt.Fscan(in, &ps[i].l, &ps[i].r)
	}
	ans := 0
	// 先删除一个 painter
	for i := 0; i < q-1; i++ {
		cnt, cntone := make([]int, n+2), make([]int, n+2)
		// 统计每个 section 的出现次数
		for k := 0; k < q; k++ {
			if k != i {
				cnt[ps[k].l]++
				cnt[ps[k].r+1]--
			}
		}
		// 求前缀和，并统计出现次数为 1 的 section
		res := 0
		for j := 1; j <= n; j++ {
			cnt[j] += cnt[j-1]
			if cnt[j] == 1 {
				cntone[j] = 1
			}
			cntone[j] += cntone[j-1]
			if cnt[j] > 0 {
				res++
			}
		}
		// 删除第二个 painter
		for j := i + 1; j < q; j++ {
			// 求 [ps[j].l, ps[j].r] 区间内出现次数为 1 的 section
			one := cntone[ps[j].r] - cntone[ps[j].l-1]
			ans = max(ans, res-one)
		}
	}
	fmt.Fprintln(out, ans)
}

func main() {
	solveC(os.Stdin, os.Stdout)
}
