#include<iostream>
#define MAX 20
#define INF 999
using namespace std;

class prims
{
  public:
       int v,e,G[MAX][MAX];
       void init()
       {
         int m,n,cost;
         cout<<"\nEnter number of vertices:";
         cin>>v;
         for(int i=1;i<=v;i++)
         {
           for(int j=1;j<=v;j++)
           {
               G[i][j]=INF;
            }
         }
         cout<<"\nEnter number of edges:";
         cin>>e;
         for(int i=1;i<=e;i++)
         {
           cout<<"\nEnter start & end vertex & cost:";
           cin>>m>>n>>cost;
           G[m][n]=cost;
           G[n][m]=cost;
        }
       }
       void primfuc()
       {
         int i,min;
         int mincost=0;
         int visited[MAX];
         int lowcost[MAX];
         int from[MAX];
         
         cout<<"\nMinimum spanning tree ";
         
         for(int i=1;i<=v;i++)
         {
           lowcost[i]=G[1][i];
           from[i]=1;
           visited[i]=0;
         }
         visited[1]=1;
         
         for(int i=1;i<v;i++)
         {
           int vertex;
           
           min=INF;
           for(int j=2;j<=v;j++)
           {
             if(!visited[j] && min>lowcost[j] )  
             {
               min=lowcost[j];
               vertex=j;
             }
           }
           
           cout<<"\nEdge:"<<from[vertex]<<" "<<vertex<<"\n";
           
           mincost=mincost + lowcost[vertex];  
           visited[vertex]=1;
           
           for(int j=1;j<=v;j++)
           {
             if(!visited[j] && lowcost[j]>G[vertex][j] )
             {
               lowcost[j]=G[vertex][j];
               from[j]=vertex;
              }
            }
          }  
           cout<<"cost of MST:-"<<mincost<<"\n";                          
       }
     }; 
      int main()
      {
        prims obj;
        obj.init();
        obj.primfuc();
        return 0;
        }      
                 
  
