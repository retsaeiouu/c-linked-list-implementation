#include <stdio.h>
#include <stdlib.h>

struct node {
  int value;
  struct node *next;
};

struct node *new_list(int node_value) {
  struct node *current = (struct node *)malloc(sizeof(struct node));
  current->value = node_value;
  current->next = NULL;
  return current;
}

void append_node(struct node *head, int value) {
  struct node *new_node = new_list(value);
  while (head->next != NULL)
    head = head->next;
  head->next = new_node;
}

void insert_node(struct node *previous_node, int value) {
  struct node *new_node = new_list(value);
  if (previous_node->next != NULL) {
    struct node *temporary = previous_node->next;
    previous_node->next = new_node;
    new_node->next = temporary;
    return;
  }
  previous_node->next = new_node;
}

void print_list(struct node *head) {
  while (head != NULL) {
    (head->next != NULL) ? printf("%d, ", head->value)
                         : printf("%d\n", head->value);
    head = head->next;
  }
}

void deallocate_list(struct node *head) {
  struct node *temporary;
  while (head != NULL) {
    temporary = head->next;
    free(head);
    head = temporary;
  }
}

int main() { //  NOTE: add update, delete, and reverse functions
  struct node *head = new_list(10);
  append_node(head, 30);
  insert_node(head, 20);
  print_list(head);
  deallocate_list(head);
  return 0;
}
