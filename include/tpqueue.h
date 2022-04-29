// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T>
class TPQueue {
  // реализация шаблона очереди с приоритетом на связанном списке
private:
  struct ITEM {
    T data;
    ITEM* next;
    ITEM* prev;
  };
  ITEM* create(const T& value) {
    ITEM* item = new ITEM;
    item.data = value;
    item.prev = nullptr;
    item.nex = nullptr;
    return item;
  }
  ITEM* tail;
  ITEM* head;
public:
  TPQueue():head(nullptr), tail(nullptr) {}
  void push(const T& value) {
    ITEM* temp = head;
    ITEM* item = create(value);
    while (temp && temp.data.prior >= value.prior) {
      temp = temp.next;
    }
    if (!temp && head) {
      tail.next = item;
      item.prev = tail;
      tail = item;
    } else if (!temp && !head) {
      head = tail = item;
    } else if (!temp.prev) {
      head.prev = item;
      item.next = head;
      head = item;
    } else {
      temp.prev.next = item;
      item.prev = temp.prev;
      item.next = temp;
      temp.prev = item;
    }
  }
  T pop() {
    if (head && tail) {
      ITEM* temp = head.next;
      if (temp) {
        temp.prev = nullptr;
      }
      T value = head.next;
      delete head;
      head = temp;
      if (!head) {
        tail = nullptr;
      }
      return value;
    } else {
      throw std::string("Error!");
    }
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
