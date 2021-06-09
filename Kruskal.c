#include <stdio.h>

#define MAX_v 8 // 정점의 개수
#define INF 10000 // 경로가 존재하지 않음을 뜻함
#define MAX_e 15 // heap의 최대크기

typedef struct{
    int p; // 정점 1
    int q; // 정점 2
    int weight; // 가중치
} element;
 
typedef struct{
    element heap[MAX_e];
    int size;
} Heap;

int parent[MAX_v]; // 정점의 부모 노드
int num[MAX_v]; // 집합의 크기

void insert_min(Heap *h, element e){
    int i = ++(h->size);
    
    while ((i != 1) && (e.weight < h->heap[i / 2].weight)){
        h->heap[i] = h->heap[i / 2]; // 현재노드를 부모노드로
        i /= 2; // 부모노드의 인덱스로 설정.
    }
    h->heap[i] = e;
}

void insert(Heap *h, int p, int q, int weight){
    element e;
    e.p = p;
    e.q = q;
    e.weight = weight;
    insert_min(h, e);
}

int find(int v){
    int p, r, i = -1;
 
    for (i = v; (p = parent[i]) >= 0; i = p); // 부모노드가 -1일때까지(루트) 반복
    r = i; // r에 루트 저장
    for (i = v; (p = parent[i]) >= 0; i = p){
        parent[i] = r; // v의 조상이 r을 향하게
    }
    return r;
}

void merge(int p, int q){
    if (num[p] < num[q]){ // 더 큰쪽으로 부모노드 merge
        parent[p] = q;
        num[q] += num[p];
    }else{
        parent[q] = p;
        num[p] += num[q];
    }
}
 
element delete_min_heap(Heap *h){
    int parent=1, child=2;
    element e1, e2;
 
    e1 = h->heap[1]; // 가장 작은 값인 루트노드 값 저장
    e2 = h->heap[(h->size)--]; // 마지막 노드 값 저장하고 heap size--
    
    while (child <= h->size){ // heap 안에서 비교
        if ((child < h->size) && (h->heap[child].weight) > h->heap[child + 1].weight ) child++; // 오른쪽 자녀가 있을때
        if (e2.weight <= h->heap[child].weight) break; // e2가 더 작으면 break

        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2; // 다음 자녀
    }
    h->heap[parent] = e2;
    return e1;
}

void kruskal(Heap *h){
    int edge=0, sum=0, p, q;
    element e;

    while (edge < (MAX_v - 1)){ // 간선의 수 < (n - 1)
        e = delete_min_heap(h); // 작은 가중치 간선 찾은 후 heap에서 제거
        p = find(e.p);   // 정점 u의 집합 번호
        q = find(e.q);   // 정점 v의 집합 번호
 
        if (p != q){ // 서로 다른 집합일 경우
            printf("[V%d-V%d] 연결 가중치 : %d \n", e.p+1, e.q+1, e.weight);
            sum+=e.weight;
            edge++;
            merge(p, q);  // 두 개의 집합 merge
        }
    } printf("Kruscal algorithm : %d\n",sum); // 총 거리 출력
}
 
int main()
{
    Heap h;
    h.size = 0;
    
    // 정점 값 추가
    insert(&h,0,1,11);
    insert(&h,0,2,9);
    insert(&h,0,3,8);
    insert(&h,1,2,3);
    insert(&h,2,6,1);
    insert(&h,1,4,8);
    insert(&h,1,5,8);
    insert(&h,2,3,15);
    insert(&h,2,5,12);
    insert(&h,3,6,10);
    insert(&h,4,5,7);
    insert(&h,4,7,4);
    insert(&h,5,7,5);
    insert(&h,6,7,2);

    for (int i = 0; i < MAX_v; i++){ // 집합 초기화
        parent[i] = -1;
        num[i] = 1;
    }
    
    kruskal(&h);
}
