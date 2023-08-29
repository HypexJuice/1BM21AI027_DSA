#include <iostream>
#define N 100
using namespace std;
class Queen
{
public:

void printSolution(int board[N][N],int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
           if(board[i][j])
            cout << "Q ";
           else cout<<"_ ";
        printf("\n");
    }
}
bool isSafe(int board[N][N], int row, int col,int n)
{
    int i, j;
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;
    for (i = row, j = col; j >= 0 && i < n; i++, j--)
        if (board[i][j])
            return false;

    return true;
}
bool solveNQUtil(int board[N][N], int col,int n)
{
    if (col >= n)
        return true;
    for (int i = 0; i < n; i++) {
        if (isSafe(board, i, col,n)) {
            board[i][col] = 1;
            if (solveNQUtil(board, col + 1,n))
                return true;
            board[i][col]=0;
        }
    }
    return false;
}
bool solveNQ(int n)
{
    int board[N][N];
    for(int i=0; i<n;i++)
    {
        for(int j=0;j<n;j++)
            board[i][j]=0;
    }
    if (solveNQUtil(board, 0,n) == false) {
        cout << "Solution does not exist";
        return false;
    }

    printSolution(board,n);
    return true;
}
};
int main()
{
    Queen Q;
    int n;
    cout<<"\nEnter number of Queen: ";
    cin>>n;
    Q.solveNQ(n);
    return 0;
}
