/*
描述
小青蛙有一天不小心落入了一个地下迷宫,小青蛙希望用自己仅剩的体力值P跳出这个地下迷宫。
为了让问题简单,假设这是一个n*m的格子迷宫,迷宫每个位置为0或者1,
0代表这个位置有障碍物,小青蛙达到不了这个位置;1代表小青蛙可以达到的位置。小青蛙初始在(0,0)位置,地下迷宫的出口在(0,m-1)
(保证这两个位置都是1,并且保证一定有起点到终点可达的路径),小青蛙在迷宫中水平移动一个单位距离需要消耗1点体力值,
向上爬一个单位距离需要消耗3个单位的体力值,向下移动不消耗体力值,当小青蛙的体力值等于0的时候还没有到达出口,
小青蛙将无法逃离迷宫。现在需要你帮助小青蛙计算出能否用仅剩的体力值跳出迷宫(即达到(0,m-1)位置)。
输入描述：
输入包括n+1行:
第一行为三个整数n,m(3 <= m,n <= 10),P(1 <= P <= 100)
接下来的n行:
每行m个0或者1,以空格分隔
输出描述：
如果能逃离迷宫,则输出一行体力消耗最小的路径,输出格式见样例所示;如果不能逃离迷宫,则输出"Can not escape!"。 测试数据保证答案唯一
示例1
输入：
4 4 10 1 0 0 1 1 1 0 1 0 1 1 1 0 0 1 1
复制
输出：
[0,0],[1,0],[1,1],[2,1],[2,2],[2,3],[1,3],[0,3]*/
#include <iostream>
#include<stack>
using namespace std;
struct Postion
{
    int row;
    int col;
};

stack<Postion> s1;   //路径
stack<Postion>mins;  //最短的路径

void PrintMaze(int** maze, int N, int M)
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; j++)
        {
            cout << maze[i][j];
        }
    }
}
 
void PrintPass(stack<Postion>s)
{
    stack<Postion> s2;
    while (!s.empty())
    {
        s2.push(s.top());
        s.pop();
    }
    while (s2.size() > 1)
    {
        Postion x = s2.top();
        s2.pop();
        cout << "[" << x.row << "," << x.col << "],";
    }
    Postion x = s2.top();
    s2.pop();
    cout << "[" << x.row << "," << x.col << "]";
}

bool IsPass(int** maze, int N, int M, Postion pos)
{
    if (pos.row >= 0 && pos.row < N && pos.col >= 0 && pos.col < M
        && maze[pos.row][pos.col] == 1)
    {
        return true;
    }
    else
    {
        return false;
    }

}

void  GetMazePath(int** maze, int N, int M, Postion cur, int P)
{
    // 如果走到出口
    s1.push(cur);
    if (cur.row == 0 && cur.col == M - 1)
    {
        //如果找到了更短的路径，更新mins
        if (mins.empty() || s1.size() < mins.size())
        {
            mins = s1;
        }
    }
    //探测cur位置的上下左右四个方向 
    Postion next;
    maze[cur.row][cur.col] = 2;
    //上
    next = cur;
    next.row -= 1;
    if (IsPass(maze, N, M, next))
    {
        GetMazePath(maze, N, M, next, P - 3);

    }

    //下
    next = cur;
    next.row += 1;
    if (IsPass(maze, N, M, next))
    {
        GetMazePath(maze, N, M, next, P);

    }
    //左
    next = cur;
    next.col -= 1;
    if (IsPass(maze, N, M, next))
    {
        GetMazePath(maze, N, M, next, P - 1);
    }
    //右
    next = cur;
    next.col += 1;
    if (IsPass(maze, N, M, next))
    {
        GetMazePath(maze, N, M, next, P - 1);
    }
    maze[cur.row][cur.col] = 1;
    s1.pop();
}

int main() {

    int N = 0, M = 0, P = 0;
    cin >> N >> M >> P;
    int** maze = new int* [N];
    for (int i = 0; i < N; i++)
    {
        maze[i] = new int[M];
    }
    //二维数组输入
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> maze[i][j];
        }
    }
    //PrintMaze(maze,N,M);
    Postion entry = { 0,0 };

    GetMazePath(maze, N, M, entry, P);
    PrintPass(mins);
    for (int i = 0; i < N; i++)
    {
        free(maze[i]);
    }
    free(maze);
    maze = nullptr;

}
