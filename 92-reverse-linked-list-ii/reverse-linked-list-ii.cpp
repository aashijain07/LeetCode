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
    ListNode* deleteNode(ListNode* &head,int &x){
            
        if(x == 1){
                ListNode* temp = head;
                head = head->next;
                delete temp;
                return head;
                
        }else{
                
            ListNode* prev = NULL;
            ListNode* curr = head;
                
            int cnt = 1;
            while(cnt < x){
                prev = curr;
                curr = curr->next;
                cnt++;
            }
                
            prev->next = curr->next;
            curr->next = NULL;
            delete(curr);
                
        return head;
        }
    }



    void insertAthead(ListNode* &head , int &data){

    ListNode* temp = new ListNode(data);
    temp->next = head;
    head = temp;
    }


    void insertAtTail(ListNode* &tail , int &data){
    
    ListNode* temp = new ListNode(data);
    tail->next = temp;  
    tail = temp;
    }



    ListNode* insertNode(ListNode* &head , int &data , int &position){

        if(position == 1){
        insertAthead(head , data);
        return head;
        }

        ListNode* temp = head;
        int ct = 1;

        while( temp->next != NULL && ct < position-1){
            temp = temp->next;
            ct++;
        }

        if(temp->next == NULL){
        insertAtTail(temp , data);
        return head;
        }

        ListNode* newNode = new ListNode(data);
        newNode->next = temp->next;
        temp->next = newNode;

    return head;
    }





    ListNode* reverseBetween(ListNode* head, int left, int right) {

            if(left == right)
            return head;
        
        while(left <= right){

            int count1 = 1;
            int count2 = 1;
            ListNode* curr1 = head;
            ListNode* curr2 = head;

            while(count1 < left && curr1 !=NULL ){
                curr1 = curr1->next;
                count1++;
            }
            while(count2 < right  && curr2 != NULL){
                curr2 = curr2->next;
                count2++;
            }
            int data1 = curr2->val;
            int data2 = curr1->val;

            ListNode* deleteNodeleft = deleteNode(head , left);
            ListNode* insertFirst = insertNode(head , data1, left);
            ListNode* deleteNodeRight = deleteNode(head , right);
            ListNode* insertRight = insertNode(head , data2, right);
        left++;
        right--;
        }
    return head;
    }
};