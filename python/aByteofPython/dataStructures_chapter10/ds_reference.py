print 'simple assigment'

shoplist = ['apple', 'mango', 'carrot', 'banana']
mylist = shoplist

del shoplist[0]

print 'shoplist is ', shoplist
print 'mylist is ', mylist

print 'copy by making a full slice'
mylist = shoplist[:]
del mylist[0]

print 'shoplist now is : ', shoplist
print 'mylist now is   : ', mylist
