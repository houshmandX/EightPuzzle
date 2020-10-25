# EightPuzzle solver

![omt diagram](image/eightpuzzle.jpg)

#Introduction
In this project, I write a program called 8-puzzle solver. This project requires using 3 search algorithms
to solve the puzzle and visualize the differences between these 3 algorithms with respect to
their speed. I explore the Uniform cost search, and A* searches with Misplaced Tile
heuristic, and Euclidean distance euritic by my language of choice C++.

#Specifications
These three algorithms have different speeds regarding the puzzle input, each algorithm
following different methods to swap the tiles or to better understanding, different choices
of moves to expand the nodes. By comparing the result of each algorithm with the same
choice of the puzzle, we can justify how the algorithm is important in the speed of our
program.

#Uniform Cost Search
In this algorithm, we are expanding the cheapest node. The cost of this algorithm is the
path cost represent as g(n). More specifically, from A* if heuristic h(n) hardcode to 0 that
algorithm is uniform cost search.

#Misplaced Tile heuristic
The second algorithm used in this assignment is A* with the Misplaced Tile heuristic.
Heuristic in the algorithm is telling us, estimated how many more moves need to solve the
puzzle by misplaced the tiles to reach the goal state. More specifically, how many tiles are
not in their actual location, and we need to move to reach the goal state, will be calculated
each time we need to expand the nodes, not including empty tile(0 in my program). We do
expand the nodes with lower cost, respect to expanding nodes after the position is
changed. Our queue will expand the nodes with lower cost, and will not expand each child
like uniform cost search.

#Euclidian distance heuristic
This algorithm is similar to misplaced Tile, but there is a difference;
In this algorithm, we calculate the summation of the distance between tiles are not in the
right location, and we expand the nodes regarding with the lowest cost, lowest cost
meaning of with lowest h(n) where h(n) is the total distance between tiles after relocating

#Comparison
So when we look at the graph after we expand the nodes, we can see how big the
difference between the Uniform cost Search and two other algorithms.
In the example that I included the picture in this document shows the Euclidian distance
algorithm, let’s just express the differences:
For uniform cost search:
Nodes expanded: 42
Max nodes in the queue: 19
Cost search: 5
For Misplace Tile heuristic :
Nodes expanded: 18
Max nodes in the queue: 10
Cost search: 5
For Euclidian distance heuristic :
Nodes expanded: 17
Max nodes in the queue: 10
Cost search: 5
But as the puzzle gets more complicated the numbers are will increase, and we will look at
some of the puzzle differences in the end.

#Conclusion:
In this project, I pictured problems while I try to reach my boundaries, checking the
boundaries, and after try and error, I found that using the index of each location of tile, and
swapping them with the proper location. Priority queue helped me a lot to achieve the
project. So after trying to solve each puzzle by hand with these 3 algorithms, I
understood, how these algorithms, work, and I could progress the project easier.
Now I understand the differences between these 3 search algorithms, and what would one
program get benefit while having a faster algorithm.
Out of these 3 algorithms, Euclidian distanced Heuristic performs better compare to two
others as we can see in the graphs above. And The next best algorithm will be Misplaced
Tile Heuristic. Uniform cost search has a time complexity of O(b^d) when hardcoded to
h(n) = 0, using g(n) from uniform cost search and h(n) the cost to reach the node, in other
two algorithms performed a better search.
Altogether, both Euclidian distance and misplaced tile used heuristic which is perform
better than blind search, but Euclidian distance performed better. Therefore heuristic
performing differently in different algorithms.


How to run the code:

please run this command in the project directory:

g++ main.cpp puzzle.cpp

*****************************************************************************
