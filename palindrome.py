# -*- coding:utf-8
# Project: Compiler final project
def printf(format, *args):
    if len(args):
        print ((""+format) % tuple(args)),
    else:
        print (""+format),

def scanf(format, arg):
    temp_str = input()
    for i in range(len(temp_str)):
        arg[i] = temp_str[i]

def strlen(char_list):
    result = 0
    for i in range(len(char_list)):
        if not char_list[i]:
            break;
        result += 1
    return result

def atoi(clist):
    newlist = []
    for item in clist:
        if not item:
            break
        newlist.append(item)
    return float(''.join(newlist))

def main():
    str = [None]*100
    printf("请输入一个字符串:")
    scanf("%s",str)
    a = 1
    i = None
    l = strlen(str)
    lh = (l / 2)
    rst = 1
    i = 0
    while (i < lh):
        if ((str[i] != str[((l - 1) - i)])):
            rst = 0
            break

        i = (i + 1)

    if ((rst == 1)):
        printf("True %d",1)
    else:
        printf("False")

    return 0

if __name__ == "__main__":
    main()
