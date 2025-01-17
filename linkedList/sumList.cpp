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


//Sum two linked list given in reverse order.
//ex: (7 -> 1 -> 6) + (5 -> 9 -> 2). That is 617 + 295
// Output: [2 -> 1 -> 9] 912
//Approach: use the longest list and update the values until you reach the end of the smallest list or remainder exist
// Since we only itterate through the list one time the time complexity is O(N). The space complexity is optimized since we only update longest list.
// Time Complexity O(N). Space Complexity O(1)
ListNode* SumLists(ListNode* l1, ListNode* l2) {
    int l1_size =linkedlistSize(l1);
    int l2_size=linkedlistSize(l2);
       
    //If list 2 is larger, then we swap to make sure we only update the largest list(being L1)
    if(l2_size > l1_size){
        ListNode* temp = l1;
        l1 = l2;
        l2 = temp;
    }

    ListNode* head = l1; //Track head as we traverse L1
    int remainder=0;
    while(l2 != nullptr || remainder > 0){  
        l1->val+=remainder; // For any remainders add to L1->val
        if(l2 != nullptr){ //If not at the end of the list, add l2 value
            l1->val+= l2->val;
            l2=l2->next;
        }
        
        //add the value in the tenths place to reaminder and ones in l1->value
        remainder = l1->val / 10;
        l1->val = l1->val % 10;
        
        //If remainder exist at the end of L1. Create new node and append to end of the list.
        //Remainder will be stored in last itteration of the while loop
        if(l1->next == nullptr && remainder != 0){
            ListNode *n = new ListNode(0);
            l1->next = n;
        }
        l1= l1->next;
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

//L1 = [4-> 6-> 8 -> 2 -> 9] 92864
//L2 = [5 -> 8 -> 3 -> 9] 9385
//Output: [9-> 4 -> 2 -> 2 -> 0 ->1]
int main(){
    ListNode *l1= nullptr;
    ListNode *l2= nullptr;

    appendToTail(l1,4);
    appendToTail(l1,6);
    appendToTail(l1,8);
    appendToTail(l1,2);
    appendToTail(l1,9);

    appendToTail(l2,5);
    appendToTail(l2,8);
    appendToTail(l2,3);
    appendToTail(l2,9);

    printLinkedList(l1);
    printLinkedList(l2);

    SumLists(l1,l2);
    printLinkedList(l1);
    
    return 0;
}
