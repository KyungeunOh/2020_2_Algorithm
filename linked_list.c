#include <stdio.h>
#include <stdlib.h> // malloc 사용하기위한 라이브러리

typedef struct _TreeNode{
    struct _TreeNode *left;
    char value;
    struct _TreeNode *right;
} treenode; // left와 right, value 트리 형태로 구조체 선언 -> treenode로 typedef

treenode* searchNode(treenode* root, char c){ // 노드 탐색 함수
    treenode *n; // 재귀함수때문에 return이 제대로 작동되지 않는 경우를 방지
    if(root == NULL) return NULL; // NULL일 경우 NULL을 return
    if(root->value == c) return root; // value와 일치할경우 그때의 부모노드를 return
    else{
        n=searchNode(root->left,c); // left 재귀함수
        if(n!=NULL) return n; // return 반환값이 있을경우 바로 return 하기 위한 코드
        n=searchNode(root->right, c); // right 재귀함수
        if(n!=NULL) return n;
        return NULL;
    }
}
void treeInOrder(treenode *root){ // 중위 순회 방식으로 출력하기위한 함수
    if(root!=NULL){
        treeInOrder(root->left); // left 재귀함수
        printf("%c",root->value);
        treeInOrder(root->right); // right 재귀함수
    }
}

int main(){
    treenode *root = NULL; // 루트트리를 위한 treenode
    
    int n; // 노드 개수
    printf("노드의 개수 N(1≤N≤26)을 입력하시오. \n");
    scanf("%d",&n);
    getchar();
    
    for(int i=0; i<n; i++) {
        treenode *n1=malloc(sizeof(treenode)); // n1->value = parent;
        treenode *n2=malloc(sizeof(treenode));
        n2->left=NULL;
        n2->right=NULL;
        // 무한 재귀를 막기 위한 NULL 처리
        treenode *n3=malloc(sizeof(treenode));
        n3->left=NULL;
        n3->right=NULL;
        
        char parent, leftChild, rightChild;
        scanf("%c %c %c", &parent, &leftChild, &rightChild); // 부모, 왼쪽 자식, 오른쪽 자식 입력
        getchar();
        
        if(root==NULL) root=n1; // root에 n1 연결
        else n1 = searchNode(root, parent); // parent를 입력할 n1노드 탐색
        
        n1->value=parent;
        if(leftChild=='.') n2=NULL; // '.' 입력 처리 코드
        else n2->value=leftChild; // n2에 leftChild 삽입
        n1->left=n2; // n1에 n2 연결
        if(rightChild=='.') n3=NULL;
        else n3->value=rightChild; // n3에 rightChild 삽입
        n1->right=n3; // n1에 n3 연결
        
    }
    treeInOrder(root); // root 트리를 가리키고 있는 root 전달
    printf("\n");
}
