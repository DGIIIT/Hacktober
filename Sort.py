#!/usr/bin/env python
# coding: utf-8

# In[ ]:


import matplotlib.pyplot as plt
import random
from random import randint
import time
import sys
sys.setrecursionlimit(10000)

def randList(limit):
	mylist=[]
	for i in range(0, limit):
		x= random.randint(1, 100)
		mylist.append(x)
	return mylist

def bubble(list):

    l=len(list)

    for i in range(l-1):

        for j in range(0, l-i-1):

            if list[j]>list[j+1]:

                list[j], list[j+1]= list[j+1], list[j]

                

def insertion(list):

    l=len(list)

    for i in range(1,l):

        current = list[i]

        position = i

        

        while position > 0 and list[position -1] > current:

            list[position] = list[position -1 ]

            position -= 1

        list[position] = current

    return list

def merge(list):
    if len(list) > 1:
        mid = len(list) // 2
        leftHalf = list[:mid]
        rightHalf = list[mid:]

        merge(leftHalf)
        merge(rightHalf)

        i = 0
        j = 0
        k = 0
        while i < len(leftHalf) and j < len(rightHalf):
            if leftHalf[i] < rightHalf[j]:
                list[k] = leftHalf[i]
                i = i + 1
            else:
                list[k] = rightHalf[j]
                j = j + 1
            k = k + 1

        while i < len(leftHalf):
            list[k] = leftHalf[i]
            i = i + 1
            k = k + 1

        while j < len(rightHalf):
            list[k] = rightHalf[j]
            j = j + 1
            k = k + 1
    return list

def partition(nums, low, high):
    pivot = nums[(low + high) // 2]
    i = low - 1
    j = high + 1
    while True:
        i += 1
        while nums[i] < pivot:
            i += 1

        j -= 1
        while nums[j] > pivot:
            j -= 1

        if i >= j:
            return j
        nums[i], nums[j] = nums[j], nums[i]


def quick_sort(nums):
    def _quick_sort(items, low, high):
        if low < high:
            split_index = partition(items, low, high)
            _quick_sort(items, low, split_index)
            _quick_sort(items, split_index + 1, high)

    _quick_sort(nums, 0, len(nums) - 1)
    
    
def partition(alist, start, end):
	pivot = randint(start, end)
	temp = alist[end]
	alist[end] = alist[pivot]
	alist[pivot] = temp
	pIndex = start
	
	for i in range(start, end):
		if alist[i] <= alist[end]:
			temp = alist[i]
			alist[i] = alist[pIndex]
			alist[pIndex] = temp
			pIndex += 1
	temp1 = alist[end]
	alist[end] = alist[pIndex]
	alist[pIndex] = temp1
	
	return pIndex

def quicksort(alist, start, end):
	if start < end:
		pIndex = partition(alist, start, end)
		quicksort(alist, start, pIndex-1)
		quicksort(alist, pIndex+1, end)
	
	return alist

                

                

p=2000    

x1=[]

y1=[]

x2=[]

y2=[]

x3=[]

y3=[]

x4=[]

y4=[]

x5=[]

y5=[]

for i in range(0, 10):

    li1=randList(p)

    li2=li1[:]
    
    li3=li1[:]
 
    li4=li1[:]
    
    li5=li1[:]
    

    t11=time.clock()
    
    insertion(li1)

    t12=time.clock()

    t1=t12-t11

    

    t21=time.clock()

    bubble(li2)

    t22=time.clock()

    t2=t22-t21
    
    
    t31=time.clock()

    merge(li3)

    t32=time.clock()

    t3=t32-t31


    t41=time.clock()

    quick_sort(li4)

    t42=time.clock()

    t4=t42-t41
    
    
    t51=time.clock()

    quicksort(li5)

    t52=time.clock()

    t5=t52-t51


    x1.append(p)

    y1.append(t1)

    x2.append(p)

    y2.append(t2)
    
    x3.append(p)

    y3.append(t3)
    
    x4.append(p)

    y4.append(t4)
    
    x5.append(p)

    y5.append(t5)


    p=p+1000

    

#%matplotlib inline

plt.plot(x2, y2, 'blue',label='Bubble Sort')

plt.plot(x1, y1, 'red',label='Insertion Sort')

plt.plot(x3, y3, 'green',label='Merge Sort')

plt.plot(x4, y4, 'black',label='Quick Sort')

plt.xlabel('limit')

plt.ylabel('time')

plt.title('Complexity Graph')

plt.legend()

plt.show()

plt.plot(x4, y4, 'black',label='Quick Sort')

plt.plot(x5, y5, 'red',label='Quick Sort random')

plt.xlabel('limit')

plt.ylabel('time')

plt.title('Complexity Graph')

plt.legend()

plt.show()


# In[ ]:




