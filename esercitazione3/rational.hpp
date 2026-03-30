#include <iostream>
#include <numeric>    // per gcd (calcola MCD trovata in cppreference)
#include <concepts>   // per integral

// Questa classe gestisce le operazioni con inf e Nan in questo modo:
//  Numero + Inf  = Inf
//  Inf + Inf     = NaN 
//  Inf - Inf     = NaN
//  Qualsiasi operazione con NaN = NaN
//  Inf * Numero+ = Inf
//  Inf * Numero- = -Inf
//  Inf * Inf     = Inf
//  Inf * 0       = NaN 
//  Numero / 0    = Inf
//  Inf / Inf     = NaN
//  0 / 0         = NaN
 
template<typename I> requires std::integral<I>
class rational {
private:
	I num_;
	I den_;
	
	// metodo privato per semplificare la frazione
	void simplify() {
		if (den_ == 0){
			if (num_ != 0) {
				num_ = (num_ > 0) ? 1 : -1;  // normalizzo a 1/0 o -1/0    costrutto:   (...) ? ... : ...    trovato su internet per compattare il codice
			}                                //                                          se num_ > 0 diventa 1 altrimenti -1
			return;
		}
		
		if (num_ == 0) {
			den_ = 1;           // normalizzo a 0/1
			return;
		}
		
		I g = std::gcd(num_, den_);  // gcd calcola MCD (trovato in cppreference)
		num_ /= g;
		den_ /= g;
		
		// passa il segno meno al numeratore
		if (den_ < 0) {
			num_ = -num_;
			den_ = -den_;
		}
	}

public:
	// costruttore di default (0/1) 
	rational() : num_{0}, den_{1} {}
	
	// costruttore definito dall'utente
	rational(I n, I d) : num_{n}, den_{d} {
		simplify();
	}
	
	I num() const { return num_;}     // servono per vedere dentro num_ e den_ 
	I den() const { return den_;}     // senza modificarli
	
	// OVERLOAD operazioni	
	
	rational& operator+=(const rational& other) {
		// a/b + c/d = (ad + bc)/bd
		num_ = (num_*other.den_) + (other.num_*den_);
		den_ = den_*other.den_;
		simplify();
		return *this;
	}
	
	rational& operator-=(const rational& other) {
		// a/b - c/d = (ad - bc)/bd
		num_ = (num_*other.den_) - (other.num_*den_);
		den_ = den_*other.den_;
		simplify();
		return *this;
	}
	
	rational& operator*=(const rational& other) {
		// (a/b)(c/d) = ac/bd
		num_ = num_*other.num_;
		den_ = den_*other.den_;
		simplify();
		return *this;
	}
	
	rational& operator/=(const rational& other) {
		// (a/b)/(c/d) = ad/bc
		num_ = num_*other.den_;
		den_ = den_*other.num_;
		simplify();
		return *this;
	}
	
	rational operator+(const rational& other) const {
		rational ret = *this;
		ret += other;
		return ret;
	}
	
	rational operator-(const rational& other) const {
		rational ret = *this;
		ret -= other;
		return ret;
	}

	rational operator*(const rational& other) const {
		rational ret = *this;
		ret *= other;
		return ret;
	}

	rational operator/(const rational& other) const {
		rational ret = *this;
		ret /= other;
		return ret;
	}
};


// OVERLOAD OPERATORE DI OUTPUT
template<typename I>
std::ostream& operator<<(std::ostream& os, const rational<I>& r) {
	if (r.den() == 0) 
	{
		if (r.num() == 0)
		{
			os << "NaN";
		}
		else
		{
			os << ((r.num() > 0) ? "Inf" : "-Inf");          // stesso costrutto usato sopra per compattare
		}
	}
	else if (r.den() == 1)
	{
		os << r.num();
	}
	else
	{
		os << r.num() << "/" << r.den();
	}
	return os;
}	