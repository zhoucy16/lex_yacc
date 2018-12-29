# -*- coding:utf-8
# Project: Compiler final project
def printf(format, *args):
    if len(args):
        print (""+format) % tuple(args),
    else:
        print (""+format),

def atoi(clist):
    newlist = []
    for item in clist:
        if not item:
            break
        newlist.append(item)
    return float(''.join(newlist))

def main():
    expr = ['1', '6', '/', '4', '+', '(', '(', '8', '-', '5', ')', '*', '(', '4', '+', '3', ')', '+', '1', ')', '-', '1', '0', '/', '2', '*', '9', '#']
    post = [None]*1000
    ss = [None]*1000
    ch = None
    sum = None
    i = None
    t = None
    z = None
    error = 0
    top = 0
    sum = len(expr)
    t = 1
    i = 0
    ch = expr[i]
    i = (i + 1)
    while (ch != '#'):
        if (((ch == '+') or (ch == '-'))):
            while ((top != 0) and (ss[top] != '(')):
                post[t] = ss[top]
                top = (top - 1)
                t = (t + 1)

            top = (top + 1)
            ss[top] = ch
        else:
            if (((ch == '*') or (ch == '/'))):
                while ((ss[top] == '*') or (ss[top] == '/')):
                    post[t] = ss[top]
                    top = (top - 1)
                    t = (t + 1)

                top = (top + 1)
                ss[top] = ch
            else:
                if ((ch == '(')):
                    top = (top + 1)
                    ss[top] = ch
                else:
                    if ((ch == ')')):
                        while (ss[top] != '('):
                            post[t] = ss[top]
                            top = (top - 1)
                            t = (t + 1)

                        top = (top - 1)
                    else:
                        if ((ch == ' ')):
                            z = 1
                        else:
                            while (str.isdigit(ch) or (ch == '.')):
                                post[t] = ch
                                t = (t + 1)
                                ch = expr[i]
                                i = (i + 1)

                            i = (i - 1)
                            post[t] = ' '
                            t = (t + 1)





        ch = expr[i]
        i = (i + 1)

    while (top != 0):
        post[t] = ss[top]
        t = (t + 1)
        top = (top - 1)

    post[t] = ' '
    newstack = [0]*100
    newstr = [None]*100
    t = 1
    top = 0
    ch = post[t]
    t = (t + 1)
    temp = None
    while ((ch != ' ') and (error == 0)):
        if ((ch == '+')):
            newstack[(top - 1)] = (newstack[(top - 1)] + newstack[top])
            top = (top - 1)
        else:
            if ((ch == '-')):
                newstack[(top - 1)] = (newstack[(top - 1)] - newstack[top])
                top = (top - 1)
            else:
                if ((ch == '*')):
                    newstack[(top - 1)] = (newstack[(top - 1)] * newstack[top])
                    top = (top - 1)
                else:
                    if ((ch == '/')):
                        if ((newstack[top] != 0)):
                            newstack[(top - 1)] = (newstack[(top - 1)] / newstack[top])
                        else:
                            error = 1

                        top = (top - 1)
                    else:
                        i = 0
                        while (str.isdigit(ch) or (ch == '.')):
                            newstr[i] = ch
                            i = (i + 1)
                            ch = post[t]
                            t = (t + 1)

                        temp = 0
                        newstr[i] = temp
                        top = (top + 1)
                        newstack[top] = atoi(newstr)




        ch = post[t]
        t = (t + 1)

    if ((error == 0)):
        printf("%d",newstack[top])
    else:
        printf("invalid expression")

    return 0

if __name__ == "__main__":
    main()
