/*
 * 题目：填充每个节点的下一个右侧节点指针
 * 链接：https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node/
 */

struct Node {
    int val;
    Node* left;
    Node* right;
    Node* next;
};

Node* connect(Node* root) {
    if (!root) return nullptr;
    connectTwoNodes(root->left, root->right);
    
    return root;
}

void connectTwoNodes(Node* left, Node* right) {
    if (!left || !right) return;
    
    // 连接两个节点
    left->next = right;
    // 连接相同父节点的两个子节点
    connectTwoNodes(left->left, left->right);
    connectTwoNodes(right->left, right->right);
    // 连接不同父节点的两个子节点
    connectTwoNodes(left->right, right->left);
}