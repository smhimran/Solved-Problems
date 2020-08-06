while True:
    try:
        s = input()
        z = 0
        o = 0
        zz = 0
        oz = 0
        for i in range(len(s)):
            if s[i] == '0':
                z+=1
                if s[i-1] == '0':
                    zz+=1

            elif s[i] == '1':
                o+=1
                if s[i-1] == '0':
                    oz+=1

        shoot=zz/(zz+oz)
        rotate=z/(z+o)
        if shoot>rotate:
            print("SHOOT")
        elif shoot<rotate:
            print('ROTATE')
        else:
            print("EQUAL")

    except EOFError:
        break
