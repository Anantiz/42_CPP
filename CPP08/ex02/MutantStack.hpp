#pragma once

#include <stack>

#define TTT template <typename T>

TTT
class MutantStack : public std::stack<T>
{
public:

	class iterator
	{
		private:

			T *_ptr;

		public:

			typename container::iterator &begin()
			{
				_ptr = this->c.begin();
				return *this;
			}

			typename container::iterator &end()
			{
				_ptr = this->c.end();
				return *this;
			}
	};
};
