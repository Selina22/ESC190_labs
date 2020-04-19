class graph:
    def __init__(self):
        self.store=[]

    def addVertex(self,n):
        if(n<=0):
            return -1
        for i in range(0,n):
            self.store=self.store+[[]]
        return len(self.store)

    def addEdge(self,from_idx,to_idx,directed,weight): #inputing the index of the Gertices list
        store=self.store
        if(from_idx<0)or(from_idx>=len(store))or(to_idx<0)or(to_idx>=len(store)):
            print("ERR: invalid index number")
            return False
        if(weight==0):
            print("ERR: invalid weight number")
            return False
        if(directed==True):
            edge=[to_idx,weight]
            store[from_idx].append(edge)
            return store
        elif(directed==False):
            edge1=[to_idx,weight]
            edge2=[from_idx,weight]
            store[from_idx].append(edge1)
            store[to_idx].append(edge2)
            return store
        else:
            print("ERR: invalid input to identify direct or indirect tree")
            return False
        
    def traverse(self,start,typeBreadth):
        store=self.store
        accum=[]
        if(start==None):
            if(typeBreadth==True):
                C=queue()
                D=[False]*len(store)
                P=[False]*len(store)
                for i in range(0,len(store),1):
                    rval=[]
                    if(D[i]==False):
                        C.enqueue(i)
                        D[i]=True
                    while(C.store!=[]):
                        w=C.dequeue()
                        if(P[w]==False):
                            rval=rval+[w]
                            P[w]=True
                        for j in range(0,len(store[w]),1):
                            x=store[w][j][0]
                            if(D[x]==False):
                                C.enqueue(x)
                                D[x]=True
                    if(len(rval)>0):
                        accum=accum+[rval]
                return accum
            elif(typeBreadth==False):
                C=stack()
                D=[False]*len(store)
                P=[False]*len(store)
                for i in range(0,len(store),1):
                    rval=[]
                    if(D[i]==False):
                        C.push(i)
                        D[i]=True
                    while(C.store!=[]):
                        w=C.pop()
                        if(P[w]==False):
                            rval=rval+[w]
                            P[w]=True
                        for j in range(0,len(store[w]),1):
                            x=store[w][j][0]
                            if(D[x]==False):
                                C.push(x)
                                D[x]=True
                    if(len(rval)>0):
                        accum=accum+[rval]
                return accum
        elif(start>=0):
            if(typeBreadth==True):
                rval=[]
                C=queue()
                D=[False]*len(store)
                P=[False]*len(store)
                i=start
                if(D[i]==False):
                    C.enqueue(i)
                    D[i]=True
                while(C.store!=[]):
                    w=C.dequeue()
                    if(P[w]==False):
                        rval=rval+[w]
                        P[w]=True
                    for j in range(0,len(store[w]),1):
                        x=store[w][j][0]
                        if(D[x]==False):
                            C.enqueue(x)
                            D[x]=True
                return rval
            elif(typeBreadth==False):
                rval=[]
                C=stack()
                D=[False]*len(store)
                P=[False]*len(store)
                i=start
                if(D[i]==False):
                    C.push(i)
                    D[i]=True
                while(C.store!=[]):
                    w=C.pop()
                    if(P[w]==False):
                        rval=rval+[w]
                        P[w]=True
                    for j in range(0,len(store[w]),1):
                        x=store[w][j][0]
                        if(D[x]==False):
                            C.push(x)
                            D[x]=True 
                return rval

    def connectivity(self,vx,vy):
        rval=[True,True]
        store=self.path(vx,vy)
        if(store[0]==[]):
            rval[0]=False
        else:
            rval[0]=True
        if(store[1]==[]):
            rval[1]=False
        else:
            rval[1]=True
        return rval
    
    def path(self,vx,vy):
        path=[[],[]]
        path[0]=self.pathHelper(vx,vy)
        path[1]=self.pathHelper(vy,vx)
        if(path[0]==None):
            path[0]=[]
        if(path[1]==None):
            path[1]=[]
        return path

    def pathHelper(self,initial,final):
        fake=graph()
        fake.store=self.store
        order=fake.traverse(initial,False)
        for i in range(0,len(order),1):
            if(order[i]==final):
                order=order[0:i+1]
                for x in range(len(order)-2,1,-1):
                    vertice=order[x]
                    lis=fake.store[vertice]
                    for item in lis:
                        if(item[0]!=order[x+1]):
                            lis.remove(item)
                    if(lis==[]):
                        order.remove(order[x])
                return order       
class queue:
    def __init__(self):
        self.store=[]
    def enqueue(self,x):
        self.store=self.store+[x]
        return True
    def dequeue(self):
        if(len(self.store)==0):
            return []
        else:
            val=self.store[0]
            self.store=self.store[1:len(self.store)]
            return val

class stack:
    def __init__(self):
        self.store=[]
    def push(self,x):
        self.store=[x]+self.store
        return True
    def pop(self):
        if(len(self.store)==0):
            return []
        else:
            val=self.store[0]
            self.store=self.store[1:len(self.store)]
            return val
        
G=graph()
G.addVertex(11)
G.addEdge(0,1,True,1)
G.addEdge(0,2,True,1)
G.addEdge(0,3,True,1)
G.addEdge(1,4,True,1)
G.addEdge(1,5,True,1)
G.addEdge(3,6,True,1)
G.addEdge(3,7,True,1)
G.addEdge(6,5,True,1)
G.addEdge(6,0,True,1)
G.addEdge(5,4,True,1)
G.addEdge(1,0,True,1)

print(G.store)
print(G.path(0,1))
print(G.connectivity(0,1))

