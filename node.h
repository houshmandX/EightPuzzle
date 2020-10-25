#ifndef _NODE_H_
#define _NODE_H_
#include <iostream>
#include <vector>
using namespace std;

struct node
{
    node* child1;
    node* child2; 
    node* child3;
    node* child4;
    node* parent;
    vector<vector<char>> mypuzzle;
    int heuristic_cost;
    int uniform_cost;
};


class node_Comparison{
public:
    bool operator()(node* node1, node* node2)
    {   
       if((node1->uniform_cost + node1->heuristic_cost) > (node2->uniform_cost + node2->heuristic_cost)) return true; 
       return false;
      
    }
 
};

#endif