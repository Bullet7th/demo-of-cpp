#include<iostream>
#include<math.h>
using namespace std;

class puzzle_solver
{
public:
	puzzle_solver();
	void puzzle_input();
	void puzzle_solve();
	void puzzle_start();
private:
	int puzzle[10];
};

puzzle_solver::puzzle_solver()//数组初始化
{
	int i;
	for(i=0;i<10;i++)puzzle[i]=0;
}

void puzzle_solver::puzzle_input()//输入
{
	int i;
	for(i=0;i<10;i++)
	{
		cin>>puzzle[i];
		if(puzzle[i]==0)break;
	}
}

void puzzle_solver::puzzle_solve()
{
	int object;
	int i,j,k;
	int number[10];
	int score=0;
	int check_num=0;
	int check_flag=0;
	cout<<"ob"<<endl;
	cin>>object;

	for(i=0;i<50;i++)
	{
		for(j=0;j<10;j++)
		{
			number[j]=puzzle[j]*pow(-1,rand()%2);
			score+=number[j];
		}
		if(score%object==0)
		{
			if(score==0)//结果为0的情况
			{
				for(j=0;j<10;j++)
				{
					for(k=j;k<10;k++)
					{
						check_num+=number[k];//暂时用check_num代替score来进行检测
						if((check_num==object)||(check_num==-object))
						{
							check_flag=1;//check_flag用来检测是否出现指定的数，ob或者-ob
							break;
						}
						if(check_flag)break;
					}
					if(check_flag)break;
					check_num=0;
				}
				if(check_flag)cout<<"flag=1"<<endl;
				for(j=0;j<10;j++)cout<<number[j]<<"  ";
				cout<<score<<endl;
				check_flag=0;
			}
			else if(score==object)//结果为ob的情况
			{
				for(j=0;j<10;j++)
				{
					for(k=j;k<10;k++)
					{
						check_num+=number[k];
						if(check_num==-object)
						{
							check_flag=1;
							break;
						}
						if(check_flag)break;
					}
					if(check_flag)break;
					check_num=0;
				}
				if(!check_flag)
				{
					for(j=0;j<10;j++)cout<<number[j]<<"  ";
					cout<<score<<endl;
				}
				check_flag=0;
			}
			else if(score==-object)//结果为-ob的情况
			{
				for(j=0;j<10;j++)
				{
					for(k=j;k<10;k++)
					{
						check_num+=number[k];
						if(check_num==object)
						{
							check_flag=1;
							break;
						}
						if(check_flag)break;
					}
					if(check_flag)break;
					check_num=0;
				}
				if(!check_flag)
				{
					for(j=0;j<10;j++)cout<<number[j]<<"  ";
					cout<<score<<endl;
				}
				check_flag=0;
			}
			else{}//其他情况
		}
		score=0;
	}
}

void puzzle_solver::puzzle_start()
{
	while(1)
	{
		puzzle_input();
		puzzle_solve();
	}
}

void main()
{
	puzzle_solver object_1;
	object_1.puzzle_start();
}
