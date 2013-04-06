TEMPLATE = subdirs

SUBDIRS *= utilities \
           stringrpc \
           tokenizer

utilities.file = 3rdparty/common-cpp/code/utilities.pro

stringrpc.depends = utilities

tokenizer.depends = utilities
