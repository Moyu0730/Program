#include "iostream"
#include <ctime>
using namespace std;
int main()
{
srand(time(NULL));
int seat[6][8];
int *p = (int*)seat;
int i;
//初始化,每个位置是编号1-48的学生
for(i = 0; i < 48; i++)
    p[i] = i + 1;
//打乱顺序
while(--i)
{
int changePos = rand() % (i + 1);
int tmp = p[i];
p[i] = p[changePos];
p[changePos] = tmp;
}
//满足特殊要求
cout << "输入特殊要求:(以任意字母或0结束输入)" << endl;
int studentId;
while((cout << "输入学生编号: ", cin >> studentId) && studentId > 0 &&
studentId < 49)
{
int row;
while((cout << "输入要求排数: ", cin >> row))
if(row > 0 && row < 7)
break;
//查找该生原来别分配的位置
for(i = 0; i < 48; i++)
if(p[i] == studentId)
break;
//和第row排的任意位置交换
if(row == i / 8+1)
continue;
int column = rand() % 8;
int tmp = p[i];
p[i] = seat[row - 1][column];
seat[row - 1][column] = tmp;
}
//输出最终结果
cout << "座位安排如下:" << endl;
for(i = 0; i < 6; i++)
{
for(int j = 0; j < 8; j++)
cout.width(2), cout << seat[i][j] << ' ';
cout << endl;
}
}
