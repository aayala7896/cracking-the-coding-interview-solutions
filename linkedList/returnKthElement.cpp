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

//return size of linked list
int linkedlistSize(ListNode* head){
    ListNode *n = head;
    int size=0;
    while(n != nullptr){
        size++;
        n=n->next;
    }

    return size;
}

//Find the kth to last element of a singly linkedlist
int returnKthElement(ListNode* head,int k) {
    ListNode *n = head;
    int linkedSize = linkedlistSize(head);
    int kDistance = linkedSize - k;
    
    if(k > linkedSize || k <= 0){ // Error cases
        return -1;
    }

    while(kDistance > 0){ //Step until reach Kdistance of 0
        n = n->next;
        kDistance--;
    }
    
    return n->val;
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
    int size = linkedlistSize(head);
    cout<<"LinkedList Size:"<<size<<endl;
    cout<<"The "<<size<<"th element to the last is: "<<returnKthElement(head, size)<<endl;
    cout<<"The 3rd to last element is:"<<returnKthElement(head,3)<<endl;
    cout<<"The 1st to last element is:"<<returnKthElement(head,1)<<endl;

    printLinkedList(head);
    cout<<"LinkedList Size:"<<linkedlistSize(head)<<endl;

    return 0;
}
