# -*- coding:utf-8
def main():
    text = ['S', 'h', 'a', 'n', 'g', 'h', 'a', 'i', 'Z', 'i', 'L', 'a', 'i', 'S', 'h', 'u', 'i', 'u', 'h', 'S', 'i', 'a', 'L', 'i', 'Z', 'i', 'a', 'h', 'g', 'n', 'a', 'h', 'S']
    #True = ['T', 'r', 'u', 'e']
    #False = ['F', 'a', 'l', 's', 'e']
    i = None
    l = len(text)
    lh = (l / 2)
    rst = 1
    i = 0
    while (i < lh):
        if ((text[i] != text[((l - 1) - i)])):
            rst = 0
            

        i = (i + 1)

    if ((rst == 1)):
        print("True")
    else:
        print("False")

    return 0

if __name__ == "__main__":
    main()
