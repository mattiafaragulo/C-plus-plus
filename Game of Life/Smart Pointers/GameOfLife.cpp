#include <memory>
#include <iostream>
using namespace std;


//GameOfLife//
int main()
{
    unique_ptr<unique_ptr<char[]>[]> board(new std::unique_ptr<char[]>[5] ());
    unique_ptr<unique_ptr<char[]>[]> boardRes(new std::unique_ptr<char[]>[5] ());
    
    
    /* Create the input board */
    for (int i = 0; i < 5; i++)
    {
        unique_ptr<char[]> temp_ptr(new char[5]);
        for (int j = 0; j < 5; j++) {
            temp_ptr[j] = '.';
            if((i == 1 && j == 2) || (i == 3 && j == 2) || (i == 2 && j == 2) ) {
                temp_ptr[j] = '*';
            }
            /*if ((i == 0 && j == 2) || (i == 0 && j == 3) || (i == 0 && j == 4) ||
                (i == 1 && j == 0) || (i == 2 && j == 3) || (i == 2 && j == 4) ||
                (i == 3 && j == 0) || (i == 3 && j == 4)){
                temp_ptr[j] = '*';
            }*/ //other default configuration
        }
        board[i] = move(temp_ptr);
    }
    
    /*Create the default board */
    for (int i = 0; i < 5; i++)
    {
        unique_ptr<char[]> temp_ptr2(new char[5]);
        for (int j = 0; j < 5; j++) {
            temp_ptr2[j] = '.';
            if((i == 1 && j == 2) || (i == 3 && j == 2) || (i == 2 && j == 2) ) {
                temp_ptr2[j] = '*';
            }
        }
        boardRes[i] = move(temp_ptr2);
    }
    
    
    cout<< "First we have this configuration: ";
    cout<< '\n';
    
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++){
            cout << board[i][j] << " ";
        }
        cout << '\n';
    }
    
    cout<< '\n';
    
    int i = 0;
    
    cout<< "After 10 iterations... ";
    cout<< '\n';
    
    while (i<10) {
    
    /*Checking the GameOfLife rules*/
    for(int i = 0; i < 5; ++i) {
        for(int j = 0; j < 5; ++j) {
            int count = 0;
            if(i>0 && board[i-1][j] == '*') count++;
            if(i>0 && j<4 && board[i-1][j+1] == '*') count++;
            if(j<4 && board[i][j+1] == '*') count++;
            if(i<4 && j<4 && board[i+1][j+1] == '*') count++;
            if(i<4 && board[i+1][j] == '*') count++;
            if(i<4 && j>0 && board[i+1][j-1] == '*') count++;
            if(j>0 && board[i][j-1] == '*') count++;
            if(i>0 && j>0 && board[i-1][j-1] == '*') count++;
            if(board[i][j] == '*') {
                if( count == 2 || count ==3 ) {
                    boardRes[i][j] = '*';
                }
                else {
                    boardRes[i][j] = '.';
                }
            }
            else{
                if(count == 3) {
                    boardRes[i][j] = '*';
                }
                else {
                    boardRes[i][j] = '.';
                }
            }
        }
    }
     
    /*switch the boards after the generation*/
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++) {
            board[i][j] = boardRes[i][j];
        }
            
    }
        
    i++;
    cout << '\n';
    cout << "Iteration " << i ;
    cout << '\n';
    
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++) {
            cout << boardRes[i][j] << " ";
        }
        cout << '\n';
    }
        
    cout << '\n';
        
    }
    
    
}
