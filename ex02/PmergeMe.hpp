/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 18:07:27 by athonda           #+#    #+#             */
/*   Updated: 2025/10/13 08:13:12 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <utility>
# include <vector>
# include <deque>
# include <ostream>
# include <iostream>
# include <sstream>
# include <string>
# include <algorithm>
# include <climits>

// utility functions
std::ostream	&operator<<(std::ostream &os, std::pair<unsigned int, unsigned int> const &p);

void	print(std::vector<std::pair<unsigned int, unsigned int> > const &v, std::string const &s);
void	print(std::vector<unsigned int> const &v, std::string const &s);
void	print(std::vector<size_t> const &v, std::string const &s);
void	print(std::deque<std::pair<unsigned int, unsigned int> > const &v, std::string const &s);
void	print(std::deque<unsigned int> const &v, std::string const &s);
void	print(std::deque<size_t> const &v, std::string const &s);

long	getTime();

class BinarySearchCounter
{
	public:
		BinarySearchCounter(unsigned int &_counter);
		~BinarySearchCounter();
		bool operator()(std::pair<unsigned int, unsigned int> const &lhs, std::pair<unsigned int, unsigned int> const &rhs);
	private:
		unsigned int &counter;
};
class FindSecondByFirst
{
	private:
		unsigned int	_first;

	public:
		FindSecondByFirst(unsigned int value);
		~FindSecondByFirst();
		bool	operator()(std::pair<unsigned int, unsigned int> const &p) const;
};

// Pmergeme class
template <template <typename, typename> class T, typename N>
class Pmergeme
{
	typedef T<N, std::allocator<N> >	container_type;
	typedef std::pair<N, N>				pair_type;
	typedef T<pair_type, std::allocator<pair_type> >	pair_container;

	public:
		Pmergeme();
		Pmergeme(Pmergeme const &other);
		Pmergeme	&operator=(Pmergeme const &other);
		~Pmergeme();

		bool	setInput(int ac, char **av);
		container_type	sort(container_type value);
//		std::vector<unsigned int>	sort(std::vector<unsigned int> value);
		const container_type	&getValue() const;
		const container_type	&getSorted() const;
		const unsigned int		&getCounter() const;


	private:
		container_type	_value;
		container_type	_sorted;
		N				counter;

		pair_container	generatePairs(const container_type &value);
		container_type	extractFirsts(pair_container const &pair);
		container_type	buildPends(container_type const &a, pair_container &pair, bool is_odd, N odd_value);
		pair_container	generateMainChainWithIndex(const container_type &a);
		pair_container	generatePairsOrdered(pair_container a_with_index, const container_type &b);
		container_type	generateJacobsthal(N n);
		unsigned int	Jacobsthal(unsigned int n);
		void	generateMainChain(
			pair_container &a_with_index,
			const container_type &b,
			const container_type &jacobsthal,
			const pair_container &pair
		);
		typename container_type::size_type binary_search(container_type const &v, N value);
};

template <template <typename, typename> class T, typename N>
Pmergeme<T, N>::Pmergeme(): counter(0)
{}

template <template <typename, typename> class T, typename N>
Pmergeme<T, N>::Pmergeme(Pmergeme const &other):
	_value(other._value),
	_sorted(other._sorted),
	counter(other.counter)
{
}

template <template <typename, typename> class T, typename N>
Pmergeme<T, N>	&Pmergeme<T, N>::operator=(Pmergeme const &other)
{
	if (this != &other)
	{
		_value = other._value;
		_sorted = other._sorted;
		counter = other.counter;
	}
	return (*this);
}

template <template <typename, typename> class T, typename N>
Pmergeme<T, N>::~Pmergeme()
{}

template <template <typename, typename> class T, typename N>
const typename Pmergeme<T, N>::container_type	&Pmergeme<T, N>::getValue() const
{
	return (_value);
}

template <template <typename, typename> class T, typename N>
const typename Pmergeme<T, N>::container_type	&Pmergeme<T, N>::getSorted() const
{
	return (_sorted);
}

template <template <typename, typename> class T, typename N>
const unsigned int	&Pmergeme<T, N>::getCounter() const
{
	return (counter);
}

template <template <typename, typename> class T, typename N>
bool	Pmergeme<T, N>::setInput(int ac, char **av)
{
	_value.clear();
	std::stringstream	ss;
	for (int i = 1; i < ac; ++i)
	{
		ss << av[i] << " ";
	}

	std::string			line;
	std::getline(ss, line);
	if (line.empty() || ss.fail() || !ss.eof())
	{
		std::cerr << "error: Wrong input of argument." << std::endl;
		return false;
	}

	std::stringstream	ss_input(line);
	std::string			token;
	while (ss_input >> token)
	{
		if (token.empty() || ss_input.fail())
		{
			std::cerr << "error: Wrong input of token." << std::endl;
			_value.clear();
			return false;
		}
		// Parse to signed int first to detect negatives, then cast to N
		std::stringstream	ss_num(token);
		long long			num = 0;
		ss_num >> num;
		if (ss_num.fail() || !ss_num.eof())
		{
			std::cerr << "error: Wrong input of numbers." << std::endl;
			_value.clear();
			return false;
		}
		if (num < 0)
		{
			std::cerr << "error: Negative number is not allowed." << std::endl;
			_value.clear();
			return false;
		}
		if (num > INT_MAX)
		{
			std::cerr << "error: Number too large." << std::endl;
			_value.clear();
			return false;
		}
		_value.push_back(static_cast<N>(num));
	}
	return true;
}

template <template <typename, typename> class T, typename N>
typename Pmergeme<T, N>::container_type	Pmergeme<T, N>::sort(container_type value)
{
	// stop condition
	if (value.size() <= 1)
		return (value);

	// odd check and keep the last element if odd
	const bool is_odd = (value.size() % 2 == 1);
	const N odd_value = is_odd ? value.back() : 0;

	// calculate number of pairs
	const size_t number_of_pends = value.size() / 2 + (is_odd ? 1 : 0);

	// display the progress containers
	// print(container variables, "message")

	// forming pairs and sorting each pair
	pair_container pair = generatePairs(value);

	// generate firsts (greaters) from pairs
	container_type firsts = extractFirsts(pair);

	// recursively sort the firsts
	container_type a = sort(firsts);

	// extract the seconds according to the order of firsts
	container_type b = buildPends(a, pair, is_odd, odd_value);

	// making main chain with index
	pair_container a_with_index = generateMainChainWithIndex(a);

	// making pair container of a with b
	pair.clear();
	pair = generatePairsOrdered(a_with_index, b);

	// Generate Jacobsthal sequence up to size of pair (or size of pair + 1 if odd)
	container_type jacobsthal = generateJacobsthal(number_of_pends);

	// Insertion of element b into the interval of a with index using Jacobsthal sequence
	generateMainChain(a_with_index, b, jacobsthal, pair);
	container_type a_temp;
	for (size_t k = 0; k < a_with_index.size(); ++k)
	{
		a_temp.push_back(a_with_index[k].first);
	}
	_sorted = a_temp;
	return (a_temp);
}

template <template <typename, typename> class T, typename N>
typename Pmergeme<T, N>::pair_container Pmergeme<T, N>::generatePairs(const container_type &value)
{
	pair_container	pair;
	for (size_t i = 0; (2 * i + 1) < value.size(); ++i)
	{
		pair_type	p;
		if (value[2 * i] < value[2 * i + 1])
		{
			p = std::make_pair(value[2 * i + 1], value[2 * i]);
		}
		else
		{
			p = std::make_pair(value[2 * i], value[2 * i + 1]);
		}
		pair.push_back(p);
		counter++;
	}
	return (pair);
}

template <template <typename, typename> class T, typename N>
typename Pmergeme<T, N>::container_type Pmergeme<T, N>::extractFirsts(pair_container const &pair)
{
	container_type firsts;
	for (size_t j = 0; j < pair.size(); ++j)
	{
		firsts.push_back(pair[j].first);
	}
	return (firsts);
}

template <template <typename, typename> class T, typename N>
typename Pmergeme<T, N>::container_type Pmergeme<T, N>::buildPends(
		container_type const &a,
		pair_container &pair,
		bool is_odd,
		N odd_value)
{
	container_type	b;
	for (typename container_type::const_iterator it = a.begin(); it != a.end(); ++it)
	{
		typename pair_container::iterator found = std::find_if(pair.begin(), pair.end(), FindSecondByFirst(*it));
		b.push_back(found->second);
		pair.erase(found);
	}
	if (is_odd)
		b.push_back(odd_value);
	return (b);
}

template <template <typename, typename> class T, typename N>
typename Pmergeme<T, N>::pair_container Pmergeme<T, N>::generateMainChainWithIndex(
	const container_type &a)
{
	pair_container a_with_index;
	for (size_t j = 0; j < a.size(); ++j)
	{
		a_with_index.push_back(std::make_pair(a[j], static_cast<N>(j)));
	}
	return (a_with_index);
}

template <template <typename, typename> class T, typename N>
typename Pmergeme<T, N>::pair_container Pmergeme<T, N>::generatePairsOrdered(
	pair_container a_with_index,
	const container_type &b)
{
	pair_container	pair;
	for (size_t j = 0; j < a_with_index.size(); ++j)
	{
		pair.push_back(std::make_pair(a_with_index[j].first, b[j]));
	}
	return (pair);
}

template <template <typename, typename> class T, typename N>
typename Pmergeme<T, N>::container_type Pmergeme<T, N>::generateJacobsthal(N n)
{
	container_type jacobsthal;
	jacobsthal.push_back(1);

	N j_prev = 1;
	N j_curr = 3;

	N t = 2;
	while (n > j_curr)
	{
		N pos = j_curr;
		while (pos > j_prev)
		{
			jacobsthal.push_back(pos);
			--pos;
		}
		++t;
		j_prev = j_curr;
		j_curr = Jacobsthal(t);
	}
	while (n > j_prev)
	{
		jacobsthal.push_back(n);
		--n;
	}
	return (jacobsthal);
}

template <template <typename, typename> class T, typename N>
void Pmergeme<T, N>::generateMainChain(
	pair_container &a_with_index,
	const container_type &b,
	const container_type &jacobsthal,
	const pair_container &pair
)
{
	for (typename container_type::const_iterator it = jacobsthal.begin(); it != jacobsthal.end(); ++it)
	{
		const N index_b = *it - 1; // index into _b (0-based)
		const N insert_b = b[index_b];
		pair_type b_with_index = std::make_pair(insert_b, index_b);

		typename pair_container::iterator range_end;
		if (index_b < a_with_index.size())
		{
			const pair_type target_a = std::make_pair(pair[index_b].first, index_b);
			range_end = std::find(a_with_index.begin(), a_with_index.end(), target_a);
			if (range_end == a_with_index.end())
				range_end = a_with_index.end();
		}
		else
			range_end = a_with_index.end();
		typename pair_container::iterator insert_pos = std::lower_bound(a_with_index.begin(), range_end, b_with_index, BinarySearchCounter(counter));
		a_with_index.insert(insert_pos, b_with_index);
	}
}

template <template <typename, typename> class T, typename N>
typename Pmergeme<T, N>::container_type::size_type Pmergeme<T, N>::binary_search(container_type const &v, N value)
{
	typename container_type::size_type lo = 0;
	typename container_type::size_type hi = v.size();
	while (lo < hi)
	{
		typename container_type::size_type mid = lo + (hi - lo) / 2;
		if (v[mid] < value)
			lo = mid + 1;
		else
			hi = mid;
	}
	return lo;
}

template <template <typename, typename> class T, typename N>
unsigned int Pmergeme<T, N>::Jacobsthal(unsigned int n)
{
	if (n == 0)
		return (1);
	if (n == 1)
		return (1);
	return (Jacobsthal(n - 1) + 2 * Jacobsthal(n - 2));
}

#endif
