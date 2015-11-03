def reverse(text):
    """TODO: Docstring for reverse.

    :text: TODO
    :returns: TODO

    """
    return text[::-1]

def is_palindrome(text):
    """TODO: Docstring for is_palindrome.

    :test: TODO
    :returns: TODO

    """
    return text == reverse(text)

something = raw_input("Enter text: ")
if is_palindrome(something):
    print "yes, it is a palindrome"
else:
    print "no, it is not a palindrome"
