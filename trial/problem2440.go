package main

import "fmt"

func main() {
	var N int

	fmt.Scanf("%d", &N)

	for i := 0; i < N; i++ {
		text := ""
		for j := 0; j < N-i; j++ {
			text = text + "*"
		}

		fmt.Println(text)
	}
}