/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) 
{
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* curr = head;
    head->next = NULL;
    int Tot = 0, carry = 0, first = 1;
    while(l1 != NULL && l2 != NULL)
    {
        struct ListNode* Node = NULL;
        if(first) //If its the first iteration then
        {
            Node = head;
        }
        else
        {
            Node = (struct ListNode*)malloc(sizeof(struct ListNode));
            Node->next = NULL;
        }

        if(carry) //If carry = 1
        {
            Tot = l1->val + l2->val + carry;
        }
        else
        {
            Tot = l1->val + l2->val;
        }

        if(Tot >= 10)
        {
            carry = 1;
            Tot -= 10;
        }
        else
        {
            carry = 0;
        }
        Node->val = Tot;
        if(first)
        {first = 0;}
        else //If its the head then there is no previous
        {
            curr->next = Node; 
            curr = Node; //curr will always be the previous node
        }
        l1 = l1->next;
        l2 = l2->next;
    }
    while(l1 != NULL)
    {
        struct ListNode* Node = (struct ListNode*)malloc(sizeof(struct ListNode));
        Node->next = NULL;
        if(carry) //If carry = 1
        {
            Tot = l1->val + carry;
        }
        else
        {
            Tot = l1->val;
        }

        if(Tot >= 10)
        {
            carry = 1;
            Tot -= 10;
        }
        else
        {
            carry = 0;
        }
        Node->val = Tot;
        curr->next = Node; 
        curr = Node; //curr will always be the previous node
        l1 = l1->next;
    }

    while(l2 != NULL)
    {
        struct ListNode* Node = (struct ListNode*)malloc(sizeof(struct ListNode));
        Node->next = NULL;
        if(carry) //If carry = 1
        {
            Tot = l2->val + carry;
        }
        else
        {
            Tot = l2->val;
        }

        if(Tot >= 10)
        {
            carry = 1;
            Tot -= 10;
        }
        else
        {
            carry = 0;
        }
        Node->val = Tot;
        curr->next = Node; 
        curr = Node; //curr will always be the previous node
        l2 = l2->next;
    }
    if(carry) //If carry is 1 then it means we need to make a new node to store carry
    {
        struct ListNode* Node = (struct ListNode*)malloc(sizeof(struct ListNode));
        Node->next = NULL;
        Node->val = carry;
        curr->next = Node; 
        curr = Node; //curr will always be the previous node
    }
    return head;
}
