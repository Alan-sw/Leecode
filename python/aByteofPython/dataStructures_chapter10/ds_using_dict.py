ab = {
        'Swaroop'   :   'swaroop@swaroopch.com',
        'Larry'     :   'larry@wll.org',
        'Matsumoto' :   'matz@ruby-lang.com',
        'Spammer'   :   'spammer@hotmail.com'
        }
print "Swaroop's address is ", ab['Swaroop']

del ab['Spammer']
print '\nThere are {} contacts in the address-book\n' .format(len(ab))

for name, address in ab.items():
    print 'Contact {} at {}' .format(name, address)

ab['Guido'] = 'guido@python.org'

if 'Guido' in ab :
    print "\nGudio's address is ", ab['Guido']


