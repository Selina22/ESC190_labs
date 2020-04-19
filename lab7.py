def selection_sort(u):
    last=len(u)-1
    while(last>0):
        i=last
        for j in range(0,last+1,1):
            if(u[i]<u[j]):
                i=j
        temp=u[i]
        u[i]=u[last]
        u[last]=temp
        last=last-1
    return True

def heapify(u):
    
        
v1=[10,9,8,7,6,5,4,3,2,1,0]
v2=[100,1,1000,9,8,7,2,2000,10]
v3=[100,10,1000,9,8,7,2,6,5,2,3,1]

for i in [ v1,v2,v3 ]:
    x=list(i)
    selection_sort(x)
    print(x)
