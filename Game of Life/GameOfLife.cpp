#include <memory>
#include <iostream>
using namespace std;
const int r = 5, c = 5;

void addLife(char board [r][c], int i, int j);
void addLife(char board [r][c], int i, int j);
int near(char board [r][c], int i, int j);
void copyMatrix(char m1 [r][c], char m2 [r][c]);
void view(char board [r][c]);
void nextGeneration(char board [r][c]);


void addLife(char board [r][c], int i, int j)
{
    board[i][j] = '*';
}

int near(char board [r][c], int i, int j)
{
    int count = 0;
    if(i>0 && board[i-1][j] == '*') count++;
    if(i>0 && j<4 && board[i-1][j+1] == '*') count++;
    if(j<4 && board[i][j+1] == '*') count++;
    if(i<4 && j<4 && board[i+1][j+1] == '*') count++;
    if(i<4 && board[i+1][j] == '*') count++;
    if(i<4 && j>0 && board[i+1][j-1] == '*') count++;
    if(j>0 && board[i][j-1] == '*') count++;
    if(i>0 && j>0 && board[i-1][j-1] == '*') count++;
    return count;
}

void copyMatrix(char m1[r][c], char m2 [r][c])
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++) {
            m1[i][j] = m2[i][j];
        }
        
    }
}

void view(char board [r][c])
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++) {
            cout<< board[i][j] <<' ';
        }
        cout<<'\n';
    }
}

void nextGeneration(char board [r][c])
{
    char boardRes [r][c];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++) {
            boardRes[i][j] = '.';
        }
    }
    for(int i = 0; i < r; ++i) {
        for(int j = 0; j < c; ++j) {
            int count = near(board,i,j);
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
    copyMatrix(board,boardRes);
    
}


//GameOfLife//
int main()
{
    char board [r][c];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++) {
            board[i][j] = '.';
        }
    }
    addLife(board,1,2); addLife(board,2,2); addLife(board,3,2);
    cout<<"This is the first configuration: " <<'\n';
    view(board);
    cout<<'\n';
    cout<<"Press enter to view a next generation or any button to exit";
    cout<<'\n';
    char c;
    int g = 0;
    while(true) {
        nextGeneration(board);
        g++;
        cout<<'\n';
        cin.get(c);
        if(c != '\n') {
            break;
        }
        cout<<g <<" Generation"<<'\n';
        view(board);
        
    }
    
    
    
    
    
}
