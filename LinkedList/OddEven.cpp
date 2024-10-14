
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *oddEvenList(ListNode *head)
{

    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    ListNode *start_odd = head;
    ListNode *start_even = head->next;
    ListNode *start_even_aux = head->next;

    while (start_even != nullptr && start_even->next != nullptr)
    {
        start_odd->next = start_even->next;
        start_odd = start_odd->next;
        start_even->next = start_odd->next;
        start_even = start_even->next;
    }

    start_odd->next = start_even_aux;
    return head;
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode *result = oddEvenList(head);
    return 0;
}