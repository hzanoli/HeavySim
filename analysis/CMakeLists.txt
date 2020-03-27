ROOT_GENERATE_DICTIONARY(G__analysis analysis/reduced_particle.h analysis/reduced_event.h LINKDEF analysis_linkdef.h)
            
add_library(analysis SHARED
            G__analysis.cxx
            reduced_particle.cc
            reduced_event.cc
            filter.cc
            )

link_libraries(analysis ${ROOT_LIBRARIES})
