#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *convert_int_to_listnode(unsigned long long int num)
    {
        int remainder;
        ListNode *mainHead = new ListNode();
        remainder = num % 10;
        mainHead->val = remainder;
        num = num / 10;
        ListNode *head = mainHead;
        while (num != 0)
        {
            ListNode *nextNode = new ListNode();
            remainder = num % 10;
            nextNode->val = remainder;
            head->next = nextNode;
            head = nextNode;
            num = num / 10;
        }
        return mainHead;
    }

    void print_list(ListNode *n)
    {
        while (n != nullptr)
        {
            cout << n->val << "";
            n = n->next;
        }
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *dummyHead = new ListNode();
        ListNode *temp = dummyHead;
        int carry = 0;
        int sum = 0;
        int x, y;
        while (l1 != nullptr or l2 != nullptr)
        {
            if (l1 != nullptr)
            {
                x = l1->val;
                l1 = l1->next;
            }
            else
            {
                x = 0;
            }
            if (l2 != nullptr)
            {
                y = l2->val;
                l2 = l2->next;
            }
            else
            {
                y = 0;
            }
            sum = carry + x + y;
            carry = sum / 10;
            temp->next = new ListNode(sum % 10);
            temp = temp->next;
        }
        if (carry > 0)
        {
            temp->next = new ListNode(carry);
        }
        return dummyHead->next;
    }
};

int main()
{
    Solution *solution = new Solution();
    ListNode *firstList = solution->convert_int_to_listnode(9999999);
    ListNode *secondList = solution->convert_int_to_listnode(9999);
    ListNode *resultList = solution->addTwoNumbers(firstList, secondList);
    solution->print_list(resultList);
}