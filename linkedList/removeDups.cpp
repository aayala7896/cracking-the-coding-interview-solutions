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

//Delete duplicates in an unordered linkedlist.
ListNode* deleteDuplicates(ListNode* head) {
        unordered_set<int> valueFrequency;
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode *n = head;
        valueFrequency.insert(n->val);

        while(n->next != nullptr){
            if(valueFrequency.count(n->next->val)){
                n->next = n->next->next;
            }
            else{
                valueFrequency.insert(n->next->val);
                n = n->next;
            }
        }

       
        return head;
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
    appendToTail(head,2);
    
    printLinkedList(head);
    deleteDuplicates(head);
    cout<<"Duplicated Deleted"<<endl;
    printLinkedList(head);


    return 0;
}
