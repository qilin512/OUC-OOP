#ifndef ARRAY_H
#define ARRAY_H

#include <cassert>
#include <ostream>
#include <fstream>

template <class T>
class Array
{
private:
	struct DataPack
	{
		T* data;
		int size;
		int refcnt;
	};

	DataPack* ptr;

public:
	Array(int sz = 50)
	{
		assert(sz >= 0);
		ptr = new DataPack;
		ptr->size = sz;   // ��Ԫ�ظ�����ֵ������size
		ptr->data = new T[sz];    //��̬����size��T���͵�Ԫ�ؿռ�
		ptr->refcnt = 1;
	}

	Array(const Array<T>& a)
	{
		ptr = a.ptr;
		(ptr->refcnt)++;
	}

	~Array(void)
	{
		(ptr->refcnt)--;
		if ((ptr->refcnt) == 0)
		{
			delete[] (ptr->data);
			delete ptr;
		}
	}

	Array<T>& operator= (const Array<T>& rhs)
	{
		if (&rhs != this)     // ����Ƿ����Ը�ֵ
		{
			(ptr->refcnt)--;
			if ((ptr->refcnt) == 0)
			{
				delete[] (ptr->data);
				delete ptr;
			}
			ptr = rhs.ptr;
			(ptr->refcnt)++;
		}
		return *this;
	}

	T& operator[ ](int i)
	{
		// ����±��Ƿ�Խ��
		assert(i >= 0 && i < ptr->size);
		// �����±�Ϊn������Ԫ��
		return (ptr->data)[i];
	}

	const T& operator[ ](int i) const
	{
		// ����±��Ƿ�Խ��
		assert(i >= 0 && i < ptr->size);
		// �����±�Ϊn������Ԫ��
		return (ptr->data)[i];
	}

	operator T* ()
	{
		// ���ص�ǰ������˽��������׵�ַ
		return ptr->data;
	}

	operator const T* () const
	{
		// ���ص�ǰ������˽��������׵�ַ
		return ptr->data;
	}

	int GetSize() const
	{
		return ptr->size;
	}
	void Resize(int sz)
	{
		assert(sz >= 0); // ���sz�Ƿ�Ǹ�
		if (sz == ptr->size)
			return;
		T * newData = new T[sz];
		int n = (sz < ptr->size) ? sz : ptr->size;
		for (int i = 0; i < n; i++)
			newData[i] = ptr->data[i];
		delete[] (ptr->data);
		ptr->data = newData;
		ptr->size = sz;
	}

	Array<T> Clone()
	{
		Array<T> t(ptr->size);
		for (int i = 0; i < ptr->size; i++)
		{
			t.ptr->data[i] = ptr->data[i];
		}
		return t;
	}

	void Write(const char* filename)
	{
		std::ofstream file(filename, std::ios::binary);
		file.write((const char*)(ptr->data), sizeof(T) * ptr->size);
		file.close();
	}
};

template<class T>
std::ostream& operator<<(std::ostream& o, Array<T>& a)
{
	o << '[';
	for (int i = 0; i < a.GetSize(); i++)
	{
		o << a[i] << ' ';
	}
	o << ']';
	return o;
}


#endif

