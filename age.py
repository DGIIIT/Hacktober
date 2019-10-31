print("Choose option\n1 for age\n2 for year of birth")
x= int(input())
if x==1:
    print("Enter your age")
    a=int(input())
else:
    print("Enter year of birth")
    a=int(input())
if a<200:
    print(f"after {100-a} years you will be 100 years")
    age=2019-a
elif 1920<a:
    print(f"At {a+100} year you will be 100 years")
    print(f"NOw your age is {2019-a} year")
print("If you want to know your age at given year press 1 else anynumber")
x=int(input())
if x==1:
    print("Enter the year")
    b=int(input())
    a=age
    print(f"At {b} year your age will be {a-b}")
