#include<iostream>
#include<math.h>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(): val(0),next(nullptr){}
    ListNode(int x): val(x), next(nullptr){}
    ListNode(int x, ListNode* next): val(x), next(next) {}
};
class Solution {
    

//               pr    N,cr
// null<-1<-2<-3<-4 null
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* Next = head;
        while(current){
            Next=current->next;
            current->next = prev;
            prev=current;
            current = Next;
        }
        return prev;
    }
    
    void printList(ListNode* head){
        cout<<"LinkedList: ";
        while(head!=nullptr){
            cout<<head->val<<" ";
            head=head->next;
        }
        cout<<endl;
    }
};
int main(){
    int noOfNodes;
    cin>>noOfNodes;
    int nodeVal;
    cin>>nodeVal;
    ListNode* head = new ListNode(nodeVal);
    ListNode* tail=head;
    for(int i=0;i<noOfNodes-1;i++){
        cin>>nodeVal;
        tail->next = new ListNode(nodeVal);
        tail=tail->next;
    }
    Solution s = Solution();
    s.printList(s.reverseList(head));
}

