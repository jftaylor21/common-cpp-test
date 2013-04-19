TEMPLATE = subdirs

SUBDIRS *= utilities \
           stringrpc \
           tokenizer \
           screen \
           logger

utilities.file = 3rdparty/common-cpp/code/utilities.pro

stringrpc.depends = utilities

tokenizer.depends = utilities

screen.depends = utilities

logger.depends = utilities
