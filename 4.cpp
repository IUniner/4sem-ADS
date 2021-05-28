#include <iostream>
#include <vector>
#include <queue>

using namespace std;


bool NextCompare(int row, int column, int N, int M, bool used[101][101]) {
    return (!used[row][column] && row >= 0 && row < M && column >= 0 && column < N);
}


int main()
{
    //pair<int ,int> s = {0,0};
    int M, N, x, y;
    cin >> M >> N >> x >> y;
    --x; --y;
    queue<pair<int, int>> line;

    line.push({0, 0});
    bool used[101][101] = {false};
    int cd[101][101] = {0};
    used[0][0] = true;
    bool validation = false;

    while(!line.empty()) {
        int row = line.front().first, column = line.front().second;
        line.pop();
        if(NextCompare(row + 2, column + 1, N, M, used))
        {
            used[row + 2][column + 1] = true;                   // +
            line.push({row+2, column+1});
            cd[row + 2][column + 1] = cd[row][column] + 1;
        }
        if(NextCompare(row + 2, column - 1, N, M, used))
        {
            used[row + 2][column - 1] = true;                   // +
            line.push({row+2, column - 1});
            cd[row + 2][column - 1] = cd[row][column] + 1;
        }
        if(NextCompare(row - 2, column + 1, N, M, used))
        {
            used[row - 2][column + 1] = true;                   // +
            line.push({row-2, column+1});
            cd[row - 2][column + 1] = cd[row][column] + 1;
        }
        if(NextCompare(row - 2, column + 1, N, M, used))
        {
            used[row - 2][column - 1] = true;                   // +
            line.push({row-2, column-1});
            cd[row - 2][column - 1] = cd[row][column] + 1;
        }
        if(NextCompare(row + 1, column + 2, N, M, used))
        {
            used[row + 1][column + 2] = true;                   // +
            line.push({row+1, column +2});
            cd[row + 1][column +2] = cd[row][column] + 1;
        }
        if(NextCompare(row - 1, column + 2, N, M, used))
        {
            used[row - 1][column + 2] = true;                   // +
            line.push({row-1, column +2});
            cd[row - 1][column +2] = cd[row][column] + 1;
        }
        if(NextCompare(row + 1, column - 2, N, M, used))
        {
            used[row + 1][column - 2] = true;                   // +
            line.push({row+1, column -2});
            cd[row + 1][column -2] = cd[row][column] + 1;
        }
        if(NextCompare(row - 1, column - 2, N, M, used))
        {
            used[row - 1][column - 2] = true;                   // +
            line.push({row-1, column -2});
            cd[row - 1][column -2] = cd[row][column] + 1;
        }
        if (used[x][y])
        {
            validation = true;
            break;
        }
    }
    if(validation)
        cout << cd[x][y];
    else
        cout << "NEVAR";

    return 0;
}
