class ShortInputException(Exception):
    def __init__(self, length, atlease):
        Exception.__init__(self)
        self.length = length
        self.atlease = atlease


try:
    text = raw_input('Enter something--->')
    if len(text) < 3:
        raise ShortInputException(len(text), 3)
except EOFError:
    print 'Why did you do an EOF on me'
except ShortInputException as ex:
    print ("ShortInputException: The input was {0} long, expected at least {1}") \
            .format(ex.length, ex.atlease)
else:
    print 'No exception was raised'
