class vector {
	/*
	����ʽ��
	�� 0 <= n < sz��elem[n] Ϊ���Ϊ n ��Ԫ��
	sz <= space
	�� sz < space������ elem[sz-1] ֮�������� (space-sz) �� double �Ŀռ�
	*/
	int sz;
	double* elem;
	int space;
public:
	vector() : sz { 0 }, elem { nullptr }, space { 0 } {}
	explicit vector(int s) : sz { s }, elem { new double[s] }, space { s }
	{
		for (int i = 0; i < sz; ++i)
			elem[i] = 0;
	}

	vector(const vector&);
	vector& operator=(const vector&);

	vector(vector&&);
	vector& operator=(vector&&);
	~vector() { delete[] elem; }

	double& operator[](int n) { return elem[n]; }
	const double& operator[](int n) const { return elem[n]; }

	int size() const { return sz; }
	int capacity() const { return space; }

	void resize(int newsize);
	void push_back(double d);
	void reserve(int newalloc);
};