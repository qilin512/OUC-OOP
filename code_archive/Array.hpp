#ifndef ARRAY_HPP
#define ARRAY_HPP

template<class T> class Array;

template <class T>
class ArrayProxy
{
private:
	ArrayProxy(int sz) 
	{
		size = sz;   // 将元素个数赋值给变量size
		data = new T [size];
		refcnt = 1;
	}
	ArrayProxy(const ArrayProxy &other)
	{
	}
	~ArrayProxy()
	{
		delete [] data;
	}

	void DecreaseRef()
	{
		refcnt--;
		if (refcnt == 0)
			delete [] data;
	}

	void IncreaseRef()
	{
		refcnt++;
	}

	friend class Array<T>;

	T* data;
	int size;
	int refcnt;
};

template <class T> 
class Array
{
private:
	ArrayProxy<T> *ptr;

public:

	typedef T* iterator;
	class reverse_iterator
	{
	public:
		T* p;
		reverse_iterator(T* pa)
		{
			p = pa;
		}
		reverse_iterator& operator++()
		{
			--p;
			return *this;
		}
		bool operator!=(reverse_iterator &a)
		{
			return p != a.p;
		}
		T& operator*()
		{
			return *p;
		}
	};

    Array(int sz = 50)
	{
		ptr = new ArrayProxy<T>(sz);				
	}
    
	Array(const Array<T>& a)
    {
		ptr = a.ptr;
		ptr->refcnt++;
	}

	~Array()
	{
		ptr->refcnt--;
		if (ptr->refcnt == 0)
		{
			delete ptr;
		}
	}

    Array<T>& operator= (const Array<T> &rhs)
	{
		if (&rhs != this)     // 检查是否是自赋值
		{
			ptr->DecreaseRef();
            ptr = rhs.ptr;
			ptr->IncreaseRef();
		}
		return *this;
		
	}

    T& operator[ ](int n)
	{
		// 检查下标是否越界
		assert(n >= 0 && n < ptr->size);
		// 返回下标为n的数组元素
		return ptr->data[n];
		
	}

    const T& operator[ ](int i) const
	{
		// 检查下标是否越界
		assert(n >= 0 && n < ptr->size);
		// 返回下标为n的数组元素
		return ptr->data[n];
		
	}
    int size() const {return ptr->size;}

    void Resize(int sz)
	{
		assert(sz >= 0); // 检查sz是否非负
		if (sz == ptr->size)
			return;

		T *newData = new T [sz];		
		int n = (sz < ptr->size) ? sz : ptr->size;
		for (int i = 0; i < n; i++)
			newData[i] = ptr->data[i];
		
		delete [ ] ptr->data;
			
		ptr->data = newData;
		ptr->size = sz;		
	}

	Array<T> Clone()
	{
		Array<T> t(ptr->size);
		for (int i = 0; i < t.ptr->size; i++)
			t.ptr->data[i] = ptr->data[i];
		return t;
	}

	iterator begin()
	{
		return ptr->data;
	}

	iterator end()
	{
		return ptr->data + ptr->size;
	}

	reverse_iterator rbegin()
	{
		return reverse_iterator(ptr->data + ptr->size - 1);
	}

	reverse_iterator rend()
	{
		return reverse_iterator(ptr->data - 1);
	}

};

#endif