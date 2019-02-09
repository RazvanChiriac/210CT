#include<iostream>
#include <string.h>
#include <fstream>
using namespace std;
ofstream out;




int matrix[50][50];
int vertices;



void read_vertices(int n)
{
    int  vertex1,vertex2;

    while(vertex1!=0&&vertex2!=0)
    {
        LOOP:
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


void bfs(int start_node)
{
    int start_q, end_q, i, vertex, q[100], visited[100] = { 0 };
    start_q=end_q=1; // the beginning and the end of the tail
    visited[start_node]=1;
    q[start_q]=start_node;
    out<<start_node<<" ";
    while(start_q<=end_q)
    {
        vertex=q[start_q];
        for(i=1;i<=vertices;i++)
        {
            if(matrix[vertex][i]==1 && visited[i]==0)
            {
                end_q++;
                q[end_q]=i;
                out<<i<<" ";
                visited[i]=1;
            }
        }
        start_q++;
    }
}


int visited_dfs[50];
void dfs(int start_node)
{ int j;
visited_dfs[start_node]=1;
out<<start_node<<" ";
for(j=1;j<=vertices;j++)
    if(matrix[start_node][j]==1 && visited_dfs[j]==0)
     dfs(j);

}


int main()
{

    out.open ("text.txt");


    cout<<"How many vertices do you want to enter?: ";
    cin>>vertices;

    read_vertices(vertices);

    for(int i=1; i<=vertices; i++)
    {
        for(int j=1; j<=vertices; j++)
            cout<<matrix[i][j]<<" ";
        cout<<endl;
    }

    bfs(2);
    out<<endl;
    dfs(2);

    out.close();

}
