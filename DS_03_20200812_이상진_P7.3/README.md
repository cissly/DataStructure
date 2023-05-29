
1 과제설명

연결리스트 기반의 이진 트리를 구현해보자

BT_Node* BT_Create_Node(int newData)
void BT_Destroy_Node(BT_Node* node)
void BT_Make_Left_Sub_Tree(BT_Node* parent, BT_Node * sub)
void BT_Make_Right_Sub_Tree(BT_Node * parent, BT_Node * sub)
void BT_Preorder_Traversal(BT_Node* node);
void BT_Inorder_Traversal(BT_Node* node);
void BT_Postorder_Traversal(BT_Node* node);
void BT_Count_Node(BT_Node* node, int* count);
void BT_Count_Leaf(BT_Node* node, int* count);

2 소스코드

첨부

3 고찰

앞서 만든 트리와 달리 연결리스트를 기반으로 이진 트리를 만드는 과정을 진행하였고 이진 트리의 순회 방식에 대하여 그리고 그 순회방법에 따른 함수들을 각각 구현하여보았다.
이전까지의 트리를 만드는 과정을 통해 어느정도 트리를 만드는 요령을 알고 있었고 이를 바탕으로 어느정도 순조롭게 만들 수 있었다. 순회방법에 따른 함수들 또한 간단하게 재귀함수를 이용해서 해결 할 수 있었다.
