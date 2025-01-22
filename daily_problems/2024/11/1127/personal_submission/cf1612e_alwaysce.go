package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"sort"
)

type pair struct {
	first, second int
}

func check(pa, pb pair) bool {
	return pa.first*pb.second >= pb.first*pa.second
}

func cf1612E(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	/*
		每个人能够接受消息的上限很小 k<=20
		When t is large, adding new elements is not profitable.
		所以假设已经选了很多个消息的情况下
		第i个人需要被阅读的消息被选中的概率也不会很大(某一条消息)
		感觉是：t越大 越不应该增加新的消息

		假设我们知道要取到t个消息了
		Fi = 0/1/(k/t)
		贪心的选前t大就行

		但是t=2e5
		这原来就是k的作用了
	*/

	var n int
	fmt.Fscan(in, &n)

	m, k := make([]int, n), make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &m[i], &k[i])
	}

	T := 20
	ans_f := pair{0, 1}
	ans_pinned := make([]int, 0)

	for i := 1; i <= T; i++ {
		score := make([]int, 2_000_05)
		for j := 0; j < n; j++ {
			score[m[j]] += min(i, k[j])
		}

		tmp := make([]pair, 0)
		for j := 1; j < len(score); j++ {
			tmp = append(tmp, pair{score[j], j})
		}

		// 取前i项
		sort.Slice(tmp, func(i, j int) bool {
			return tmp[i].first > tmp[j].first
		})

		cur_f := pair{0, i}
		cur_pinned := make([]int, 0)
		for j := 0; j < i; j++ {
			cur_f.first += tmp[j].first
			cur_pinned = append(cur_pinned, tmp[j].second)
		}

		if check(cur_f, ans_f) {
			ans_f = cur_f
			ans_pinned = cur_pinned
		}
	}
	fmt.Fprintln(out, len(ans_pinned))
	for _, v := range ans_pinned {
		fmt.Fprintf(out, "%d ", v)
	}
}

// func main() {
// 	cf1612E(bufio.NewReader(os.Stdin), os.Stdout)
// }
