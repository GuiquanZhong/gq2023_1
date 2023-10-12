///*链接：https://www.nowcoder.com/questionTerminal/cf24906056f4488c9ddb132f317e03bc
//来源：牛客网
//定义一个二维数组 N*M ，如 5 × 5 数组下所示：
//int maze[5][5] = {
//0, 1, 0, 0, 0,
//0, 1, 1, 1, 0,
//0, 0, 0, 0, 0,
//0, 1, 1, 1, 0,
//0, 0, 0, 1, 0,
//};
//输入描述:
//输入两个整数，分别表示二维数组的行数，列数。再输入相应的数组，其中的1表示墙壁，0表示可以走的路。迷宫只有一条通道。
//输出描述:
//左上角到右下角的最短路径，格式如样例所示。
//示例1
//输入
//5 5
//0 1 0 0 0
//0 1 1 1 0
//0 0 0 0 0
//0 1 1 1 0
//0 0 0 1 0
//输出
//(0,0)
//(1,0)
//(2,0)
//(2,1)
//(2,2)
//(2,3)
//(2,4)
//(3,4)
//(4,4)
//示例2
//输入
//5 5
//0 1 0 0 0
//0 1 0 1 0
//0 0 0 0 1
//0 1 1 1 0
//0 0 0 0 0
//输出
//(0,0)
//(1,0)
//(2,0)
//(3,0)
//(4,0)
//(4,1)
//(4,2)
//(4,3)
//(4,4)
//说明
//注意：不能斜着走！！     */
//#include <iostream>
//#include<stack>
//using namespace std;
//struct Postion
//{
//    int row;
//    int col;
//};
//stack<Postion> s1;
//
//void PrintMaze(int** maze, int N, int M)
//{
//    for (int i = 0; i < N; ++i)
//    {
//        for (int j = 0; j < M; j++) 
//        {
//            cout << maze[i][j];
//        }
//    }
//}
//
//void PrintPass(stack<Postion>s)
//{
//    stack<Postion> s2;
//    while (!s.empty())
//    {
//        s2.push(s.top());
//        s.pop();
//    }
//    while (!s2.empty())
//    {
//        Postion x = s2.top();
//        s2.pop();
//        cout << "(" << x.row << "," << x.col << ")" << endl;
//    }
//}
//
//bool IsPass(int** maze, int N, int M, Postion pos)
//{
//    if (pos.row >= 0 && pos.row < N && pos.col >= 0 && pos.col < M
//        && maze[pos.row][pos.col] == 0)
//    {
//        return true;
//    }
//    else
//    {
//        return false;
//    }
//
//}
//
//bool GetMazePath(int** maze, int N, int M, Postion cur)
//{
//    // 如果走到出口
//    s1.push(cur);
//    if (cur.row == N - 1 && cur.col == M - 1)
//    {
//        return true;
//    }
//
//    //探测cur位置的上下左右四个方向
//    Postion next;
//    maze[cur.row][cur.col] = 2;
//    //上
//    next = cur;
//    next.row -= 1;
//    if (IsPass(maze, N, M, next))
//    {
//        if (GetMazePath(maze, N, M, next))
//        {
//            return true;
//        }
//    }
//
//    //下
//    next = cur;
//    next.row += 1;
//    if (IsPass(maze, N, M, next))
//    {
//        if (GetMazePath(maze, N, M, next))
//        {
//            return true;
//        }
//    }
//
//    //左
//    next = cur;
//    next.col -= 1;
//    if (IsPass(maze, N, M, next))
//    {
//        if (GetMazePath(maze, N, M, next))
//        {
//            return true;
//        }
//    }
//
//    //右
//    next = cur;
//    next.col += 1;
//    if (IsPass(maze, N, M, next))
//    {
//        if (GetMazePath(maze, N, M, next))
//        {
//            return true;
//        }
//    }
//    s1.pop();
//    return false;
//}
//
//int main() {
//
//    int N = 0, M = 0;
//    cin >> N >> M;
//    int** maze = new int* [N];
//    for (int i = 0; i < N; i++)
//    {
//        maze[i] = new int[M];
//    }
//    //二维数组输入
//    for (int i = 0; i < N; ++i)
//    {
//        for (int j = 0; j < M; j++)
//        {
//            cin >> maze[i][j];
//        }
//    }
//    //PrintMaze(maze,N,M);
//    Postion entry = { 0,0 };
//
//    if (GetMazePath(maze, N, M, entry))
//    {
//        PrintPass(s1);
//    }
//    else
//    {
//        cout << "没有通路";
//    }
//    for (int i = 0; i < N; i++)
//    {
//        free(maze[i]);
//    }
//    free(maze);
//    maze = NULL;
//    return 0;
//}
