/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int length(ListNode* head){
        int count=0;
        while(head!=NULL){
            count++;
            head=head->next;
        }
        return count;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        int l=length(head);
       // int m=length(head);
        //cout<<l<<" "<<m<<endl;
        if(l==1 && n==1) return NULL;
        int steps=l-n;
        if(steps==0) return head->next;
        while(steps-->1){
            temp=temp->next;
        }
        if(temp->next!=NULL){
            ListNode* nextn=temp->next;
            temp->next=nextn->next;
        }
        return head;
    }
};