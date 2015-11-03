import os, platform, logging

if platform.platform().startswith('Windows'):
    logging_file = 'helloworld'
else:
    logging_file = os.path.join(os.getenv('HOME'), 'test.log')

print "logging to ",logging_file

logging.basicConfig(level = logging.DEBUG,
        format='%(asctime)s : %(levelname)s : %(message)s',
        filename = logging_file,
        filemode = 'w',
        )

logging.debug("start of the program")
logging.info("Doing something")
logging.warning("Dying now")
