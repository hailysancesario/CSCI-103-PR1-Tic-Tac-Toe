// NxN tic-tac-toes
#include <iostream>
using namespace std;

// The following 3 functions are helper functions to convert
// between 1D and 2D array indices.  The grid itself is stored
// as a 1D array.  However, for printing, checking who won,
// etc. it may be easier to write loops that generate separate
// row/column indices (i.e. treating the array like a 2D array).
// The functions below should be written using the hints in the
// writeup for performing the appropriate arithmetic conversion
// between 1D- and 2D-indices, and can then be called in any
// of the other functions when you find yourself wanting to 
// convert one to the other.

/**
 * Helper function - Given the grid array and its dimension
 *    as well as a particular row (r) and column (c), this
 *    function performs the arithmetic to convert r and c
 *    to a 1D index and returns that character in the grid.
 *    For example, for dim = 3 and r = 2, c = 1, this function
 *    should compute the corresponding index: 7 and return
 *    grid[7].
 *
 * Use this function wherever you generate, row/column
 *    indices and want to access that element in the grid.
 *    Pass the row/column indices as r and c, respectively.
 *
 */
char getEntryAtRC(char grid[], int dim, int r, int c);

/**
 * Helper function - Given a 1D index returns the row
 * that corresponds to this 1D index.  Use this in
 * conjunction with idxToCol() anytime you have a 1D index
 * and want to convert to 2D indices.
 */
int idxToRow(int idx, int dim);

/**
 * Helper function - Given a 1D index returns the column
 * that corresponds to this 1D index.  Use this in
 * conjunction with idxToRow() anytime you have a 1D index
 * and want to convert to 2D indices.
 */
int idxToCol(int idx, int dim);


/** Should print the tic-tac-toe board in a nice grid
 *  format as shown below:
 *
 * Parameters:
 *   grid: Array of dim^2 characters representing the state
 *         of each square.  Each entry contains 'X', 'O'
 *         (the letter oh), or '?'.
 */
void printTTT(char grid[], int dim);

/** 
 * Should check if any player has won the game yet.
 *
 * Parameters:
 *   grid: Array of dim^2 characters representing the state
 *         of each square.  Each entry contains 'X', 'O', or '?'
 *
 * Return value:
 *   Should return 1 if 'X' has won, 2 if 'O' has won, or 0 (zero)
 *   if the game is still undecided.
 * 
 */
int checkForWinner(char grid[], int dim);


/** 
 * Should check if there is no possible way any player can win.
 * More specifically, if there does not exist a row, column,
 * or diagonal that can still have 3 of a kind, then the game
 * will be a draw.
 * 
 *
 * Parameters:
 *   grid: Array of dim^2 characters representing the state
 *         of each square.  Each entry contains 'X', 'O', or '?'
 *
 * Return value:
 *   Return true if no player can win given the current 
 *   game state, false otherwise.
 */
bool checkForDraw(char grid[], int dim);
 

/**********************************************************
 *  Write your implementations for each function prototyped
 *  above in the space below
 **********************************************************/

//DONE
char getEntryAtRC(char grid[], int dim, int r, int c)
{
    //ex: 5x5 grid. row 3, col 1 = (3*5)+1 = grid[16]
    return grid[(r * dim) + c];
}


//DONE
int idxToRow(int idx, int dim)
{
    //casting the result to an int so return is an int
    //ex: looking for row and col of idx 6 in a 3x3, 6/3= row 2
    return (int)idx/dim;
}

//DONE
int idxToCol(int idx, int dim)
{
    //casting the result into an int so the return is an int
    //ex: looking for row and col of idx 6 in a 3x3, 6%3= row 0
    return (int)idx%dim;
}


//MORE CUSTOM HELPER FUNCTIONS
int checkForRowWin(char grid[], int dim){
    
    //check indices in groups of dim
    //repeat until dim*dim
    int xCount = 0;
    int oCount = 0;
    //for every index in the array
    for(int set = 0; set < dim*dim; set++){
       //loop through the first set of dim
       for(int spot = 0; spot < dim; spot++){
           if(grid[spot] == 'X'){
            xCount++;
            }
            else if(grid[spot] == 'O'){
            oCount++;
            }   
       }
       //after it goes through the set, check to see if all match
       //if count = the amount needed to win (dim) the return 1 or 2
    }
    if(xCount == dim-1){
            return 1;
        }
        else if(oCount == dim-1){
            return 2;
        }
        else{
            return 0;
        }
}
    

int checkForColWin(char grid[], int dim){
    //checking columns
    int countX = 0;
    int countO = 0;
    for(int row = 0; row < dim; row++){
        for(int column = 0; column < dim; column += dim){
            if(grid[row] == 'X'){
                countX++;
            }
            else if(grid[row] == 'O'){
                countO++;
            }
        }
        
        if(countX == dim){
            return 1;
        }
        else if(countO == dim){
            return 2;
        }
        
    }
    
    return 0;
}
    
int checkForDiagLRWin(char grid[], int dim){
    //checking diagonal left to right
    int r = 0;
    int c = 0;
    int countX = 0;
    int countO = 0;
    char temp;
    
    for(int i = 0; i < dim; i++){
        temp = getEntryAtRC(grid, dim, r, c);
        if(temp == 'X'){
            countX++;
        }
        else if(temp == 'O'){
            countO++;
        }
        
        r++;
        c++;
    }
    
    if(countX == dim){
        return 1;
    }
    else if(countO == dim){
        return 2;
    }
    
    return 0;
}

int checkForDiagRLWin(char grid[], int dim){    
    //checking diagonal right to left
    //resetting variables
    int r = 0;
    int c = dim-1; //we have to start from the right, so the last col
    char temp; //placeholder char
    int countO = 0;
    int countX = 0;
    for(int i = 0; i < dim; i++){
        temp = getEntryAtRC(grid, dim, r, c);
        if(temp == 'X'){
            countX++;
        }
        else if(temp == 'O'){
            countO++;
        }
    }
    
    if(countX == dim){
        return 1;
    }
    else if(countO == dim){
        return 2;
    }
    
    return 0;
}




void printTTT(char grid[], int dim){
    //will go through every row
    //variable used for storing char X or O
    char indexVar;
    for(int rowCount = 0; rowCount < dim; rowCount++){
        
        //printing each index followed by format of grid
        for(int colCount = 0; colCount < dim; colCount++){
            //using getEntryAtRC to attain the char for square choice
            // also prevents printing char for entire column
            indexVar = getEntryAtRC(grid, dim, rowCount, colCount);
            //checks to see whether or not to add a | or not
            if(colCount == (dim-1)){
                cout << " " << indexVar << " ";
            }
            else {
                cout << " " <<indexVar << " " << "|";
            }

            
        }
        //end row and now skip to next to begin printing dashes
        cout<< endl;
        
        for(int dashRow = 0; dashRow < ((3*dim) + (dim-1));dashRow++){
            //checks to see if it's the last row bc it can't print dashes under
            if(rowCount == dim-1) {
                break;
            }
            cout << "-";
        }
        cout << endl;
        
    }
}

int checkForWinner(char grid[], int dim)
{
    //checking every way to win
    int resultRow = checkForRowWin(grid, dim);
    int resultCol = checkForColWin(grid, dim);
    int resultLR = checkForDiagLRWin(grid, dim);
    int resultRL = checkForDiagRLWin(grid, dim);
    
    
    
    
    
    
    //comparing the return ints. 1 means Xs win
    if(resultRow == 1 || resultCol == 1 || resultLR == 1 || resultRL == 1) {
        return 1;
    }
    //2 means Os win
    else if(resultRow == 2|| resultCol == 2|| resultLR == 2 || resultRL == 2){
        return 2;
    }
    //0 means game can continue
    return 0;
}

bool checkForDraw(char grid[], int dim)
{
    char temp;
    int spotsO = 0;
    int spotsX = 0;
    for(int i = 0; i < dim*dim; i++){
        temp = grid[i];
        if(temp == 'X'){
            spotsX++;
        }
        else if(temp == 'O'){
            spotsO++;
        }
    }
    
    if((spotsX + spotsO) == dim*dim){
        return true;
    }
    
    return false;
}



/**********************************************************
 *  Complete the indicated parts of main(), below. 
 **********************************************************/
int main()
{
  // This array holds the actual board/grid of X and Os. It is sized 
  // for the biggest possible case (11x11), but you should only 
  // use dim^2 entries (i.e. if dim=3, only use 9 entries: 0 to 8)
  char tttdata[121];
    
  // dim stands for dimension and is the side length of the 
  // tic-tac-toe board i.e. dim x dim (3x3 or 5x5). 
  int dim;
  // Get the dimension from the user
  cout << "Enter dimension: ";
  cin >> dim;
    
  int dim_sq = dim*dim;

  for(int i=0; i < dim_sq; i++){
    tttdata[i] = '?';
  }

  // Print one of these messages when the game is over
  // and before you quit
  const char xwins_msg[] = "X player wins!";
  const char owins_msg[] = "O player wins!";
  const char draw_msg[] =  "Draw...game over!";
  
  int count = 0;
  bool done = false;
  char player = 'X';
  // Show the initial starting board
  printTTT(tttdata, dim);

  while(!done){
    //updates count for player count
    count++;
    //**********************************************************
    // Get the current player's input (i.e. the location they want to
    // choose to place their mark [X or O]) and update the tttdata array.
    // Be sure to follow the requirements defined in the guide/writeup
    // for quitting immediately if the user input is out-of-bounds 
    // (i.e. not in the range 0 to dim_sq-1) as well as continuing to 
    // prompt for an input if the user chooses locations that have already
    // been chosen (already marked with an X or O).
    //**********************************************************

    // Add your code here for getting input
    int input;
    cout << "Player " << player << " enter your square choice [0-" << dim_sq -1 <<"]: ";
    cin >> input;
    
    //if the input is out of range, stop program immediately
    if(input < 0 || input > (dim_sq - 1)) {
        return 0;
    }
    
    //while the square choice equals X or O, keep asking. 
    while(tttdata[input] == 'X' || tttdata[input] == 'O') {
        cout << "Player " << player << " enter your square choice [0-" << dim_sq -1 <<"]: ";
        cin >> input;
    }
    
    //once they type an empty (?) square choice we can put their symbol there
    tttdata[input] = player;
    

    // Show the updated board if the user eventually chose a valid location
    // (i.e. you should have quit the loop and program by now without any 
    //  other output message if the user chosen an out-of-bounds input).
 
    printTTT(tttdata, dim);
    
    //storing return values in variables for conditions
    int testWin = checkForWinner(tttdata, dim);
    bool testDraw = checkForDraw(tttdata, dim);
    if(testWin == 1){
        done = true;
        cout << xwins_msg << endl;
        
    }
    else if(testWin == 2){
        done = true;
        cout << owins_msg << endl;
        
    }
    else if(testDraw == true){
        done = true;
        cout << draw_msg << endl;
        
    }
    
    //if it doesn't pass any of those tests, change player to O and loop back around
    if(count%2 == 0){
        player = 'X';
    }
    else{
        player = 'O';
    }
    
    

    //**********************************************************
    // Complete the body of the while loop to process the input that was just
    //  received to check for a winner or draw and update other status, as 
    //  needed. 
    // 
    // To match our automated checkers' expected output, you must output 
    // one of the messages defined above using *one* of the cout commands 
    // (under the appropriate condition) below:
    //   cout << xwins_msg << endl;  OR
    //   cout << owins_msg << endl;  OR
    //   cout << draw_msg << endl;
    //
    // Note: Our automated checkers will examine a specific number of lines
    //  at the end of the program's output and expect to see the updated board
    //  and game status message.  You may certainly add some debug print  
    //  statements during development but they will need to be removed to 
    //  pass the automated checks.
    //**********************************************************
  } // end while
  return 0;
}



