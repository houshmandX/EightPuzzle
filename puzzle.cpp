#include <iostream>
#include "puzzle.h"

using namespace std;

//constructor

puzzle::puzzle(){state = nullptr;}

/*check for user uption and if option is 1, defualt puzzle, 
* and if option is 2 make the puzle in three different vector, 
* ask user for three input lines with space in between
*/
void puzzle::makePuzzle(int option)
{
    node* t = new node;
    t->child1 = NULL;
    t->child2 = NULL;
    t->child3 = NULL;
    t->child4 = NULL;
    t->parent = NULL;
    t->heuristic_cost = 0;
    t->uniform_cost = 0;
    goalState = false;
    tot_expand = 0;
    tot_node = 0;

    if(option == 1)  //default
    {
        cout <<"default puzzle: "<< endl;
        vector<char> v1{'1', '2', '3'};
        vector<char> v2{'4', '8', '0'};
        vector<char> v3{'7', '6', '5'};
        
        t->mypuzzle.push_back(v1);
        t->mypuzzle.push_back(v2);
        t->mypuzzle.push_back(v3);

        state = t;
        q.push(state);
        list.push_back(state->mypuzzle);
        puzzleOutput(state);

    }

    else if(option == 2) //user puzzle
	{
		cout << "Enter your puzzle Use a 0 to represent the blank: \n";

		char value1, value2, value3;
		cout << "Enter the first row with space between each value: \n";
	    cin >> value1 >> value2 >> value3;
	   	vector<char> v1{value1,value2,value3};
		t->mypuzzle.push_back(v1);

		cout << "Enter the second row with space between each value: \n";
	    cin >> value1 >> value2 >> value3;
		vector<char> v2{value1, value2, value3};
		t->mypuzzle.push_back(v2);

		cout << "Enter the third row with space between each value: \n";
	    cin >> value1 >> value2 >> value3;		
		vector<char> v3{value1, value2, value3};
		t->mypuzzle.push_back(v3);

		state = t;
		q.push(state);
		list.push_back(state->mypuzzle);
		
	}
	else
	{
		cout << "Invalid input!\n";
		return;
	}
}


// need to check for validation puzzle that contais with 0, 9 indexes including 0, 3x3 . 
bool puzzle::valid(node* current)
{
	bool flag  = false;
	int p = 1;
	 
	while( p < 9){
		for(int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 3; j++)
			{
				if(current->mypuzzle.at(i).at(j) == (char)p || current->mypuzzle.at(i).at(j) == '0')
				{
					flag = true;
				}
				if((i == 2) && (j == 2) && flag == false)
				{
					return false;
				}
			}

		}
		p ++;
		flag = false;
	}
	return true;
}

//checks for user input algorithm option

void puzzle::optionSelected(int option)
{      
	if(state == NULL) // if the root of state is null
	{
		cout << "making the puzzle failed!" << endl;
		return;
	}
	if(!valid(state))  //check if he puzzle is not a valid input
	{
		cout << "This puzzle is not a valid puzzle!" << endl;
		return;
	}
	A_option = option;
	cout << "Expanding state:\n";

	if(option == 1)
	{
		puzzleOutput(state);
		search(state);
	}
	else if(option == 2)
	{
		puzzleOutput(state);
		search(state);
	}
	else if(option == 3)
	{
		puzzleOutput(state);
		search(state);
	}
	else
	{
		cout << "Invalid algorithm input!" << endl;
		return;
	}
}


// using if statement to chose the right moves, and swap with respect to index of eampty spot(0)
void puzzle::search(node* current)
{	
	int index = 10;
	int tempIndex = 0;
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(current->mypuzzle.at(i).at(j) == '0')
			{
				index = tempIndex;
			}
			else
			{
				tempIndex++;
			}
		}
	}
	if(index == 10)
	{
		cout << "Invalid responces !" << endl; /// check for boundries if the eampty is out of 3x3 
		return;
	}

	if(completeCheck(current->mypuzzle))
	{
		goalState = true;
		goalNode = current;
	}
	else
	{
		q.pop();
	}

	if(index == 0){upLeft(current);}
    else if(index == 0){upLeft(current);}
	else if(index == 1){up(current);}
	else if(index == 2){upRight(current);}
	else if(index == 3){left(current);}
	else if(index == 4){middle(current);}
	else if(index == 5){right(current);}
	else if(index == 6){downLeft(current);}
	else if(index == 7){down(current);}
	else if(index == 8){downRight(current);}
	
	if(goalState)
	{
		while(q.top() != goalNode)
		{
			q.pop();
		}
		puzzleOutput(q.top());
		cout <<endl;
		cout << "Goal!!! \n" << endl;

		cout << "To solve this problem the search algorithm expanded a total of: ";
		cout << tot_expand << " nodes." << endl;

		cout << "The maximum number of nodes in the queue at any one time: ";
		cout << tot_node << endl;

		cout << "The cost of search is: ";
		cout << q.top()->uniform_cost << endl;

		return;
	}
	else
	{
		if(q.top() != NULL)
		{   
			puzzleOutput(q.top());
			cout << "Expanding this node… \n" << endl;
			search(q.top());
		}
	}

}
