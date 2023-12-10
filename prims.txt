//prims

#include <bits/stdc++.h>
using namespace std;
#define V 5
#define INF 100

int G[V][V]=
{
    { 0, 5, 1, 0, 2 },
    { 5, 0, 0, 3, 1 },
    { 1, 0, 0, 7, 0 },
    { 0, 3, 7, 0, 0 },
    { 2, 1, 0, 0, 0 } 
};

int main()
{
    int edge;
    int selected [V];
    memset(selected,false,sizeof(selected));
    
    edge=0;
    selected[0]=true;
    int x;
    int y;
    
    cout<<"Edge"<<":"<<"Weight\n";
    
    while(edge<V-1)
    {
        int min =INF;
        x=0;
        y=0;
        
        for(int i=0;i<V;i++)
        {
            if (selected[i])
            {
                for (int j=0;j<V;j++)
                {
                    if(!selected[j]&&G[i][j])
                    {
                        if (min >G[i][j])
                        {
                            min=G[i][j];
                            x=i;
                            y=j;
                        }
                    }
                    
                } 
            }
        }
        cout<<x<<"_"<<y<<":"<<G[x][y];
        cout<<endl;
        selected[y]=true;
        edge++;
    }
    return 0;
}    