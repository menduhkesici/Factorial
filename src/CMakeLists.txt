file(GLOB PROJECT_SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp)
add_library(src STATIC ${PROJECT_SOURCES})
target_include_directories(src PUBLIC ${PROJECT_SOURCE_DIR})
