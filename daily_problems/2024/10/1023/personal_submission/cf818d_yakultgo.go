package main

import (
	"bufio"
	"fmt"
	"os"
)

func solve(in *bufio.Reader, out *bufio.Writer) {
	var n, m int
	fmt.Fscan(in, &n, &m)
	a := make([]int, n)
	pos := make([]int, 0, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i])
		if a[i] == m {
			pos = append(pos, i)
		}
	}
	if len(pos) == 0 {
		for i := 1; i <= 1e6; i++ {
			if i != m {
				fmt.Fprintln(out, i)
				return
			}
		}
	}
	pos = append(pos, n)
	cnt := make(map[int]int)
	for i := 0; i < pos[0]; i++ {
		cnt[a[i]]++
	}
	for i := 0; i < len(pos)-1; i++ {
		for k, v := range cnt {
			if v < i+1 {
				delete(cnt, k)
			}
		}
		j := pos[i] + 1
		for ; j < pos[i+1]; j++ {
			v, ok := cnt[a[j]]
			if !ok {
				continue
			}
			if v < i {
				delete(cnt, a[j])
			} else {
				cnt[a[j]]++
			}
		}
	}
	if len(cnt) == 0 {
		fmt.Fprintln(out, -1)
		return
	}
	for k, _ := range cnt {
		fmt.Fprintln(out, k)
		return
	}
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()
	T := 1
	for t := 0; t < T; t++ {
		solve(in, out)
	}
}
