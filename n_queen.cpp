// #include<bits/stdc++.h>
// using namespace std;

// #define N 4

// void printSolution(int board[N][N])
// {
//     for (int i = 0; i < N; i++) 
//     {
//         for (int j = 0; j < N; j++)
//         {
//             cout << board[i][j] << " ";
//         }
//         cout << endl;   
//     }
// }
// bool isSafe(int board[N][N], int row, int col)
// {
//     for (int i = 0; i < col; i++) //check row on left  
//     {
//         if (board[row][i]==1)   //already a queen is placed in that row
//             return false;
//     }

//     //check diagonals
//     // for(int i=0;i<N;i++)
//     // {
//     //     for(int j=0;j<N;j++)
//     //     {
//     //         if(i+j==col || (i==j && j==col) )
//     //         {
//     //             if(board[i][j]==1)
//     //             {
//     //                 return false;
//     //             }
//     //         }
//     //     }
//     // }
//     int i,j;
//      /* Check upper diagonal on left side */
//     for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
//         if (board[i][j]==1)
//             return false;

//     /* Check lower diagonal on left side */
//     for (i = row, j = col; j >= 0 && i < N; i++, j--)
//         if (board[i][j]==1)
//             return false;

//     return true;
        
// }
// bool solve(int board[N][N], int col)
// {
//     if(col>=N)  //all queens placed
//     {
//         return true;
//     }

//     //consider this column, and try placing queens in all rows one by one
//     for(int i=0; i<N; i++)
//     {
//         //queen can be safely placed
//         if(isSafe(board,i,col))
//         {
//             board[i][col]=1;
//             //call recursively and check for every row
//             if(solve(board,col+1))
//             {
//                 return true;
//             }
//              //if placing a queen doesnt lead to a solution, then remove queen from board
//             else
//             {
//                 board[i][col]=0;    //backtrack
//             }
//         }
        
       
//     }
    

// }
// bool solveNQ()
// {
//     int board[N][N] = { { 0, 0, 0, 0 },
//                         { 0, 0, 0, 0 },
//                         { 0, 0, 0, 0 },
//                         { 0, 0, 0, 0 } };

//     if (solve(board, 0) == false) 
//     {
//         cout <<"Solution does not exist"<<endl;
//         return false;
//     }

//     printSolution(board);
//     return true;
// }

// int main()
// {
//     solveNQ();
// }

#include<iostream>
using namespace std;
#define N 8

void printBoard(int board[N][N]) {
   for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++)
         cout << board[i][j] << " ";
      cout << endl;
   }
}

bool isValid(int board[N][N], int row, int col) {
   for (int i = 0; i < col; i++)    //check whether there is queen in the left or not
      if (board[row][i])
         return false;
   for (int i=row, j=col; i>=0 && j>=0; i--, j--)
      if (board[i][j])       //check whether there is queen in the left upper diagonal or not
         return false;
   for (int i=row, j=col; j>=0 && i<N; i++, j--)
      if (board[i][j])      //check whether there is queen in the left lower diagonal or not
         return false;
   return true;
}

bool solveNQueen(int board[N][N], int col) {
   if (col >= N)           //when N queens are placed successfully
      return true;
   for (int i = 0; i < N; i++) {     //for each row, check placing of queen is possible or not
      if (isValid(board, i, col) ) {
         board[i][col] = 1;      //if validate, place the queen at place (i, col)
         if ( solveNQueen(board, col + 1))    //Go for the other columns recursively
            return true;
                   
         board[i][col] = 0;        //When no place is vacant remove that queen
      }
   }
   return false;       //when no possible order is found
}

bool checkSolution() {
   int board[N][N];
   for(int i = 0; i<N; i++)
      for(int j = 0; j<N; j++)
         board[i][j] = 0;      //set all elements to 0
               
   if ( solveNQueen(board, 0) == false ) {     //starting from 0th column
      cout << "Solution does not exist";
      return false;
   }
   printBoard(board);
   return true;
}

int main() {
   checkSolution();
}