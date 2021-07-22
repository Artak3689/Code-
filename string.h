#ifendef String_h
#define String_h
	class String
	{
		private:
		char* m_arr;
		int m_size;
		int m_capesity;
		public:
		String()
		{
			m_capesity = 32;
			m_arr=new char[m_capesity];
			m_size = 0;
		}
		String(int capesity)
		{
			this->m_capesity = capesity;
			m_arr=new char[m_capesity];
			m_size = 0;
		}
		String(const String & tmp)
		{
			this->m_capesity = tmp.m_capesity;
			this->m_size = tmp.m_size;
			tmp.m_arr = new char [m_capesity];
			for(int i = 0 ; i<m_size;++i)
			{
				this->m_arr[i] = tmp.m_arr[i];
			}
		}
		~String(){delete[]m_arr;}
		String& operator=(const String& tmp)
		{
			if(*this == &tmp){return *this;}
			delete[] this->m_arr;

			this->m_capesity = tmp.m_capesity;
			this->m_size = tmp.m_size;
			tmp.m_arr = new char [m_capesity];
			for(int i = 0 ; i<m_size;++i)
			{
				this->m_arr[i] = tmp.m_arr[i];
			}
		}
		String& operator+(const String& stl)
		{
			if (this->m_capasitin <= (this->m_size + stl.m_size))
			{
				m_capasity *= 2;
				char* tmp= new char [m_capasity];
				for(int i=0;i<this->m_size;++i)
				{
					tmp[i]=this->m_arr[i];
				}
				delete[] this->m_arr;
				this -> m_arr = tmp ;
				tmp = nullptr ;
			}
			for(int i=this->m_arr,k=0; k < stl.m_size ;++i,++k)
			{
				this->m_arr[i]=stl.m_arr[k];
			}
		}
		String& operator+=(const String& stl)
		{
			if (this->m_capasitin <= (this->m_size + stl.m_size))
			{
				m_capasity *= 2;
				char* tmp= new char [m_capasity];
				for(int i=0;i<this->m_size;++i)
				{
					tmp[i]=this->m_arr[i];
				}
				delete[] this->m_arr;
				this -> m_arr = tmp ;
				tmp = nullptr ;
			}
			for(int i=this->m_arr,k=0; k < stl.m_size ;++i,++k)
			{
				this->m_arr[i]=stl.m_arr[k];
			}
		}
	}
#endif
