list1=[]
num=int(input("enter the number of elements"));
for i in range(1,num + 1):
	ele=int(input("enter elements: "))
	list1.append(ele)
print("largest num",max(list1))