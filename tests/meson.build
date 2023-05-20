cmake               = import('cmake')
options             = cmake.subproject_options()
options.add_cmake_defines({'RC_ENABLE_GTEST': 'ON'})

rapidcheck_project  = cmake.subproject('rapidcheck', options: options)
rapidcheck          = rapidcheck_project.dependency('rapidcheck')
rapidcheck_gtest    = rapidcheck_project.dependency('rapidcheck_gtest')

dependencies  = [
    dependency('gtest')
  , dimension_dep
  , rapidcheck
  , rapidcheck_gtest
  ]

millimeter  = executable('millimeter', 'millimeter.cpp', dependencies: dependencies)
test('millimeter', millimeter)
