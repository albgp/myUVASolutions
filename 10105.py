import operator as op
from functools import reduce
from sys import stdin

def nOverr(n, r):
    r = min(r, n-r)
    numer = reduce(op.mul, range(n, n-r, -1), 1)
    denom = reduce(op.mul, range(1, r+1), 1)
    return numer // denom

while(True):
    input1=stdin.readline()
    if input1 in ['\n','']:
        break
    n,k = [int(i) for i in input1.split()]
    ns= [int(i) for i in stdin.readline().split()]

    ns=[i for i in ns if n!=0]
    suma=0
    resultado=1
    for i in ns:
        resultado*=nOverr(n-suma,i)
        suma+=i
    print(resultado)
