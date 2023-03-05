#include <bits/stdc++.h>

using namespace std;

typedef struct list_t {
  int data;
  struct list_t *next = NULL;
  bool is_first = true;
} LinkedList;

void insert(LinkedList *f, LinkedList *n) {
  auto next = f->next;
  f->next = n;
  auto i = n;
  i->is_first = false;
  while (i->next != NULL) {
    i = i->next;
    // cout << i->data << " ";
    i->is_first = false;
  }
  i->is_first = false;
  i->next = next;
}

void printList(LinkedList *L) {
  auto i = L;
  while (i != NULL) {
    cout << i->data << " ";
    i = i->next;
  }
  cout << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;

  LinkedList *lists[500000];
  for (int i = 1; i <= n; i++) {
    LinkedList *temp = (LinkedList *)malloc(sizeof(LinkedList));
    temp->data = i;
    temp->is_first = true;
    lists[i] = temp;
  }
  for (int i = 1; i < n; i++) {
    // cout << lists[i]->is_first << " ";
  }
  // cout << "\n";
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    insert(lists[v], lists[u]);
    // printList(lists[v]);
  }
  // cout << "\n";
  for (int i = 1; i < n; i++) {
    if (lists[i]->is_first) {
      printList(lists[i]);
      break;
    }
  }
  return 0;
}