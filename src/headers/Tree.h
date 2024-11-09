#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <exception>
#include <stdexcept>

namespace dsi {
template <typename T> 
class tree {

    struct _tree_node {
        T data;
        _tree_node* left;
        _tree_node* right;

        _tree_node(T data) : data(data), left(nullptr), right(nullptr) {}
    };

public:
    enum _pos { LEFT, RIGHT };
    tree() : head(nullptr), _depth(0), _qty(0) {}
    ~tree();

    void add(T item, _pos pos);
    bool contains(const T& item) const;
    void remove(const T& item);
    size_t depth() const { return _depth; }
    size_t size() const { return _qty; }

    void in_order_traversal() const;
    void pre_order_traversal() const;
    void post_order_traversal() const;
    
private:
    _tree_node* head;
    size_t _depth;
    size_t _qty;

    void delete_tree(_tree_node* node);
    bool contains(const _tree_node* node, const T& item) const;
    _tree_node* remove(_tree_node* node, const T& item);
    void in_order_traversal(const _tree_node* node) const;
    void pre_order_traversal(const _tree_node* node) const;
    void post_order_traversal(const _tree_node* node) const;
};

template <typename T>
dsi::tree<T>::~tree() {
    delete_tree(head);
}

template <typename T>
void dsi::tree<T>::delete_tree(_tree_node* node) {
    if (!node) return;
    delete_tree(node->left);
    delete_tree(node->right);
    delete node;
}

template <typename T>
void dsi::tree<T>::add(T item, _pos pos) {
    spdlog::info("Adding item: {} at position {}", item, (pos == LEFT ? "LEFT" : "RIGHT"));
    
    if (!head) {
        head = new _tree_node(item);
        _qty = 1;
        _depth = 1;
    } else {
        _tree_node* newNode = new _tree_node(item);
        if (pos == LEFT) {
            if (head->left) {
                throw std::runtime_error("Left position already occupied");
            }
            head->left = newNode;
        } else {
            if (head->right) {
                throw std::runtime_error("Right position already occupied");
            }
            head->right = newNode;
        }
        ++_qty;
        _depth = 2;
    }
}

template <typename T>
bool dsi::tree<T>::contains(const T& item) const {
    return contains(head, item);
}

template <typename T>
bool dsi::tree<T>::contains(const _tree_node* node, const T& item) const {
    if (!node) return false;
    if (node->data == item) return true;
    return contains(node->left, item) || contains(node->right, item);
}

template <typename T>
void dsi::tree<T>::remove(const T& item) {
    head = remove(head, item);
    if (head) --_qty;
}

template <typename T>
typename dsi::tree<T>::_tree_node* dsi::tree<T>::remove(_tree_node* node, const T& item) {
    if (!node) return nullptr;

    if (item < node->data) {
        node->left = remove(node->left, item);
    } else if (item > node->data) {
        node->right = remove(node->right, item);
    } else {
        if (!node->left) {
            _tree_node* temp = node->right;
            delete node;
            return temp;
        } else if (!node->right) {
            _tree_node* temp = node->left;
            delete node;
            return temp;
        }
        _tree_node* temp = node->right;
        while (temp->left) temp = temp->left;
        node->data = temp->data;
        node->right = remove(node->right, temp->data);
    }
    return node;
}

template <typename T>
void dsi::tree<T>::in_order_traversal() const {
    in_order_traversal(head);
}

template <typename T>
void dsi::tree<T>::in_order_traversal(const _tree_node* node) const {
    if (!node) return;
    in_order_traversal(node->left);
    spdlog::info("{}", node->data);
    in_order_traversal(node->right);
}

template <typename T>
void dsi::tree<T>::pre_order_traversal() const {
    pre_order_traversal(head);
}

template <typename T>
void dsi::tree<T>::pre_order_traversal(const _tree_node* node) const {
    if (!node) return;
    spdlog::info("{}", node->data);
    pre_order_traversal(node->left);
    pre_order_traversal(node->right);
}

template <typename T>
void dsi::tree<T>::post_order_traversal() const {
    post_order_traversal(head);
}

template <typename T>
void dsi::tree<T>::post_order_traversal(const _tree_node* node) const {
    if (!node) return;
    post_order_traversal(node->left);
    post_order_traversal(node->right);
    spdlog::info("{}", node->data);
}

} 
