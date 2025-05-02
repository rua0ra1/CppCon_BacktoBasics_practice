#include <iostream>

class Node {
public:
  int data;
  Node *next;
  ~Node() { delete next; }
};
Node *head = nullptr;

void display(Node *p) {
  while (p != nullptr) {
    std::cout << p->data << " \n";
    p = p->next;
  }
}

void displayRecursive(Node *p) {
  if (p != nullptr) {
    std::cout << p->data << " \n";
    displayRecursive(p->next);
  }
}

void displayReverse(Node *p) {
  if (p != nullptr) {
    displayReverse(p->next);
    std::cout << p->data << " \n";
  }
}

void counting(Node *p) {
  int count = 0;
  while (p != nullptr) {
    count++;
    p = p->next;
  }
  std::cout << "Count: " << count << "\n";
}

void create(int A[], int n) {
  Node *t, *last;
  head = new Node;
  head->data = A[0];
  head->next = nullptr;
  last = head;

  for (int i = 1; i < n; i++) {
    t = new Node;
    t->data = A[i];
    t->next = nullptr;
    last->next = t;
    last = t;
  }
}

int main() {

  int A[] = {2, 4, 6, 8, 10};
  create(A, 5);

  displayRecursive(head);
  displayReverse(head);

  counting(head);

  delete head;
}
