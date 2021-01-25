#!/usr/bin/env python3
"""
Translate an infix expression to a postfix expression
"""
import sys
import os.path
import queue
import stack
import re

my_Queue = queue.Queue()
my_Stack = stack.Stack()

__author__ = 'Kevin'

def is_number(token):
    """
    Determines whether a string is a number
    :param token: a string
    :return: True if token contains a string of digits,
             possibly preceded by a sign (+ or -), False otherwise
    """

    return re.compile(r"^-?[0-9]+$").match(token) is not None


def is_left_associative(operator_token):
    """
    Determine whether an operator is left-associative
    :param operator_token: a string containing an operator
    :return: True if the operator is left-associative, False otherwise
    """
    return operator_token in "+-*/"


def precedence(operator_token):
    """
    Determine the precedence of an operator
    :param operator_token: a string containing an operator
    :return: A precedence--an int value between 2 and 4
    """
    return {'^': 4, '*': 3, '/': 3, '+': 2, '-': 2}[operator_token]


def evaluate(token_list):
    """
    Return the value of an infix expression
    :param token_list: a list of operators and values, all str objects,
           representing an infix expression--for example,
           ['2', '*', '(', '3', '+', '4', ')']
    :return: a postfix notation equivalent of token_listy,
             represented as a list of strings--for example,
             ['2', '3', '4', '+', '*']
    :raise SyntaxError if an error occurs
    """

    # Read a token.
    for token in token_list:
    # If the token is a number, then push it to the output queue.
        if is_number(token):
            my_Queue.enqueue(token)

    # If the token is an operator, o1, then:
    #  while there is an operator token o2, at the top of the operator stack and either
    #   o1 is left-associative and its precedence is less than or equal to that of o2, or
    #  o1 is right associative, and has precedence less than that of o2,

        elif is_left_associative(token):
            if not my_Stack.isEmpty():
                token2 = my_Stack.peek()
                while is_left_associative(token2) and \
                    ((is_left_associative(token) and precedence(token) <= precedence(token2)) or \
                             (not is_left_associative(token) and precedence(token)< precedence(token2))):
                    #pop o2 off the operator stack, onto the output queue;
                    my_Queue.enqueue(my_Stack.pop())
                    # at the end of iteration push o1 onto the operator stack.
            my_Stack.push(token)

       # If the token is a left parenthesis (i.e. "("), then push it onto the stack.
        elif token == '(':
            my_Stack.push(token)

       #If the token is a right parenthesis (i.e. ")"):
        elif token == ')':
            try:
                #Until the token at the top of the stack is a left parenthesis,
                while token != '(':
                    #pop operators off the stack onto the output queue.
                    my_Queue.enqueue(my_Stack.pop())
                # Pop the left parenthesis from the stack, but not onto the output queue.
                my_Stack.pop()
            except:
                # If the stack runs out without finding a left parenthesis,
                # then there are mismatched parentheses.
                raise SyntaxError("mismatched parenthese")

    # When there are no more tokens to read:
    # While there are still operator tokens in the stack:
    while not my_Stack.isEmpty():
        #If the operator token on the top of the stack is a parenthesis,
        if my_Stack.peek() == '(' or my_Stack.peek() == ')':
        #then there are mismatched parentheses.
            print("there are mismatched parenthesis")

        #Pop the operator onto the output queue.
        my_Queue.enqueue(my_Stack.pop())
    final_Queue = []
    for i in range(my_Queue.size()):
        final_Queue.append(my_Queue.dequeue())
    return final_Queue   # STUB


def main():
    """
    Process an infix expression provided as command line
    arguments and then print the expression in postfix notation
    :return: None
    """
    if len(sys.argv) > 1:
        token_list = sys.argv[1:]
        print('Infix:  ', token_list)
        print('Postfix:', evaluate(token_list))
    else:
        module_name = os.path.split(sys.argv[0])[1]
        print('Usage: {} <infix-tokens>'.format(module_name))


if __name__ == '__main__':
    main()