add_library(tree_analysis SHARED
        task.cpp task.h)

target_link_libraries(tree_analysis container "${ROOT_LIBRARIES}")