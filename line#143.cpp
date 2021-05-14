#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
Node *create_node(int data)
{
    Node *c = new Node();
    c->data = data;
    c->next = NULL;
    return c;
}
Node * find_start_of_node(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    if (head == NULL || head->next == NULL)
        return NULL;

    while (fast && slow && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            break;
        }
    }

    slow = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}
Node *create_link_list(int n)
{
    int data;
    cin >> data;
    Node *head = create_node(data);
    Node *temp = head;
    for (int i = 1; i < n; i++)
    {
        int data;
        cin >> data;
        Node *list_data = create_node(data);
        temp->next = list_data;
        temp = temp->next;
    }
    temp->next = head->next->next->next;
    return head;
}
int main()
{
    int n;
    cin >> n;

    Node *head = create_link_list(n);
    Node *ans = find_start_of_node(head);
    cout << ans->data;
    return 1;
}