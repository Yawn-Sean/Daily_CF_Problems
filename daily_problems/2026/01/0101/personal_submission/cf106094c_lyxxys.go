const tot = 200000

var MIP [tot + 1]int

func main() {
	for i := range MIP {
		MIP[i] = i
	}
	for i := 2; i*i <= tot; i++ {
		if MIP[i] == i {
			for j := i * i; j <= tot; j += i {
				if MIP[j] == j {
					MIP[j] = i
				}
			}
		}
	}

	in, out := bufio.NewReader(os.Stdin), bufio.NewWriter(os.Stdout)
	defer out.Flush()
	var T int
	fmt.Fscan(in, &T)
	for ; T > 0; T-- {
		var X int
		var K int64
		fmt.Fscan(in, &X, &K)

		// 质因数分解，统计指数
		m := make(map[int]int)
		tmp := X
		for tmp > 1 {
			p := MIP[tmp]
			tmp /= p
			m[p]++
		}

		exponents := make([]int, 0, len(m))
		for _, exp := range m {
			exponents = append(exponents, exp)
		}

		ans := 0
		for i := 1; i <= 60; i++ {
			cur2 := int64(1) << i // 2^i
			avail := K
			valid := true
			for _, l := range exponents {
				mark := (int64(l) + cur2 - 1) / cur2 * cur2
				avail -= mark - int64(l)
				if avail < 0 {
					valid = false
					break
				}
			}
			if valid {
				ans = i
			} else {
				break
			}
		}
		fmt.Fprintln(out, ans)
	}
}
