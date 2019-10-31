print("Enter the how Many number you want take")
n= int(input())
x={}
a={}
print("Enter the number")
for i in range(0,n):
    x[i]=input()
    a[i]=x[i]
for i in range(0,n):
    for j in range(0,15):
        s=x[i]
        t=s[::-1]
        if x[i]==t:
            print(f"Next Palindrome of {a[i]} is : {int(x[i])}")
            break
        else:
           x[i]=int(x[i]) + 1
           x[i]=str(x[i])
