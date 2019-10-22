#python3

import os
import sys

def timeConversion(s):
    x=s[0:2]
    y=int(x)
    if s[-2:]=='PM':
        if y==12:
            y=12
            z=str(y)
            time=z+s[2:8]
        else:
            y+=12   
            z=str(y)
            time=z+s[2:8]
            return time
    if (s[-2:]=='AM' and y==12):
        y=00
        z=str(y)
        time=z+z+s[2:8]
        return time
    else:
        return s[0:8]

        


if __name__ == '__main__':
    f = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = timeConversion(s)

    f.write(result + '\n')

    f.close()
