/// @brief Node of list 
/// @tparam T inner data type
template <typename T>
struct Node {
    Node*   next;
    T       data;

    Node(T value) : data(value), next(nullptr) {}
};
