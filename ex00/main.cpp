#include "whatever.hpp"
#include <iostream>

int	main(void)
{
	int			a;
	int			b;
	int			equal_a;
	int			equal_b;
	double		float_a;
	double		float_b;
	char		char_a;
	char		char_b;
	const int	cx = 10;
	const int	cy = 20;
	int			first;
	int			second;
	bool		b1;
	bool		b2;
	float		f1;
	float		f2;
	int			val1;
	int			val2;
	int			*ptr1;
	int			*ptr2;

	std::cout << "--- 1. TEST : subject required  ---" << std::endl;
	a = 2;
	b = 3;
	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
	std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
	std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
	std::cout << "--- 1. TEST : Valeurs identiques (Cas limites) ---" << std::endl;
	equal_a = 42;
	equal_b = 42;
	std::cout << "min(42, 42) = " << ::min(equal_a, equal_b) << std::endl;
	// Doit retourner la deuxième valeur selon le sujet
	std::cout << "max(42, 42) = " << ::max(equal_a, equal_b) << std::endl;
	// Doit retourner la deuxième valeur selon le sujet
	std::cout << "\n--- 2. TEST : Types à virgule flottante (double\
		/ float) ---"
				<< std::endl;
	float_a = 4.23;
	float_b = 4.21;
	::swap(float_a, float_b);
	std::cout << "Après swap -> float_a = " << float_a << ",\
		float_b = "
				<< float_b << std::endl;
	std::cout << "min(float_a, float_b) = " << ::min(float_a,
		float_b) << std::endl;
	std::cout << "max(float_a, float_b) = " << ::max(float_a,
		float_b) << std::endl;
	std::cout << "\n--- 3. TEST : Type Caractère (char) ---" << std::endl;
	char_a = 'a';
	char_b = 'z';
	::swap(char_a, char_b);
	std::cout << "Après swap\
						->char_a = "
				<< char_a << ",\
			char_b = "
				<< char_b << std::endl;
	std::cout << "min(char_a, char_b) = " << ::min(char_a, char_b) << std::endl;
	std::cout << "max(char_a, char_b) = " << ::max(char_a, char_b) << std::endl;
	// =============================================================================
	// TEST 1: CONST-CORRECTNESS (Will fail compilation if templates are wrong)
	// =============================================================================
	std::cout << "=== TEST 1: Const-Correctness ===" << std::endl;
	{
		// This checks if your min/max accept 'const T &' and return 'const T &'
		std::cout << "min(const 10, const 20): " << ::min(cx,
			cy) << " (Expected: 10)" << std::endl;
		std::cout << "max(const 10, const 20): " << ::max(cx,
			cy) << " (Expected: 20)" << std::endl;
		// Note: ::swap(cx,cy) should NOT compile since const cannot be swapped.
	}
	// =============================================================================
	// TEST 2: THE STRICT EQUALITY RULE (Crucial for 42 correction matrix)
	// Rule: "If the two values are equal, it must return the second one"
	// =============================================================================
	std::cout << "\n=== TEST 2: Strict Equality & Memory Address Return ===" << std::endl;
	{
		first = 42;
		second = 42;
		// If your template returns the second one,its address will match 'second'
		const int &min_res = ::min(first, second);
		const int &max_res = ::max(first, second);
		std::cout << "min address matches second? " << (&min_res == &second ? "YES ✅" : "NO ❌") << std::endl;
		std::cout << "max address matches second? " << (&max_res == &second ? "YES ✅" : "NO ❌") << std::endl;
	}
	// =============================================================================
	// TEST 3: BOOLEANS & FLOATING POINT EDGE CASES
	// =============================================================================
	std::cout << "\n=== TEST 3: Booleans & Floats ===" << std::endl;
	{
		b1 = false;
		b2 = true;
		::swap(b1, b2);
		std::cout << "Post-swap bools: b1=" << b1 << " (Expected: 1),\
			b2 = " << b2
					<< "(Expected : 0) " << std::endl;
		f1 = -0.0f;
		f2 = 0.0f;
		std::cout << "min(-0.0f, 0.0f): " << ::min(f1, f2) << std::endl;
	}
	// =============================================================================
	// TEST 4: POINTERS (Addresses vs Values comparison check)
	// =============================================================================
	std::cout << "\n=== TEST 4: Pointer Typings ===" << std::endl;
	{
		val1 = 5;
		val2 = 10;
		ptr1 = &val1;
		ptr2 = &val2;
		// Note: This compares memory addresses, not the values inside them!
		std::cout << "ptr1: " << ptr1 << ", ptr2: " << ptr2 << std::endl;
		std::cout << "min(ptr1, ptr2): " << ::min(ptr1, ptr2) << std::endl;
		::swap(ptr1, ptr2);
		std::cout << "Post-swap pointers\
							->ptr1 points to : "
					<< *ptr1 << "(Expected : 10) " << std::endl;
	}
	// =============================================================================
	// TEST 5: COMPLEX CLASS TYPE (Validating operators evaluation)
	// =============================================================================
	std::cout << "\n=== TEST 5: Complex User-Defined Type ===" << std::endl;
	{
		// Awesome a(1337);
		// Awesome b(42);
		// std::cout << "Initial: a=" << a << ", b=" << b << std::endl;
		// ::swap(a, b);
		// std::cout << "Post-swap: a=" << a << ", b=" << b << std::endl;
		// std::cout << "min(a, b): " << ::min(a,
		// 	b) << " (Expected: 42)" << std::endl;
		// std::cout << "max(a, b): " << ::max(a,
		// 	b) << " (Expected: 1337)" << std::endl;
	}
	return (0);
}

/* expected output:
a = 3, b = 2
min(a, b) = 2
max(a, b) = 3
c = chaine2, d = chaine1
min(c, d) = chaine1
max(c, d) = chaine2
*/