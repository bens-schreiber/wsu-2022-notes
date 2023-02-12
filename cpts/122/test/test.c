typedef struct Node Node;
struct Node {
    Node *next;
    char data;
};

Node **reverse(Node **head) {
    if ((*head)->next == 0) {return head;}
    (*head) = (*head)->next;
    printf("%c", (*reverse(head))->data);
}



int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
