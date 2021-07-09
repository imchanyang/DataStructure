#include <iostream>
#include <crt_externs.h>
#include <vector>
#define endl '\n'
using namespace std;

class Node {
public:
    Node(int data)  // 멤버 변수 초기화시 초기화 리스트 사용 추천
        : mData(data)    // 멤버변수 data를 매개변수 data로 초기화
        , mPar(nullptr)  // par노드를 nullptr로 초기화 (C++ 11 부터 포인터 초기화시 NULL 대신에 nullptr을 권장하고 있음)
    {
    }

    // 이론 강의자료 p5 참고
    bool IsExternal() { return mChild_v.size() == 0;}
    bool IsRoot() { return mPar != nullptr; }

    // friend class 대신 Set / Get 함수 정의해서 사용하기
    int GetData() { return mData; }
    void SetData(int data) { mData = data; }
    Node* GetPar() { return mPar; }
    void SetPar(Node* par) { mPar = par; }

    void AddChild(Node* node) { mChild_v.push_back(node); }
    vector<Node*>& GetChild_v() { return mChild_v; }    // 참조 반환 https://boycoding.tistory.com/219 참고

private:
    int mData;
    Node* mPar;
    vector<Node*> mChild_v;
};

class Tree {
public:
    Tree(Node*);
    void insertNode(int, int);

    int GetRootData() { return mRoot->GetData(); }  // 루트노드의 데이터 반환
    void printPostorder() { postorder(mRoot); }
    void printPreorder() { preorder(mRoot); }

private:
    Node* mRoot;             // 루트 노드
    //vector<Node*> mNode_v;   // 모든 노드를 저장하는 벡터 ?? 이게 필요한 이유가 뭘까?? -> 노드 삽입시 사용하는데 공간 효율이 안좋은 문제가 있음.
    void preorder(Node*);
    void postorder(Node*);
};

Tree::Tree(Node* root)
    :mRoot(root)
{

}

//Tree::Tree(int data) {
//    Node* node = new Node(data);
//    mRoot = node;
//    mNode_v.push_back(node);
//}
//void Tree::insertNode(int par_data, int data)   // 새로운 노드 삽입 (입력: 부모 노드 data와 새로운 노드 data)
//{
//    for (auto parNode : mNode_v)                // 모든 노드를 저장하는 벡터 mNode_v를 루프를 통해 접근
//    {
//        if (parNode->GetData() == par_data) {   // 트리의 모든 노드 중에서 부모노드에 해당하는 노드를 탐색
//            Node* newNode = new Node(data);
//            newNode->SetPar(parNode);
//            parNode->AddChild(newNode);
//            mNode_v.push_back(newNode);
//            return;
//        }
//    }
//}
void Tree::preorder(Node* node) {
    if (node == nullptr)
        return;

    cout << node->GetData() << " ";
    for (auto childNode : node->GetChild_v())
    {
        preorder(childNode);
    }
}

void Tree::postorder(Node* node) {
    if (node == nullptr)
        return;

    for (auto childNode : node->GetChild_v())
    {
        postorder(childNode);
    }

    cout << node->GetData() << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);


    int T, N;
    int data[1'001] = { 0, }, newDepth, curDepth;
    vector<Node*> waitParent[1'001];

    cin >> T;
    while (T--)
    {
        cin >> N;

        for (int i = 0; i < N; i++)
        {
            cin >> data[i]; // 데이터 입력받음
        }

        curDepth = 0;
        Node* newNode = nullptr;
        for (int i = 0; i < N; i++)
        {
            cin >> newDepth;    // 깊이 입력 받음

            newNode = new Node(data[i]);
            waitParent[newDepth].push_back(newNode);

            if (curDepth - 1 == newDepth) // 부모 찾은 거임, 모였던 동기들 함께 부모랑 연결해줘야함.
            {
                for (auto childNode : waitParent[curDepth])
                {
                    newNode->AddChild(childNode);
                    childNode->SetPar(newNode);
                }

                waitParent[curDepth].clear();
            }
            else if (curDepth == newDepth) // 동기들 모이는 거임. 딱히 할일 없음.
                ;
            else if (curDepth < newDepth) // 동기들의 자식들이 모이기 시작하는 거임
                ;

            curDepth = newDepth;
        }
        Tree tree(newNode);
        tree.printPreorder();

    }



    return 0;
}
