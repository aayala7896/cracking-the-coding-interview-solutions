#include<iostream>
#include <unordered_set>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

void appendToTail(ListNode* &head, int d){
    ListNode *end = new ListNode(d);
    if(head == nullptr){
        head = end;
        return;
    }
    
    ListNode *n = head;
    if(n->next == nullptr){
        n->next = end;
        return;
    }
    while(n->next != nullptr){
        n = n->next;
    }
    n->next = end;

}



//Delete given node that is not the first or last node. 
//Nothing shall be returned however, if given last node this algorithm would not work
// This approach is dependent on copying the givens node->next. Discuss this with interviewer!
bool deleteMiddleNode(ListNode* node) {
    //return false if node is at the end of the list
    if(node->next == nullptr){
        return false;
    }

    ListNode* temp = node->next;
    node->val = temp->val;
    node->next= temp->next;

    delete temp;

    return true;
}

void printLinkedList(ListNode* head){
    ListNode *n = head;
    cout<<"LinkedList: [ ";
    while(n != nullptr){
        if(n->next != nullptr){
            cout<<n->val<<" ->";
        }
        else{
            cout<<n->val;
        }
        n = n->next;
    }
    cout<<" ]"<<endl;
}
int main(){
    ListNode *head= nullptr;

    appendToTail(head,4);
    appendToTail(head,6);
    appendToTail(head,8);
    appendToTail(head,2);
    appendToTail(head,12);
    
    printLinkedList(head);
    if(deleteMiddleNode(head->next)){
        printLinkedList(head);
    }else{
        cout<<"Unable to delete give node: Please ensure node is not the last node in the linked list"<<endl;
    }

    return 0;
}
