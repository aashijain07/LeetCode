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


ListNode* reve( ListNode* l)
{
    ListNode* pre=NULL;
    //cout<<pre->val;
    ListNode* cur=l;
    ListNode* temp=l;
    while(cur)
    {
        temp=temp->next;
        cur->next=pre;
        pre=cur;
        cur=temp;



    }
    return  pre;

}
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
      ListNode* ll1 = reve(l1);    
      ListNode* ll2 = reve(l2); 
      ListNode* ans= new ListNode();
      ListNode* res=ans;
      int rem=0;

      while(ll1!=NULL&&ll2!=NULL)
      {
           ListNode* temp= new ListNode((ll1->val+ll2->val+rem)%10);
          ans->next=temp;
          ans=ans->next;
          rem=(ll1->val+ll2->val+rem)/10;
          ll1= ll1->next;
          ll2= ll2->next;
      }
      while(ll1!=NULL)
      {
          ListNode* temp= new ListNode((ll1->val+rem)%10);
          ans->next=temp;
          ans=ans->next;
          rem=(ll1->val+rem)/10;
          ll1= ll1->next;
      
      }
       while(ll2!=NULL)
      {
          ListNode* temp= new ListNode((ll2->val+rem)%10);
          ans->next=temp;
          ans=ans->next;
          rem=(ll2->val+rem)/10;
          
          ll2= ll2->next;
      }
      if(rem!=0)
      {
           ListNode* temp= new ListNode(rem);
          ans->next=temp;

      }

      //final ans//////
        ListNode*final= res->next;
        return reve(final);

    }


        
    
};