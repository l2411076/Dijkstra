#include <iostream>
#include <vector>
using namespace std;
const int inf = 999999;
const int n = 6;
int L[n][n]={
    0,  7,  9,inf,inf, 14,
    7,  0, 10, 15,inf,inf,
    9, 10,  0, 11,inf,  2,
  inf, 15, 11,  0,  6,inf,
  inf,inf,inf,  6,  0,  9,
   14,inf,  2,inf,  9,  0
};
int dis[n];
vector<int> path[n];

int main()
{
    for(int i=0;i<n;i++)
    {
        dis[i] = L[0][i];
        path[i].push_back(1);
        for(int a=0;a<path[i].size();a++)
        {
            cout<<"path0:"<<path[i][a]<<endl;
            cout<<"dis0:" <<dis[i]<<endl;
        }
        cout<<"+++++++"<<endl;        
        path[i].push_back(i+1);
    }
    for(int i =1;i<n;i++)
    {
        for(int j =0;j<n;j++)
        {
            if(dis[i] > dis[j]+L[j][i])
            {
                cout<<"i:"<<i<<"j:"<<j<<endl;
                dis[i] = dis[j] + L[j][i];
                //cout<<"dis1:"<<dis[i]<<endl;
                path[i].clear();
                path[i].insert(path[i].end(),path[j].begin(),path[j].end());
                
                for(int k=0;k<path[i].size();k++)
                {
                       cout<<"path1:"<<path[i][k]<<endl;
                       cout<<"dis1:" <<dis[i]<<endl;
                }
                cout<<"****"<<endl;

                path[i].push_back(i+1);
                
            }
        }
        for(int m=0;m<i;m++)
        {
            for(int j=0;j<n;j++)
            {
                if(dis[m] > dis[j]+L[j][m])
                {
                    dis[m] = dis[j]+L[j][m];
                    cout<<"m:"<<m<<"j:"<<j<<endl;
                    path[m].clear();
                    path[m].insert(path[m].end(),path[j].begin(),path[j].end());
                    for(int n=0;n<path[n].size();n++)
                    {
                        cout<<"path2:"<<path[m][n]<<endl;
                        cout<<"dis2:" <<dis[m]<<endl;
                    }
                    cout<<"------"<<endl;
                    
                    path[m].push_back(m+1);
                    
                }
            }
        }
    }

    vector<int>::iterator ite;
    for(int i=0;i<n;i++)
    {
        cout<<"原点1到"<<i+1<<"的最短路径长度："<<dis[i]<<endl<<"Path:";
        for(ite = path[i].begin();ite!=path[i].end();++ite)
        {
            if(ite ==path[i].begin())
            {
                cout<<*ite;
            }
            else
            {
                cout<<"->"<<*ite;
            }
        }
        cout<<endl;
    }
    return 0;
}