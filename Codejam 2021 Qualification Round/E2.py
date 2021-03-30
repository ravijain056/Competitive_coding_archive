import numpy as np

#import sys
#sys.stdin = open('Codejam 2021 Qualification Round/ts1_input.txt', 'r')
#sys.stdout = open('output.txt', 'w')

t = int(input())
p = int(input())

def inv_sigmoid(y):
    return np.log(y/(1-y))

def sigmoid(x):
    return np.where(x >= 0, 
                    1 / (1 + np.exp(-x)), 
                    np.exp(x) / (1 + np.exp(x)))

for ti in range(1, t+1):
    results = np.array([[int(ch) for ch in input()] for _ in range(100)])

    skill = inv_sigmoid(np.sum(results, axis=1) / 10000)
    diff = inv_sigmoid(1 - (np.sum(results, axis = 0) / 100))

    diffsort = list(zip(diff, range(10000)))
    diffsort.sort()

    easyQ = diffsort[:500] 
    hardQ = diffsort[-500:]
    
    selRes = [(np.sum(results[i][[q[1] for q in hardQ]]),
                np.sum(results[i][[q[1] for q in easyQ]])) for i in range(100)]

    selExp = np.array([[np.sum(sigmoid(skill[i] - diff[[q[1] for q in hardQ]])),
                    np.sum(sigmoid(skill[i] - diff[[q[1] for q in easyQ]]))] for i in range(100)])

    seldiff = np.subtract.reduce((selRes - selExp), axis=1)

    ans = np.argmax(seldiff) + 1

    print("Case #" + str(ti) + ": " + str(ans))
