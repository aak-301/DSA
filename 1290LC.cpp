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
    int power=-1;
    int ans1(ListNode* head){
        // Time Complexity -  O(n)
        // Space Complexity - O(1)
        int ans=0;
        while(head)
        {
            ans=ans*2 + (head->val);
            head=head->next;
        }
        return ans;
    }
    int ans2(ListNode* head){
        // Time Complexity -  O(2*n)
        // Space Complexity - O(1)
        int len=-1;
        int ans=0;
        ListNode*temp = head;
        // First finding the length of List
        while(temp){
            len++;
            temp=temp->next;
        }
        temp=head;
        // Then adding the sum by converting binary to decimal from msb -> lsb
        while(temp){
            ans+=pow(2,len)*temp->val;
            len--;
            temp=temp->next;
        }
        return ans;
    }
public:
    int getDecimalValue(ListNode* head) {
        // return ans1(head);
        return ans2(head);
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
    s.printList(head);
    cout<<s.getDecimalValue(head);
}

