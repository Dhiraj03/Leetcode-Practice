// https://leetcode.com/problems/add-two-numbers/description/
#include <iostream>
#include <string>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int val) : val(val), next(nullptr) {}
    ListNode(int val, ListNode *next) : val(val), next(next) {}
};

void printListNode(ListNode *head)
{
    string s;
    while (head)
    {
        s.push_back(head->val + '0');
        head = head->next;
    }
    reverse(s.begin(), s.end());
    cout << "Result: " << s << endl;
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode result(0);
    ListNode *tail = &result;
    int carryOver = 0;
    while (l1 != NULL || l2 != NULL || carryOver)
    {
        int sum = carryOver;
        if (l1)
        {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2)
        {
            sum += l2->val;
            l2 = l2->next;
        }
        carryOver = sum / 10;
        tail->next = new ListNode(sum % 10);
        tail = tail->next;
    }
    return result.next;
}

int main()
{
    string op1, op2;
    cout << "Enter the first number: " << endl;
    cin >> op1;
    cout << endl
         << "Enter the second number: " << endl;
    cin >> op2;
    ListNode head1(0);
    ListNode *headptr1 = &head1;
    for (int idx = op1.size() - 1; idx >= 0; --idx)
    {
        headptr1->next = new ListNode(op1[idx] - '0');
        headptr1 = headptr1->next;
    }
    ListNode head2(0);
    ListNode *headptr2 = &head2;
    for (int idx = op2.size() - 1; idx >= 0; --idx)
    {
        headptr2->next = new ListNode(op2[idx] - '0');
        headptr2 = headptr2->next;
    }

    printListNode(addTwoNumbers(head1.next, head2.next));
    return 0;
}