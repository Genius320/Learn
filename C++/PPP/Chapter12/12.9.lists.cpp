// ����ʵ��

#include "std_lib_facilities.h"

class Link {
public:
	string value;
	Link(const string&v, Link* p = nullptr, Link*s = nullptr)
		: value { v }, prev { p }, succ { s } {}

	Link* insert(Link* n);
	Link* add(Link* n);
	Link* erase();
	Link* find(const string& s);
	const Link* find(const string& s) const;

	Link* advance(int n) const;

	Link* next() const { return succ; }
	Link* previous() const { return prev; }
private:
	Link* prev;
	Link* succ;
};


Link* Link::insert(Link* n)	// �� this ǰ���� n������ n
{
	if (n == nullptr)
		return this;
	if (this == nullptr)
		return n;
	n->succ = this;
	if (prev)
		prev->succ = n;
	n->prev = this->prev;
	prev = n;
	return n;
}

Link* Link::add(Link * n)	// �� this �ĺ������ n�� ���� n
{
	if (this == nullptr)
		return n;
	if (n == nullptr)
		return this;
	n->prev = this;
	if (succ)
		succ->prev = n;
	n->succ = succ;
	succ = n;
	return n;
}

Link* Link::erase()		// ɾ�� this�� ���� this �ĺ��
{
	if (this == nullptr)
		return nullptr;
	if (succ)
		succ->prev = prev;
	if (prev)
		prev->succ = succ;
	return succ;
}

Link* Link::find(const string& s)	// �������в��� s
{
	Link* p = this;
	while (p) {
		if (p->value == s)
			return p;
		p = p->succ;
	}
	return nullptr;
}

const Link* Link::find(const string & s) const
{
	const Link* p = this;
	while (p) {
		if (p->value == s)
			return p;
		p = p->succ;
	}
	return nullptr;
}

Link* Link::advance(int n) const	// ��õ� n �����
{
	const Link* p = this;
	if (p == nullptr)
		return nullptr;
	if (0 < n) {
		while (n--) {
			if (p->succ == nullptr)
				return nullptr;
			p = p->succ;
		}
	}
	else if (n < 0) {
		while (n++) {
			if (p->prev == nullptr)
				return nullptr;
			p = p->prev;
		}
	}
	return const_cast<Link*>(p);
}

void print_all(Link* p)
{
	cout << "{ ";
	while (p) {
		cout << p->value;
		if (p = p->next())
			cout << ", ";
	}
	cout << " }";
}

/*
Link* insert(Link* p, Link* n)
{
	if (n == nullptr)
		return p;
	if (p == nullptr)
		return n;
	n->succ = p;
	if (p->prev)
		p->prev->succ = n;
	n->prev = p->prev;
	p->prev = n;
	return n;
}

// chapter12_ex11
Link* add(Link* p, Link* n)	// �� p �ĺ������ n�� ���� n
{
	if (p == nullptr)
		return n;
	if (n == nullptr)
		return p;
	n->prev = p;
	if (p->succ)
		p->succ->prev = n;
	n->succ = p->succ;
	p->succ = n;
	return n;
}

Link* erase(Link* p)		// ɾ�� p�� ���� p �ĺ��
{
	if (p == nullptr)
		return nullptr;
	if (p->succ)
		p->succ->prev = p->prev;
	if (p->prev)
		p->prev->succ = p->succ;
	return p->succ;
}

Link* find(Link* p, const string& s)	// ������ p �в��� s
{
	while (p) {
		if (p->value == s)
			return p;
		p = p->succ;
	}
	return nullptr;
}

Link* advance(Link* p, int n)	// ��õ� n �����
{
	if (p == nullptr)
		return nullptr;
	if (0 < n) {
		while (n--) {
			if (p->succ == nullptr)
				return nullptr;
			p = p->succ;
		}
	}
	else if (n < 0) {
		while (n++) {
			if (p->prev == nullptr)
				return nullptr;
			p = p->prev;
		}
	}
	return p;
}

void print_all(Link* p)
{
	cout << "{ ";
	while (p) {
		cout << p->value;
		if (p = p->succ)
			cout << ", ";
	}
	cout << " }";
}
*/

int main()
{
	Link* norse_gods = new Link { "Thor" };
	/*
	norse_gods = insert(norse_gods, new Link { "Odin" });
	norse_gods = insert(norse_gods, new Link { "Freia" });
	print_all(norse_gods);
	cout << '\n';
	*/
	norse_gods = norse_gods->insert(new Link { "Odin" });
	norse_gods = norse_gods->insert(new Link { "Freia" });
	print_all(norse_gods);
	cout << '\n';
	keep_window_open();
	return 0;
}