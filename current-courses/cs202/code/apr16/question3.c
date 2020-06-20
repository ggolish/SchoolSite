int skipSum(node_t *curr)
{
    if(curr == NULL) return 0;
    int sum = curr->data;
    while(curr->next != NULL && curr->next->next != NULL) {
        curr = curr->next->next;
        sum += curr->data;
    }
    return sum;
}
