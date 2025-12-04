#include <initializer_list>
#include <stdexcept>
namespace random_things {
template <typename T> class base_singly_linked_node {
protected:
  T m_value{};
  base_singly_linked_node<T> *m_next_node{nullptr};

public:
  base_singly_linked_node() {}
  base_singly_linked_node(int lenght) {
    base_singly_linked_node<T> *node = this;
    for (int i = 1; i < lenght; i++) {
      node->m_next_node = new base_singly_linked_node<T>();
      node = m_next_node;
    }
  }
  base_singly_linked_node(int lenght, T value) : m_value(value) {
    base_singly_linked_node<T> *node = this;
    for (int i = 1; i < lenght; i++) {
      node->m_next_node = new base_singly_linked_node<T>{value};
      node = m_next_node;
    }
  }
  // По std::initializer_list нельзя нормально пройти, так что вот так
  base_singly_linked_node(std::initializer_list<T> init_lst) {
    base_singly_linked_node<T> *node = this;
    int i = 1;
    for (T value : init_lst) {
      node->m_value = value;
      if (i < init_lst.size()) {
        node->m_next_node = new base_singly_linked_node<T>{};
        node = m_next_node;
      }
    }
  }

  base_singly_linked_node<T> *get_node_ptr(int index) {
    base_singly_linked_node<T> *node = this;
    for (int i = 0; i < index; i++)
      node = node->m_next_node;
    return node;
  }

  // TODO: Проверить что нет утечек памяти
  ~base_singly_linked_node() {
    delete m_value;
    delete m_next_node;
    m_next_node = nullptr;
  }

  // Debuging
  T value() { return m_value; }
  void value(T v) { m_value = v; }
  base_singly_linked_node<T> *next_node() { return m_next_node; }
  void next_node(base_singly_linked_node<T> nn) { m_next_node = nn; }
};

template <typename T> class list : public base_singly_linked_node<T> {
private:
  int m_lenght{};
  base_singly_linked_node<T> *m_last_node_ptr{nullptr};

  void update_last_node_ptr() {
    m_last_node_ptr = this;
    for (int i = 1; i < m_lenght; i++)
      m_last_node_ptr = m_last_node_ptr->m_next_node;
  }

public:
  list() : m_lenght(1), m_last_node_ptr(this) {}
  list(int lenght) : m_lenght(lenght) { update_last_node_ptr(); }
  list(int lenght, T value) : m_lenght() { update_last_node_ptr(); }
  list(std::initializer_list<T> init_lst) : m_lenght(init_lst.size()) {
    update_last_node_ptr();
  }

  T &at(int index) {
    if (index < 0 || index >= m_lenght)
      throw std::runtime_error("Index erore");
    return this->get_node_ptr(index)->m_value;
  }

  void append(T value) {
    m_lenght++;
    m_last_node_ptr->m_next_node = new base_singly_linked_node<T>{value};
    m_last_node_ptr = m_last_node_ptr->m_next_node;
  }

  void insert(T value, int index) {
    if (index > m_lenght || index < 0)
      return; // TODO: Добавить эксепшн какойнибудь
    if (index == m_lenght)
      return append(value);
    base_singly_linked_node<T> *node = this->get_node_ptr(index);
    base_singly_linked_node<T> *next_node = node->m_next_node;
    node->m_next_node = new base_singly_linked_node<T>{value};
    node->m_next_node->m_next_node = next_node;
    m_lenght++;
  }

  T pop() {
    if (m_lenght < 1)
      throw std::runtime_error("Index error");
    T value = m_last_node_ptr->m_value;
    delete m_last_node_ptr;
    m_lenght--;
    update_last_node_ptr();
    m_last_node_ptr->m_next_node = nullptr;
    return value;
  }

  T pop(int index) {
    if (index == m_lenght - 1)
      return pop();
    if (index < 0 || index >= m_lenght)
      throw std::runtime_error("Произошла ошибка");
    base_singly_linked_node<T> *node;
    T value;
    if (index == 0) {
      node = this;
      value = this->m_value;
      this->m_value = this->m_next_node->m_value;
    } else {
      node = this->get_node_ptr(index - 1);
      value = node->m_next_node->m_value;
    }
    base_singly_linked_node<T> *new_next_node = node->m_next_node->m_next_node;
    node->m_next_node->m_next_node = nullptr;
    delete node->m_next_node;
    m_lenght--;
    node->m_next_node = new_next_node;
    return value;
  }
};
} // namespace random_things