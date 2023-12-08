// Sequential Coloring of a Graph

#include <bits/stdc++.h>
using namespace std;

void sequentialColoring(int **adj, int nv, int ne){
  int *colors = new int[nv];
  for(int i=0; i<nv; i++)
    colors[i] = -1;
  for(int i=0; i<nv; i++){ // for each vertex
    int j;
    for(j=1; j<=nv; j++){ // find a color
      bool colorUsed = false;
      for(int k=0; k<nv; k++){ // check if color is used
        if(adj[i][k] && colors[k] == j){ // if color is used
          colorUsed = true;
          break;
        }
      }
      if(!colorUsed)
        break;
    }
    colors[i] = j;
  }
  for(int i=0; i<nv; i++)
    cout << "Vertex " << i << ": Color " << colors[i] << endl;
}

int main(){
  int nv, ne;
  cin >> nv >> ne;
  int **adj = new int*[nv];
  for(int i=0; i<nv; i++)
    adj[i] = new int[nv];
  for(int i=0; i<nv; i++)
    for(int j=0; j<nv; j++)
      cin >> adj[i][j];
  sequentialColoring(adj, nv, ne);
  return 0;
}