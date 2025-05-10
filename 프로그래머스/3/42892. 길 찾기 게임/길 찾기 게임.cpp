#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
    전위 & 후위 순회 결과 반환하기
    방문지점들로 이진트리 만들기
    방문지점들은 x, y 정수좌표 /
    모든 지점의 x축은 서로 다 다름 /
    같은 레벨인 지점의 y 좌표는 동일 /
    자식노드의 y값은 항상 부모의 y보다 작음 /
    left subtree의 모든 x값은 해당 서브트리의 루트의 x값보다 모두 작음/
    right에 대해선 모두 큼
    
    한 팀은 전위 순회 & 다른 팀은 후위 순회
    
    ---
    1. 모든 정점들의 좌표가 담긴 nodeinfo 배열로 이진트리를 만든다.
        이 때, 해당 배열의 index+1이 노드 번호!!
    2. 재귀함수를 이용하여 전위, 후위 순회한 결과를 반환한다
*/

struct Node {
    int x, y, number;
    Node* left {nullptr};
    Node* right{nullptr};
    Node(int x, int y, int number) : x(x), y(y), number(number) {} 
    
    void Insert(Node* newNode);
};

void Node::Insert(Node* newNode)
{
    if(newNode->x < x)
    {
        if(!left)
            left = newNode;
        else
            left->Insert(newNode);
    }
    else
    {
        if(!right)
            right = newNode;
        else
            right->Insert(newNode);
    }
}

bool comp(const vector<int>& n1, const vector<int>& n2)
{
    if(n1[1] == n2[1]) // y값 비교
        return n1[0] < n2[0]; // x값 오름차순
    return n1[1] > n2[1]; // y값 내림차순
}

/*
      1
    2   3
*/
void PreOrder(vector<int>& preOrder, Node* curNode)
{
    if(!curNode) return;
    
    preOrder.push_back(curNode->number);
    PreOrder(preOrder, curNode->left);
    PreOrder(preOrder, curNode->right);
}

/*
      3
    1   2
*/
void PostOrder(vector<int>& postOrder, Node* curNode)
{
    if(!curNode) return;
    
    PostOrder(postOrder, curNode->left);
    PostOrder(postOrder, curNode->right);
    postOrder.push_back(curNode->number);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    
    for(int i=0; i<nodeinfo.size(); ++i)
        nodeinfo[i].push_back(i+1);
    
    // 위쪽(y값이 큰) 노드부터 넣기 위해 정렬을 해준다
    sort(nodeinfo.begin(), nodeinfo.end(), comp);
    
    vector<int> rootInfo = nodeinfo[0];
    // (x,y,number)
    Node* Root = new Node(rootInfo[0], rootInfo[1], rootInfo[2]);
    
    for(int i=1; i<nodeinfo.size(); ++i)
    {
        vector<int>& info = nodeinfo[i];
        Root->Insert(new Node(info[0], info[1], info[2]));
    }
    
    vector<int> preOrder;
    PreOrder(preOrder, Root);
    
    vector<int> postOrder;
    PostOrder(postOrder, Root);
    
    answer.push_back(preOrder);
    answer.push_back(postOrder);
    
    return answer;
}