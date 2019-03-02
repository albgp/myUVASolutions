from sys import stdin

def numberTiles(n):
    if n in [0,1]: return 1
    a=[1,3]
    for i in range(2,n):
        a.append(a[i-1]+2*a[i-2])
    return a[-1]

while(True):
    l=stdin.readline()
    if l in ["","\n"]:
        break
    else: print(numberTiles(int(l)))