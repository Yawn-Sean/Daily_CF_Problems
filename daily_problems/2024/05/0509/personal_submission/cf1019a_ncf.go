package main

import (
	"bufio"
	"fmt"
	"io"
	"math"
	"os"
	"sort"
)

func main() { CF1019A(os.Stdin, os.Stdout) }

func CF1019A(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n, m, p, c int
	fmt.Fscan(in, &n, &m)
	party := make([][]int, m+1)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &p, &c)
		party[p] = append(party[p], c)
	}
	for i := 2; i <= m; i++ {
		if len(party[i]) > 0 {
			sort.Ints(party[i])
		}
	}
	if len(party[1]) > (n+1)/2 {
		fmt.Fprintf(out, "0")
		return
	}
	ans := math.MaxInt
	for i := max(len(party[1]), 1); i <= (n+1)/2; i++ {
		var arr []int
		cur := 0
		count := i - len(party[1])
		for j := 2; j <= m; j++ {
			if len(party[j]) == 0 {
				continue
			}
			k := 0
			for len(party[j])-k >= i {
				cur += party[j][k]
				k += 1
				count -= 1
			}
			arr = append(arr, party[j][k:]...)
		}
		sort.Ints(arr)
		for _, e := range arr {
			if count <= 0 {
				break
			}
			cur += e
			count -= 1
		}
		ans = min(ans, cur)
	}
	fmt.Fprintf(out, "%d", ans)
}
