#ifndef HF_SIM_TREE_HANDLER_H
#define HF_SIM_TREE_HANDLER_H

#include <algorithm>
#include <memory>
#include <string>
#include "TFile.h"
#include "TTreeReader.h"
#include "TTreeReaderValue.h"

namespace tree_analysis {

template <class T>
class Reader {
 private:
  TFile file_;
  TTreeReader tree_reader_;
  TTreeReaderValue<T> reader_value_;

 public:
  class iterator {
   private:
    Reader* reader_;
    TTreeReader::Iterator_t tree_iteration_;

   public:
    iterator() = default;
    iterator(Reader& reader, Long64_t entry)
        : reader_(&reader),
          tree_iteration_(reader.tree_reader_, entry){};

    bool operator==(const iterator& rhs) const {
      return reader_ == rhs.reader_ &&
             tree_iteration_ == rhs.tree_iteration_;
    }
    bool operator!=(const iterator& rhs) const { return !(rhs == *this); }

    iterator& operator++() {
      ++tree_iteration_;
      return *this;
    }

    const iterator operator++(int) {
      iterator value = *this;
      ++(*this);
      return value;
    }

    const T& operator*() const {
      return *(reader_->reader_value_);
    }
  };

  // Given a file path, the name of the tree and and
  Reader(const std::string& file_path, const std::string& tree_name,
         const std::string& branch_name)
      : file_(file_path.c_str()),
        tree_reader_(tree_name.c_str(), &file_),
        reader_value_(tree_reader_, branch_name.c_str()){};

  auto begin() {
    tree_reader_.Next(); //Initialize the Tree reading
    return iterator(*this, 0); };

  auto end() { return iterator(*this, -1); };
};

}  // namespace tree_analysis

#endif  // HF_SIM_TREE_HANDLER_H
