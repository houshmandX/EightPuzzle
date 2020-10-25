#ifndef _OUTPUT_H_
#define _OUTPUT_H_
#include <iostream>
#include "puzzle.h"
#include <math.h>
using namespace std;

/*heuristicCalculation checks each space (0) in the puzzle and counts when
* blank space in the current state does not match the blank in the goal state
* and it returns the number of spaces misplaced
* in manhatan, it returns the space in the goal state that has the number passed in
*/
int puzzle::heuristicCalculation(vector< vector<char> > mypuzzle)
{
	int num = 0;
    int x = 0;
    int y = 0 ;
    const vector<char> v1{'1', '2', '3'};
    const vector<char> v2{'4', '5', '6'};
    const vector<char> v3{'7', '8', '0'};
    
    vector< vector<char> > p_solved{v1, v2, v3};
	
    if(A_option == 1) // uniform cost heuristic
	{
		return num;
	}
	else if(A_option == 2) // misplaced node heuristic calculation
	{
		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 3; j++)
			{
                if(mypuzzle.at(i).at(j) == 0){
                continue;
                }
				if(mypuzzle.at(i).at(j) != p_solved.at(i).at(j))
				{
					num++;
				}
			}
		}
		return num;
	}
	else if(A_option == 3) // Eucledian heuristic calculation
	{	
		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 3; j++)
			{
				for(int p = 0; p < 3; p++)
				{
					for(int l = 0; l < 3; l++)
					{
                        if(mypuzzle.at(i).at(j) == 0){
                        continue;
                        }
						if(p_solved.at(i).at(j) == mypuzzle.at(p).at(l))
						{
                            
                            x = (i > p) ? (i - p) : (p - i);
                            y = (j > l) ? (j - l) : (l - j);
                            num += sqrt(pow(x,2) + pow(y,2)); 
                            
						}
					}
				}
			}
		}

		return num;
	}
	return 0;
}

// compares the puzzle to see if it has been represented already
bool puzzle::puzzleCompare(vector< vector<char> > mypuzzle)
{
	for(int i = 0; i < list.size(); i++)
	{
		if(mypuzzle == list.at(i))
		{
			return true;
		}

	}
	return false;
}

// calculates if the number of nodes in the queue has increased
void puzzle::maxQueueCalculation()
{
	if(q.size() > tot_node)
	{
		tot_node = q.size();
	}
}

// we need to check if curent puzzle match with the goal puzzle
bool puzzle::completeCheck(vector< vector<char> > mypuzzle)
{
    const vector<char> v1{'1', '2', '3'};
    const vector<char> v2{'4', '5', '6'};
    const vector<char> v3{'7', '8', '0'};
    
	vector< vector<char> > p_solved{v1, v2, v3};
    
	if(mypuzzle == p_solved)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// output the puzzle with uniform_cost / g(n), and heuristic_cost/ h(n)
void puzzle::puzzleOutput(node* current)
{    
    
	if(current != state)
	{
		cout << "The best state to expand with a g(n) = ";
		cout << current->uniform_cost;
		cout << " and h(n) = ";
		cout << current->heuristic_cost;
		cout << " is..." << endl;
	}
    
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			cout << current->mypuzzle.at(i).at(j) << " ";
		}
		cout << endl;
		
	}
    cout << endl;
}

#endif