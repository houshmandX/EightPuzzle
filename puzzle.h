#ifndef _PUZZLE_H_
#define _PUZZLE_H_
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <queue>
#include <list>
#include "node.h"

using namespace std;

class puzzle
{
    private:

    node* state;  //wich is gonna roots of our graph
    node* goalNode;   // goal node need to store 

    bool goalState;   //boolian ex to find the goal state
    int tot_expand; // track to reach goal
    int tot_node;   // get track of all nodes
    int A_option;     // which algorithm option
    vector< vector< vector<char> > >list;     //for comparing the repeat state
    priority_queue<node*, vector<node*>, node_Comparison > q; //for lowest cost of heuristic_cost and cost_of_moves

    public:
    puzzle();
    void makePuzzle(int option);
    bool valid(node* current);
    void optionSelected(int option);
    void search(node* current);

    void upLeft(node* current);
    void up(node* current);
    void upRight(node* current);
    void left(node* current);
    void middle(node* current);
    void right(node* current);
    void downLeft(node* current);
    void down(node* current);
    void downRight(node* current);
   
    //assign each child 
    void aChild1(node* current, vector< vector<char> > tmpv1);
    void aChild2(node* current, vector< vector<char> > tmpv2);
    void aChild3(node* current, vector< vector<char> > tmpv3);
    void aChild4(node* current, vector< vector<char> > tmpv4);

    bool puzzleCompare(vector< vector<char> > puzzle);
    bool completeCheck(vector< vector<char> > puzzle);
    int heuristicCalculation(vector< vector<char> > puzzle);
    void maxQueueCalculation();
    void puzzleOutput(node* current);
};

#endif