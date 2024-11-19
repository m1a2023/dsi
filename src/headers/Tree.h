#include <memory>
#include <functional>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
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
    tree() : head(nullptr), _qty(0) {
        logger = spdlog::basic_logger_mt("tree_logger", "logs/tree-logs.txt");
        logger->set_level(spdlog::level::info);
        logger->info("Tree created");
    }

    ~tree() {
        logger->info("Tree destroyed");
        delete_tree(head);
    }

    void add(T item) {
        logger->info("Adding item: {}", item);
        head = add(head, item);
        ++_qty;
        logger->info("Item added: {}, Tree size: {}", item, _qty);
    }

    bool contains(const T& item) const {
        bool result = contains(head, item);
        logger->info("Item {} {} in the tree", item, (result ? "found" : "not found"));
        return result;
    }

    void remove(const T& item) {
        logger->info("Removing item: {}", item);
        head = remove(head, item);
    }

    size_t size() const { return _qty; }

    void in_order_traversal(const std::function<void(const T&)>& visit) const {
        logger->info("Starting in-order traversal");
        in_order_traversal(head, visit);
    }

    void pre_order_traversal(const std::function<void(const T&)>& visit) const {
        logger->info("Starting pre-order traversal");
        pre_order_traversal(head, visit);
    }

    void post_order_traversal(const std::function<void(const T&)>& visit) const {
        logger->info("Starting post-order traversal");
        post_order_traversal(head, visit);
    }

private:
    _tree_node* head;
    size_t _qty;
    std::shared_ptr<spdlog::logger> logger;

    _tree_node* add(_tree_node* node, T item) {
        if (!node) {
            return new _tree_node(item);
        }
        if (item < node->data) {
            node->left = add(node->left, item);
        } else if (item > node->data) {
            node->right = add(node->right, item);
        }
        return node;
    }

    bool contains(const _tree_node* node, const T& item) const {
        if (!node) return false;
        if (node->data == item) return true;
        return contains(node->left, item) || contains(node->right, item);
    }

    _tree_node* remove(_tree_node* node, const T& item) {
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
                --_qty;
                return temp;
            } else if (!node->right) {
                _tree_node* temp = node->left;
                delete node;
                --_qty;
                return temp;
            }

            _tree_node* temp = node->right;
            while (temp->left) temp = temp->left;
            node->data = temp->data;
            node->right = remove(node->right, temp->data);
        }
        return node;
    }

    void in_order_traversal(const _tree_node* node, const std::function<void(const T&)>& visit) const {
        if (!node) return;
        in_order_traversal(node->left, visit);
        visit(node->data);
        in_order_traversal(node->right, visit);
    }

    void pre_order_traversal(const _tree_node* node, const std::function<void(const T&)>& visit) const {
        if (!node) return;
        visit(node->data);
        pre_order_traversal(node->left, visit);
        pre_order_traversal(node->right, visit);
    }

    void post_order_traversal(const _tree_node* node, const std::function<void(const T&)>& visit) const {
        if (!node) return;
        post_order_traversal(node->left, visit);
        post_order_traversal(node->right, visit);
        visit(node->data);
    }

    void delete_tree(_tree_node* node) {
        if (!node) return;
        delete_tree(node->left);
        delete_tree(node->right);
        logger->info("Deleted node with item: {}", node->data);
        delete node;
    }
};

}  // namespace dsi