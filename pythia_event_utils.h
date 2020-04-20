#ifndef HEAVYSIM_CONTAINER_REDUCED_EVENT_CC_PYTHIA_EVENT_UTILS_H_
#define HEAVYSIM_CONTAINER_REDUCED_EVENT_CC_PYTHIA_EVENT_UTILS_H_

#include "Pythia8/Pythia.h"

namespace analysis {
/*
 * Given a PYTHIA event, returns the number of heavy-flavour (charm or beauty)
 * quarks that are outgoing particles of the hardest subprocess.
 */
int ClassifyHFProcess(Pythia8::Event event);
}  // namespace analysis

#endif  // HEAVYSIM_CONTAINER_REDUCED_EVENT_CC_PYTHIA_EVENT_UTILS_H_
