project('cppbase64', 'cpp', version : '0.1')

override = []

if host_machine.system() == 'windows'
  override = ['cpp_std=vc++17']
else
  override = ['cpp_std=c++2a']
endif

cppbase64_incdir = include_directories('include', is_system : true)
cppbase64_libsources = files(
    'base64.cpp',
)

cppbase64_library = library(
  'cppbase64',
  cppbase64_libsources,
  include_directories: cppbase64_incdir,
  cpp_args: ['-DBASE64_BUILDING_THE_LIB'],
  override_options: override,
)

cppbase64_dep = declare_dependency(
  link_with: cppbase64_library,
  include_directories: cppbase64_incdir,
)
