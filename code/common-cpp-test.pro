TEMPLATE = subdirs

SUBDIRS *= utilities \
           stringrpc

utilities.file = 3rdparty/common-cpp/code/utilities.pro

stringrpc.depends = utilities
