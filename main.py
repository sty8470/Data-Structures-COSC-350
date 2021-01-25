"""
This module tests the function bintree.has_path_sum()
"""

import sys
import os.path
import bintree


def main():
    if  len(sys.argv) != 3:
        print("Usage: {} <bin_tree> <sum>".format(os.path.split(sys.argv[0])[1]), file=sys.stderr)
        print("    Be sure to delimit the argument using quotation marks.", file=sys.stderr)
        return 1

    try:
        # First, eval each argument and make sure they are well formed
        arg1 = eval(sys.argv[1])
        arg2 = eval(sys.argv[2])

        if bintree.is_binary_tree(arg1):
            result = bintree.has_path_sum(arg1, arg2)
            print('has_path_sum({}, {}) --> {}'.format(arg1, arg2, result))
        else:
            print("Could not process the input because it is not a binary tree.", file=sys.stderr)

    except Exception as e:
        print("Exception", type(e), file =sys.stderr)
        print("   ", e, file =sys.stderr)


if __name__ == '__main__':
    main()