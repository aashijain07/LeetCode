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
    int solve(ListNode* head){
        if(!head){
            return 0;
        }
        ListNode* temp=head;
        int len=0;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        return len;
    }
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;
        int len=solve(head);
        int npg=len/k;
        int en=len%k;
        ListNode*temp=head;
        vector<int>nodepg(k,npg);
        int i=0;
        while(en!=0){
            nodepg[i]++;
            i++;
            en--;
        }
        i=0;
        while(i<k){
            int x=nodepg[i];
            ListNode*fh=NULL,*ft=NULL;
            while(temp && x!=0){
                ListNode*newnode=new ListNode(temp->val);
                if(!fh){
                    fh=newnode;
                    ft=newnode;
                }
                else{
                    ft->next=newnode;
                    ft=ft->next;
                }
                x--;
                temp=temp->next;
            }
            ans.push_back(fh);
            i++;
        }
        return ans;
    }
};