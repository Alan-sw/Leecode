import os
import time

source = ['~/test']

target_dir = './backup'

target = target_dir + os.sep + time.strftime('%Y%m%d%H%M%S') + '.zip'

if not os.path.exists(target_dir):
    os.mkdir(target_dir)

zip_command = "zip -r {0} {1}" .format(target, ' '.join(source))

print "zip command is :", zip_command
print "Running"

if os.system(zip_command) == 0:
    print 'Successful back up', target
else:
    print 'Backup failed'


