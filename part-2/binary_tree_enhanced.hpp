#ifndef __binary_tree_enhanced__
#define __binary_tree_enhanced__

#include <cassert>
#include <vector>
#include <memory>

// A class representing a binary tree
template <typename V> struct BinaryTreeEnhanced {
    V _value;
    std::unique_ptr<BinaryTreeEnhanced<V>> _left;
    std::unique_ptr<BinaryTreeEnhanced<V>> _right;

    // WRITE YOUR CODE HERE
    // A child should not own the parent so a vanilla pointer is used.
    BinaryTreeEnhanced<V>* _parent;

    friend V &value(BinaryTreeEnhanced *t) { return t->_value; }
    friend const V &value(const BinaryTreeEnhanced *t)
    {
        return t->_left_value;
    }
    friend BinaryTreeEnhanced *left(const BinaryTreeEnhanced *t)
    {
        return t->_left.get();
    }
    friend BinaryTreeEnhanced *right(const BinaryTreeEnhanced *t)
    {
        return t->_right.get();
    }
    friend BinaryTreeEnhanced *parent(const BinaryTreeEnhanced *t)
    {
        // WRITE YOUR CODE HERE
        return t->_parent;
    }
};

// A helper function to build an enhanced binary tree
template <typename V>
std::unique_ptr<BinaryTreeEnhanced<V>>
make_binary_tree_enhanced(const V &value,
                          std::unique_ptr<BinaryTreeEnhanced<V>> l,
                          std::unique_ptr<BinaryTreeEnhanced<V>> r)
{
    // WRITE YOUR CODE HERE
    return std::make_unique<BinaryTreeEnhanced<V>>{new BinaryTreeEnhanced<V>{value, std::move(l), std::move(r)};
}

#endif // __binary_tree_enhanced__
