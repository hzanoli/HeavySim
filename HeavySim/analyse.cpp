#include <iostream>
#include "container/reduced_event.h"
#include "tree_analysis/reader.h"

int main(int argc, char** argv) {
  tree_analysis::Reader<container::ReducedEvent> ev_reader(
      "/Users/hzanoli/HeavySim/build/tree.root", "event", "event");

  auto n = 0;
  for (auto&& current_event : ev_reader) {
    std::cout << "Read event " << n << " with " << current_event.Particles().size()
              << " particles" << std::endl;
    n++;
  }

  return 0;
}