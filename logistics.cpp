#include<bits/stdc++.h>
using namespace std;

class graph{
    int vertices;
    int ** adj;
    public:
    graph(int v){
        vertices = v;
        adj = new int*[v];
        for(int i =0;i<v;i++){
             adj[i] = new int[V];
              memset(adj[i], 0, v*sizeof(int)); 
        }
    }
    void addEdge(int u,int v,int weight){
        adj[u][v] = weight;
    }
    void print() 
    { 
        for (int u=0; u<V; u++) 
            { 
                for (int v=0; v<V; v++) 
                cout << adj[u][v] << " "; 
                cout << endl; 
            } 
    }

    int final_path[vertices+1]; 
  
 

bool visited[vertices]; 
  
 
int final_res = IverticesT_MAX; 
  
 
void copyToFinal(int curr_path[]) 
{ 
    for (int i=0; i<vertices; i++) 
        final_path[i] = curr_path[i]; 
    final_path[vertices] = curr_path[0]; 
} 
  
 
int firstMin( int i) 
{ 
    int min = IverticesT_MAX; 
    for (int k=0; k<vertices; k++) 
        if (adj[i][k]<min && i != k) 
            min = adj[i][k]; 
    return min; 
} 
  

int secondMin( int i) 
{ 
    int first = IverticesT_MAX, second = IverticesT_MAX; 
    for (int j=0; j<vertices; j++) 
    { 
        if (i == j) 
            continue; 
  
        if (adj[i][j] <= first) 
        { 
            second = first; 
            first = adj[i][j]; 
        } 
        else if (adj[i][j] <= second && 
                 adj[i][j] != first) 
            second = adj[i][j]; 
    } 
    return second; 
} 
  
 
void TSPRec(int curr_bound, int curr_weight, 
            int level, int curr_path[]) 
{ 
     
    if (level==vertices) 
    { 
     
        if (adj[curr_path[level-1]][curr_path[0]] != 0) 
        { 
     
            int curr_res = curr_weight + 
                    adj[curr_path[level-1]][curr_path[0]]; 
  
     
            if (curr_res < final_res) 
            { 
                copyToFinal(curr_path); 
                final_res = curr_res; 
            } 
        } 
        return; 
    } 
  
     
    for (int i=0; i<vertices; i++) 
    { 
      
        if (adj[curr_path[level-1]][i] != 0 && 
            visited[i] == false) 
        { 
            int temp = curr_bound; 
            curr_weight += adj[curr_path[level-1]][i]; 
  
      
            if (level==1) 
              curr_bound -= ((firstMin(adj, curr_path[level-1]) + 
                             firstMin(adj, i))/2); 
            else
              curr_bound -= ((secondMin(adj, curr_path[level-1]) + 
                             firstMin(adj, i))/2); 
  
      
            if (curr_bound + curr_weight < final_res) 
            { 
                curr_path[level] = i; 
                visited[i] = true; 
  
     
                TSPRec(adj, curr_bound, curr_weight, level+1, 
                       curr_path); 
            } 
  
      
            curr_weight -= adj[curr_path[level-1]][i]; 
            curr_bound = temp; 
  
      
            memset(visited, false, sizeof(visited)); 
            for (int j=0; j<=level-1; j++) 
                visited[curr_path[j]] = true; 
        } 
    } 
} 
  
  
void TSP() 
{ 
    int curr_path[vertices+1]; 
  
 
    int curr_bound = 0; 
    memset(curr_path, -1, sizeof(curr_path)); 
    memset(visited, 0, sizeof(curr_path)); 
  

    for (int i=0; i<vertices; i++) 
        curr_bound += (firstMin(adj, i) + 
                       secondMin(adj, i)); 
  

    curr_bound = (curr_bound&1)? curr_bound/2 + 1 : 
                                 curr_bound/2; 
  
 
    visited[0] = true; 
    curr_path[0] = 0; 
  
 
    TSPRec(adj, curr_bound, 0, 1, curr_path); 
} 

};


int main(){
    cout<<"enter no. of cities"<<endl;
    int v;
    cin>>v;
    graph g(v);
    bool check = true;
    while(check){
        int u,v,weight;
        cout<<"enter u,v and weight"<<endl;
        cin>>u>>v>>weight;
        int connect= 2;;
        cout<<"still more connections yes: 1 and no:0"<<endl;
        cin>>connect ;
        if(connect == 0){
            check = false;
        }
    }
    g.TSP();
    return 0;
}
