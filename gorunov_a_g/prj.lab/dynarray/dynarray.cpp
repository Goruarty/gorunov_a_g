#include <iostream>
#include "dynarray.h"

DynArray::DynArray(const DynArray& arr)
  : capacity_(arr.capacity_)
  , size_(arr.size_)
  , data_ (new float[capacity_])
{
	for (std::ptrdiff_t i = 0; i < size_; ++i){
		data_[i]=arr.data_[i];
	}
}

DynArray::DynArray(const std::ptrdiff_t size){
	 if (size > 0){
		 size_= size;
		 capacity_ = size;
         data_ = new float [capacity_] { 0 };
	 } else {
         throw std::logic_error("size is not correct");
	 }
 }

DynArray& DynArray::operator=(const DynArray& rhs){
	 if (this!= &rhs){
		 float *data = new float [rhs.capacity_];
		 for (std::ptrdiff_t i = 0; i < rhs.size_; ++i){
		   data[i]=rhs.data_[i];
		   }
		 delete[] data_;
		 capacity_ = rhs.capacity_;
		 size_ = rhs.size_;
		 data_ = data;
	 }
	 return *this;
 }

float& DynArray::operator[] (const std::ptrdiff_t i) {
  if (i < 0 || size_ <= i) {
    throw std::out_of_range("index is out of range");
  }
  return data_[i];
}

const float& DynArray::operator[] (const std::ptrdiff_t i) const{
	if (i < 0 || size_ <= i) {
	    throw std::out_of_range("index is out of range");
	  }
	  return data_[i];
}

void DynArray::resize(const std::ptrdiff_t size){
	if (size < 0) {
		throw std::logic_error ("size is not correct"); }
    else {
		if (size <= capacity_) {
		  size_ = size;
        } else {
		  float *data = new float[size];
		  for (std::ptrdiff_t i = 0; i < size_ ; ++i){
			  data[i] = data_[i];
          }
          for (std::ptrdiff_t i = size_; i < size ; ++i){
              data[i] = 0;
          }
		  delete [] data_;
		  size_ = size;
		  capacity_ = size;
		  data_ = data;
		}
	}
}
DynArray::~DynArray() {
  delete [] data_;
  capacity_ = 0;
  size_ = 0 ;
  data_ = nullptr;
}









