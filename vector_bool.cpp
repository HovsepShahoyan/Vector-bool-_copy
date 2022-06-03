#include <iostream>
class Vector_bool {
public:
unsigned int _ptr = 0 ; 
int _length = 32;

public:
    Vector_bool() = default;

	void push_back(bool val){
    		_length--;
 		if (val == true) {
   			_ptr = _ptr >> _length;
			_ptr ++;
    	  		_ptr = _ptr << _length;
    		}
	}

	void pop_back(){
		_length++;
		_ptr = _ptr >> _length;
		_ptr = _ptr << _length;
	}

	void print (int index){
		int pt = _ptr ;
                pt = pt >> (31 - index);
                std::cout << (pt & 1) << std::endl;
        }

	void insert(int index, bool val) {
		if(index == 32 - _length) {
			push_back(val);
			return;
		} else {
			int pt = _ptr;
			pt = pt << index;
			pt = pt >> (index + _length);
			_ptr = _ptr >> (32 - index);
			_ptr = _ptr << (32 - index);
			int length1 = _length;
			_length == (32 - index);
		       	push_back(val);
			_length = length1 - 1;
			_ptr >> _length;
			_ptr += pt;
			_ptr = _ptr << _length;
		  }  
	}

	void reverse () {
		int pt = _ptr;
		int length1 = _length;
		_length = 32;
		_ptr = 0;
		pt = pt >> length1;
		do {
			push_back(pt & 1);
			pt = pt >> 1;
		} while(length1 != _length);
	}
};

int main() {
    Vector_bool vv;
    vv.push_back(true);
	vv.insert(3, false);
    vv.print(3) ;
}

