C = int(input())

for i in range(C):
    s = input()
    s = s.replace('(', ' ').replace(')', ' ')
    print(s)



    # print("Case #{0}: {1} {2}".format(i+1, neww, newh))

'''
4
SSSEEE
N
N3(S)N2(E)N
2(3(NW)2(W2(EE)W))
'''