

#ifndef MINT_H
#define MINT_H
#include <stdexcept>
#include <ostream>
#include <istream>
#include <cstdlib>
//rule of zero: mumkunse herseyi derleyici yazsin

class Mint {
public:
	explicit Mint(int val = 0) : mval{ val }
	{

	};
	
	friend bool operator<(const Mint& lhs, const Mint& rhs)
	{
		return lhs.mval < rhs.mval;
	}
	friend bool operator==(const Mint& lhs, const Mint& rhs)
	{
		return lhs.mval == rhs.mval;
	}

	Mint operator+()const // + isaret operatoru
	{
		return *this;
	}
	Mint operator-()const // - isaret operatoru
	{
		return Mint{ -mval };
	}

	Mint& operator++()   //prefix
	{
		++mval;
		return *this;
	}
	Mint operator++(int) //postfix
	{
		Mint ret{ *this };
		++* this;
		return ret;
	}
	Mint& operator--()   //prefix
	{
		--mval;
		return *this;
	}
	Mint operator--(int) //postfix
	{
		Mint ret{ *this };
		--* this;
		return ret;
	}
	

	Mint& operator+=(const Mint& other)
	{
		mval += other.mval;
		return *this;
	}


	Mint& operator-=(const Mint& other)
	{
		mval -= other.mval;
		return *this;
	}
	Mint& operator*=(const Mint& other)
	{
		mval *= other.mval;
		return *this;
	}
	Mint& operator/=(const Mint& other)
	{
		if (other.mval == 0)
			throw std::runtime_error{"sifira bolunemez"}; //ileride gorecez
		mval /= other.mval;
		return *this;
	}
	Mint& operator%=(const Mint& other)
	{
		mval %= other.mval;
		return *this;
	}
	
	
	//Aritmetik operatorler
	friend Mint operator+(const Mint& lhs, const Mint& rhs)
	{
		return Mint{ lhs } += rhs;

		//Alternatif bir yöntem olarak
		/*Mint result{ lhs };
		result += rhs;
		return result;*/
	}
	friend Mint operator-(const Mint& lhs, const Mint& rhs)
	{
		return Mint{ lhs } -= rhs;
	}
	friend Mint operator*(const Mint& lhs, const Mint& rhs)
	{
		return Mint{ lhs } *= rhs;
	}
	friend Mint operator/(const Mint& lhs, const Mint& rhs)
	{
		return Mint{ lhs } /= rhs;
	}
	friend Mint operator%(const Mint& lhs, const Mint& rhs)
	{
		return Mint{ lhs } %= rhs;
	}

	//Karsilastirma operatorleri
	friend bool operator!=(const Mint& lhs, const Mint& rhs)
	{
		return !(lhs == rhs);
	}
	friend bool operator>(const Mint& lhs, const Mint& rhs)
	{
		return rhs < lhs;
	}
	friend bool operator>=(const Mint& lhs, const Mint& rhs)
	{
		return !(lhs < rhs);
	}
	friend bool operator<=(const Mint& lhs, const Mint& rhs)
	{
		return !(rhs < lhs);
	}

	friend std::ostream& operator<<(std::ostream& os, const Mint& x)
	{
		return os << '(' << x.mval << ')';
	}

	//extractor fonksiyonlari iostream kutuphanesini ogrendikten sonra
	// tekrar ele alinacak.
	friend std::istream& operator>>(std::istream& is, Mint& x)
	{
		return is >> x.mval;
	}


	static Mint random()
	{
		return Mint{ std::rand() };
	}

private:
	int mval;

};

#endif
