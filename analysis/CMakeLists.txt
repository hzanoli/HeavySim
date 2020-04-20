add_library(analysis SHARED
        funcional_filter.cc)

target_link_libraries(analysis "${PYTHIA8_LIBRARIES}")