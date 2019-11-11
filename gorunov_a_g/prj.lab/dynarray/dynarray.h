#ifndef DYNARRAY_H_
#define DYNARRAY_H_

#include <cstddef>

class DynArray {
public:
  DynArray() = default;
  DynArray(const DynArray& arr);
  DynArray(const std::ptrdiff_t size);
  DynArray& operator=(const DynArray& rhs);
  ~DynArray();

  std::ptrdiff_t size() const { return size_; }
  std::ptrdiff_t capacity() const { return capacity_; }
  float& operator[](const std::ptrdiff_t i);
  const float& operator[](const std::ptrdiff_t i) const;
  void resize(const std::ptrdiff_t nsize);

private:
  std::ptrdiff_t capacity_ { 0 };
  std::ptrdiff_t size_ { 0 };
  float* data_ { nullptr };
};

#endif /* DYNARRAY_H_ */
