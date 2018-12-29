# -*- coding:utf-8
# Project: Compiler final project
def printf(format, *args):
   if len(args):
       new_args = []
       for arg in enumerate(args):
           if type(arg) == list and len(arg) > 0 and type(arg[0]) == str:
               new_args.append(''.join(arg))
           else:
               new_args.append(arg)
       print format % tuple(new_args)
   else:
       print format
def main():
    text = ['S', 'h', 'a', 'n', 'g', 'h', 'a', 'i', 'Z', 'i', 'L', 'a', 'i', 'S', 'h', 'u', 'i', 'u', 'h', 'S', 'i', 'a', 'L', 'i', 'Z', 'i', 'a', 'h', 'g', 'n', 'a', 'h', 'S']
    True = ['T', 'r', 'u', 'e']
    False = ['F', 'a', 'l', 's', 'e']

    i = None
    l = len(text)
    lh = (l / 2)
    rst = 1
    i = 0
    while (i < lh):
        if ((text[i] != text[((l - 1) - i)])):
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
