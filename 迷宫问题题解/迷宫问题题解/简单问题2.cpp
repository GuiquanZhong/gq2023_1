/*
����
С������һ�첻С��������һ�������Թ�,С����ϣ�����Լ���ʣ������ֵP������������Թ���
Ϊ���������,��������һ��n*m�ĸ����Թ�,�Թ�ÿ��λ��Ϊ0����1,
0�������λ�����ϰ���,С���ܴﵽ�������λ��;1����С���ܿ��Դﵽ��λ�á�С���ܳ�ʼ��(0,0)λ��,�����Թ��ĳ�����(0,m-1)
(��֤������λ�ö���1,���ұ�֤һ������㵽�յ�ɴ��·��),С�������Թ���ˮƽ�ƶ�һ����λ������Ҫ����1������ֵ,
������һ����λ������Ҫ����3����λ������ֵ,�����ƶ�����������ֵ,��С���ܵ�����ֵ����0��ʱ��û�е������,
С���ܽ��޷������Թ���������Ҫ�����С���ܼ�����ܷ��ý�ʣ������ֵ�����Թ�(���ﵽ(0,m-1)λ��)��
����������
�������n+1��:
��һ��Ϊ��������n,m(3 <= m,n <= 10),P(1 <= P <= 100)
��������n��:
ÿ��m��0����1,�Կո�ָ�
���������
����������Թ�,�����һ������������С��·��,�����ʽ��������ʾ;������������Թ�,�����"Can not escape!"�� �������ݱ�֤��Ψһ
ʾ��1
���룺
4 4 10 1 0 0 1 1 1 0 1 0 1 1 1 0 0 1 1
����
�����
[0,0],[1,0],[1,1],[2,1],[2,2],[2,3],[1,3],[0,3]*/
#include <iostream>
#include<stack>
using namespace std;
struct Postion
{
    int row;
    int col;
};

stack<Postion> s1;   //·��
stack<Postion>mins;  //��̵�·��

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
    // ����ߵ�����
    s1.push(cur);
    if (cur.row == 0 && cur.col == M - 1)
    {
        //����ҵ��˸��̵�·��������mins
        if (mins.empty() || s1.size() < mins.size())
        {
            mins = s1;
        }
    }
    //̽��curλ�õ����������ĸ����� 
    Postion next;
    maze[cur.row][cur.col] = 2;
    //��
    next = cur;
    next.row -= 1;
    if (IsPass(maze, N, M, next))
    {
        GetMazePath(maze, N, M, next, P - 3);

    }

    //��
    next = cur;
    next.row += 1;
    if (IsPass(maze, N, M, next))
    {
        GetMazePath(maze, N, M, next, P);

    }
    //��
    next = cur;
    next.col -= 1;
    if (IsPass(maze, N, M, next))
    {
        GetMazePath(maze, N, M, next, P - 1);
    }
    //��
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
    //��ά��������
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
