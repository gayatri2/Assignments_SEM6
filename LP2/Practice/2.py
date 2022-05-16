class Node():
    """A node class for A* Pathfinding"""
    #position will be a tuple of (x,y)
    def __init__(self, parent=None, position=None):
        self.parent = parent
        self.position = position
        #cost values
        self.g = 0
        self.h = 0
        self.f = 0

    def __eq__(self, other): #implement the Python __eq__ method to define the equality logic for comparing two objects using the equal operator (==)
        return self.position == other.position

def astar(maze, start, end):
    """Returns a list of tuples as a path from the given start to the given end in the given maze"""
    #initialise start & end nodes
   
    start_node = Node(None, start)
    start_node.g = start_node.h = start_node.f = 0
    end_node = Node(None, end)
    end_node.g = end_node.h = end_node.f = 0
    
    
    #initialise closed list & open list
    #closed list - contains processed nodes
    #open list - contains visited but unprocessed nodes
    open_list = []
    closed_list = []

    # Add the start node
    open_list.append(start_node)
   
    # Loop until you find the end
    while len(open_list) > 0:

        # Get the current node
        current_node = open_list[0]
        current_index = 0
        for index, item in enumerate(open_list): #enumerate is to loop over list items
            if item.f < current_node.f:
                current_node = item
                current_index = index
        
        # Pop current off open list, add to closed list
        open_list.pop(current_index)
        closed_list.append(current_node)

        # Found the goal
        if current_node == end_node:
            path = []
            current = current_node
            while current is not None:
                path.append(current.position)
                current = current.parent
            #as we added path from target to start we need to reverse it
            return path[::-1] # Return reversed path
        
        # Generate children
         #If not the target node we generate its children
        children = []
        for new_position in [(0, -1), (0, 1), (-1, 0), (1, 0), (-1, -1), (-1, 1), (1, -1), (1, 1)]: # Adjacent squares

            # Get node position
            node_position = (current_node.position[0] + new_position[0], current_node.position[1] + new_position[1]) #adding x,y coordinates

            # Make sure within range
            if node_position[0] > (len(maze) - 1) or node_position[0] < 0 or node_position[1] > (len(maze[len(maze)-1]) -1) or node_position[1] < 0:
                continue  #skip iteration for this condition and move to next iteration

            # Make sure walkable terrain
            if maze[node_position[0]][node_position[1]] != 0: #1 indicates obstacle
                continue #skip iteration for this condition and move to next iteration

            # Create new node
            new_node = Node(current_node, node_position) #current node is parent node

            # Append
            children.append(new_node)

            # Loop through children
        for child in children:

            # Child is in the closed list
            for closed_child in closed_list:
                if child == closed_child: #already visited node
                    continue #skip iteration for this condition and move to next iteration


            # Create the f, g, and h values
            child.g = current_node.g + 1
            child.h = ((child.position[0] - end_node.position[0]) ** 2) + ((child.position[1] - end_node.position[1]) ** 2) #eucledian distance
            child.f = child.g + child.h

            # Child is already in the open list
            for open_node in open_list:
                if child == open_node and child.g > open_node.g: #if child's g value is greater than open_node, then dont change list contents. 
                    continue #skip this iteration, move on to next iteration

            # Add the child to the open list
            open_list.append(child)

def plot (maze,path,x1,y1,x2,y2):
    for i in path:
        maze[i[0]][i[1]]='✅'
    maze[x1][y1]='🐱'
    maze[x2][y2]='🥛'
    for i in range(len(maze)):
        for j in range(len(maze)):
            if maze[i][j]==1:
                maze[i][j] ='🧱'
            if maze[i][j]==0:
                maze[i][j] ='🌸'
            

    return maze
def main():

    maze = [[0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]]
    
    
  

    #print maze
    for r in maze:
        for c in r:
            print(c,end = " ")
        print()
    
    x1=int(input("Enter x coordinate of start: (< 9)"))
    y1=int(input("Enter y coordinate of start: (< 9)"))
    x2=int(input("Enter x coordinate of end: (< 9)"))
    y2=int(input("Enter x coordinate of end: (< 9)"))

    start = (x1, y1)
    end = (x2, y2)
    
    path = astar(maze, start, end)
    print(path)
    mazeNew = plot(maze,path,x1,y1,x2,y2)
    for row in mazeNew:
        for col in row:
            print(col,end = " ")
        print()

if __name__ == '__main__':
    main()
