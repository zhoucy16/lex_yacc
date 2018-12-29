# -*- coding:utf-8
# Project: Compiler final project
def printf(format, *args):
    if len(args):
        print format % tuple(args)
    else:
        print format

def atoi(clist):
    newlist = []
    for item in clist:
        if not item:
            break
        newlist.append(item)
    return float(''.join(newlist))

def main():
    i = 0
    j = -1
    kmpNext = [None]*100
    kmpNext[0] = -1
    text = ['r', 'u', 'n', 'n', 'i', 'n', 'g', 'm', 'a', 'n', 'n']
    n = len(text)
    pattern = ['n', 'n']
    m = len(pattern)
    res = [None]*100
    while (i < m):
        while ((j > -1) and (pattern[i] != pattern[j])):
            j = kmpNext[j]

        i = (i + 1)
        j = (j + 1)
        if (((i >= m) or (j >= m))):
            break

        if ((pattern[i] == pattern[j])):
            kmpNext[i] = kmpNext[j]
        else:
            kmpNext[i] = j

    print kmpNext
    i = 0
    j = 0
    num = 0
    while (j < n):
        while ((i > -1) and (pattern[i] != text[j])):
            i = kmpNext[i]

        i = (i + 1)
        j = (j + 1)
        if ((i >= m)):
            res[num] = (j - i)
            i = kmpNext[i]
            num = (num + 1)


    if ((num == 0)):
        printf("False")
    else:
        if ((num == 1)):
            printf("%d",res[0])
        else:
            i = 0
            while (i < (num - 1)):
                printf("%d",res[i])
                printf(",")
                i = (i + 1)

            printf("%d",res[(num - 1)])


    return 0

if __name__ == "__main__":
    main()
