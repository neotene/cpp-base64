project('cppbase64', 'cpp', version : '0.1')

cppbase64_incdir = include_directories('.', is_system : true)
cppbase64_libsources = files(
    'base64.cpp',
)

cppbase64_library = library(
  'cppbase64',
  cppbase64_libsources,
  include_directories: cppbase64_incdir,
)

cppbase64_dep = declare_dependency(
  link_with: cppbase64_library,
  include_directories: cppbase64_incdir,
)
