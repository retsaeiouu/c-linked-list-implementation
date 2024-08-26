#include "lib/linked_list_functions.h"

int main() {
  struct node *head = new_head(20);

  insertion_at_tail(head, 30);
  insertion_at_tail(head, 50);
  insertion_before(head->next, 40);
  insertion_at_head(&head, 10);

  print_list(head); // 10, 20, 30, 40, 50

  reverse_list(&head);
  print_list(head); // 50, 40, 30, 20, 10
  deallocate_list(head);
  return 0;
}
