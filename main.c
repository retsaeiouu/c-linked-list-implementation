#include "lib/linked_list_functions.h"

int main() { //  NOTE: add update, delete, and reverse functions
  struct node *head = new_head(20);
  insertion_at_tail(head, 30);
  insertion_at_tail(head, 50);
  insertion_at(head->next, 40);
  insertion_at_head(&head, 10);

  print_list(head); // 10, 20, 30, 40, 50
  deallocate_list(head);
  return 0;
}
