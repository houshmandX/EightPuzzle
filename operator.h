#ifndef _OPERATOR_H_
#define _OPERATOR_H_
#include <iostream>
#include "puzzle.h"

using namespace std;

// the possibility of empty (0) in the puzzle and the moves
// find the 0 and call swap function to suap and move the node in the right location, respect to 
// available location 
// 0 1 2  positions number
// 3 4 5
// 6 7 8
void puzzle::upLeft(node* current)
{
	// if is on position_0 there is two possibility

	vector< vector<char> > tmpv1 = current->mypuzzle;
	vector< vector<char> > tmpv2 = current->mypuzzle;

	swap(tmpv1.at(0).at(0), tmpv1.at(0).at(1));
	aChild1(current, tmpv1);

	swap(tmpv2.at(0).at(0), tmpv2.at(1).at(0));
	aChild2(current, tmpv2);
}

void puzzle::up(node* current)
{
	// if is on position_1 there is three possibility

	vector< vector<char> > tmpv1 = current->mypuzzle;
	vector< vector<char> > tmpv2 = current->mypuzzle;
	vector< vector<char> > tmpv3 = current->mypuzzle;

	swap(tmpv1.at(0).at(1), tmpv1.at(0).at(0));
	aChild1(current, tmpv1);

	swap(tmpv2.at(0).at(1), tmpv2.at(0).at(2));
	aChild2(current, tmpv2); 

	swap(tmpv3.at(0).at(1), tmpv3.at(1).at(1));
	aChild3(current, tmpv3);
}

void puzzle::upRight(node* current)
{
	// if is on position_2 there is two possibility

	vector< vector<char> > tmpv1 = current->mypuzzle;
	vector< vector<char> > tmpv2 = current->mypuzzle;

	swap(tmpv1.at(0).at(2), tmpv1.at(0).at(1));
	aChild1(current, tmpv1);

	swap(tmpv2.at(0).at(2), tmpv2.at(1).at(2));
	aChild2(current, tmpv2);
}

void puzzle::left(node* current)
{
	// if is on position_3 there is three possibility

	vector< vector<char> > tmpv1 = current->mypuzzle;
	vector< vector<char> > tmpv2 = current->mypuzzle;
	vector< vector<char> > tmpv3 = current->mypuzzle;

	swap(tmpv1.at(1).at(0), tmpv1.at(0).at(0));
	aChild1(current, tmpv1);

	swap(tmpv2.at(1).at(0), tmpv2.at(1).at(1));
	aChild2(current, tmpv2);

	swap(tmpv3.at(1).at(0), tmpv3.at(2).at(0));
	aChild3(current, tmpv3);
}

void puzzle::right(node* current)
{
	// if is on position_5 there is three possibility

	vector< vector<char> > tmpv1 = current->mypuzzle;
	vector< vector<char> > tmpv2 = current->mypuzzle;
	vector< vector<char> > tmpv3 = current->mypuzzle;

	swap(tmpv1.at(1).at(2), tmpv1.at(0).at(2));
	aChild1(current, tmpv1);

	swap(tmpv2.at(1).at(2), tmpv2.at(1).at(1));
	aChild2(current, tmpv2);

	swap(tmpv3.at(1).at(2), tmpv3.at(2).at(2));
	aChild3(current, tmpv3);
}

void puzzle::middle(node* current)
{
	// if is on position_4 there is three possibility

	vector< vector<char> > tmpv1 = current->mypuzzle;
	vector< vector<char> > tmpv2 = current->mypuzzle;
	vector< vector<char> > tmpv3 = current->mypuzzle;
    vector< vector<char> > tmpv4 = current->mypuzzle;

	swap(tmpv1.at(1).at(1), tmpv1.at(0).at(1));
	aChild1(current, tmpv1);

	swap(tmpv2.at(1).at(1), tmpv2.at(1).at(0));
	aChild2(current, tmpv2);

	swap(tmpv3.at(1).at(1), tmpv3.at(1).at(2));
	aChild3(current, tmpv3);

    swap(tmpv4.at(1).at(1), tmpv4.at(2).at(1));
	aChild4(current, tmpv4);
}

void puzzle::downLeft(node* current)
{
	// if is on position_6 there is two possibility

	vector< vector<char> > tmpv1 = current->mypuzzle;
	vector< vector<char> > tmpv2 = current->mypuzzle;

	swap(tmpv1.at(2).at(0), tmpv1.at(1).at(0));
	aChild1(current, tmpv1);

	swap(tmpv2.at(2).at(0), tmpv2.at(2).at(1));
	aChild2(current, tmpv2);
}

void puzzle::downRight(node* current)
{
	// if is on position_8 there is two possibility

	vector< vector<char> > tmpv1 = current->mypuzzle;
	vector< vector<char> > tmpv2 = current->mypuzzle;

	swap(tmpv1.at(2).at(2), tmpv1.at(1).at(2));
	aChild1(current, tmpv1);

	swap(tmpv2.at(2).at(2), tmpv2.at(2).at(1));
	aChild2(current, tmpv2);
}

void puzzle::down(node* current)
{
	// if is on position_7 there is three possibility

	vector< vector<char> > tmpv1 = current->mypuzzle;
	vector< vector<char> > tmpv2 = current->mypuzzle;
	vector< vector<char> > tmpv3 = current->mypuzzle;

	swap(tmpv1.at(2).at(1), tmpv1.at(1).at(1));
	aChild1(current, tmpv1);

	swap(tmpv2.at(2).at(1), tmpv2.at(2).at(0));
	aChild2(current, tmpv2);

	swap(tmpv3.at(2).at(1), tmpv3.at(2).at(2));
	aChild3(current, tmpv3);
}

//when expanding the nodes, there are 4 child and max four nodes, 
//these are depend on number of nodes created after expanding them 

void puzzle::aChild1(node* current, vector< vector<char> > tmpv1)
{
	
	node* tmp1 = new node;
	
	if(goalState)
	{
		return;
	}
	if(completeCheck(tmpv1))
	{
		goalState = true;

		list.push_back(tmpv1);
        // update uniform_cost each time noes created
		tmp1->uniform_cost = current->uniform_cost + 1;
		tmp1->mypuzzle = tmpv1;
		//send the temp vector of current puzzle to calcute how many moves need to reach the goal state h(n)
		tmp1->heuristic_cost  = heuristicCalculation(tmpv1); 

		current->child1 = tmp1;
		current->child1->parent = current;
		q.push(current->child1);
		tot_expand++;  //track of how many time expanded by choosen algorithm
		maxQueueCalculation();

		goalNode = current->child1;

		return;
	}
	if(puzzleCompare(tmpv1))
	{
		current->child1 = NULL;
	}
	else if(!puzzleCompare(tmpv1))
	{
		// when we expanding the nodes, if that have not seen before, we need to
		// update our uniform_cost, therefore we add one to it. 
		// and call heuristicCalculation to calculate the heuristic_cost
		list.push_back(tmpv1);
        // update uniform_cost each time noes created
		tmp1->uniform_cost = current->uniform_cost + 1;
		tmp1->mypuzzle = tmpv1;
	    //send the temp vector of current puzzle to calcute how many moves need to reach the goal state h(n)
		tmp1->heuristic_cost = heuristicCalculation(tmpv1);

		current->child1 = tmp1;
		current->child1->parent = current;
		q.push(current->child1);
		tot_expand++;
		maxQueueCalculation();
		
	}
	
}

void puzzle::aChild2(node* current, vector< vector<char> > tmpv2)
{
	
	node* tmp2 = new node;
	
	if(goalState)
	{
		return;
	}
	if(completeCheck(tmpv2))
	{
		goalState = true;

		list.push_back(tmpv2);

		tmp2->uniform_cost = current->uniform_cost + 1;
		tmp2->mypuzzle = tmpv2;
		tmp2->heuristic_cost = heuristicCalculation(tmpv2);

		current->child2 = tmp2;
		current->child2->parent = current;
		q.push(current->child2);
		tot_expand++;
		maxQueueCalculation();

		goalNode = current->child2;

		return;
	}
	if(puzzleCompare(tmpv2))
	{
		current->child2 = NULL;
	}
	else if(!puzzleCompare(tmpv2))
	{
		
		// when we expanding the nodes, if that have not seen before, we need to
		// update our uniform_cost, therefore we add one to it. 
		// and call heuristicCalculation to calculate the heuristic_cost
		list.push_back(tmpv2);

		tmp2->uniform_cost = current->uniform_cost + 1;
		tmp2->mypuzzle = tmpv2;
		tmp2->heuristic_cost = heuristicCalculation(tmpv2);

		current->child2 = tmp2;
		current->child2->parent = current;
		q.push(current->child2);
		tot_expand++;
		maxQueueCalculation();
	}
	
}

void puzzle::aChild3(node* current, vector< vector<char> > tmpv3)
{
	
	node* tmp3 = new node;
	
	if(goalState)
	{
		return;
	}
	if(completeCheck(tmpv3))
	{
		goalState = true;

		list.push_back(tmpv3);

		tmp3->uniform_cost = current->uniform_cost + 1;
		tmp3->mypuzzle = tmpv3;
		tmp3->heuristic_cost = heuristicCalculation(tmpv3);

		current->child3 = tmp3;
		current->child3->parent = current;
		q.push(current->child3);
		tot_expand++;
		maxQueueCalculation();

		goalNode = current->child3;

		return;
	}
	if(puzzleCompare(tmpv3))
	{
		current->child3 = NULL;
	}
	else if(!puzzleCompare(tmpv3))
	{
		// when we expanding the nodes, if that have not seen before, we need to
		// update our uniform_cost, therefore we add one to it. 
		// and call heuristicCalculation to calculate the heuristic_cost
		list.push_back(tmpv3);

		tmp3->uniform_cost = current->uniform_cost + 1;
		tmp3->mypuzzle = tmpv3;
		tmp3->heuristic_cost = heuristicCalculation(tmpv3);

		current->child3 = tmp3;
		current->child3->parent = current;
		q.push(current->child3);
		tot_expand++;
		maxQueueCalculation();
	}
	
}

void puzzle::aChild4(node* current, vector< vector<char> > tmpv4)
{
	
	node* tmp4 = new node;
	
	if(goalState)
	{
		return;
	}
	if(completeCheck(tmpv4))
	{
		goalState = true;

		list.push_back(tmpv4);

		tmp4->uniform_cost = current->uniform_cost + 1;
		tmp4->mypuzzle = tmpv4;
		tmp4->heuristic_cost = heuristicCalculation(tmpv4);

		current->child4 = tmp4;
		current->child4->parent = current;
		q.push(current->child4);
		tot_expand++;
		maxQueueCalculation();

		goalNode = current->child4;

		return;
	}
	if(puzzleCompare(tmpv4))
	{
		current->child4 = NULL;
	}
	else if(!puzzleCompare(tmpv4))
	{
		// when we expanding the nodes, if that have not seen before, we need to
		// update our uniform_cost, therefore we add one to it. 
		// and call heuristicCalculation to calculate the heuristic_cost
		list.push_back(tmpv4);

		tmp4->uniform_cost = current->uniform_cost + 1;
		tmp4->mypuzzle = tmpv4;
		tmp4->heuristic_cost = heuristicCalculation(tmpv4);

		current->child4 = tmp4;
		current->child4->parent = current;
		q.push(current->child4);
		tot_expand++;
		maxQueueCalculation();
		
	}
}

#endif