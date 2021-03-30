import numpy as np

import sys
sys.stdin = open('Codejam 2021 Qualification Round/ts1_input.txt', 'r')
sys.stdout = open('output.txt', 'w')

t = int(input())
p = int(input())

for ti in range(1, t+1):
    results = np.array([[int(ch) for ch in input()] for _ in range(100)])

    skill = np.sum(results, axis=1)
    diff = np.sum(results, axis = 0)

    diffsort = list(zip(diff, range(10000)))
    diffsort.sort()
    skillsort = list(zip(skill, range(100)))
    skillsort.sort()

    hardQ = diffsort[:500] 
    easyQ = diffsort[-500:]
    
    selRes = [(np.sum(results[i][[q[1] for q in hardQ]]),
                np.sum(results[i][[q[1] for q in easyQ]])) for i in range(100)]

    comp = [(2 * (selRes[skillsort[0][1]][0]  - selRes[skillsort[1][1]][0] - 
            selRes[skillsort[0][1]][1] + selRes[skillsort[1][1]][1]), skillsort[0][1])]

    for i in range(1, 99):
        cur = skillsort[i][1]
        n1 = skillsort[i-1][1]
        n2 = skillsort[i+1][1]
        comp.append((2 * selRes[cur][0] - selRes[n1][0] - selRes[n2][0] -
                    2 * selRes[cur][1] + selRes[n1][1] + selRes[n2][1], cur))
        
    comp.append((2 * (selRes[skillsort[-1][1]][0]  - selRes[skillsort[-2][1]][0] - 
                selRes[skillsort[-1][1]][1] + selRes[skillsort[-2][1]][1]), skillsort[-1][1]))
    comp.sort()
    
    ans = comp[-1][1]+1

    print("Case #" + str(ti) + ": " + str(ans))
