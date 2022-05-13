#ifndef SMARTPTR_HPP
#define SMARTPTR_HPP

template<typename T>
class SmartPtr
{
private:
	T *p;
	int *refcnt;
public:
	SmartPtr()
	{
		p = NULL;
		refcnt = new int(1);
	}

	SmartPtr(T *q)
	{
		p = q;
		refcnt = new int(1);
	}

	SmartPtr(const SmartPtr<T> &ptr)
	{
		p = ptr.p;
		refcnt = ptr.refcnt;
		(*refcnt)++;
	}

	~SmartPtr()
	{
		(*refcnt)--;
		if (*refcnt == 0)
		{
			delete p;
			delete refcnt;
		}
	}

	SmartPtr<T>& operator=(const SmartPtr<T> &rhs)
	{
		if (&rhs != this)     // 检查是否是自赋值
		{
			(*rhs.refcnt)++;
			(*refcnt)--;
			if (*refcnt == 0)
			{
				delete p;
				delete refcnt;
			}
			p = rhs.p;
			refcnt = rhs.refcnt;
		}
		return *this;
	}

	T& operator*()
	{
		return *p;
	}

	T* operator->()
	{
		return p;
	}

};

#endif