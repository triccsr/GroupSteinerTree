import random
import sys

# size: number of queries, queryFilePath: the queries you need, queryGroupFilePath: a checker query file showing groups that are in queries 

def gen_queries_uniform(size:int, maxT:int, groupFilePath:str, queryFilePath:str,queryGroupFilePath:str):
    groups=[]
    with open(groupFilePath,"r") as groupFile:
        while True:
            g=groupFile.readline().split()
            if not g:
                break
            groups.append(g)
    print(groups)
    if maxT > len(groups):
        maxT=len(groups)
        print("Warning: maxT is larger than group number, setting it to group number "+str(maxT))
    with open(queryFilePath,"w") as queryFile, open(queryGroupFilePath,"w") as queryGroupFile:
        queryGroupFile.write(str(size)+"\n")
        queryFile.write(str(size)+"\n")
        for c in range(size):
            t=random.randint(2,maxT)
            choice=[1]*t+[0]*(len(groups)-t)
            random.shuffle(choice)
            queryGroupFile.write(str(t)+"  ")
            queryFile.write(str(t)+"\n")
            for i in range(len(groups)):
                if choice[i] == 1:
                    queryGroupFile.write(str(groups[i][0])+" ")
                    queryFile.write(str(len(groups[i])-1)+"  ")
                    for j in range(1,len(groups[i])):
                        queryFile.write(str(groups[i][j])+" ")
                    queryFile.write("\n")
            queryGroupFile.write("\n")
    

def gen_queries_weight(size:int, maxT:int, groupFilePath:str, queryFilePath:str, queryGroupFilePath:str):
    groups=[]
    lens=[]
    with open(groupFilePath,"r") as groupFile:
        while True:
            g=groupFile.readline().split()
            if not g:
                break
            groups.append(g)
            lens.append(len(g)-1)
    for i in range(1,len(lens)):
        lens[i]+=lens[i-1]
    print(groups)
    if maxT > len(groups):
        maxT=len(groups)
        print("Warning: maxT is larger than group number, setting it to group number "+str(maxT))
    with open(queryFilePath,"w") as queryFile, open(queryGroupFilePath,"w") as queryGroupFile:
        queryGroupFile.write(str(size)+"\n")
        queryFile.write(str(size)+"\n")
        for c in range(size):
            t=random.randint(2,maxT)
            queryGroupFile.write(str(t)+"  ")
            queryFile.write(str(t)+"\n")
            vis=set()
            for l in range(t):
                index=-1
                while True:
                    r=random.randint(1,lens[-1])
                    for i in range(0,len(lens)):
                        if(lens[i]>=r):
                            if i not in vis:
                                index=i
                            break
                    if index != -1:
                        break
                vis.add(index)
                queryGroupFile.write(str(groups[index][0])+" ")
                queryFile.write(str(len(groups[index])-1)+"  ")
                for i in range(1,len(groups[index])):
                    queryFile.write(str(groups[index][i])+" ")
                queryFile.write("\n")
            queryGroupFile.write("\n")

def gen_all_queries(dataName:str,size:int,maxT:int):
    gen_queries_uniform(size,maxT,dataName+"_groups.txt",dataName+"_u_q.txt",dataName+"_u_qg.txt")
    gen_queries_weight(size,maxT,dataName+"_groups.txt",dataName+"_w_q.txt",dataName+"_w_qg.txt")


#gen_all_queries("toy",20,3)

if len(sys.argv)!=4:
    print("Error: Too many or too few args.\n Usage: gen_queries.py YOUR_DATA_NAME YOUR_QUERY_SIZE YOUR_MAX_GROUP_NUMBER_IN_A_QUERY")
else:
    gen_all_queries(sys.argv[1],int(sys.argv[2]),int(sys.argv[3]))