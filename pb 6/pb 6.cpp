#include<iostream>
#include <string.h>
#include <fstream>
using namespace std;
#define MAX 99999

int matrix[50][50];
int vertices;
int edge[20][20];
void edge_length()
{
    for(int i=1; i<=vertices; i++)
        for(int j=1; j<=vertices; j++)
            if(matrix[i][j]!=0)
                edge[i][j]=matrix[i][j];
            else
                edge[i][j]=MAX;

}

int dist[20],predecessor[20];
void afis(int start_node)
{
    int l;
    for(int i=1; i<=vertices; i++)
        if(i!=start_node)
        {
            cout<<endl<<"Distance of node"<<i<<"="<<dist[i];
            cout<<endl<<"Path="<<i;
            l=i;
            l=predecessor[l];
            cout<<"<-"<<l;

            while(l!=start_node)
            {
                l=predecessor[l];
                cout<<"<-"<<l;

            }

        }
}

int visit[20];

void dijkstra(int start_node)
{
    int minimum,node_next,k;
    edge_length();
    for(int i=1; i<=vertices; i++)
    {
        dist[i]=edge[start_node][i];
        predecessor[i]=start_node;
    }

    visit[start_node]=1;
    dist[start_node]=0;

    for(int i=1; i<=vertices; i++)
    {
        minimum=MAX;
        for(int j=1; j<=vertices; j++)
            if(visit[j]==0&&dist[j]<minimum)
            {
                minimum=dist[j];
                node_next=j;
            }

        visit[node_next]=1;
        for(int j=1; j<=vertices; j++)
            if(visit[j]==0)
            {
                k=minimum+edge[node_next][j];

                if(k<dist[j])
                {
                    predecessor[j]=node_next;
                    dist[j]=k;

                }
            }
    }
    afis(start_node);
}


void read_vertices(int n)
{
    int  vertex1,vertex2,weight;


    while(vertex1!=0&&vertex2!=0)
    {
        cout<<"Enter the path and the length(ex 1 2 5)"<<endl<<"Enter 0 0 0 if you want to quit"<<endl;
        cin>>vertex1>>vertex2>>weight;
        matrix[vertex1][vertex2]=weight;
        matrix[vertex2][vertex1]=weight;
    }

}

int main()
{
    cout<<"How many vertices do you want to enter?: ";
    cin>>vertices;

    read_vertices(vertices);
    edge_length();
    for(int i=1; i<=vertices; i++)
    {
        for(int j=1; j<=vertices; j++)
            cout<<edge[i][j]<<" ";
        cout<<endl;
    }
    cout<<"Enter the star node: ";
    int start_node;
    cin>>start_node;
    dijkstra(start_node);
}
