# defining the function to count the phone numbers
def count_phone_numbers(num):
    """
    Determine the possible phone numbers that can be
    formed by a sequence of Roman numerals
    :params: a string of Roman numerals representing
              a 7-digit phone number--e.g., "XIXXXXIII"
    :return: a list of tuples, each a phone number--e.g.,
             [('X', 'I', 'X', 'X', 'X', 'X', 'III'),
              ('X', 'IX', 'X', 'X', 'X', 'I', 'II'),
              ('X', 'IX', 'X', 'X', 'X', 'II', 'I')]
    """
    return phone_numbers_helper(s,7)
    # defining the helper function to distinguish each case
    def phone_numbers_helper(s, d):
        roman__numerals = set('I II III IV V VI VII VIII IX X'.split())
        lst = []
        # base case which does not need any recursion
        if d == 1:
            if s in roman__numerals:
                return [[s]]
            else:
                return []
        numbers = []
        j = 1
        for k in roman__numerals:
            for num in s:
                if k == num:
                    lst = phone_numbers_helper(s[j:], d-1)
                    for t in lst:
                        numbers.append(t)
                numbers.extend(lst)
                j += 1
        return numbers
