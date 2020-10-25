#include <iostream>
#include "puzzle.h"
#include "operator.h"
#include "output.h"

using namespace std;


int main(){


    puzzle option;
    int p_option = 0;
    //display default or manual
    cout <<"welcome to Hayden Pour (862145756) 8 puzzle solver. " << endl;
    cout <<"Type \"1\" to use a default puzzle, or \"2\" to enter your own puzzle."<< endl;
    cin >> p_option;
    option.makePuzzle(p_option);

    //display the algorithm menu
    int a_option = 0;
    cout << "Enter your choice of algorithm" << endl
         <<"1. Uniform Cost Search" << endl
         <<"2. A* with the Misplaced Tile heuristic." << endl
         <<"3. A* with the Eucledian distance heuristic." << endl; 
    cin >> a_option;
    option.optionSelected(a_option); 

    return 0;    
}
