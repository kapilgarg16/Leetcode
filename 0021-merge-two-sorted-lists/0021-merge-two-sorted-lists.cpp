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
    ListNode* mergeTwoLists(ListNode* root1, ListNode* root2) 
    {
    if(root1 == NULL)
    return root2;
    
    if(root2 == NULL)
    return root1;
    
    ListNode* head, *temp;
    
    if(root1->val < root2->val)
    {
        head = root1;
        root1 = root1->next;
    }
    else
    {
        head = root2;
        root2 = root2->next;
    }
    temp = head;
    while(root1 && root2)
    {
        if(root1->val < root2->val)
        {
            temp->next = root1;
            root1 = root1->next;
        }
        else
        {
            temp->next = root2;
            root2 = root2 -> next;
        }
        temp = temp->next;
    }
    if(root1)
    {
        temp->next = root1;
    }
    else
    {
        temp->next = root2;
    }
    return head;
        
    }
};