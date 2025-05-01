#prac 1
lin = [None] * 10
qd = [None] * 10

def fun(val):
    return val % 10

def linear(val):
    index = fun(val)
    i = 0
    while lin[(index + i) % 10] is not None:
        i += 1
    return (index + i) % 10

def quad(val):
    index = fun(val)
    i = 0
    while qd[(index + i * i) % 10] is not None:
        i += 1
    return (index + i * i) % 10

def insert(val):
    l = linear(val)
    lin[l] = val
    q = quad(val)
    qd[q] = val

def displin():
    print("Linear probing:")
    for i in range(10):
        print(f"[{i}]--->{lin[i]}")

def dispquad():
    print("Quadratic probing:")
    for i in range(10):
        print(f"[{i}]--->{qd[i]}")

def searchl(val):
    index = fun(val)
    i = 0
    while i < 10:
        if lin[(index + i) % 10] == val:
            print(f"{val} found at index {(index + i) % 10}")
            return
        i += 1
    print(f"{val} not found")

# Driver code
while True:
    ch = int(input("1-insert \n 2-display linear\n 3-display quadratic\n 4-search linear\n 5-exit\nenter your choice: "))
    if ch == 1:
        x = int(input("Enter telephone number: "))
        insert(x)
    elif ch == 2:
        displin()
    elif ch == 3:
        dispquad()
    elif ch == 4:
        y = int(input("Enter value to search: "))
        searchl(y)
    else:
        break