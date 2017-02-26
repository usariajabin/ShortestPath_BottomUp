#include<iostream>
using namespace std;

int main(){
    const int rows = 5;
    const int cols = 6;
    int toPath[6];
struct memoarray {
        int cost;
        int trace;
  };
memoarray memo[rows][cols]={0};
    
    int weight[rows][cols]={
        {3,4,1,2,8,6},
        {6,1,8,2,7,4},
        {5,9,3,9,9,5},
        {8,4,1,3,2,6},
        {3,7,2,8,6,4}};
    
    int n=0;
    while(n<rows){
        memo[n][0].cost=weight[n][0];
        n++;
   }

 for(int j=1;j<cols;j++){
        for(int i=0;i<rows;i++){
            int left = weight[i][j] + memo[i][j-1].cost;
            int up = weight[i][j] + memo[(i+4)%rows][j-1].cost;
            int down = weight[i][j] + memo[(i+1)%rows][j-1].cost;
            
            int min=left;    

 memo[i][j].trace=0;
            if (up<min) { 
                min=up;
                memo[i][j].trace=-1;
            } 
if (down<min) { 
                min=down;
                memo[i][j].trace=1;
            } 
            
            memo[i][j].cost=min; 
        }
    }
 int ex[rows];
    
    for( int i=0; i<rows; i++)
        ex[i]=memo[i][cols-1].cost;
    
    int min=ex[0];
    toPath[0]=0;
    for(int i=1; i<rows;i++)
        if(min>ex[i]){
            min=ex[i];
            toPath[0]=i;
        }

int j=6;
    for (int k=1; k<6; k++)
        toPath[k]=toPath[k-1] + memo[toPath[k-1]][--j].trace;
    cout<<"the shortest path is of length "<<min<<endl<<"the path is:"<<endl;
    for (int j=5; j>=0; j--) 
        cout<<toPath[j]<<",";
    cout<<endl;
    return 0;
}            
