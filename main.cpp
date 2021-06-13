#include <cassert>

template<typename  T>
struct Node {
    T data;

    Node<T>* left;
    Node<T>* right;

    Node(T value)
        : data{value}
        , left{nullptr}
        , right{nullptr}
    {}

    ~Node() {
        if(left)
            delete left;

        if(right)
            delete right;
    }

    Node<T>* addLeft(Node<T>* node) {
        left = node;
        return left;
    }
    Node<T>* addRight(Node<T>* node) {
        right = node;
        return right;
    }
};


void fill(Node<int>* root) {

    ///               1
    ///             /   \
    ///             2    6
    ///           /  \    \
    ///          3    5    8
    ///              /   /  \
    ///             4   7    9

    Node<int>* filler = root;

    filler = filler->addLeft(new Node<int>(2));
    filler->addLeft(new Node<int>(3));
    filler = filler->addRight(new Node<int>(5));
    filler->addLeft(new Node<int>(4));

    filler = root;
    filler = filler->addRight(new Node<int>(6));
    filler = filler->addRight(new Node<int>(8));
    filler->addLeft(new Node<int>(7));
    filler->addRight(new Node<int>(9));
}

constexpr auto right = &Node<int>::right;
constexpr auto left =  &Node<int>::left;


template<typename T, typename ... Paths>
Node<T>* get_tree(Node<T>* root, Paths ... paths) {
    return ((root = root->*paths), ...);
}

int main()
{
    Node<int>* top = new Node<int>(1);

    ///               1
    ///             /   \
    ///             2    6
    ///           /  \    \
    ///          3    5    8
    ///              /   /  \
    ///             4   7    9

    fill(top);

    Node<int>* six   = get_tree(top, right);
    Node<int>* eight = get_tree(top, right, right);
    Node<int>* four  = get_tree(top, left, right, left);

    assert(six->data   == 6);
    assert(eight->data == 8);
    assert(four->data  == 4);

    delete  top;
    return 0;
}
