ROOT_GENERATE_DICTIONARY(G__container container/reduced_particle.h container/reduced_event.h
        LINKDEF container_linkdef.h)

add_library(container SHARED
        G__container.cxx)

target_link_libraries(container "${ROOT_LIBRARIES}")