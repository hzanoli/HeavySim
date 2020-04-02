ROOT_GENERATE_DICTIONARY(G__analysis analysis/reduced_particle.h analysis/reduced_event.h LINKDEF analysis_linkdef.h)
            
add_library(analysis SHARED
            G__analysis.cxx
            reduced_particle.cc
            reduced_event.cc
            filter.cc
            )

target_link_libraries(analysis "${PYTHIA8_LIBRARIES}" "${ROOT_LIBRARIES}")