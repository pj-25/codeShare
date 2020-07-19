import matplotlib.pyplot as graph

x = []
y = [[[], [], []], [[], [], []], [[], [], []]] #[W(B,S,I),A(...),B(...)] 

with open("points.txt") as pfile:
    data = pfile.readlines()
    l = 0
    while l < len(data):
        x.append(int(data[l]))
        for i in range(3):
            l += 1
            for j,p in enumerate(data[l].split()):
                y[i][j].append(float(p))
        l += 1
      
case = ('W', 'A', 'B')
algo = ('Bubble' ,'Selection', 'Insertion')

#case     
for i in range(3):
    #algo
    for j in range(3):
        graph.plot(x,y[i][j],label=f'{algo[j]}({case[i]})')

graph.xlabel('Input size(n)')
graph.ylabel('Time Complexity T(n)sec')

graph.title('Analysing Time Complexity\nBubble Sort Vs Selection Sort Vs Insertion Sort')

graph.legend()
graph.show()
            
            
   
