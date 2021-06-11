#include <stdio.h>

#define N 5
#define W 9
int MAX=0;

int p[N]={20,30,35,12,3};
int w[N]={2,5,7,3,1};

int promissing(int weight, int profit, int level){
    int bound=profit;
    while(weight!=W){
        level++;
        if(level>=N) break;
        if(weight+w[level]>W){
            bound+=(W-weight)*(p[level]/w[level]);
            break;
        } else{
            bound+=p[level];
            weight+=w[level];
        }
    }
    return bound;
}

int DFS(int weight, int profit, int level){
    
    if(level>=N || weight>W) return 0;
    
    if((weight<=W) && (profit>MAX)) MAX=profit;
    if(promissing(weight,profit,level-1)<MAX) return 0;
    DFS(weight+w[level],profit+p[level],level+1);
    DFS(weight,profit,level+1);
    return 0;
}

int main(void) {
    DFS(0,0,0);
    printf("Best profit : %d\n",MAX);
    return 0;
}
