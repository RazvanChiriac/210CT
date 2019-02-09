#include<iostream>
#include <string.h>
#include <fstream>
using namespace std;

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

int visited_dfs[100];

void dfs(int start_node)
{
    int j;

    visited_dfs[start_node]=1;

    for(j=1; j<=vertices; j++)
        if(matrix[start_node][j]==1 && visited_dfs[j]==0)
            dfs(j);

}


void isConnected()
{
    int nr=0;
    for(int i=1; i<=vertices; i++)
    {
        if(visited_dfs[i]==1)
            nr++;
    }
    if(nr==vertices)
        cout<<"Yes";
    else
        cout<<"No";
}

int main()
{

    cout<<"How many vertices do you want to enter?: ";
    cin>>vertices;

    read_vertices(vertices);

    for(int i=1; i<=vertices; i++)
    {
        for(int j=1; j<=vertices; j++)
            cout<<matrix[i][j]<<" ";
        cout<<endl;
    }


    cout<<endl;
    dfs(2);

    isConnected();


}

