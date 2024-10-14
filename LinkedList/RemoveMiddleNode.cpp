struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *deleteMiddle(ListNode *head)
{

    if (head == nullptr || head->next == nullptr)
    {
        return nullptr;
    }

    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *prev = nullptr;

    while (fast != nullptr && fast->next != nullptr)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    prev->next = slow->next;
    return head;
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode *result = deleteMiddle(head);
    return 0;
}