
template<class T>
class my_shared_ptr {
private:
	T *ptr;
	unsigned long *counter;

public:
	my_shared_ptr(T* ptr_) : ptr(ptr_), counter(new unsigned long(1)) {}
	
	my_shared_ptr(const my_shared_ptr<T> &other) : ptr(other.ptr), counter(other.counter) { ++*counter; }
	my_shared_ptr &operator= (const my_shared_ptr<T> &other) {
		if(ptr == other.ptr)
			return *this;
		if(ptr && counter) {
			(*counter)--;
			if(counter == 0) {
				delete ptr;
				delete counter;
			}
		}
		ptr = other.ptr;
		counter = other.counter;
		++*counter;
		
	}

	my_shared_ptr(my_shared_ptr &&other) : ptr(other.ptr), counter(other.counter) { other.ptr = nullptr; other.counter = nullptr; }
	my_shared_ptr& operator=(my_shared_ptr &&other) {
		if(ptr == other.ptr) {	
			other.ptr = nullptr; 
			other.counter = nullptr;
			return *this;
		}

		if(ptr && counter) {
			(*counter)--;
			if(counter == 0) {
				delete ptr;
				delete counter;
			}
		}
		ptr = other.ptr;
		counter = other.counter;
		other.ptr = nullptr; 
		other.counter = nullptr;
		return *this;
	}
	
	~my_shared_ptr() {
		if(counter == nullptr || ptr == nullptr) {
		
			return;
		}
		--*counter;
		if(counter == 0) {
			delete ptr;
			delete counter;
		}
	}


};



