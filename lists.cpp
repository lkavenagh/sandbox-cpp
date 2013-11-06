#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

void initNode(struct Node *head,int n){
    head->data = n;
	head->next = NULL;
}

void appendNode(struct Node* head, int n) {
    Node* newNode = new Node;
    initNode(newNode, n);
    
    Node* cur = head;
    while (cur != NULL) {
        if (cur->next == NULL) {
            cur->next = newNode;
            return;
        }
        cur = cur->next;
    }
}

void traverseList(struct Node* head) {
    Node* cur = head;
    while (cur != NULL) {
        cout << cur->data << endl;
        cur = cur->next;
    }
}

struct Node* reverseList(struct Node** head) {
    Node* pre = *head;
    if(pre == NULL) {return *head;}
    Node* cur = pre->next;
    if(cur == NULL) {return *head;}
    Node* next = cur->next;
    
    pre->next = NULL;
    
    while (cur->next != NULL) {
        cur->next = pre;
        pre = cur;
        cur = next;
        next = cur->next;
    }
    cur->next = pre;
    *head = cur;
    return *head;
}

int main()
{
    Node* myList = new Node;
    initNode(myList, 0);

    for (int i=1; i<=10; ++i) {
      appendNode(myList, i);
    }
    
    traverseList(myList);
    reverseList(&myList);   
    traverseList(myList);
    return 0;
}