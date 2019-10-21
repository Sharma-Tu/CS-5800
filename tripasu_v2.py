import sys
import copy
from collections import defaultdict
T = int(input().strip())

for a0 in range(T):
    n = int(input().strip())
    tri = {}
    #path = {}
    for a1 in range(n):
        c = input().strip()
        C = list(map(int, c.split()))
        tri[a1] = C
    
    path = copy.deepcopy(tri)
    #print(dict(path))
    for i in tri:
        if i>0:
            for j in range(len(tri[i])):
                if j == 0:
                    path[i][j] = tri[i][j] + path[i-1][j]
                if j == i:
                    path[i][j] = tri[i][j] + path[i-1][j-1]
                else:
                    path[i][j] = tri[i][j] + max(path[i-1][j-1],path[i-1][j])
    print (max(path[n-1]))
