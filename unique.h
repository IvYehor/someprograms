#ifdef USELOGGING
#include <iostream>
using std::cout;
#endif

template <class T>
class my_unique_ptr {
private:
	T* ptr;
	

public:
	my_unique_ptr(T *ptr_) : ptr(ptr_) {	
#ifdef USELOGGING
	cout << "Called my_unique_ptr constructor for T *ptr_\n";
#endif
	}

	my_unique_ptr(const my_unique_ptr<T>&) = delete;
	my_unique_ptr& operator=(const my_unique_ptr<T>&) = delete;

	my_unique_ptr(my_unique_ptr<T> &&ptr_) : ptr(ptr_.ptr) {
		ptr_.ptr = nullptr;
#ifdef USELOGGING
		cout << "Called my_unique_ptr move constructor\n";
#endif
	}

	T& operator*() {
		return ptr;
	}

	T& operator->() {
		return ptr;
	}

	~my_unique_ptr() {
		if(ptr != nullptr)
			delete ptr;
#ifdef USELOGGING
		cout << "Called my_unique_ptr destructor\n";
#endif
	}

	//friend my_unique_ptr<T> my_make_unique<T>(T *ptr);

};


/*template<class T>
my_unique_ptr<T> my_make_unique(T *ptr) {

#ifdef USELOGGING
	cout << "Called my_make_unique\n";
#endif
	return my_unique_ptr<T>(ptr);
}*/


