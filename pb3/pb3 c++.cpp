#include<iostream>
#include <string.h>
#include <fstream>
#include <cstdlib>
using namespace std;

int matrix[50][50];
int vertices;

void read_vertices(int n)
{
    int  vertex1,vertex2;

    while(vertex1!=0&&vertex2!=0)
    {  LOOP:
        cout<<"Enter the path"<<endl;
        cout<<"Example 1 2 / enter 0 0 for exit"<<endl;

        cin>>vertex1>>vertex2;
        if(vertices<vertex1|| vertices<vertex2)
        {  cout<<"The path is wrong, enter the numbers again"<<endl;
           goto LOOP;
           }
        matrix[vertex1][vertex2]=matrix[vertex2][vertex1]=1;
    }

}


void bfs(int start_node,int end_node)
{
    int start_q, end_q, i, vertex, q[100], visited[100] = { 0 }, road[50], road_idx=0;
    start_q=end_q=1; // the beginning and the end of the tail
    visited[start_node]=1;
    q[start_q]=start_node;
    road[road_idx]=start_node;
    road_idx++;;
    while(start_q<=end_q)
    {
        vertex=q[start_q];

        for(i=1; i<=vertices; i++)
        {
            if(matrix[vertex][i]==1 && visited[i]==0)
            {
                end_q++;
                q[end_q]=i;
                road[road_idx]=i;
                road_idx++;
                visited[i]=1;
                if(i==end_node)
                {
                    start_q=end_q+1;
                    break;
                }


            }
        }
        start_q++;

    }
    ofstream out;
    out.open ("text.txt");
    if(visited[end_node]==1)
        for(int i=0; i<road_idx; i++)

            out<< road[i]<<" ";

    else
    {

        out<< "No road\n";
        out.close();
    }
}



int main()
{
    ofstream out;
    out.open ("text.txt");

     int node1,node2;
    cout<<"How many vertices do you want to enter?: ";
    cin>>vertices;


    read_vertices(vertices);

    for(int i=1; i<=vertices; i++)
    {
        for(int j=1; j<=vertices; j++)
            cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
    cout<<"Check if there is a path between 2 nodes, enter the nodes: "<<endl;
    cin>>node1>>node2;

    bfs(node1,node2);
    out.close();

}
