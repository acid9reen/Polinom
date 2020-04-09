#include <gtest.h>
#include "polinom.h"


TEST(Polynom, can_use_constructor)
{
	ASSERT_NO_THROW(Polinom p());
}

TEST(Polynom, can_use_toStr)
{
	Polinom p;
	Monom m(4, 456);

	p.AddMonom(m);

	ASSERT_NO_THROW(p.toStr());
}

TEST(Polynom, can_correct_use_toStr)
{
	Polinom p;
	Monom m(4, 456);

	p.AddMonom(m);

	EXPECT_EQ(p.toStr(), "4x^4y^5z^6");
}

TEST(Polynom, can_add_monom)
{
	Polinom p;
	Monom m(4, 456);

	ASSERT_NO_THROW(p.AddMonom(m));
}

TEST(Polynom, can_correct_add_monom)
{
	Polinom p;
	Monom m(4, 456);

	p.AddMonom(m);

	EXPECT_EQ(p.toStr(), "4x^4y^5z^6");
}

TEST(Polynom, can_correct_use_plus)
{
	Polinom p, q, res;
	Monom m(4, 456);
	Monom n(5, 456);

	p.AddMonom(m);
	q.AddMonom(n);

	res = p + q;

	EXPECT_EQ(res.toStr(), "9x^4y^5z^6");
}

TEST(Polynom, can_correct_use_minus)
{
	Polinom p, q, res;
	Monom m(4, 456);
	Monom n(5, 456);

	p.AddMonom(m);
	q.AddMonom(n);

	res = p - q;

	EXPECT_EQ(res.toStr(), "-1x^4y^5z^6");
}

TEST(Polynom, can_sort_monoms)
{
	Polinom p, q, res;
	Monom m(4, 111);
	Monom n(5, 222);

	p.AddMonom(m);
	q.AddMonom(n);

	res = p + q;

	EXPECT_EQ(res.toStr(), "5x^2y^2z^2 + 4x^1y^1z^1");
}
