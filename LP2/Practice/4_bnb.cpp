#include <bits/stdc++.h>
#define n 8
using namespace std;

void printboard(int board[n][n])
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}
bool isValid(int board[n][n], int row, int col,int lowerleftvalues[n][n],int upperleftvalues[n][n], bool column[n], bool lowerleft[2*n-1], bool upperleft[2*n-1])
{
    // for(int i = 0; i < col; i++)
    // {
    //     if(board[row][i]==true)
    //     {
    //         return false;
    //     }
    // }
    // for(int i = row,j=col; i>=0 && j>=0; i--, j--)
    // {
    //     if(board[i][j]==true)
    //     {
    //         return false;
    //     }
    // }
    // for(int i = row,j=col; i<n && j>=0; i++, j--)
    // {
    //     if(board[i][j]==true)
    //     {
    //         return false;
    //     }
    // }
    // return true;
    
    if(column[col]==true || lowerleft[lowerleftvalues[row][col]]==true || upperleft[upperleftvalues[row][col]]==true)
    {
        return false;
    }
    return true;

}
bool solve(int board[n][n], int col,int lowerleftvalues[n][n],int upperleftvalues[n][n], bool column[n], bool lowerleft[2*n-1], bool upperleft[2*n-1])
{
    if(col>=n)
    {
        return true;
    }
    //check rows
    for(int i=0; i<n; i++)
    {
        if(isValid(board,i,col,lowerleftvalues, upperleftvalues,column,lowerleft,upperleft)==true)
        {
            board[i][col]=1;
            column[col]=true;
            lowerleft[lowerleftvalues[i][col]]=true;
            upperleft[lowerleftvalues[i][col]]=true;
            //check other columns
            if(solve(board,col+1,lowerleftvalues, upperleftvalues,column,lowerleft,upperleft)==true)
            {
                return true;
            }
            board[i][col]=0;
            column[col]=false;
            lowerleft[lowerleftvalues[i][col]]=false;
            upperleft[upperleftvalues[i][col]]=false;
        }
    }
    return false;
}
void checksoln()
{
    int board[n][n];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            board[i][j] = 0;
        }
    }
    int lowerleftvalues[n][n];
    int upperleftvalues[n][n];

    bool column[n];
    bool lowerleft[2*n-1];
    bool upperleft[2*n-1];

    for(int i=0; i<n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            lowerleftvalues[i][j]=i+j;
            upperleftvalues[i][j]=i-j+n-1;
        }
    }

    for(int i=0; i<n; i++)
    {
        column[i]=false;
    }
    for(int i=0; i<(2*n-1); i++)
    {
        lowerleft[i]=false;
    }
    for(int i=0; i<(2*n-1); i++)
    {
        upperleft[i]=false;
    }

    if(solve(board,0,lowerleftvalues,upperleftvalues,column,lowerleft,upperleft)==false)
    {
        cout << "Solution does not exist";
       
    }
    printboard(board);


}
int main()
{
    checksoln();
    return 0;
}