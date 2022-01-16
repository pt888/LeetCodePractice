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
    // int length(ListNode* head){
    //     int count=0;
    //     while(head!=NULL){
    //         count++;
    //         head=head->next;
    //     }
    //     return count;
    // }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* first=head;
        ListNode* second=head;
        int x=0;
        while(first!=NULL){
            if(x<=n){
                first=first->next;
            }
            else{
                first=first->next;
                second=second->next;
            }
            x++;
        }
        if(x==1 && n==1) return NULL;
        if(x-n==0) return head->next;
        second->next=second->next->next;
        return head;
        
        // ListNode* temp=head;
        // int l=length(head);
        // if(l==1 && n==1) return NULL;
        // int steps=l-n;
        // if(steps==0) return head->next;
        // while(steps-->1){
        //     temp=temp->next;
        // }
        // if(temp->next!=NULL){
        //     ListNode* nextn=temp->next;
        //     temp->next=nextn->next;
        // }
        // return head;
    }
};