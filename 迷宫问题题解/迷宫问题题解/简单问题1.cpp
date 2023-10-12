///*���ӣ�https://www.nowcoder.com/questionTerminal/cf24906056f4488c9ddb132f317e03bc
//��Դ��ţ����
//����һ����ά���� N*M ���� 5 �� 5 ��������ʾ��
//int maze[5][5] = {
//0, 1, 0, 0, 0,
//0, 1, 1, 1, 0,
//0, 0, 0, 0, 0,
//0, 1, 1, 1, 0,
//0, 0, 0, 1, 0,
//};
//��������:
//���������������ֱ��ʾ��ά�������������������������Ӧ�����飬���е�1��ʾǽ�ڣ�0��ʾ�����ߵ�·���Թ�ֻ��һ��ͨ����
//�������:
//���Ͻǵ����½ǵ����·������ʽ��������ʾ��
//ʾ��1
//����
//5 5
//0 1 0 0 0
//0 1 1 1 0
//0 0 0 0 0
//0 1 1 1 0
//0 0 0 1 0
//���
//(0,0)
//(1,0)
//(2,0)
//(2,1)
//(2,2)
//(2,3)
//(2,4)
//(3,4)
//(4,4)
//ʾ��2
//����
//5 5
//0 1 0 0 0
//0 1 0 1 0
//0 0 0 0 1
//0 1 1 1 0
//0 0 0 0 0
//���
//(0,0)
//(1,0)
//(2,0)
//(3,0)
//(4,0)
//(4,1)
//(4,2)
//(4,3)
//(4,4)
//˵��
//ע�⣺����б���ߣ���     */
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
//    // ����ߵ�����
//    s1.push(cur);
//    if (cur.row == N - 1 && cur.col == M - 1)
//    {
//        return true;
//    }
//
//    //̽��curλ�õ����������ĸ�����
//    Postion next;
//    maze[cur.row][cur.col] = 2;
//    //��
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
//    //��
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
//    //��
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
//    //��
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
//    //��ά��������
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
//        cout << "û��ͨ·";
//    }
//    for (int i = 0; i < N; i++)
//    {
//        free(maze[i]);
//    }
//    free(maze);
//    maze = NULL;
//    return 0;
//}
