package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"slices"
)

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()
	for true {
		var n int
		fmt.Fscan(in, &n)
		if n == 0 {
			return
		}
		arr := make([][2]int, n)
		for i := range n {
			fmt.Fscan(in, &arr[i][0], &arr[i][1])
		}
		cntB, Bmin := 0, math.MaxInt
		list := make([]int, 0)
		for i := range n {
			v := arr[i][0]
			cnt := arr[i][1]
			if cnt > 0 {
				cntB += cnt
				Bmin = min(Bmin, v)
			}
			list = append(list, v)
		}
		ans := int64(0)
		cnt := n
		if cntB > 0 {
			ans = int64(Bmin)
			cnt -= cntB + 1
		}
		slices.Sort(list)
		for i := 0; cnt > 0; i++ {
			if list[i] != Bmin {
				ans += int64(list[i])
				cnt--
			} else {
				Bmin = -1
			}
		}
		fmt.Fprintln(out, ans)
	}
}
