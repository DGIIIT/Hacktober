import random
print("Enter the number")
n=int(input())
lst={}
lst1={}
for x in range(1,11):
    lst[x]=n*x
    lst1[x]=lst[x]
y=random.randint(4,8)
m=n*y
lst[y]=m+y
print("your output :",end=" ")
print(lst[x])
for x in range(1,11):
    n1=lst[x]
    n2=lst1[x]
    if n1==n2:
        continue
    else:
        print(f"At Wrong: {x}")
        print("Correct output",end=" ")
        print(lst1)