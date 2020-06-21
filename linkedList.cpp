#include <iostream>
#include <functional>
#include "node.cpp"

using namespace std;

template <class T>
class LinkedList {
  private:
    Node<T> *head, *tail;
    int size;
  public:
    LinkedList();
    bool isEmpty();
    int getSize();
    void createnode(T value);
    void insert_start(T value);
    void insert_position(int index, T value);
    void delete_first();
    void delete_end();
    void delete_position(int index);
    T get(int item);
    void display();
};

template <class T>
LinkedList<T>::LinkedList() {
  head = NULL;
  tail = NULL;
}

template <class T>
bool LinkedList<T>::isEmpty() {
  if (head == NULL) {
    return true;
  }
  return false;
}

template <class T>
int LinkedList<T>::getSize() {
  return size;
}

template <class T>
T LinkedList<T>::get(int item) {
  if (isEmpty() == true) {
    Book book;
    return book;
  }
  Node<T> *temp = new Node<T>;
  temp = head;
  while (temp != NULL) {
    if (temp -> data.id == item) {
      return temp -> data;
    }
    temp = temp -> next;
  }
  Book book;
  return book;
}

template <class T>
void LinkedList<T>::createnode(T value) {
  Node<T> *temp = new Node<T>;
  temp -> data = value;
  temp -> next = NULL;
  if (head == NULL) {
    head = temp;
    tail = temp;
    temp = NULL;
  }
  else {
    tail -> next = temp;
    tail = temp;
  }
  ++size;
}

template <class T>
void LinkedList<T>::insert_start(T value) {
  Node<T> *temp = new Node<T>;
  temp -> data = value;
  temp -> next = NULL;
  if (head == NULL) {
    head = temp;
    tail = temp;
  }
  else {
    temp -> next = head;
    head = temp;
  }
  ++size;
}

template <class T>
void LinkedList<T>::insert_position(int index, T value) {
  Node<T> *pre = new Node<T>;
  Node<T> *cur = new Node<T>;
  Node<T> *temp = new Node<T>;
  cur = head;
  for (int i=1; i < index; i++) {
    pre = cur;
    cur = cur -> next;
  }
  temp -> data = value;
  pre -> next = temp;
  temp -> next = cur;
  ++size;
}

template <class T>
void LinkedList<T>::delete_first() {
  Node<T> *temp = new Node<T>;
  temp = head;
  head = head -> next;
  delete temp;
  --size;
}

template <class T>
void LinkedList<T>::delete_end() {
  Node<T> *pre = new Node<T>();
  Node<T> *cur = new Node<T>();
  cur = head;
  while (cur -> next != NULL) {
    pre = cur;
    cur = cur -> next;
  }
  tail = pre;
  pre -> next = NULL;
  delete cur;
  --size;
}

template <class T>
void LinkedList<T>::delete_position(int index) {
  Node<T> *pre = new Node<T>;
  Node<T> *cur = new Node<T>;
  cur = head;
  for (int i=1; i < index; i++) {
    pre = cur;
    cur = cur -> next;
  }
  pre -> next = cur -> next;
  cur -> next = NULL;
  delete cur;
  --size;
}

template <class T>
void LinkedList<T>::display() {
  Node<T> *temp = new Node<T>;
  temp = head;
  while (temp != NULL) {
    cout << temp -> data << "\n";
    temp = temp -> next;
  }
  cout << "\n";
}