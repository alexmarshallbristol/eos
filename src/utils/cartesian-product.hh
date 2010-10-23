/* vim: set sw=4 sts=4 et foldmethod=syntax : */

#ifndef EOS_GUARD_SRC_UTILS_CARTESIAN_PRODUCT_HH
#define EOS_GUARD_SRC_UTILS_CARTESIAN_PRODUCT_HH 1

#include <vector>

#include <iostream>

template <typename T_> class CartesianProduct
{
    private:
        typedef std::vector<typename T_::const_iterator> IteratorState;

        std::vector<T_> _data;

        IteratorState _begin, _end;

        unsigned long _size;

        template <typename U_> class _Iterator
        {
            private:
                typedef std::vector<typename U_::const_iterator> IteratorState;

                IteratorState _state, _begin, _end;

                _Iterator(const IteratorState & state, const IteratorState & begin, const IteratorState & end) :
                    _state(state),
                    _begin(begin),
                    _end(end)
                {
                }

            public:
                friend class CartesianProduct<U_>;

                bool operator!= (const _Iterator & other)
                {
                    auto j = other._state.cbegin();

                    for (auto i = _state.cbegin(), i_end = _state.cend() ; i != i_end ; ++i, ++j)
                    {
                        if (*i != *j)
                            return true;
                    }

                    return other._state.cend() != j;
                }

                _Iterator & operator++ ()
                {
                    auto ji = _state.rbegin(), jb = _begin.rbegin(), je = _end.rbegin();

                    do
                    {
                        ++(*ji);

                        if ((*je) != (*ji))
                            break;

                        (*ji) = (*jb);

                        ++ji;
                        ++jb;
                        ++je;
                    } while (_state.rend() != ji);

                    if (_state.rend() == ji)
                        _state = _end;

                    return *this;
                }

                std::vector<double> operator* () const
                {
                    std::vector<double> result;
                    for (auto i = _state.begin() ; _state.end() != i ; ++i)
                    {
                        result.push_back(*(*i));
                    }

                    return result;
                }
        };

    public:
        typedef _Iterator<T_> Iterator;

        CartesianProduct() :
            _size(0)
        {
        }

        void over(const T_ & x)
        {
            _data.push_back(x);
            _begin.push_back(_data.back().cbegin());
            _end.push_back(_data.back().cend());

            if (0 == _size)
                _size = x.size();
            else
                _size *= x.size();
        }

        Iterator begin() const
        {
            return Iterator(_begin, _begin, _end);
        }

        Iterator end() const
        {
            return Iterator(_end, _begin, _end);
        }

        unsigned long size() const
        {
            return _size;
        }
};

#endif
