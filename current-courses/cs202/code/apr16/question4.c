int longestPath(bst_node_t *curr)
{
    if(curr == NULL) return 0;
    int rlength = 0, llength = 0;
    if(curr->left != NULL) llength = longestPath(curr->left);
    if(curr->right != NULL) rlength = longestPath(curr->right);
    int maxlength = (llength > rlength) ? llength : rlength;
    return maxlength + 1;
}
