dict={}

for i in range (10):
	dict[i]=[None,"None",None]

def hashfun(num):
	return num % 10

def chain(num):
	key=hashfun(num)
	if(dict[key][0]==None):
		return key
	else:
		x=dict[key][0]
		
		if(hashfun(x)==key):
			y=key
			while(dict[y][0]!=None):
				y=(y+1)%10
			return y
		else:
			temp=dict[key]
			y=key
			while(dict[y][0]!=None):
				y=(y+1)%10
			dict[y]=temp	
			return key
					

def insert(num,name):
	index=chain(num)
	dict[index]=[num,name]

def search(num):
	index=hashfun(num)
	if(dict[index][0]==num):
		print("this number belong to ",dict[index][1])
	else:
		x=index
		
		for i in range(1,10):
			index=(index+1)%10
			if(dict[index][0]==num):
				print("this number belong to ",dict[index][1])
			if(index==x):
				print("number not found")

def display(d):
	for i in range(10):
		print("[",i,"]","----->",d[i][0],"(",d[i][1],")")

while True:
    print("\n1. Insert")
    print("2. Search")
    print("3. Display")
    print("4. Exit")
    choice = input("Enter your choice: ")

    if choice == '1':
        num = int(input("Enter the number to insert: "))
        name = input("Enter the name: ")
        insert(num, name)
    elif choice == '2':
        num = int(input("Enter the number to search: "))
        search(num)
    elif choice == '3':
        display(dict)
    elif choice == '4':
        print("Exiting...")
        break
    else:
        print("Invalid choice. Please try again.")