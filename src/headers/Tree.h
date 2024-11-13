#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <exception>
#include <stdexcept>
#include <memory>

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

    tree() : head(nullptr), _depth(0), _qty(0) {
        logger = spdlog::basic_logger_mt("tree_logger", "logs/tree-logs.txt");
        logger->set_level(spdlog::level::info);
        logger->info("Tree created");
    }

    ~tree() {
        logger->info("Tree destroyed");
        delete_tree(head);
    }

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

    std::shared_ptr<spdlog::logger> logger;

    void delete_tree(_tree_node* node);
    bool contains(const _tree_node* node, const T& item) const;
    _tree_node* remove(_tree_node* node, const T& item);
    void in_order_traversal(const _tree_node* node) const;
    void pre_order_traversal(const _tree_node* node) const;
    void post_order_traversal(const _tree_node* node) const;
};

// Implementation of tree methods

template <typename T>
void tree<T>::add(T item, _pos pos) {
    logger->info("Adding item: {} at position {}", item, (pos == LEFT ? "LEFT" : "RIGHT"));

    if (!head) {
        head = new _tree_node(item);
        _qty = 1;
        _depth = 1;
        logger->info("Added root node with item: {}", item);
    } else {
        _tree_node* newNode = new _tree_node(item);
        if (pos == LEFT) {
            if (head->left) {
                logger->error("Left position already occupied");
                throw std::runtime_error("Left position already occupied");
            }
            head->left = newNode;
        } else {
            if (head->right) {
                logger->error("Right position already occupied");
                throw std::runtime_error("Right position already occupied");
            }
            head->right = newNode;
        }
        ++_qty;
        _depth = 2;
        logger->info("Added node with item: {}", item);
    }
}

template <typename T>
bool tree<T>::contains(const T& item) const {
    bool result = contains(head, item);
    logger->info("Item {} {} in the tree", item, (result ? "found" : "not found"));
    return result;
}

template <typename T>
bool tree<T>::contains(const _tree_node* node, const T& item) const {
    if (!node) return false;
    if (node->data == item) return true;
    return contains(node->left, item) || contains(node->right, item);
}

template <typename T>
void tree<T>::remove(const T& item) {
    logger->info("Removing item: {}", item);
    head = remove(head, item);
    if (head) {
        --_qty;
        logger->info("Item {} removed", item);
    } else {
        logger->warn("Item {} not found for removal", item);
    }
}

template <typename T>
typename tree<T>::_tree_node* tree<T>::remove(_tree_node* node, const T& item) {
    if (!node) return nullptr;

    if (item < node->data) {
        node->left = remove(node->left, item);
    } else if (item > node->data) {
        node->right = remove(node->right, item);
    } else {
        logger->info("Found item: {} for removal", item);
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
void tree<T>::in_order_traversal() const {
    logger->info("Starting in-order traversal");
    in_order_traversal(head);
}

template <typename T>
void tree<T>::in_order_traversal(const _tree_node* node) const {
    if (!node) return;
    in_order_traversal(node->left);
    logger->info("Visited node with item: {}", node->data);
    in_order_traversal(node->right);
}

template <typename T>
void tree<T>::pre_order_traversal() const {
    logger->info("Starting pre-order traversal");
    pre_order_traversal(head);
}

template <typename T>
void tree<T>::pre_order_traversal(const _tree_node* node) const {
    if (!node) return;
    logger->info("Visited node with item: {}", node->data);
    pre_order_traversal(node->left);
    pre_order_traversal(node->right);
}

template <typename T>
void tree<T>::post_order_traversal() const {
    logger->info("Starting post-order traversal");
    post_order_traversal(head);
}

template <typename T>
void tree<T>::post_order_traversal(const _tree_node* node) const {
    if (!node) return;
    post_order_traversal(node->left);
    post_order_traversal(node->right);
    logger->info("Visited node with item: {}", node->data);
}

template <typename T>
void tree<T>::delete_tree(_tree_node* node) {
    if (!node) return;
    delete_tree(node->left);
    delete_tree(node->right);
    logger->info("Deleted node with item: {}", node->data);
    delete node;
}

}  // namespace dsi
