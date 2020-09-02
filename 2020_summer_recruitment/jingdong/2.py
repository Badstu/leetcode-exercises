m = int(input())

d = []

while m > 0:
	a = list(map(int, input().split(' ')))
	if len(a) == 3:
		op, j, k = a[0], a[1], a[2]
		d.insert(j - 1, k)
	if len(a) == 2:
		op, j = a[0], a[1]
		del d[j-1]
	if len(a) == 1:
		for i in d:
			print(i, end=' ')

	m -= 1
