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
    unsigned long long int vector_to_int(vector<int> num)
    {
        unsigned long long int n = 0;
        int N = num.size();
        for (int i = 0; i < N; i++)
        {
            n += num[i] * pow(10, N - i - 1);
        }
        return n;
    }

    vector<int> int_to_vector(unsigned long long int n)
    {
        vector<int> vec;
        while (n != 0)
        {
            vec.push_back(n % 10);
            n /= 10;
        }
        // std::reverse(vec.begin(), vec.end());
        return vec;
    }
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

    void print_list(ListNode *n){
        while(n !=nullptr){
            cout << n->val << "";
            n = n->next;
        }
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        // two vectors to store the numbers
        vector<int> num1_revers, num2_revers;
        //   define actual numbers
        long long num1, num2, sum_numbers, remainder;
        while (l1 != nullptr)
        {
            num1_revers.push_back(l1->val);
            l1 = l1->next;
        }
        while (l2 != nullptr)
        {
            num2_revers.push_back(l2->val);
            l2 = l2->next;
        }
        std::reverse(num1_revers.begin(), num1_revers.end());
        std::reverse(num2_revers.begin(), num2_revers.end());
        num1 = vector_to_int(num1_revers);
        num2 = vector_to_int(num2_revers);
        sum_numbers = num1 + num2;
        ListNode *mainHead = convert_int_to_listnode(sum_numbers);
        return mainHead;
    }
};

int main()
{
    Solution *solution = new Solution();
    ListNode *firstList = solution->convert_int_to_listnode(1000000000000000000000000000001);
    ListNode *secondList = solution->convert_int_to_listnode(19999999999);
    ListNode *resultList = solution->addTwoNumbers(firstList, secondList);
    solution->print_list(resultList);

}