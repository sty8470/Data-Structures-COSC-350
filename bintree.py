"""
This module contains functions that work on binary trees

A binary tree is represented by a list:

<bin_tree> ::=  []
             |  [value <bin_tree> <bin_tree>]

t = [] indicates t is an empty tree
t = [n <bin_tree> <bin_tree>] is a binary tree whose node value is n (t[0], whose
                              left subtree is t[1], and whose right subtree is t[2]
                              
Example:
              5 
             / \ 
            4   8 
           /   / \ 
          11  13  4 
         /  \      \ 
        7    2      1
                        
is represented as
    [5,
        [4,
            [11,
                [7, [], []],
                [2, [], []]],
            []],
        [8,
            [13, [], []],
            [4,
                [],
                [1, [], []]
            ]
        ]
    ]           
"""


def is_binary_tree(obj):
    """
    Determine whether the argument is a binary tree
    :param obj: Any object
    :return: True if obj has the correct list structure, False otherwise
    """

    return isinstance(obj, list) and (obj == [] or
                                      len(obj) == 3 and is_binary_tree(obj[1]) and
                                      is_binary_tree(obj[2]))


def has_path_sum(bin_tree, path_sum):
    """
    determine whether a binary tree has a root-to-leaf path whose values sum to a
    given value
    :param bin_tree: a binary tree
    :param sum: the target value for the sum of values on a root-to-leaf path
    :return: True if the tree has a root-to-leaf path such that adding up all the
             values along the path equals the given sum, False otherwise.
    """

    if bin_tree == []:
        return False
    if bin_tree[1] == [] and bin_tree[2] == []:
        return bin_tree[0] == path_sum
    return has_path_sum(bin_tree[1], path_sum - bin_tree[0]) or has_path_sum(bin_tree[2], path_sum -bin_tree[0])

if __name__ == "__main__":
    # Test is_binary_tree()

    assert(is_binary_tree([]))
    assert(not is_binary_tree(None))
    assert(is_binary_tree([10, [], []]))
    assert(not is_binary_tree([10, []]))
    assert(is_binary_tree([10, [5, [], []], [15, [], []]]))
    assert(not is_binary_tree([10, [5, [], []], [15, []]]))
    assert(not is_binary_tree([10, [5, []], [15, [], []]]))
