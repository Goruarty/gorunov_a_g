
#ifndef DYNARRAY_H_
#define DYNARRAY_H_

class DynArray {
public:
  DynArray() = default;
  DynArray(const DynArray& arr);
  DynArray(const ptrdiff_t size);
  DynArray& operator=(const DynArray& rhs);
  ~DynArray();

  ptrdiff_t size() const { return size_; }
  ptrdiff_t capacity() const { return capacity_; }
  float& operator[] (const ptrdiff_t i);
  const float& operator[] (const ptrdiff_t i) const;
  void resize(const ptrdiff_t size);

private:
  ptrdiff_t capacity_ { 0 };
  ptrdiff_t size_ { 0 };
  float* data_ { nullptr };
};



#endif /* DYNARRAY_H_ */
