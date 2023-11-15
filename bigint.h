// <bigint.h> -*- Vss -*-

/** @file Vss/bigint.h
 *  This is not a Standard C++ Library header.
 */

#ifndef VSS_BIGINT_H__
#define VSS_BIGINT_H__

#include <math.h>
#include <string>
#include <vector>
#include <cstring>
#include <ctype.h>
#include <iostream>
#include <type_traits>

#ifdef VSS_BIGINT_DEBUG__
#include <cassert>
#endif

class bigint
{
public:
    bigint();
    bigint(const char *_str);
    bigint(const std::string &_str);
    bigint(const bigint &_other);
    bigint(const float &_num);
    bigint(const double &_num);
    bigint(const long double &_num);
    template<typename _T=long long>bigint(const _T &_num);

    //                   operator"" _bint
           bigint&       operator= (const bigint &_A);
    friend bigint        operator+ (const bigint &_A);
    friend bigint        operator- (const bigint &_A);
    friend bool          operator< (const bigint &_A,const bigint &_B);
    friend bool          operator> (const bigint &_A,const bigint &_B);
    friend bool          operator<=(const bigint &_A,const bigint &_B);
    friend bool          operator>=(const bigint &_A,const bigint &_B);
    friend bool          operator==(const bigint &_A,const bigint &_B);
    friend bool          operator!=(const bigint &_A,const bigint &_B);
    friend bigint        operator+ (const bigint &_A,const bigint &_B);
    const  bigint&       operator+=(const bigint &_A);
    const  bigint&       operator++();
           bigint        operator++(int);
    friend bigint        operator- (const bigint &_A,const bigint &_B);
    const  bigint&       operator-=(const bigint &_A);
    const  bigint&       operator--();
           bigint        operator--(int);
    friend bigint        operator* (const bigint &_A,const bigint &_B);/*
    friend bigint        operator/ (const bigint &_A,const bigint &_B);
    friend bigint        operator% (const bigint &_A,const bigint &_B);*/
    friend std::istream& operator>>(std::istream &_is,bigint &_A);
    friend std::ostream& operator<<(std::ostream &_os,const bigint &_A);

          void    e(long long _x);                     // (*this) *= 10^x
    const bigint& e(const bigint &_A,long long _x);    // (*this)*10^x

private:
    bool isNegative;
    std::vector<__int8>digits;
    void removeLeadingZeros();
};

#endif